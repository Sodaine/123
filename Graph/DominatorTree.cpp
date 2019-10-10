/**
 * 最近必经点 (idom): 节点 y 的必经点集合 dom(y) 中 dfn 值最大的点 x 是距离 y 最近的必经点
 *                   称为 y 的最近必经点, 最近必经点是唯一的, 记 x=idom(y)
 * 半必经点 (semi) : 在搜索树 T 上点 y 的祖先中，通过非树枝边可以到达 y 的深度最小的祖先 x ，
 *                 称为 y 的半必经点。半必经点也是唯一的，记 x=semi(y)。
 *
 * 1. 设有向图 G=(V,E)， (G,r) 是一个 Flow Graph，则称 (G,r) 的子图
 *    D=(V, { (idom(i),i) | i∈V,i≠r }, r) 为 (G,r) 的一棵 Dominator Tree。
 * 2.  (G,r) 的 Dominator Tree 是一棵有向有根树，从 r 出发可以到达 G 中的所有点，
 *    并且树上的每条边 (u,v) 都满足： u=idom(v) ，即父节点是子节点的最近必经点。
 * 3. x=idom(y) ，当且仅当有向边 (x,y) 是 Dominator Tree 中的一条树枝边。
 * 4. x dom y ，当且仅当在 Dominator Tree 中存在一条从 x 到 y 的路径。
 * 5. x 的必经点集合 dom(x) 就是 Dominator Tree 上 x 的所有祖先以及 x 自身。
 *
 * 应用:
 * 1. 求有向图的割顶:  dominator tree 上的非叶节点
 * 2. 有向图的必经边: 每条边上加一个点, 转化成必经点问题
 * 3. 求起点 S 到终点 T 的所有路径中最接近源的必经点: 求出必经点, 取最近的
 * 4. 求多少个 (x,y) 满足存在 1->x 的路径和 1->y 的路径只有 1 这个公共点:
 *    求出 1 为根的 dominator tree , 算出不合法的, 总的减去即可.
 *    考虑 1 的每个儿子 v , 同一颗子树的节点对都是非法的.
 *
 * succ 是原图,  pred 是边反向后的图,  dom 是 Dominator Tree
 *  dom 记录的是 dfs 序构成的树,  G 中节点 u 在 dom 树上的标号是 dfn[u]
 * 相反 dom 中节点 u 在原图 G 中的标号是 pt[u]
 * 调用 build 得到以 s 为根的 Dominator Tree
 **/
namespace DT {
  int dfn[N], pre[N], pt[N], sz;
  int semi[N], dsu[N], idom[N], best[N];
  int get(int x) {
    if (x == dsu[x]) return x;
    int y = get(dsu[x]);
    if (semi[best[x]] > semi[best[dsu[x]]]) best[x] = best[dsu[x]];
    return dsu[x] = y;
  }
  void dfs(int u, const vi succ[]) {
    dfn[u] = sz; pt[sz ++] = u;
    for (auto &v: succ[u]) if (!~dfn[v]) {
      dfs(v, succ); pre[dfn[v]] = dfn[u];
    }
  }
  void tarjan(const vi pred[], vi dom[]) {
    for (int j = sz - 1, u; u = pt[j], j > 0; -- j) {
      for (auto &tv: pred[u]) if (~dfn[tv]) {
        int v = dfn[tv]; get(v);
        if (semi[best[v]] < semi[j]) semi[j] = semi[best[v]];
      }
      dom[semi[j]].push_back(j);
      int x = dsu[j] = pre[j];
      for (auto &z: dom[x]) {
        get(z);
        if (semi[best[z]] < x) idom[z] = best[z];
        else idom[z] = x;
      }
      dom[x].clear();
    }
    for (int i = 1; i < sz; ++ i) {
      if (semi[i] != idom[i]) idom[i] = idom[idom[i]];
      dom[idom[i]].push_back(i);
    }
  }
  void build(int n, int s, const vi succ[], const vi pred[], vi dom[]) {
    for (int i = 0; i < n; ++i) {
      dfn[i] = -1; dom[i].clear();
      dsu[i] = best[i] = semi[i] = i;
    }
    sz = 0; dfs(s, succ); tarjan(pred, dom);
  }
}

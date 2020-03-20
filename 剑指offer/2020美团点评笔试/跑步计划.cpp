
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9; 

/*
 * Dijkstra最短路径。
 * 即，统计图(G)中"顶点vs"到其它各个顶点的最短路径。
 *
 * 参数说明：
 *        G -- 图
 *       vs -- 起始顶点(start vertex)。即计算"顶点vs"到其它顶点的最短路径。
 *     prev -- 前驱顶点数组。即，prev[i]的值是"顶点vs"到"顶点i"的最短路径所经历的全部顶点中，位于"顶点i"之前的那个顶点。
 *     dist -- 长度数组。即，dist[i]是"顶点vs"到"顶点i"的最短路径的长度。
 *        n -- 顶点数
 */

vector<int> dijkstra(vector<vector<int> > G, int vs, int n)
{
    vector<int> dist();
}

int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<int> > G;
    for(int i = 0; i < n; ++i) {
        vector<int> v(n, INF);
        G.push_back(v);
    }
    int u, v, w;
    for(int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        G[u-1][v-1] = G[v-1][u-1] = w;
    }
    int k;
    cin >> k;
    vector<bool> vis(n);
    vector<int> d(n);
    vector<int> pre(n);

    Dijkstra(n, 0, G, vis, d, pre);

    int res = 0;
    for(int i = 0; i < n; ++i) {
        int x = d[i];
        if(x == k) {
            ++res;
        } else if(x < k) {
            for(int j = 0; j < n; ++j) {
                if(G[i][j] != INF && G[i][j] + d[i] > k) {
                    ++res;
                } 
            }
        }
    }
    cout << res;
    return 0;
}

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int INF = INT_MAX; 

/*
 * Dijkstra最短路径。
 * 即，统计图(G)中"顶点vs"到其它各个顶点的最短路径。
 *
 * 参数说明：
 *        G -- 图
 *       vs -- 起始顶点(start vertex)。即计算"顶点vs"到其它顶点的最短路径。
 *     prev -- 前驱顶点数组。即，prev[i]的值是"顶点vs"到"顶点i"的最短路径所经历的全部顶点中，位于"顶点i"之前的那个顶点。
 *     dist -- 长度数组。即，dist[i]是"顶点vs"到"顶点i"的最短路径的长度。
 *     flag -- 源点到各顶点的距离是否已得到
 *        n -- 顶点数
 */
class Dijkstra {
private:
    //vector<int> prev;
public:
    vector<int> run(vector<vector<int> > G, int vs, int n) {
        vector<int> flag(n, false);
        vector<int> dist(G[vs].begin(), G[vs].end());
        int min, minNode, temp;

        //初始化
        dist[vs] = 0;
        flag[vs] = true;
        //prev.resize(n);
        //fill(prev.begin(), prev.end(), 0);

        for(int i = 1; i < n; ++i) {
            min = INF;
            //查找未获取最短路径的顶点中距离最近的顶点
            for(int j = 0; j < n; ++j) {
                if(flag[j] == false && dist[j] < min) {
                    min = dist[j];
                    minNode = j;
                }
            }

            //标记minNode为“已获取路径”
            flag[minNode] = true;

            //更新与minNode相连的顶点的最短路径
            for(int j = 0; j < n; ++j) {
                temp = (G[minNode][j] == INF)? INF: dist[minNode] + G[minNode][j];
                if(flag[j] == false && temp < dist[j]) {
                    dist[j] = temp;
                    //prev[j] = minNode;
                }
            }
        }

        return dist;
    }

    void printDist(vector<int> dist, int n) {
        for(int i = 0; i < n; ++i) {
            if(dist[i] == INF) {
                cout << '\t' << i << ":\tINF" << endl;
            }
            else {
                cout << '\t' << i << ":\t" << dist[i] << endl;
            }      
        }
    }

    
    // 输出从起点s到顶点v的最短路径
    /*void DFSPrint(int s, int v)
    {
        if (v == s)
        {
            cout << s << " ";
            return;
        }
        DFSPrint(s, prev[v]);
        cout << v << " ";
    }*/
};


int main()
{
    int n, m, s;    //顶点数、边数、源点
    cin >> n >> m >> s;
    vector<vector<int> > G; //保存邻接矩阵的二维矩阵
    for(int i = 0; i < n; ++i) {
        vector<int> v(n, INF);
        G.push_back(v);
    }
    int u, v, w;    //起点、重点、边的权重
    for(int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        G[u-1][v-1] = G[v-1][u-1] = w;
    }
    int k;      //跑步数
    cin >> k;

    Dijkstra dijk;
    vector<int> d = dijk.run(G, s, n);

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
    /*vector<vector<int>> G = {{  0,  4,INF,INF,  1,  2},
                             {  4,  0,  6,INF,INF,  3},
                             {INF,  6,  0,  6,INF,  5},
                             {INF,INF,  6,  0,  4,  5},
                             {  1,INF,INF,  4,  0,  3},
                             {  2,  3,  5,  5,  3,  0}};
    Dijkstra d;
    vector<int> dist = d.run(G, 0, 6);
    d.printDist(dist, 6);*/
}

/**
 * 给定一张包含N个点、N-1条边的无向连通图，节点从1到N编号，每条边的长度均为1。
 * 假设你从1号节点出发并打算遍历所有节点，那么总路程至少是多少？
 * 
 * 输入描述：
 * 第一行包含一个整数N，1≤N≤10^5。
 * 接下来N-1行，每行包含两个整数X和Y，表示X号节点和Y号节点之间有一条边，1≤X，Y≤N。
 * 
 * 输出描述：
 * 输出总路程的最小值。
 */

/**
 * 思路：
 * 由题可知，这是一个无环图，所以使用bfs即可遍历，除了一条“主路”外，其他路都要折返
 * 所以总路程为2*(n-1)-“主路”，为使总路程最短，可选最长的一条路为“主路”
 */
#include <iostream>
#include <vector>
using namespace std;

//计算结点k的深度,叶结点深度为1，使用时可减1
long depth(vector<vector<long> > &Graph, long n, long k) {
    long res = 0;
    long size = Graph[k].size();
    for(long i = 0; i < size; ++i) {
        long j = Graph[k][i];
        for (vector<long>::iterator it = Graph[j].begin(); it != Graph[j].end(); ) {
            if (*it == i) {
                it = Graph[j].erase(it);
                break;
            } else {
                ++it;
            }
        }
        res = max(res, depth(Graph, n, j));
    }
    return res + 1;
}

int main() {
    long N, begin, end;
    cin >> N;
    vector<vector<long> > Graph(N);
    for(long i = 0; i < N-1; ++i) {
        cin >> begin >> end;
        Graph[begin-1].push_back(end-1);
        Graph[end-1].push_back(begin-1);
    }
    long maxDepth = depth(Graph, N, 0)-1;
    cout << 2*(N-1) - maxDepth;
}

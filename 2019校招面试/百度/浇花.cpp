/**
 * 一个花坛中有很多花和两个喷泉。
 * 喷泉可以浇到以自己为中心，半径为r的圆内的所有范围的花。 
 * 现在给出这些花的坐标和两个喷泉的坐标，要求你安排两个喷泉浇花的半径r1和r2，
 * 使得所有的花都能被浇到的同时, r12 + r22 的值最小。
 * 
 * 输入描述：
 * 第一行5个整数n，x1，y1，x2，y2表示花的数量和两个喷泉的坐标。
 * 接下来n行，每行两个整数xi, yi表示第i朵花的坐标。
 * 满足1 <= n <= 2000，花和喷泉的坐标满足-107<= x, y <= 107。
 * 
 * 输出描述：
 * 一个整数，r12 + r22 的最小值。
 */
#include <bits/stdc++.h>
using namespace std;

typedef struct point {
    int x, y;
} point;

long fun(long n, point p1, point p2, vector<point> flower) {
    vector<pair<long, long> > dis(n);
    int x1 = p1.x, y1 = p1.y;
    int x2 = p2.x, y2 = p2.y;

    for(int i = 0; i < n; ++i) {
        dis[i]={pow(abs(flower[i].x-x1),2)+pow(abs(flower[i].y-y1),2),pow(abs(flower[i].x-x2),2)+pow(abs(flower[i].y-y2),2)};
    }
    sort(dis.begin(),dis.end(),[&](const pair<long,long>& a,const pair<long,long>& b){return a.first > b.first;});
    long res = LONG_MAX,r2 = 0;
    for(int i = 0;i < n;i++){
        res = min(res,dis[i].first+r2);
        r2 = max(dis[i].second,r2);
    }
    return min(res, r2);
}

int main() { 
    int n;
    point p1, p2, temp;
    cin >> n >> p1.x >> p1.y >> p2.x >> p2.y;

    vector<point> flower(n);
    for(int i = 0; i < n; ++i) {
        cin >> flower[i].x >> flower[i].y;
    }

    cout << fun(n, p1, p2, flower);
}
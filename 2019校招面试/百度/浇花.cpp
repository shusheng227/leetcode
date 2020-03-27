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
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef struct point {
    int x, y;
} point;

long fun(int n, point p1, point p2, vector<point> flower) {
    
}



 

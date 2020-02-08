/*
 * 给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。
 */
/*
 * 思路：
 * 以某一点为原点，计算其他点与该点形成的直线的斜率，斜率相同说明在同一条直线上
 * 将所有点循环一遍即可得到同一直线上的点数
 * 缺点：进行除法计算无法得到精确结果，所以两个点相近时计算斜率会出现计算错误
 * 提高：计算斜率分子和分母的最大公约数，得到斜率的最简分数，使用最简分数保存斜率
 *       具体方法见"直线上最多的点(提高).cpp"
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int max_number = 0;
        int len = points.size();
        if(len<3) return len;

        for(int i=0; i<len-1; i++) {
            int number = 0;         //保存与当前点坐标相同的点的数量
            int max_number2 = 0;    //保存本轮直线上最多的点
            vector<vector<double>> count;   //保存当前点与其他点组成的直线斜率

            for(int j=i+1; j<len; j++) {
                double slope = getSlope(points[i], points[j]);
                
                //若两点相同，跳过循环
                if(slope == -INT_MAX) {
                    number++;
                    continue;
                }
                count.push_back({slope,1});
                if(max_number2<1) max_number2=1;
                // 遍历查找斜率是否已存在，即该点是否在其他直线上
                for(int k=0; k<count.size()-1; k++) {
                    if(abs(count[k][0]-slope)<1e-5) {
                        count[k][1]++;
                        count.pop_back();
                        if(count[k][1]>max_number2) max_number2=count[k][1];
                        break;
                    }
                }
            }
            
            //更新最多点数
            max_number = max(max_number, max_number2+number);
        }

        return max_number+1;
    }

private:
    // 计算point1和point2组成的直线的斜率，
    double getSlope(vector<int> point1, vector<int> point2) {
        double k = 0;  //记录point1和point2组成的直线的斜率
        if(point1[0] == point2[0]) {
            k = INT_MAX;
            if(point1[1] == point2[1]) {
                k = -INT_MAX;
            }
        }
        else k = (double)(point2[1]-point1[1])/(point2[0]-point1[0]);

        return k;
    }

};

int main() {
    vector< vector<int> > points;
    points.push_back({0,0});
    points.push_back({94911151,94911150});
    points.push_back({94911152,94911151});

    Solution s;
    int result = s.maxPoints(points);
    cout << result;
}
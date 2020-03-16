/**
 * 地上有一个m行和n列的方格。
 * 一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 
 * 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。
 * 请问该机器人能够达到多少个格子？
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        vector<bool> flag(rows*cols, false);
        helper(threshold, rows, cols, 0, 0, flag);
        return count;
    }

private:
    int count = 0;
    void helper(int threshold, int rows, int cols, int x, int y, vector<bool> &flag) {
        if(x < 0 || x >= rows) return ;
        if(y < 0 || y >= cols) return ;
        if(flag[x*cols+y] == true) return ;
        if(getSum(x, y) > threshold) return ;
        else {
            ++count;
            flag[x*cols+y] = true;
            //cout << x << "," << y << endl;
        }

        helper(threshold, rows, cols, x-1, y, flag);
        helper(threshold, rows, cols, x+1, y, flag);
        helper(threshold, rows, cols, x, y-1, flag);
        helper(threshold, rows, cols, x, y+1, flag);
    }
    //求取两个整数数位之和
    int getSum(int x, int y) {
        int res = 0;

        while(x) {
            res += x%10;
            x /= 10;
        }
        while(y) {
            res += y%10;
            y /= 10;
        }

        return res;
    }
};

int main() {
    Solution s;
    cout << s.movingCount(10, 3, 4) << endl;
}
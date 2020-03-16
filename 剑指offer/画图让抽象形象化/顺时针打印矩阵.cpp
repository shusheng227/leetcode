/**
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
 * 例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
 */
/**
 * 思路：
 * 以一圈为单位，进行循环输出，按照从左到右，再从上到下，再从右向左，再从下到上
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0, right = col - 1, top = 0, bottom = row - 1;

        if(row == 0 || col == 0) {
            return res;
        }

        while(left <= right && top <= bottom) {
            //从左到右输出最上面一行
            for(int i = left; i <= right-1; ++i) {
                res.push_back(matrix[top][i]);
            }

            //从上到下输出最右面一行
            for(int i = top; i <= bottom; ++i) {
                res.push_back(matrix[i][right]);
            }

            //从右向左输出最下面一行
            if(top != bottom) {
                for(int i = right-1; i >= left; --i) {
                    res.push_back(matrix[bottom][i]);
                }
            }

            //从上到下输出最左边一行
            if(left != right) {
                for(int i = bottom-1; i >= top+1; --i) {
                    res.push_back(matrix[i][left]);
                }
            }

            ++left;
            --right;
            ++top;
            --bottom;
        }

        return res;
    }
};
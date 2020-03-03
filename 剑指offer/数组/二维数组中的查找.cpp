/**
 * 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
 * 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 */
/**
 * 思路：
 * 首先选取数组中右上角的数字。如果该数字等于要查找的数字，查找过程结束；
 * 如果该数字大于要查找的数组，剔除这个数字所在的列；
 * 如果该数字小于要查找的数字，剔除这个数字所在的行。
 * 这样每一步都可以缩小查找的范围，直到找到要查找的数字，或者查找范围为空。
 */ 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int rows = array.size();
        int cols = array[0].size();
        if(!array.empty() && rows > 0 && cols > 0){
            int row = 0;
            int col = cols - 1;
            while(row < rows && col >= 0){
                if(array[row][col] == target){
                    return true;
                }
                else if(array[row][col] > target){
                    --col;
                }
                else{
                    ++row;
                }
            }
        }
        return false;
    }
};

int main(){
    vector<vector<int> > array;
    array.push_back({1,2,8,9});
    array.push_back({2,4,9,12});
    array.push_back({4,7,10,13});
    array.push_back({6,8,11,15});
    Solution s;
    cout << s.Find(7,array);
}
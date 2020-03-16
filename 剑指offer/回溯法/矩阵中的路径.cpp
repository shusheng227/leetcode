/**
 * 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
 * 路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
 *                                                                  | a b c e |
 * 如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 例如 | s f c s |
 *                                                                  | a d e e |
 * 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
 * 因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
 */
#include <iostream>
#include <vector>
using namespace std;
#define index(p, cols, x, y) *(p + x*cols + y)

class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        vector<bool> v(rows*cols, false);
        for(int i=0; i<rows; ++i) {
            for(int j=0; j<cols; ++j) {
                if(index(matrix, cols, i, j) == *str) {                   
                    if(isPath(matrix, str, v, rows, cols, i, j)) return true;
                }
            }
        }
        return false;
    }
private:
    bool isPath(char* matrix, char* str, vector<bool> &flag, int rows, int cols, int x, int y) {
        
        if(*str == 0) return true;
        if(x < 0 || x >= rows) return false;
        if(y < 0 || y >= cols) return false;
        if(index(matrix, cols, x, y) != *str) return false;

        if(flag[x*cols+y] == true) return false;
        else flag[x*cols+y] = true;
        //cout << x << "," << y << ":" << *str << endl;
        if(isPath(matrix, str+1, flag, rows, cols, x-1, y)) return true;
        if(isPath(matrix, str+1, flag, rows, cols, x+1, y)) return true;
        if(isPath(matrix, str+1, flag, rows, cols, x, y-1)) return true;
        if(isPath(matrix, str+1, flag, rows, cols, x, y+1)) return true;

        flag[x*cols+y] = false;
        return false;
    }

};

int main() {
    char matrix[] = "ABCESFCSADEE";
    char str[] = "ABCB";
    Solution s;
    cout << s.hasPath(matrix,3,4,str) << endl;
}
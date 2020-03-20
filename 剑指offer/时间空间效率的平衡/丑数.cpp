/**
 * 把只包含质因子2、3和5的数称作丑数（Ugly Number）。
 * 例如6、8都是丑数，但14不是，因为它包含质因子7。 
 * 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
 */
/**
 * 思路：
 * 每个丑数都由其他丑数乘以2/3/5得到，即对于丑数M，x*2>M,y*3>M,z*5>M
 * 则M的下一个丑数为min（x*2，y*3，z*5），但每次需要遍历得到第一个大于M的x、y、z，
 * 所以需要三个指针，分别指向上一个x、y、z，直接减少遍历这一步
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index < 7) return index;
        vector<int> v(index);
        v[0] = 1;
        int x = 0, y = 0, z = 0;
        for(int i = 1; i < index; ++i) {
            v[i] = min(v[x]*2, min(v[y]*3, v[z]*5));
            if(v[i] == v[x]*2) ++x;
            if(v[i] == v[y]*3) ++y;
            if(v[i] == v[z]*5) ++z;       
        }
        return v[index-1];
    }
};

int main() {
    Solution s;
    cout << s.GetUglyNumber_Solution(7) << endl;
}
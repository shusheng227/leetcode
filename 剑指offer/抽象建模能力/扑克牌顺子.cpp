/**
 * LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...
 * 他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！
 * “红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。
 * 上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。 
 * 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何， 
 * 如果牌能组成顺子就输出true，否则就输出false。
 * 为了方便起见,你可以认为大小王是0。
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        int count_zero = 0; //0的数量，即王的数量
        int count = 0;      //属于牌面之间的差值，用于判断能否使用大/小王填充
        int size = numbers.size();
        if(size < 5) return false; 

        sort(numbers.begin(), numbers.end());
        for(int i = 0; i < size-1; ++i) {
            int val = numbers[i];
            if(val == 0) {
                ++count_zero;
            } else if(val == numbers[i+1]) {
                return false;
            } else {
                count += numbers[i+1] - val - 1;
            }
        }

        return (count_zero >= count);
    }
};
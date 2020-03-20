/**
 * 求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
 * 为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
 * ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
 */
/**
 * 思路：
 * 对于n的i位数（i：个、十、百、千……），大于2时该位出现过一次1，即1出现的次数增加i次
 * 等于1时出现次数取决于低一位（即十位数为1时，十位数上出现过1的次数取决于个位数）
 * 等于0时出现次数取决于高一位（即十位数为0时，十位数上出现过1的次数取决于百位数）
 * 对于单独每一位。由于每10次出现一次1，大于2时额外加1次，故单独看某一位时，
 * (a + 8) / 10为该位1出现次数，乘以i后是该位i出现总次数
 * 当该位为1时还需额外计算该位出现次数，例如对于12，按上面方法得到十位数中1出现0次，
 * 只因大于10的部分无法根据十位数判断，需要额外使用个位数计算，即2+1=3次
 * 同理，对于112，对于百位数，还需额外加12+1=13次
 */
#include <iostream>
using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count = 0;
        for (int i = 1; i <= n; i *= 10) {
            int a = n / i,b = n % i;    //a为当前位变化次数，（a+8）/10即为1在该位遍历次数
            count += (a + 8) / 10 * i + ((a % 10 == 1) ? b + 1 : 0);
            //(a + 8) / 10 * i：i位数上出现过1的次数，加8是为了却别是否大于2，若大于2需要多加1次
            //((a % 10 == 1) ? b + 1 : 0)：i位数为1时出现次数由低一位决定
        }
        return count;
    }
};

int main() {
    Solution s;
    cout << s.NumberOf1Between1AndN_Solution(111) << endl;
}
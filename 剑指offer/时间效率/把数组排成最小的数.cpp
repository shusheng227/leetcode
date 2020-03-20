/**
 * 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
 * 例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
 */
/**
 * 比较两个字符串s1, s2大小的时候，先将它们拼接起来，比较s1+s2,和s2+s1那个大，
 * 如果s1+s2大，那说明s2应该放前面，所以按这个规则，s2就应该排在s1前面。
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        int size = numbers.size();
        for(int i = 0; i < size-1; ++i) {
            for(int j = i+1; j < size; ++j) {
                if(helper(numbers[i], numbers[j]) > helper(numbers[j], numbers[i])) {
                    swap(numbers[i], numbers[j]);
                }
            }
        }
        string res;
        for(int i = 0; i < size; ++i) {
            res += to_string(numbers[i]);
        }
        return res;
    }
private:
    int helper(int num1, int num2) {
        int m = num2;
        do {
            num1 *= 10;
        } while(m /= 10);
        num1 += num2;
        return num1;
    }
};
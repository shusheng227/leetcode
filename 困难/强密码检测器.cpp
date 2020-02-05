/*
 * 一个强密码应满足以下所有条件：
 * 由至少6个，至多20个字符组成。
 * 至少包含一个小写字母，一个大写字母，和一个数字。
 * 同一字符不能连续出现三次 (比如 "...aaa..." 是不允许的, 但是"...aa...a..." 是可以的)。
 * 编写函数strongPasswordChecker(s)，s 代表输入字符串，如果 s 已经符合强密码条件，则返回0；
 * 否则返回要将 s 修改为满足强密码条件的字符串所需要进行修改的最小步数。
 * 插入、删除、替换任一字符都算作一次修改。
 */ 
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int strongPasswordChecker(string s) {
    	int len = s.length();
    	int number_fix = 0;					//修改次数
		int number_change = 0;				//替换次数
		int number_insert = max(0,6-len);	//插入次数 
		int number_delete = max(0,len-20);	//删除次数 
    	int count_three = 0;				//用于统计字符连续出现三次个数的中间变量 
        int number_three = 0;				//字符连续出现三次的个数 
        bool flag_capital = false;			//字符串中是否含有大写字母的标志
        bool flag_lowercase = false;		//字符串中是否含有小写字母的标志
		bool flag_number = false;			//字符串中是否含有数字的标志
		
		//统计不满足强密码条件的各个标志 
        for(int i=0; i<len; i++) {
        	if(i>0 && s[i]==s[i-1]) count_three++;
			else count_three = 0;
			if(count_three==3) {
				number_three++;
				count_three = 0;
			}
			
        	if(s[i]>'A' && s[i]<'Z') flag_capital = true;
        	else if(s[i]>'a' && s[i]<'z') flag_lowercase = true;
        	else if(s[i]>'0' && s[i]<'9') flag_number = true;
		}
		
		number_fix = (!flag_capital) + (!flag_lowercase) + (!flag_number);
		
		return number_fix;
    }
};

int main() {
	string str = "123456";
	Solution s;
	int result = s.strongPasswordChecker(str);
	cout << result;
}
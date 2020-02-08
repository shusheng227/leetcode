/*
 * 一个强密码应满足以下所有条件：
 * 由至少6个，至多20个字符组成。
 * 至少包含一个小写字母，一个大写字母，和一个数字。
 * 同一字符不能连续出现三次 (比如 "...aaa..." 是不允许的, 但是"...aa...a..." 是可以的)。
 * 编写函数strongPasswordChecker(s)，s 代表输入字符串，如果 s 已经符合强密码条件，则返回0；
 * 否则返回要将 s 修改为满足强密码条件的字符串所需要进行修改的最小步数。
 * 插入、删除、替换任一字符都算作一次修改。
 */ 

/*
 * 思路：
 * 不满足条件情况有以下三种：
 * ①长度	②类型缺失	③字符重复
 * 当密码长度小于6时，情况三可以完全被情况一和情况二替代，所以只需要考虑前两种情况
 * 当密码长度大于6时，由于长度超出所以需要尽量避免插入，所以字符重复时尽量使用删除和替代进行修改
 * 对于字符重复长度超过3的，只需要删除至（3m+2）个字符，然后替代m个字符即可
 */ 
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int strongPasswordChecker(string s) {
    	int len = s.length();
    	int number_fix = 0;					//修改次数
		int number_change = 0;				//替换次数
		int number_missing = 0;				//类型缺失数
        bool flag_capital = false;			//字符串中是否含有大写字母的标志
        bool flag_lowercase = false;		//字符串中是否含有小写字母的标志
		bool flag_number = false;			//字符串中是否含有数字的标志
		vector<int> repeat(len,0);			//统计每个位置重复字符数
		
		//统计不满足强密码条件的各个标志 
        for(int i=0; i<len;) {	
			// 统计类型缺失					
        	if(s[i]>='A' && s[i]<='Z') flag_capital = true;
        	else if(s[i]>='a' && s[i]<='z') flag_lowercase = true;
        	else if(s[i]>='0' && s[i]<='9') flag_number = true;

			// 统计字符重复
			int j = i;
			while(i<len && s[i]==s[j]) i++;
			repeat[j] = i-j;
		}
		
		number_missing = (!flag_capital) + (!flag_lowercase) + (!flag_number);
		if(len < 6) {
			// 长度小于6时，直接根据情况一和情况二得到结果
			return max(number_missing, 6-len);
		}
		else {
			int number_delete = max(0,len-20);	//至少删除次数
			number_fix = number_delete;
			//先用删除解决字符重复问题，将重复字符删至3m+2个
			for(int k=1; k<3; k++) {
				for(int i=0; i<len && number_delete>=k; i++) {
					if(repeat[i]<3 || (repeat[i]%3)!=(k-1)) continue;
					repeat[i] -= k;
					number_delete -= k;
				}
			}
			//若长度还是超过20，则继续删除重复字符，否则使用替换解决重复字符
			for(int i=0; i<len; i++) {
				if(repeat[i]>=3 && number_delete>0) {
					int need = repeat[i]-2;
					repeat[i] -= number_delete;
					number_delete -= need;
				}
				if(repeat[i]>=3) number_change += repeat[i]/3;
			}
			//若替换数量足够大，则可以使用替换解决类型缺失问题
			number_fix += max(number_missing, number_change);

			return number_fix;
		}		
    }
};

int main() {
	string str = "1234567890123456Baaaa";
	Solution s;
	int result = s.strongPasswordChecker(str);
	cout << result;
}

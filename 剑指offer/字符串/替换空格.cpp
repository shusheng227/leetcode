/**
 * 请实现一个函数，将一个字符串中的每个空格替换成“%20”。
 * 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 */
#include <iostream>
#include <cstring>
using namespace std; 

class Solution {
public:
	void replaceSpace(char *str,int length) {
        int len = 0;
        char *p = str;
        for(int i=0; i<length; i++) {
            if(*p == ' ') len+=3;
            else len++;
            p++;

        }
        
        char *t = new char[len+1];
        char *s = t;
        p = str;
        for(int i=0; i<length; i++) {
            if(*p == ' ') {
                strcpy(s, "%20");
                s += 3;
            }
            else {
                *s = *p;
                s++;
            }
            p++;
            
        }
        *s = '\0';
        strcpy(str, t);
        delete []t;
	}
};

int main() {
    char str[] = "We are happy!";
    Solution s;
    s.replaceSpace(str,strlen(str));
    cout << str;
}
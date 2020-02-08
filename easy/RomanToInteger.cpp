/**
 * ����һ���������֣�ת��Ϊ����������
 */
#include <iostream>
#include <string>
using  namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
        if(s.find("IV")!=-1){sum-=2;}
        if(s.find("IX")!=-1){sum-=2;}
        if(s.find("XL")!=-1){sum-=20;}
        if(s.find("XC")!=-1){sum-=20;}
        if(s.find("CD")!=-1){sum-=200;}
        if(s.find("CM")!=-1){sum-=200;}

        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='M') sum+=1000;
            if(s[i]=='D') sum+=500;
            if(s[i]=='C') sum+=100;
            if(s[i]=='L') sum+=50;
            if(s[i]=='X') sum+=10;
            if(s[i]=='V') sum+=5;
            if(s[i]=='I') sum+=1;
        }
        return sum;
    }
};

int main()
{
    string s = "MCMXCIV";
    Solution m;
    int num = m.romanToInt(s);
    cout << num << endl;
    return 0;
}

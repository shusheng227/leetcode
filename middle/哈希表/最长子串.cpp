#include <stdio.h> 
#include <string.h>

int lengthOfLongestSubstring(char * s){
    int dict[256]={-1}; //记录对应字符最后一次出现的位置
    int max_length=0;
    int start=-1;       //记录当前子串的开始位置
    int len=strlen(s);    
    for(int i=0;i<256;i++) dict[i]=-1;
    for(int i=0;i<len;i++) {
        if(dict[s[i]]>start){
            // 字符重复，开始位置延后
            start=dict[s[i]];
        }
        dict[s[i]] = i;        
        max_length=((max_length>i-start)?max_length:i-start);
        //printf("%c %d %d\n",s[i],max_length,start);
    }
    return max_length;
}

int main(){
	char s[] = "abcabcbb";
	printf("%d\n",lengthOfLongestSubstring(s));
} 



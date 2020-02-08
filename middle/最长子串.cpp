#include <stdio.h> 
#include <string.h>

int lengthOfLongestSubstring(char * s){
	int i=0;
    int dict[256]={-1};
    int max_length=0;
    int start=-1;
    int len=strlen(s);    
    for(i=0;i<256;i++) dict[i]=-1;
    for(i=0;i<len;i++) {
        if(dict[s[i]]>start){
            start=dict[s[i]];
        }
        dict[s[i]] = i;
        max_length=((max_length>i-start)?max_length:i-start);
        printf("%c %d %d\n",s[i],max_length,start);
    }
    return max_length;
}

int main(){
	char s[] = "abcabcbb";
	printf("%d\n",lengthOfLongestSubstring(s));
} 



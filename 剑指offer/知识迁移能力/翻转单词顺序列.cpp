/**
 * 牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
 * 同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
 * 例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
 * Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        int len = str.length();
        int old_position = 0;
        int new_position = str.find(' ', 0);
        if(new_position == str.npos) {
            return str;
        }

        while(new_position != str.npos) {
            reverse(str, old_position, new_position-1);
            old_position = new_position + 1;
            new_position = str.find(' ', old_position);
        }
        reverse(str, old_position, len-1);
        reverse(str, 0, len-1);
        return str;
    }
private:
    //将str的第left~right位翻转
    void reverse(string &str, int left, int right) {
        char temp;

        while(left < right) {
            temp = str[left];
            str[left] = str[right];
            str[right] = temp;
            ++left;
            --right;
        }
    }
};
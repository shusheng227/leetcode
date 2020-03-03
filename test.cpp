#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    /*cout << INT_MAX+1 << endl;
    cout << INT_MIN << endl;
    int temp = INT_MAX;
    while(temp){
        cout << temp%2;
        temp /=2;
    }*/

    vector<int> v = {1,2,3,4,5};
    /* 查找元素位置
    vector <int>::iterator iElement = find(v.begin(), v.end(), 3);
    if( iElement != v.end() )	 {	      
        int nPosition = distance(v.begin(),iElement);		  
        cout << "Value  "<< *iElement;		  
        cout <<"  find in the vector at position: " <<nPosition + 1 <<endl;	 
    }*/
    /* 截取字符串
    vector<int> v2(v.begin(), v.begin()+3);
    for(auto i:v2) {
        cout << i << " ";    
    }*/

    char s1[] = "ght";
    char s2[] = "hjksd";
    int i = 20;
    int j = 30;
    char *s = 0;
    char *s3 = strcat(s1,s2);
    cout << s3 << endl;
}
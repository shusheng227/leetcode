#include <iostream>
using namespace std;

int main() {
    cout << INT_MAX+1 << endl;
    cout << INT_MIN << endl;
    int temp = INT_MAX;
    while(temp){
        cout << temp%2;
        temp /=2;
    }
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int s[] = {1,2,3};
	vector<int> v(s,s+3);
	v.erase(v.begin());
	cout << v.size() << endl;
	cout << v[0];
}

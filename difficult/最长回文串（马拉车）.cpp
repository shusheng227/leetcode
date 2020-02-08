#include <vector>
#include <iostream>
#include <string>

using namespace std;

string Manacher(string s) {
    // Insert '#'
    string t = "$#";
    for (int i = 0; i < s.size(); ++i) {
        t += s[i];
        t += "#";
    }
    cout << t <<endl;
    // Process t
    vector<int> p(t.size(), 0);
    int mx = 0, id = 0, resLen = 0, resCenter = 0;
    for (int i = 1; i < t.size(); ++i) {
    	//cout << i  <<":\tt:" << t << "\tp[i]:" << p[i] << "\tid:"<< id << "\tmx:" << mx << "\trescenter:" << resCenter << "\treslen:" << resLen <<endl;
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while (t[i + p[i]] == t[i - p[i]]) ++p[i];
        if (mx < i + p[i]) {
            mx = i + p[i];
            id = i;
        }
        if (resLen < p[i]) {
            resLen = p[i];
            resCenter = i;
        }
		//cout << i  <<":\tt:" << t << "\tp[i]:" << p[i] << "\tid:"<< id << "\tmx:" << mx << "\trescenter:" << resCenter << "\treslen:" << resLen <<endl;
    }
    return s.substr((resCenter - resLen) / 2, resLen - 1);
}

int main() {
	string s;
	string result;
	do {
		cin >> s;
		result = Manacher(s);
		cout << result << "\t" << result.length() << endl;
	}while(s!="***");
}

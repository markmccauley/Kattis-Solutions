#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int hashfunc(string a) {
	int x = 0;
	for (int i = 0; i < a.size(); i++) {
		x ^= a[i];
	}
	return x;
}

int main() {
	int t;
	while (cin >> t && t != 0) {
		string line;
		getline(cin, line);
		map<int, vector<string>> vecstring;
		map<int, set<string>> setstring;
		for (int i = 0; i < t; i++) {
			getline(cin, line);
			int hashed = hashfunc(line);
			vecstring[hashed].push_back(line);
			setstring[hashed].insert(line);
		}
		int col = 0, unrep = 0;
		for (auto it = vecstring.begin(); it != vecstring.end(); it++) {
			int key = (*it).first;
			unrep += setstring[key].size();
			int p = 0;
			vector<string> a = (*it).second;
			for (int i = 0; i < a.size(); i++) {
				for (int j = i+1; j < a.size(); j++) {
					if (a[i] != a[j]) {
						p++;
					}
				}
			}
			col += p;
		}
		cout << unrep << " " << col << endl;
	}
} 

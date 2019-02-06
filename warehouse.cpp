#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t > 0) {
		int n;
		cin >> n;
		map<string, int> toys;
		for (int i = 0; i < n; i++) {
			string toy;
			int k;
			cin >> toy >> k;
			
			toys[toy] += k;
		}

		vector<pair<int, string>> pairs;
		for (auto i : toys) {
			pairs.push_back(make_pair(-i.second, i.first));
		}
		cout << pairs.size() << endl;

		sort(pairs.begin(), pairs.end());	
		for (auto i : pairs) {
			cout << i.second << " " <<  -i.first << endl;
		} 
		t--;
	}
}
			

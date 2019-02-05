#include <iostream>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, vector<string>> groups;

vector<string> process(string word) {
	vector<string> ans;
	if (word == "union") {
		string name1, name2;
		cin >> name1;
		vector<string> g1 = process(name1);
		cin >> name2;
		vector<string> g2 = process(name2);
		set_union(g1.begin(), g1.end(), g2.begin(), g2.end(), back_inserter(ans));
		ans.erase(unique(ans.begin(), ans.end()), ans.end());
		return ans;
	}
	if (word == "intersection") {
		string name1, name2;
		cin >> name1;
		vector<string> g1 = process(name1);
		cin >> name2;
		vector<string> g2 = process(name2);
		set_intersection(g1.begin(), g1.end(), g2.begin(), g2.end(), back_inserter(ans));
		ans.erase(unique(begin(ans), end(ans)), end(ans));
		return ans;
	}
	if (word == "difference") {
		string name1, name2;
		cin >> name1;
		vector<string> g1 = process(name1);
		cin >> name2;
		vector<string> g2 = process(name2);
		set_difference(g1.begin(), g1.end(), g2.begin(), g2.end(), back_inserter(ans));
		ans.erase(unique(ans.begin(), ans.end()), ans.end());
		return ans;
	}
	else {
		return groups[word];
	}			
}

int main() {
	string start;
	while (cin >> start) {
		
		if (start == "group") {
			string name;
			vector<string> names;
			int num;
			cin >> name >> num;
			for (int i = 0; i < num; i++) {
				string n;
				cin >> n;
				names.push_back(n);
			}
			sort(names.begin(), names.end());
			groups[name] = names;
		}
		else {
			vector<string> ans = process(start);	
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i] << " ";
			}
			cout << endl;
		}
	}
}				

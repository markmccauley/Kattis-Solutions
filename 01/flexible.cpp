#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int w, p;
	vector<int> l;
	vector<int> ans;
	cin >> w >> p;
	ans.push_back(w);
	for (int i = 0; i < p; i++) {
		int a;
		cin >> a;
		ans.push_back(a);
		ans.push_back(w - a);
		l.push_back(a);
	}
	for (int i = 0; i < l.size() - 1; i++) {
		for (int j = i+1; j < l.size(); j++) {
			ans.push_back(l[j] - l[i]);
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] != ans[i+1]) {
			cout << ans[i] << " ";
		}
	}
}

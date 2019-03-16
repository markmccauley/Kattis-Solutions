#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    bool space = false;
    while (cin >> n && n != 0) {
        vector<int> bags(n);
        for (int i = 0; i < n; i++) {
            cin >> bags[i];
        }

        sort(bags.begin(), bags.end());
        int pieces = 0, max = 1;
		for (int i = 0; i < n; i++) {
			if (bags[i] != bags[i+1]) {
				if (max > pieces) {
					pieces = max;
				}
				max = 1;
			}
			else {
				max++;
			}
		}

        vector<int> ans[pieces];
        for (int i = 0; i < n; i++) {
            ans[i % pieces].push_back(bags[i]);
        }

        if (space) {
            cout << endl;
        }
        space = true;
        cout << pieces << endl;
        for (int i = 0; i < pieces; i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                if (j > 0) {
                    cout << " " << ans[i][j];
                }
                else {
                    cout << ans[i][j];
                }
            }
            cout << endl;
        }
    }
}

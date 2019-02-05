#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t > 0) {
		int n;
		cin >> n;
		int candidate;
		int limit = 0;
		int tie = 0;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int votes;
			cin >> votes;
			sum += votes;
			if (votes > limit) {
				limit = votes;
				candidate = i + 1;
				tie = 0;
			}
			else if (votes == limit) {
				tie = 1;
			}
		}
		if (tie) {
			cout << "no winner" << endl;
		}
		else {
			if (limit > sum/2) {
				cout << "majority winner " << candidate << endl;
			}
			else {
				cout << "minority winner " << candidate << endl;
			}
		}
		t--;
	}
}

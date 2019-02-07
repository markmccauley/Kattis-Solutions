#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t > 0) {
		string p;
		int n;
		cin >> p >> n;
		bool reverse = false;
		bool out = true;

		deque<int> numbers;
		cin.ignore();
		for (int i = 0; i < n; i++) {
			int a;
			cin.ignore();
			cin >> a;
			numbers.push_back(a);
		}
		cin.ignore();
		if (n == 0) {
			cin.ignore();
		}

		for (int i = 0; i < p.length(); i++) {
			if (p[i] == 'R') {
				reverse = !reverse;
			}
			if (p[i] == 'D') {
				if (numbers.size() == 0) {
					out = false;
					cout << "error" << endl;
					break;
				}
				else {
					if (reverse) {
						numbers.pop_back();
					}
					else {
						numbers.pop_front();
					}
				}
			}
		}
							
		if (out) {
			cout << "[";
			while (!numbers.empty()) {
				if (reverse) {
					cout << numbers.back();
					numbers.pop_back();
				}
				else {
					cout << numbers.front();
					numbers.pop_front();
				}
				if (numbers.size() != 0) {
					cout << ",";
				}
			}	 
			cout << "]" << endl;
		}
		t--;
	}
}		

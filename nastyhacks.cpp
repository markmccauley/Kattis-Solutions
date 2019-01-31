#include <iostream>

using namespace std;

int main() {
	int n, r, e, c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> r;
		cin >> e;
		cin >> c;
		if (e > (r + c)) {
			cout << "advertise \n";
		}
		else if (e == (r + c)) {
			cout << "does not matter \n";
		}
		else {
			cout << "do not advertise \n";
		}
	}
}

#include <iostream>
#include <string.h>

using namespace std;

int main() {
	int n;
	string bits1, bits2;
	cin >> n;
	cin >> bits1;
	cin >> bits2;
	n = n % 2; // if even, string is same as input
	if (n == 0) {
		for (int i = 0; i < bits1.length(); i++) {
			if (bits1[i] != bits2[i]) {
				cout << "Deletion failed\n";
				exit(0);
			}
		}
		cout << "Deletion succeeded\n";
	}
	else {
		for (int i = 0; i < bits1.length(); i++) {
			if (bits1[i] == bits2[i]) {
				cout << "Deletion failed\n";
				exit(0);
			}
		}
		cout << "Deletion succeeded\n";
	}
}


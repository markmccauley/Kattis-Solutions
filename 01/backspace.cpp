#include <iostream>
#include <string.h>

using namespace std;

int main() {
	string input;
	cin >> input;
	char output[1000000];
	int count = 0;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '<') {
			if (count > 0) {
				count--;
			}
		}
		else {
			output[count] = input[i];
			count++; // count valid letters
		}
	}
	output[count] = '\0';
	cout << output << endl;
}

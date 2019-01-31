#include <iostream>

using namespace std;

int main () {
	string name;
	string abv;
	cin >> name;
	for (int i = 0; i < name.length(); i++) {
		if (isupper(name[i])) {
			abv += name[i];
		}
	}
	cout << abv << endl;
}

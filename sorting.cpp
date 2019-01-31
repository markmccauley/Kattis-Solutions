#include <iostream>
#include <vector>

using namespace std;

void swap (string *a, string *b) {
	string temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int n;
	while(cin >> n && n != 0) {
		vector<string> names;
		for (int i = 0; i < n; i++) {
			string name;
			cin >> name;
			names.push_back(name);
		}
	
		for (int i = 0; i < names.size()-1; i++) {
			for (int j = 0; j < names.size()-i-1; j++) { 
				if (names[j][0] > names[j+1][0]) {
					swap(&names[j], &names[j+1]);
				}
				if (names[j][0] == names[j+1][0]) {
					if (names[j][1] > names[j+1][1]) {
						swap(&names[j], &names[j+1]);
					}
				}
			}
		}
		for (int i = 0; i < names.size(); i++) {
			cout << names[i] << endl;
		}
		cout << endl;
	}
}	

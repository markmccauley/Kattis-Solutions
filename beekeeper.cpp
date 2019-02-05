#include <iostream>

using namespace std;

int main() {
	int n;
	while (cin >> n && n != 0) {
		string favorite = " ";
		int max = -1;
		for (int i = 0; i < n; i++) {
			string word;
			cin >> word;
			int count = 0;
			for (int i = 0; i < word.length(); i++) {
				if (word[i] == word[i+1]) {
					if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' || word[i] == 'y') {
						count++;
					}
				}
			}
			if (count > max) {
				max = count;
				favorite = word;
			}
		}
		cout << favorite << endl;
	}
}	

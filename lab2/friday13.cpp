#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int count = 0;
		int d, m;
		cin >> d >> m;
		vector<int> months;
		for (int i = 0; i < m; i++) {
			int di;
			cin >> di;
			
			for (int i = 1; i <= di; i++) {
				months.push_back(i);
			} 
		}
		for (int i = 0; i < d; i++) {
			if (months[i] == 13 && i % 7 == 5) {
				count++;
			}
		}
		cout << count << endl;
	}
}

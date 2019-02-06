#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	map<string, vector<int>> vacations;
	for (int i = 0; i < n; i++) {
		string location;
		int year;
		cin >> location >> year;
		vacations[location].push_back(year);
	}
	
	for (auto it = vacations.begin(); it != vacations.end(); it++) {
		sort((*it).second.begin(), (*it).second.end());
	}
	
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string location;
		int num;
		cin >> location >> num;
		cout << vacations[location][num-1] << endl;
	}
}

	

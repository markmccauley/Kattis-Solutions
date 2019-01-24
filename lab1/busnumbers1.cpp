#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, b;
	vector<int> busses;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> b;
		busses.push_back(b);
	}
	sort(busses.begin(), busses.end());
	int i = 0;
	while (i < n) {
		if ((busses[i] + 2) == (busses[i+2])) {
			cout << busses[i] << "-";
			i += 2;
			while (busses[i] == (busses[i+1] - 1)) {
				i++;
			}
			cout << busses[i] << " ";
			i++;
		}   	
		else {
			cout << busses[i] << " ";
			i++;
		}
	}
}  

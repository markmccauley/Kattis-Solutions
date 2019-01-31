#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int m;
	cin >> m;
	vector<int> num;
	vector<int> sum;
	for (int i = 1; i <= 73; i++) {
		int k = 0;
		k = i * i * i;
		num.push_back(k);
	}
	for (int i = 0; i < num.size(); i++) {
		for (int j = i+1; j < num.size(); j++) {
			sum.push_back(num[i] + num[j]);
		}
	}
	sort(sum.begin(), sum.end());
	while (m > 0) {
		int count = 0;
		for (int i = 0; i < sum.size(); i++) {
			if (m == sum[i] && m <= 400000) {
				count++;
				if (count > 1) {
					cout << m << endl;
					exit(0);
				}
			}
		}
		m--;
	}
	cout << "none" << endl;
}	

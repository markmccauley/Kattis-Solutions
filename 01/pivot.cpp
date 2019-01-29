#include <iostream>
#include <set>

using namespace std;

int main() {
	int n;
	cin >> n;
	set<int> p;
	int max = -1;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		p.erase(p.upper_bound(m), p.end());
		if (m > max) {
			max = m;
			p.insert(m);
		}
	}
	cout << p.size() << endl;
}

#include <iostream>
#include <vector>

#define LSOne(S) (S & (-S))

using namespace std;

class FenwickTree {
private:
	vector<int> ft;

public:
	FenwickTree(int n) { ft.assign(n + 1, 0); }
	
	int rsq(int b) {
		int sum = 0;
		for (; b; b -= LSOne(b)) {
			sum += ft[b];
		}
		return sum;
	}
	
	int rsq(int a, int b) {
		return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
	}

	void update(int k, int v) {
		for (; k < (int)ft.size(); k += LSOne(k)) {
			ft[k] += v;
		}
	}
};

int main() {
	int t;
	cin >> t;
	int position[100000];
	for (int i = 0; i < t; i++) {
		FenwickTree fen(200000);
		int m, r;
		cin >> m >> r;
		for(int i = 1; i <= m; i++) {
			fen.update(i, 1);
			position[i] = m - i + 1;
		}
		for (int i = m + 1; i <= m + r; i++) {
			int id, location;
			cin >> id;
			location = position[id];
			cout << m - fen.rsq(location) << " ";
			fen.update(location, -1);
			fen.update(i, 1);
			position[id] = i;
		}
		cout << endl;
	}
		
}

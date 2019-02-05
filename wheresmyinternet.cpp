#include <iostream>
#include <vector>

using namespace std;
	
class UnionFind {
private:
	vector<int> p, rank;

public:
	
	UnionFind(int n) {
		rank.assign(n, 0);
		p.assign(n, 0);
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}
	}
		
	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	
	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	
	void unionSet(int i, int j) {
		int x = findSet(i);
		int y = findSet(j);
		if (rank[x] > rank[y]) {
			p[y] = x;
		}
		else {
			p[x] = y;
			if (rank[x] == rank[y]) {
				rank[y]++;
			}
		}
	}
};
		
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	UnionFind finder(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		finder.unionSet(a-1, b-1);
	}
	bool connect = true;
	for (int i = 1; i < n; i++) {
		if (!finder.isSameSet(0, i)) {
			cout << i+1 << endl;
			connect = false;
		}
	}
	if (connect) {
		cout << "Connected" << endl;
	}
}		

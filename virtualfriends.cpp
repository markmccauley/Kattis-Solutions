#include <iostream>
#include <vector>
#include <map>

using namespace std;
	
class UnionFind {
private:
	vector<int> p;

public:
	vector<int> sums;
	
	UnionFind(int n) {
		sums.assign(n, 0);
		p.assign(n, 0);
		for (int i = 0; i < n; i++) {
			p[i] = i;
			sums[i] = 1;
		}
	}
		
	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	
	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	
	void unionSet(int i, int j) {
		int x = findSet(i), y = findSet(j);
		if (x == y) {
			return;
		}
		if (sums[x] > sums[y]) {
			p[y] = x;
			sums[x] += sums[y];
		}
		else {
			p[x] = y;
			sums[y] += sums[x];
		}
	}
};
		
int main() {
	int t;
	cin >> t;
	while (t > 0) {
		UnionFind finder(50000);
		int n;
		cin >> n;
		map<string, int> friends;
		for (int i = 0; i < n; i++) {
			string f1, f2;
			cin >> f1 >> f2;
			if (!friends.count(f1)) {
				friends[f1] = friends.size();
			}
			if (!friends.count(f2)) {
				friends[f2] = friends.size();
			}	
			finder.unionSet(friends[f1], friends[f2]);
			cout << finder.sums[finder.findSet(friends[f1])] << endl;
		}
		t--;
	}
}
				

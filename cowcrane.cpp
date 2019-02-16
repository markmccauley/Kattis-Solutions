#include <iostream>

using namespace std;

int main() {
	long long m, l, M, L, tm, tl, cow1, cow2;
	bool possible = false;
	cin >> m >> l >> M >> L >> tm >> tl;
	
	cow1 = llabs(m) + llabs(m-l) + llabs(L-l);
	cow2 = llabs(l-L) + llabs(M-l);
	if (cow1 <= tl && (cow1 + cow2) <= tm) {
		possible = true;
	}

	cow1 = llabs(l) + llabs(L-l);
	cow2 = llabs(m-L) + llabs(M-m);
	if (cow1 <= tl && (cow1 + cow2) <= tm) {
		possible = true;
	}

	cow1 = llabs(l) + llabs(m-l) + llabs(M-m);
	cow2 = llabs(m-M) + llabs(L-m);
	if (cow1 <= tm && (cow1 + cow2) <= tl) {
		possible = true;
	}
	
	cow1 = llabs(m) + llabs(M-m);
	cow2 = llabs(l-M) + llabs(L-l);
	if (cow1 <= tm && (cow1 + cow2) <= tl) {
		possible = true;	
	}
	if (possible) {
		cout << "possible" << endl;
	}
	else {
		cout << "impossible" << endl;
	}
}

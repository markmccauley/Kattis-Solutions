#include <iostream>

using namespace std;

int main() {
	int n, b, h, w, p, a;
	cin >> n;
	cin >> b;
	cin >> h;
	cin >> w;
	int price = b + 1;
	for (int i = 0; i < h; i++) {
		cin >> p;
		for (int j = 0; j < w; j++) {
			cin >> a;
			if (a >= n) {
				price = min(price, n*p);
			}
		}
	}
	if (price <= b) {
		cout << price << endl;
	} else {
		cout << "stay home \n";
	}
}

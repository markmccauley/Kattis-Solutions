#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int cx, cy, n;
	int count;
	vector<int> distances;
	cin >> cx >> cy >> n;
	for (int i = 0; i < n; i++) {
		float x, y, r;
		cin >> x >> y >> r;
		distances.push_back(sqrt(pow((cx-x), 2) + pow((cy-y), 2)) - r);
	}
	sort(distances.begin(), distances.end()); 
	if (distances[2] >= 0) {
		cout << distances[2] << endl;
	}
	else {
		cout << 0 << endl;
	}
}		

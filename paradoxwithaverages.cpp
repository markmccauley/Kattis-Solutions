#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		int cs, e;
		cin >> cs >> e;
		vector<double> cs_students(cs);
		vector<double> e_students(e);

		double cs_sum = 0;		
		for (int i = 0; i < cs; i++) {
			cin >> cs_students[i];
			cs_sum += cs_students[i];
		}

		double e_sum = 0;
		for (int i = 0; i < e; i++) {
			cin >> e_students[i];
			e_sum += e_students[i];
		}

		double cs_avg = cs_sum / cs_students.size();
		double e_avg = e_sum / e_students.size();
	
		int ans = 0;
		for (int i = 0; i < cs_students.size(); i++) {
			if (cs_students[i] > e_avg && cs_students[i] < cs_avg) {
				ans++;
			}
		}
		cout << ans << endl;
	}
}

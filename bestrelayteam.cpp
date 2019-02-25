#include <bits/stdc++.h>

using namespace std;

struct Runner {
	string name;
	double time1, time2;
};

pair<vector<string>, double> try_runners(vector<Runner> r, int a) {
	vector<string> best;
	best.push_back(r[a].name);
	double ans = r[a].time1;
	r.erase(r.begin()+a);
	/*for (int i = 0; i < r.size(); i++) {
		int min = i;
		for (int j = i + 1; j < r.size(); j++) {
			if (r[j].time2 < r[min].time2) {
				min = j;
			}
		}
		double temp = r[min].time2;
		r[min].time2 = r[i].time2;
		r[i].time2 = temp;
	}*/

	sort(r.begin(), r.end(), [](Runner l, Runner r) { return l.time2 < r.time2; });

	ans += r[0].time2;
	ans += r[1].time2;
	ans += r[2].time2;

	best.push_back(r[0].name);
	best.push_back(r[1].name);
	best.push_back(r[2].name);

	pair<vector<string>, double> tried = make_pair(best, ans);
	return tried;
}

int main() {
	int n;
	double time = 10000;
	vector<string> team;
	cin >> n;
	vector<Runner> runners(n);

	for (int i = 0; i < n; i++) {
		cin >> runners[i].name >> runners[i].time1 >> runners[i].time2;
	}
	
	for (int i = 0; i < n; i++) {
		pair<vector<string>, double> p = try_runners(runners, i);
		if (p.second < time) {
			time = p.second;
			team = p.first;
		}
	}

	cout << time << endl;
	for (int i = 0; i < team.size(); i++) {
		cout << team[i] << endl;
	}		
}

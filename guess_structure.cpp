#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
	int n;
	while(cin >> n) {
		priority_queue<int> prior;
		queue<int> q;
		stack<int> s;
		bool is_pq = true, is_q = true, is_s = true;
		for (int i = 0; i < n; i++) {
			int type, x;
			cin >> type >> x;
			if (type == 1) {
				if (is_pq) {
					prior.push(x);
				}
				if (is_q) {
					q.push(x);
				}
				if (is_s) {
					s.push(x);
				}
			}
			else {
				if (!prior.empty() && prior.top() == x) {
					prior.pop();
				}
				else {
					is_pq = false;
				}
				if (!q.empty() && q.front() == x) {
					q.pop();
				}
				else {
					is_q = false;
				}
				if (!s.empty() && s.top() == x) {
					s.pop();
				}
				else {
					is_s = false;
				}
			}
		}
		if (!is_pq && !is_q && !is_s) {
			cout << "impossible" << endl;
		}
		else if ((is_pq + is_q + is_s) > 1) {
			cout << "not sure" << endl;
		}
		else {
			if (is_pq) {
				cout << "priority queue" << endl;
			}
			if (is_q) {
				cout << "queue" << endl;
			}
			if (is_s) {
				cout << "stack" << endl;
			}
		}
	}
}
	
		

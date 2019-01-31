#include <iostream>
#include <vector>

using namespace std;

int main() {
	int time;
	int sum = 0;
	int num = 0;
	int wrong_count = 0;
	string problem, status;
	vector<string> solved = {" "};
	vector<string> wrong = {" "};
	bool count = true;
	
	while (1) {
		cin >> time;
		if (time == -1) break;
		cin >> problem;
		cin >> status;

		if (status == "right") {
			for (int i = 0; i < solved.size(); i++) {
				if (problem == solved[i]) {
					count = false;
					break;
				}
			}
			if (count == true) {
				num++;
				sum += time;
				for (int j = 0; j < wrong.size(); j++) {
					if (problem == wrong[j]) {
						wrong_count++;
					}
				}
				solved.push_back(problem);
			}
		} else {
			wrong.push_back(problem);
		}
	}
	cout << num << " " << sum + wrong_count*20 << endl;
}

#include <iostream>

using namespace std;

int main() {
	int armH, armM, armS;
	int expH, expM, expS;
	int timeH, timeM, timeS;
	char d;
	cin >> armH >> d >> armM >> d >> armS >> expH >> d >> expM >> d >> expS;
	
	timeH = expH - armH;
	timeM = expM - armM;
	timeS = expS - armS;
	
	if (timeS < 0) {
		timeS += 60;
		timeM -= 1;
	}
	if (timeM < 0) {
		timeM += 60;
		timeH -= 1;
	}
	if (timeH < 0) {
		timeH += 24;
	}
	
	if (timeH + timeM + timeS == 0) {
		timeH += 24;
	}
	
	if (timeH < 10) {
		cout << "0" << timeH << ":";
	}
	else {
		cout << timeH << ":";
	}
	if (timeM < 10) {
		cout << "0" << timeM << ":";
	}
	else {
		cout << timeM << ":";
	}
	if (timeS < 10) {
		cout << "0" << timeS << endl;
	}
	else {
		cout << timeS << endl;
	}
}

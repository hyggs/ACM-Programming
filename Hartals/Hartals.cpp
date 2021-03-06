#include "stdafx.h"
#include <iostream>
#include <list>


using namespace std;

struct day {
	int value;
	bool hartal;
};

typedef list<day> days;
typedef list<day>::iterator it;

int main() {

	int T, N, P, pi, hartals;
	day d;
	days days;
	it it;
	for (int i = 0; i < 3650; i++) {
		d.value = (i + 1) % 7;
		d.hartal = false;
		days.push_back(d);
	}
	int j;
	while (std::cin >> T) {
		while (std::cin >> N >> P) {
			hartals = 0;
			for (int i = 0; i < P; i++) {
				std::cin >> pi;
				for (it = days.begin(), j = 0; it != days.end() && j < N; it++, j++) {
					if ((j + 1) % pi == 0 && (*it).hartal == false && (*it).value != 6 && (*it).value != 0) {
						(*it).hartal = true;
						hartals++;
					}
				}
			}
			std::cout << "result: " << endl;
			std::cout << hartals << endl;
			for (it = days.begin(); it != days.end(); it++) {
				(*it).hartal = false;
			}
		}
	}
	return 0;

}
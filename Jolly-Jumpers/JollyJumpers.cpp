#include "stdafx.h"
#include "iostream"
#include <list>
#include "cmath"

using namespace std;
typedef list<int> List;
typedef list<int>::iterator Iterator;

int main() {

	List L, l;
	Iterator it, it0;
	int i, n, c, pre, dif;
	bool found, no;
	while (cin >> n) {
		i = 1;
		while (i < n) {
			L.push_back(i);
			i++;
		}
		i = 0;
		while (i < n) {
			std::cin >> c;
			l.push_back(c);
			++i;
		}
		it = l.begin();
		no = false;
		while (it != l.end() && !no) {
			pre = *it;
			it++;
			if (it != l.end()) {
				dif = abs(*it - pre);
			}
			else {
				break;
			}
			found = false;
			it0 = L.begin();
			while (it0 != L.end() && !found) {
				if (dif == *it0) {
					found = true;
					it0 = L.erase(it0);
				} else {
					it0++;
				}
			}
			if (!found) no = true;
		}
		if (n != 1 && (no || !L.empty())) {
			std::cout << "Not jolly" << endl;
		}
		else {
			std::cout << "Jolly" << endl;
		}
		l.clear();
		L.clear();
	}
	system("pause");
	return 0;

}

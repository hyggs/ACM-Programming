#include "stdafx.h"
#include <iostream>
#include <map>
#include <string.h>
#include <sstream>
#include <list>
#include <set>

std::list<std::string> D, A, Alphabet;
std::map<std::string, std::string> T;
std::map<char, char> L;

bool isFit(std::string a, std::string d) {

	std::map<char, char>::iterator p;
	std::map<std::string, std::string>::iterator t;
	if (a.length() == 0) {
		return true;
	}
	else if (a.length() != d.length()) {
		return false;
	}
	else {
		if (L.find(a.at(0)) != L.end()) {
			if (L.at(a.at(0)) != d.at(0)) {
				return false;
			}
		}
		std::map<char, char> S;
		for (p = L.begin(); p != L.end(); p++) {
			S.insert(std::make_pair(p->second, p->first));
		}
		if (S.find(d.at(0)) != S.end()) {
			if (S.at(d.at(0)) != a.at(0)) {
				return false;
			}
		}
		L.insert(std::make_pair(a.at(0), d.at(0)));	
		if (isFit(a.substr(1, a.length() - 1), d.substr(1, d.length() - 1))) {
			return true;
		}
		else {
			L.erase(a.at(0));
			return false;
		}
	}

}

bool canTranslate(std::list<std::string> A, std::list<std::string> D) {

	std::list<std::string>::iterator it, iit;
	if (A.size() == 0) {
		return true;
	}
	else if (A.size() == 1) {
		for (it = D.begin(); it != D.end(); it++) {
			if (isFit(A.front(), *it)) {
				T.insert(std::make_pair(A.front(), *it));
				return true;
			}
		}
		return false;
	}
	else {
		for (it = A.begin(); it != A.end(); it++) {
			for (iit = D.begin(); iit != D.end(); iit++) {
				if (isFit(*it, *iit)) {
					T.insert(std::make_pair(*it, *iit));
					std::list<std::string> AA = A;
					std::list<std::string> DD = D;
					std::string a = *it;
					std::string d = *iit;
					AA.remove(a);
					DD.remove(d);
					if (canTranslate(AA, DD)) {
						A.remove(a);
						D.remove(d);
						return true;
					}
					else {
						T.erase(a);
						for (int i = 0; i < a.length(); i++) {
							L.erase(a.at(i));
						}
						continue;
					}
				}
			}
			return false;
		}
	}

}

int main() {

	int n;
	std::string word;
	std::list<std::string>::iterator it;	
	std::set<std::string> E;
	std::set<std::string>::iterator e;
	std::map<std::string, std::string>::iterator t;
	scanf_s("%d\n", &n);
	for (int i = 0; i < n; i++) {
		std::cin >> word;
		D.push_back(word);
	}
	while (std::cin >> word) {
		Alphabet.push_back(word);
		E.insert(word);
		char c = getchar();
		if (c == '\n') {
			for (e = E.begin(); e != E.end(); e++) {
				A.push_back(*e);
			}
			std::string strings[100];
			int i = 0;
			for (it = A.begin(); it != A.end(); it++, i++) {
				strings[i] = *it;
			}
			for (int i = 1; i < A.size(); i++) {
				for (int j = i; j > 0; j--) {
					if (strings[j].length() > strings[j - 1].length()) {
						std::string te = strings[j - 1];
						strings[j - 1] = strings[j];
						strings[j] = te;
					}
				}
			}
			int s = A.size();
			A.clear();
			for (int i = 0; i < s; i++) {
				A.push_back(strings[i]);
			}
			if (canTranslate(A, D)) {
				for (it = Alphabet.begin(); it != Alphabet.end();) {
					for (t = T.begin(); t != T.end(); t++) {
						if ((*it) == t->first) {
							std::cout << t->second;
							break;
						}
					}
					if (++it != Alphabet.end()) std::cout << " ";
				}
				std::cout << std::endl;
			}
			else {
				for (it = Alphabet.begin(); it != Alphabet.end();) {
					for (int i = 0; i < it->length(); i++) {
						std::cout << "*";
					}
					if (++it != Alphabet.end()) std::cout << " ";
				}
				std::cout << std::endl;
			}
			Alphabet.clear();
			L.clear();
			A.clear();
			E.clear();
			T.clear();
		}
	}	
	return 0;

}
#include "stdafx.h"
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;
struct poker {
	char value;
	char suit;
};
typedef list<poker> List;
typedef list<poker>::iterator Iterator;

list<poker> sort(list<poker> l) {

	Iterator it = l.begin();
	it++;
	Iterator it0, it1;
	poker temp;
	for (int i = 1; i < l.size(); i++, it++) {
		it0 = it;
		for (int j = i; j >= 0; j--, it0--) {
			if (it0 != l.begin()) it1 = --it0;
			it0++;
			if (it1 != l.end() && it0 != l.end() && (*it1).value > (*it0).value) {
				temp = *it1;
				*it1 = *it0;
				*it0 = temp;
			}
		}
	}
	return l;

}

bool is_straight_flush(list<poker> l) {

	Iterator it = l.begin();
	char suit = (*it).suit;
	bool found = false;
	bool found0;
	while (it != l.end() && !found) {
		if ((*it).suit != suit) {
			found = true;
		}
		it++;
	}
	found0 = found;
	char value;
	Iterator it0;
	if (!found) {
		found = false;
		l = sort(l);
		it = l.begin();
		value = (*it).value;
		while (it != l.end() && !found) {
			if (value != (*it).value) {
				found = true;
			}
			value++;
			it++;
		}
	}
	return !found;

}

bool is_four_of_a_kind(list<poker> l) {

	Iterator it0 = l.begin();
	int first = (*it0).value;
	int second = (*(++it0)).value;
	int third = (*(++it0)).value;
	int fourth = (*(++it0)).value;
	int fifth = (*(++it0)).value;
	if ((first != second && second == third && third == fourth && fourth == fifth) || (first == second && second == third && third == fourth && fourth != fifth)) {
		return true;
	}
	else {
		return false;
	}

}

bool is_full_house(list<poker> l) {

	Iterator it0 = l.begin();
	int first = (*it0).value;
	int second = (*(++it0)).value;
	int third = (*(++it0)).value;
	int fourth = (*(++it0)).value;
	int fifth = (*(++it0)).value;
	if ((first == second && second != third && third == fourth && fourth == fifth) ||
		(first == second && second == third && third != fourth && fourth == fifth)) {
		return true;
	}
	else {
		return false;
	}

}

bool is_flush(list<poker> l) {

	Iterator it = l.begin();
	char suit = (*it).suit;
	bool found = false;
	while (it != l.end() && !found) {
		if ((*it).suit != suit) {
			found = true;
		}
		it++;
	}
	return !found;

}

bool is_straight(list<poker> l) {

	bool found = false;
	Iterator it = l.begin();
	int value = (*it).value;
	while (it != l.end() && !found) {
		if (value != (*it).value) {
			found = true;
		}
		value++;
		it++;
	}
	return !found;

}

bool is_three_of_a_kind(list<poker> l) {

	Iterator it0 = l.begin();
	int first = (*it0).value;
	int second = (*(++it0)).value;
	int third = (*(++it0)).value;
	int fourth = (*(++it0)).value;
	int fifth = (*(++it0)).value;
	if ((first == second && second == third && third != fourth && fourth != fifth) ||
		(first != second && second == third && third == fourth && fourth != fifth) ||
		(first != second && second != third && third == fourth && fourth == fifth)) {
		return true;
	}
	else {
		return false;
	}
}

bool is_two_pairs(list<poker> l) {

	Iterator it0 = l.begin();
	int first = (*it0).value;
	int second = (*(++it0)).value;
	int third = (*(++it0)).value;
	int fourth = (*(++it0)).value;
	int fifth = (*(++it0)).value;
	if (first == second && second != third) {
		if ((third == fourth && fourth != fifth) || (third != fourth && fourth == fifth)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (first != second && second == third) {
		if (third != fourth && fourth == fifth) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}

}

bool is_pair(list<poker> l) {

	Iterator it0 = l.begin();
	int first = (*it0).value;
	int second = (*(++it0)).value;
	int third = (*(++it0)).value;
	int fourth = (*(++it0)).value;
	int fifth = (*(++it0)).value;
	if ((first == second && second != third && third != fourth && fourth != fifth) ||
		(first != second && second == third && third != fourth && fourth != fifth) ||
		(first != second && second != third && third == fourth && fourth != fifth) ||
		(first != second && second != third && third != fourth && fourth == fifth)) {
		return true;
	}
	else {
		return false;
	}

}

bool is_high_card(list<poker> l) {

	if (!is_straight_flush(l) && !is_four_of_a_kind(l) && !is_full_house(l) && !is_flush(l) && !is_straight(l) && !is_three_of_a_kind(l) &&
		!is_two_pairs(l) && !is_pair(l)) {
		return true;
	}
	else {
		return false;
	}
}

int get_rank_pair_first(list<poker> l) { // Pair, and first ranks are equal.

	Iterator it = l.begin();
	int first = (*it).value;
	int second = (*(++it)).value;
	int third = (*(++it)).value;
	int fourth = (*(++it)).value;
	int fifth = (*(++it)).value;
	if (fifth == fourth) {
		return third;
	}
	else {
		return fifth;
	}

}

int get_rank_two_pairs_second(list<poker> l) { // Two Pairs, and first and second ranks are equal.

	Iterator it = l.begin();
	int first = (*it).value;
	int second = (*(++it)).value;
	int third = (*(++it)).value;
	int fourth = (*(++it)).value;
	int fifth = (*(++it)).value;
	if (first == second && third == fourth) {
		return fifth;
	}
	else if (first == second && fourth == fifth) {
		return third;
	}
	else {
		return first;
	}

}

int get_rank_two_pairs_frist(list<poker> l) { // Two Pairs, and first ranks are equal.

	Iterator it = l.begin();
	int first = (*it).value;
	int second = (*(++it)).value;
	int third = (*(++it)).value;
	int fourth = (*(++it)).value;
	int fifth = (*(++it)).value;
	if (first == second) {
		return first;
	}
	else {
		return second;
	}

}

int get_rank(list<poker> l, int hand) {

	Iterator it = l.end();
	if (hand == 9) { // Straight Flush
		return (*--it).value;
	}
	else if (hand == 8) { // Four of a Kind
		it--;
		it--;
		it--;
		return (*it).value;
	}
	else if (hand == 7) { // Full House
		it--;
		it--;
		it--;
		return (*it).value;
	}
	else if (hand == 6) { // Flush
		return (*--it).value;
	} 
	else if (hand == 5 && it != l.end()) { // Straight
		return (*it).value;
	}
	else if (hand == 4) { // Three of a Kind
		it--;
		it--;
		it--;
		return (*it).value;
	}
	else if (hand == 3) { // Two Pairs
		Iterator it = l.begin();
		int first = (*it).value;
		int second = (*(++it)).value;
		int third = (*(++it)).value;
		int fourth = (*(++it)).value;
		int fifth = (*(++it)).value;
		if (fifth == fourth) {
			return fifth;
		}
		else {
			return third;
		}
	}
	else if (hand == 2) { // Pair
		Iterator it = l.begin();
		int first = (*it).value;
		int second = (*(++it)).value;
		int third = (*(++it)).value;
		int fourth = (*(++it)).value;
		int fifth = (*(++it)).value;
		if (first == second) {
			return first;
		}
		else if (second == third) {
			return second;
		}
		else if (third == fourth) {
			return third;
		}
		else {
			return fourth;
		}
	}
	else { // High Card
		Iterator it = l.begin();
		int first = (*it).value;
		int second = (*(++it)).value;
		int third = (*(++it)).value;
		int fourth = (*(++it)).value;
		int fifth = (*(++it)).value;
		return fifth;
	}

}

int main() {

	List black, white;
	poker P;
	Iterator it;
	char value;
	char suit;
	int i;
	int rb, rw;
	while (cin >> value >> suit) {
		if (value == 'A') {
			value = 'Z';
		}
		else if (value == 'K') {
			value = 'Y';
		}
		else if (value == 'Q') {
			value = 'X';
		}
		else if (value == 'J') {
			value = 'W';
		}
		else if (value == 'T') {
			value = 'U';
		}
		P.value = value;
		P.suit = suit;
		black.push_back(P);
		i = 1;
		while (i < 10) {
			std::cin >> value;
			if (value == 'A') {
				value = 'Z';
			}
			else if (value == 'K') {
				value = 'Y';
			}
			else if (value == 'Q') {
				value = 'X';
			}
			else if (value == 'J') {
				value = 'W';
			}
			else if (value == 'T') {
				value = 'U';
			}
			P.value = value;
			std::cin >> P.suit;
			if (i < 5) {
				black.push_back(P);
			}
			else {
				white.push_back(P);
			}
			i++;
		}
		black = sort(black);
		white = sort(white);
		if (is_straight_flush(black)) {
			if (is_straight_flush(white)) {
				rb = get_rank(black, 9);
				rw = get_rank(white, 9);
				if (rb > rw) {
					std::cout << "Black wins." << endl;
				}
				else if (rb == rw) {
					std::cout << "Tie." << endl;
				}
				else {
					std::cout << "White wins." << endl;
				}
			}
			else {
				std::cout << "Black wins." << endl;
			}
		}
		else if (is_four_of_a_kind(black)) {
			if (is_straight_flush(white)) {
				std::cout << "White wins." << endl;
			}
			else if (is_four_of_a_kind(white)) {
				rb = get_rank(black, 8);
				rw = get_rank(white, 8);
				if (rb > rw) {
					std::cout << "Black wins." << endl;
				}
				else if (rb == rw) {
					std::cout << "Tie." << endl;
				}
				else {
					std::cout << "White wins." << endl;
				}
			}
			else {
				std::cout << "Black wins." << endl;
			}
		}
		else if (is_full_house(black)) {
			if (is_straight_flush(white) || is_four_of_a_kind(white)) {
				std::cout << "White wins." << endl;
			}
			else if (is_full_house(white)) {
				rb = get_rank(black, 7);
				rw = get_rank(white, 7);
				if (rb > rw) {
					std::cout << "Black wins." << endl;
				}
				else if (rb == rw) {
					std::cout << "Tie." << endl;
				}
				else {
					std::cout << "White wins." << endl;
				}
			}
			else {
				std::cout << "Black wins." << endl;
			}
		}
		else if (is_flush(black)) {
			if (is_straight_flush(white) || is_four_of_a_kind(white) || is_full_house(white)) {
				std::cout << "White wins." << endl;
			}
			else if (is_flush(white)) {
				rb = get_rank(black, 6);
				rw = get_rank(white, 6);
				if (rb > rw) {
					std::cout << "Black wins." << endl;
				}
				else if (rb == rw) {
					Iterator it1 = black.end();
					Iterator it2 = white.end();
					it1--;
					it2--;
					int i = 5;
					while (i > 0 && (*it1).value == (*it2).value) {
						it1--;
						it2--;
						i--;
					}
					rb = (*it1).value;
					rw = (*it2).value;
					if (rb > rw) {
						std::cout << "Black wins." << endl;
					}
					else if (rb < rw) {
						std::cout << "White wins." << endl;
					}
					else {
						std::cout << "Tie." << endl;
					}
				}
				else {
					std::cout << "White wins." << endl;
				}
			}
			else {
				std::cout << "Black wins." << endl;
			}
		}
		else if (is_straight(black)) {
			if (is_straight_flush(white) || is_four_of_a_kind(white) || is_full_house(white) || is_flush(white)) {
				std::cout << "White wins." << endl;
			}
			else if (is_straight(white)) {
				rb = get_rank(black, 5);
				rw = get_rank(white, 5);
				if (rb > rw) {
					std::cout << "Black wins." << endl;
				}
				else if (rb == rw) {
					std::cout << "Tie." << endl;
				}
				else {
					std::cout << "White wins." << endl;
				}
			}
			else {
				std::cout << "Black wins." << endl;
			}
		}
		else if (is_three_of_a_kind(black)) {
			if (is_straight_flush(white) || is_four_of_a_kind(white) || is_full_house(white) || is_flush(white) 
				|| is_straight(white)) {
				std::cout << "White wins." << endl;
			}
			else if (is_three_of_a_kind(white)) {
				rb = get_rank(black, 4);
				rw = get_rank(white, 4);
				if (rb > rw) {
					std::cout << "Black wins." << endl;
				}
				else if (rb == rw) {
					std::cout << "Tie." << endl;
				}
				else {
					std::cout << "White wins." << endl;
				}
			}
			else {
				std::cout << "Black wins." << endl;
			}
		}
		else if (is_two_pairs(black)) {
			if (is_straight_flush(white) || is_four_of_a_kind(white) || is_full_house(white) || is_flush(white) ||
				is_straight(white) || is_three_of_a_kind(white)) {
				std::cout << "White wins." << endl;
			}
			else if (is_two_pairs(white)) {
				rb = get_rank(black, 3);
				rw = get_rank(white, 3);
				if (rb > rw) {
					std::cout << "Black wins." << endl;
				}
				else if (rb == rw) {
					rb = get_rank_two_pairs_frist(black);
					rw = get_rank_two_pairs_frist(white);
					if (rb > rw) {
						std::cout << "Black wins." << endl;
					}
					else if (rb < rw) {
						std::cout << "White wins." << endl;
					}
					else {
						rb = get_rank_two_pairs_second(black);
						rw = get_rank_two_pairs_second(white);
						if (rb > rw) {
							std::cout << "Black wins." << endl;
						}
						else if (rb < rw) {
							std::cout << "White wins." << endl;
						}
						else {
							std::cout << "Tie." << endl;
						}
					}
				}
				else {
					std::cout << "White wins." << endl;
				}
			}
			else {
				std::cout << "Black wins." << endl;
			}
		}
		else if (is_pair(black)) {
			if (is_high_card(white)) {
				std::cout << "Black wins." << endl;
			}
			else if (is_pair(white)) {
				rb = get_rank(black, 2);
				rw = get_rank(white, 2);
				if (rb > rw) {
					std::cout << "Black wins." << endl;
				}
				else if (rb == rw) {
					rb = get_rank_pair_first(black);
					rw = get_rank_pair_first(white);
					if (rb > rw) {
						std::cout << "Black wins." << endl;
					}
					else if (rb < rw) {
						std::cout << "White wins." << endl;
					}
					else {
						Iterator it1 = black.end();
						Iterator it2 = white.end();
						it1--;
						it2--;
						int i = 5;
						while (i > 0 && (*it1).value == (*it2).value) {
							it1--;
							it2--;
							i--;
						}
						rb = (*it1).value;
						rw = (*it2).value;
						if (rb > rw) {
							std::cout << "Black wins." << endl;
						}
						else if (rb < rw) {
							std::cout << "White wins." << endl;
						}
						else {
							std::cout << "Tie." << endl;
						}
					}
				}
				else {
					std::cout << "White wins." << endl;
				}
			}
			else {
				std::cout << "White wins." << endl;
			}
		}
		else {
			if (is_high_card(white)) {
				rb = get_rank(black, 1);
				rw = get_rank(white, 1);
				if (rb > rw) {
					std::cout << "Black wins." << endl;
				}
				else if (rb == rw) {
					Iterator it1 = black.begin();
					Iterator it2 = white.begin();
					int first1 = (*it1).value;
					int second1 = (*(++it1)).value;
					int third1 = (*(++it1)).value;
					int fourth1 = (*(++it1)).value;
					int first2 = (*it2).value;
					int second2 = (*++it2).value;
					int third2 = (*++it2).value;
					int fourth2 = (*++it2).value;
					if (fourth1 > fourth2) {
						std::cout << "Black wins." << endl;
					}
					else if (fourth1 < fourth2) {
						std::cout << "White wins." << endl;
					}
					else {
						if (third1 > third2) {
							std::cout << "Black wins." << endl;
						}
						else if (third1 < third2) {
							std::cout << "White wins." << endl;
						}
						else {
							if (second1 > second2) {
								std::cout << "Black wins." << endl;
							}
							else if (second1 < second2) {
								std::cout << "White wins." << endl;
							}
							else {
								if (first1 > first2) {
									std::cout << "Black wins." << endl;
								}
								else if (first1 < first2) {
									std::cout << "White wins." << endl;
								}
								else {
									std::cout << "Tie." << endl;
								}
							}
						}
					}
				}
				else {
					std::cout << "White wins." << endl;
				}
			}
			else {
				std::cout << "White wins." << endl;
			}
		}
		black.clear();
		white.clear();
	}
	system("pause");
	return 0;
}


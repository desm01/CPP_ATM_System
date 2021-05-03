#ifndef CARD_H
#define CARD_H

#include <string>

using std::string;

class Card {

	public:
		Card() {}
		Card(string _pin_code) :
			PIN_CODE (_pin_code) {};

		bool check_pin_code(string _pin_code) {
			if (PIN_CODE == _pin_code) {
				return true;
			}
			return false;
		}

	private:
		string PIN_CODE;


};

#endif





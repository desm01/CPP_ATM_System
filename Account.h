#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Person.h"
#include "Card.h"
#include <string>

using std::string;

class Account {
	public:
		Account() {
			
		}
		Account(Person _person, Card _card, string _account_type, int _account_number):
			person(_person), card(_card), account_type(_account_type), account_number(_account_number) {};

		string get_name()  {
			return person.get_name();
		}

		string get_account_type() const {
			return account_type;
		}

		bool get_sign_in_status() {
			return signed_in;
		}

		string enter_card_number(string PIN_CODE) {
			if (user_is_locked_out() == true) {
				return "You have been locked out, please contact customer support at +123456789";
			}
			else {
				if (check_pin_code_is_correct(PIN_CODE) == true) {
					signed_in = true;
					attempts_remaining = 5;
					return "PIN is correct!";
					}
				else {
					signed_in = false;
					attempts_remaining--;
					return "Error, the code you've entered is incorrect";
				}
			
			}
		}

			
	
	
	private:
		Person person;
		Card card;
		string account_type;
		int account_number;
			
		bool signed_in;
		int attempts_remaining = 5;
		
		bool check_pin_code_is_correct(string PIN_CODE) {
			return card.check_pin_code(PIN_CODE);

		}
		
		bool user_is_locked_out() {
			if (attempts_remaining < 0) {
				return true;
			}

			return false;
		}

};

#endif

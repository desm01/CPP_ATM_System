#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Person.h"
#include "Card.h"
#include <string>
#include <iostream>

using namespace std;

using std::string;

class Account {
	public:
		Account() {
			
		}
		Account(Person _person, Card _card, string _account_type, int _account_number, int _current_balance):
			person(_person), card(_card), account_type(_account_type), account_number(_account_number), current_balance(_current_balance) {};

		string get_name()  {
			return person.get_name();
		}

		int get_account_number() {
			return account_number;
		}

		void detuct_from_balance(int amount_to_be_detucted) {
			current_balance = current_balance - amount_to_be_detucted;
		}

		int get_balance() {
			return current_balance;
		}

		string get_account_type() const {
			return account_type;
		}

		bool get_sign_in_status() {
			return signed_in;
		}

		bool user_is_locked_out() {
			if (attempts_remaining == 0) {
				return true;
			}

			return false;
		}

		bool enter_card_number(string PIN_CODE) {
			if (user_is_locked_out() == true) {
				cout << "You have been locked out, please contact customer support at +123456789" << endl;
				return false;
			}
			else {
				if (check_pin_code_is_correct(PIN_CODE) == true) {
					signed_in = true;
					attempts_remaining = 5;
					cout << "PIN is correct!" << endl;;
					return true;
					}
				else {
					signed_in = false;
					attempts_remaining--;
					cout << "Error, the code you've entered is incorrect\n\n\n\nYou have: " << attempts_remaining << " attempts remaining"  << endl;
					return false;
				}
			
			}
		}

			
	
	
	private:
		Person person;
		Card card;
		string account_type;
		int account_number;
		int current_balance;

		bool signed_in;
		int attempts_remaining = 5;
		
		bool check_pin_code_is_correct(string PIN_CODE) {
			return card.check_pin_code(PIN_CODE);

		}
		


};

#endif

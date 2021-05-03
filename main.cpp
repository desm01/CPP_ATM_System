#include <iostream>
#include <string>
#include "Account.h"
#include "Person.h"
#include "Card.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;



string get_user_input() {
	string pin;
	cin >> pin;
	return pin;
}

string get_user_pin_code() {
cout << "\n\n\nEnter your PIN code..." << endl;
string pin = get_user_input();
return pin;
}


void enter_pin_code(Account& currentAccount, Account* list_of_accounts) {
	
	if (currentAccount.user_is_locked_out() == true) {
		cout << "You have been locked out" << endl;
	}

	else {
		string pin_code = get_user_pin_code();

		currentAccount.enter_card_number(pin_code);

		if (currentAccount.get_sign_in_status() != true) {
			enter_pin_code(currentAccount, list_of_accounts);
		}
	}
}


void start_program(Account* list_of_accounts) {
string name;
cout << "Enter your name:" << endl;
getline(cin, name);

Account currentAccount;

for (int i = 0; i < 5; i++) {
	if (name == list_of_accounts[i].get_name()) {
		currentAccount = list_of_accounts[i];
		cout << "Successfully found your account" << endl;
		break;
	}
}

if (currentAccount.get_name() == " ") {
	cout << "Error, your name is entered incorrectly, please try again" << endl;
	start_program(list_of_accounts);
}
else {
	enter_pin_code(currentAccount, list_of_accounts);
}

}



Account* initalise_data() {
Card desCard("0010");
Card billCard("2381");
Card sarahCard("2932");
Card phillCard("1293");
Card taylorCard("1243");

Person des("Des", "M", "1990-01-01", "123 Fake Street", "Springfield");
Person bill("Bill", "B", "1987-12-12", "321 Fake Streeet", "Fake Town");
Person sarah("Sarah", "G", "1986-12-12", "94 Park Road", "Bank Road");
Person phill("Phillimena", "A", "1956-01-30", "85 Phil Street", "The Top Town");
Person taylor("Taylor", "S", "1982-12-01", "213 Swifite Ville", "Swift City");

Account desAccount(des, desCard, "Savings Account", 00000);
Account billAccount(bill, billCard, "Primary Card", 00001);
Account sarahAccount(sarah, sarahCard, "Primary Account", 00002);
Account phillAccount(phill, phillCard, "Secondary Account", 00003);
Account taylorAccount(taylor, taylorCard, "Secondary", 00004);

Account* account = new Account[5];

account[0] = desAccount;
account[1] = billAccount;
account[2] = sarahAccount;
account[3] = phillAccount;
account[4] = taylorAccount;

return account;

}

int main() {
	Account* list_of_accounts = initalise_data();
	
	start_program(list_of_accounts);


	

}

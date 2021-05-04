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

void view_balance(Account& user) {
	cout << user.get_balance() << endl;

}

void withdraw_money(Account& user) {
cout << "Your current balance = " << user.get_balance() << endl;
cout << "\n\nEnter the amount you wish to wirthdraw" << endl;

int amount_to_detuct;
cin >> amount_to_detuct;

if (amount_to_detuct > user.get_balance()) {
	cout << "Error, you do not have that amount of money in your account..." << endl;
	return;
}
else {

	user.detuct_from_balance(amount_to_detuct);

	cout << amount_to_detuct <<  " has been removed from your account" << endl;
	cout << "Your new balance is: " << user.get_balance() << endl;
}

}

void ask_what_user_wants_to_do(Account& user) {
	int selectedOption;
	cout << "Select Option: " << endl;
	cout << "1. Withdraw Money" << endl;
	cout << "3. View Balance" << endl;
	cout << "5. Exit" << endl;
	cin >> selectedOption;

	if (selectedOption == 1) {
		withdraw_money(user);
	}

	if (selectedOption == 3) {
		view_balance(user);
	}

	if (selectedOption == 5) {
		return;
	}


	char choice;
	cout << "Would you like to make another transaction? y/n" << endl;
	cin >> choice;

	if (choice == 'y') {
		ask_what_user_wants_to_do(user);
	}

	else {
		return;
	}

}

void start_program(Account* list_of_accounts) {
int account_number;
cout << "Enter your Account Number:" << endl;
cin >> account_number;

Account currentAccount;

for (int i = 0; i < 5; i++) {
	if (account_number == list_of_accounts[i].get_account_number()) {
		currentAccount = list_of_accounts[i];
		cout << "Successfully found your account" << endl;
		break;
	}
}

if (currentAccount.get_name() == " ") {
	cout << "Error, your Account Number is entered incorrectly, please try again\n\n\n\n" << endl;
	start_program(list_of_accounts);
}
else {
	enter_pin_code(currentAccount, list_of_accounts);
}


ask_what_user_wants_to_do(currentAccount);

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

Account desAccount(des, desCard, "Savings Account", 00000, 3000);
Account billAccount(bill, billCard, "Primary Card", 00001, 210);
Account sarahAccount(sarah, sarahCard, "Primary Account", 00002, 100);
Account phillAccount(phill, phillCard, "Secondary Account", 00003, 210);
Account taylorAccount(taylor, taylorCard, "Secondary", 00004, 350);

Account* account = new Account[5];

account[0] = desAccount;
account[1] = billAccount;
account[2] = sarahAccount;
account[3] = phillAccount;
account[4] = taylorAccount;

return account;

}

int main() {
	bool program_is_running = true;
	Account* list_of_accounts = initalise_data();
	while (program_is_running == true) {
		start_program(list_of_accounts);
	} 
	

}

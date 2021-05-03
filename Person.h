#ifndef PERSON_H
#define PERSON_H
#include <string>

using std::string;

class Person { 

	public:
		Person() {}
		Person(string _first_name, string _last_name, string _date_of_birth, string _street_address, string _local_bank):
			first_name(_first_name), last_name(_last_name), date_of_birth(_date_of_birth), street_address(_street_address), local_bank(_local_bank) {};

		string get_name() {
			string name = first_name + " " + last_name;
			return name;
		}

	private:
		string first_name;
		string last_name;
		string date_of_birth;
		string street_address;
		string local_bank;


};

#endif

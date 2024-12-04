#include <iostream>
#include <string>

using namespace std;

class InvalidIndex : public exception {
	string message;
public:
	InvalidIndex(const string& ex) {
		message = ex;
	}

	const char* what() const noexcept override {
		return message.c_str();
	}
};

class InvalidZeroTerminator : public exception {
	string message;
public:
	InvalidZeroTerminator(const string& ex) {
		message = ex;
	}

	const char* what() const noexcept override {
		return message.c_str();
	}
};

class InvalidDivisionZero : public exception {
	string message;
public:
	InvalidDivisionZero(const string& ex) {
		message = ex;
	}

	const char* what() const noexcept override {
		return message.c_str();
	}
};

int main() {
	char x[5] = { 1, 2, 3, 4, '\0' };
	try {
		int index;
		cout << "Write your number: ";
		cin >> index;
		if (index > 5) {
			throw InvalidIndex("Invalid index");
		}
		else if (x[4] != '\0') {
			throw InvalidZeroTerminator("Invalid zero terminator");
		}
		else if (index == 0) {
			throw InvalidDivisionZero("Invalid division zero");
		}
	}
	catch (InvalidIndex ex) {
		cout << ex.what();
	}
	catch (InvalidZeroTerminator ex) {
		cout << ex.what();
	}
	catch (InvalidDivisionZero ex) {
		cout << ex.what();
	}
}
#include <iostream>
#include <stdexcept>
#include "UnsortedList.hh"

using namespace std;

int main(int args, char* argv[]) {
	try {
		UnsortedList ul {1, 2, 3, 4, 5, 6};
		cout << "ul's Size: " << ul.getSize() << "; ul's Max Size: " << ul.getMaxSize() << endl;
		ul.printList();
		cout << ul.getElement(1) << " " << ul.getElement(2) << " " << ul.getElement(3) << endl;
		cout << ul.getElement(5) << endl;
		cout << ul.getElement(6) << endl;
	} catch (const exception& e) {
		cout << e.what() << endl;
	}

	return 0;
}

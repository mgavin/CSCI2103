/*
  Copyright (C) 2018 Matthew Gavin

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

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

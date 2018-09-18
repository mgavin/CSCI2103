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

#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <sstream>

#include "UnsortedList.hh"

using std::out_of_range;
using std::initializer_list;
using std::stringstream;

UnsortedList::UnsortedList(int sz) {
	cur_size = 0;
	max_size = sz;

	// initalizes a new integer array of sz
	arr = new int[sz];
}

UnsortedList::UnsortedList(initializer_list<int> ls) {
	cur_size = ls.size();
	max_size = ls.size();

	// initalizes a new integer array from an initializer list
	arr = new int[ls.size()];

	int i = 0;
	for (int x : ls) {
		arr[i] = x;
		++i;
	}
}

UnsortedList::~UnsortedList() {
	delete[] arr;
}

void UnsortedList::putElement(int element) {
	if (cur_size == max_size) {
		stringstream sstr;
		sstr << "Can't put " << element << " in list! for UnsortedList::putElement";
		throw out_of_range(sstr.str());
	}

	arr[cur_size] = element;
	cur_size++;
}

int UnsortedList::getElement(int pos) const {
	// if the position requested is outside of the acceptable range
	if (pos < 0 || pos >= cur_size) {
		stringstream sstr;
		sstr << "Position " << pos << " is out of range for UnsortedList::getElement";
		throw out_of_range(sstr.str());
	}

	return arr[pos];
}

bool UnsortedList::isFull() const {
	return cur_size == max_size;
}

void UnsortedList::delElement(int pos) {
	// if the position requested is outside of the acceptable range
	if (pos < 0 || pos >= cur_size) {
		stringstream sstr;
		sstr << "Position " << pos << " is out of range for UnsortedList::delElement";
		throw out_of_range(sstr.str());
	}

	// uses the swapping method
	arr[pos] = arr[cur_size-1];
	cur_size--;
}

void UnsortedList::resize(int sz) {
	if (sz <= max_size)
		return;

	max_size = sz;
	int* arr2 = new int[sz]; // create the new array

	// copy the contents
	for (int i = 0; i < cur_size; ++i) {
		arr2[i] = arr[i];
	}

	// delete the old contents
	delete[] arr;

	// copy the pointer over
	arr = arr2;
}

/*
 * Prints out the contents of the UnsortedList, separated by commas
 * and terminated by a new line.
 */
void UnsortedList::printList() const {
	using std::cout;
	using std::endl;

	if (cur_size > 0) {
		cout << arr[0];
	}
	for (int i = 1; i < cur_size; ++i) {
		cout << ", " << arr[i];
	}
	cout << endl;
}

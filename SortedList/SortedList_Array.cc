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

#include "SortedList.hh"
#include "ItemType.hh"

using std::out_of_range;
using std::domain_error;
using std::stringstream;

SortedList::SortedList(int sz) {
	cur_size = 0;
	max_size = sz;

	// initalizes a new integer array of sz
	arr = new ItemType[sz];
}

SortedList::~SortedList() {
	delete[] arr;
}

void SortedList::putElement(ItemType element) {
	// pre: must be sorted
	// post: must be sorted
	if (cur_size == max_size) {
		stringstream sstr;
		sstr << "Can't put " << element << " in list! for SortedList::putElement";
		throw out_of_range(sstr.str());
	}

	arr[cur_size] = element;
	cur_size++;
	sort_list();
}

ItemType& SortedList::getElement(ItemType element) const {
	int pos;
	if (pos = this->binary_search(element)) {
		return arr[pos];
	}
	return arr[pos];
}

bool SortedList::isFull() const {
	return cur_size == max_size;
}

void SortedList::delElement(ItemType element) {
	pos = this->binary_search(element);
	arr[pos] = arr[cur_size-1];
	cur_size--;

	this->sort_list();
}

/*
 * Prints out the contents of the SortedList, separated by commas
 * and terminated by a new line.
 */
void SortedList::printList() const {
	using std::cout;
	using std::endl;

	if (cur_size > 0) {
		cout << arr[0];

		for (int i = 1; i < cur_size; ++i) {
			cout << ", " << arr[i];
		}

		cout << endl;
	}
}

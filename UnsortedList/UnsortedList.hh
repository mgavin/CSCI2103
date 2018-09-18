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

#ifndef UNSORTEDLIST
#define UNSORTEDLIST

#include <initializer_list>

/*
 * UnsortedList of integers.
 * Elements are 0-based accessible.
 */

class UnsortedList {
public:
	UnsortedList(int sz);
	UnsortedList(std::initializer_list<int> ls);
	~UnsortedList();

	// puts an integer element into the list
	void putElement(int element);

	// gets an integer element from the list
	int getElement(int pos) const;

	// returns the status of the UnsortedList being full
	bool isFull() const;

	// deletes an element from the list by swapping the
	// element at size with the undesired element
	void delElement(int);

	void resize(int sz); // resizes the underlying array to a new size

	// accessors
	int getSize() const { return cur_size; }
	int getMaxSize() const { return max_size; }
	void printList() const;
private:
	int* arr;     // the pointer to the first position of the array
	int cur_size; // the current size of the list
	int max_size; // the max size of the list
};

#endif

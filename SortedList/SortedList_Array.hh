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

#ifndef SORTEDLIST
#define SORTEDLIST

#include <stdexcept>
#include "ItemType.hh"

/*
 * SortedList of integers.
 * Elements are 0-based accessible.
 */

class SortedList {
public:
	SortedList(int sz);
	~SortedList();

	// puts an ItemType element into the list
	void putElement(ItemType element);

	// gets a reference to ItemType element from the list
	// throws if element isn't in the list
	ItemType& getElement(ItemType element) const;

	// returns the status of the SortedList being full
	bool isFull() const;

	// deletes an element from the list
	// sorted before, sorted after
	void delElement(ItemType element);

	// accessors
	int getSize() const { return cur_size; }
	int getMaxSize() const { return max_size; }
	void printList() const;
private:
	ItemType* arr;     // the pointer to the first position of the array
	int cur_size; // the current size of the list
	int max_size; // the max size of the list

	// binary search the underlying array for v. return pos.
	int binary_search(const ItemType& v);

	// sorts the underlying array of items
	void sort_list();

	// Exception Classes
	class ItemNotFound : domain_error{};
};

#endif

#include <initializer_list>
#include <stdexcept>

using std::out_of_range;
using std::initializer_list;

UnsortedList::UnsortedList(int sz) {
	cur_size = 0;
	max_size = sz;

	// initalizes a new integer array of sz
	arr = new int[sz]; // can throw
}

UnsortedList::UnsortedList(initializer_list<int> ls) {
	cur_size = 0;
	max_size = ls.size();

	// initalizes a new integer array from an initializer list
	arr = new int[ls.size()]; // can throw

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
		throw out_of_range;
	}

	arr[cur_size] = element;
	cur_size++;
}

int UnsortedList::getElement(int pos) const {
	// if the position requested is outside of the acceptable range
	if (pos < 0 || pos >= cur_size) {
		throw out_of_range;
	}

	return arr[pos];
}

bool UnsortedList::isFull() const {
	return cur_size == max_size;
}

void UnsortedList::delElement(int pos) {
	// if the position requested is outside of the acceptable range
	if (pos < 0 || pos >= cur_size) {
		throw out_of_range;
	}

	// uses the swapping method
	arr[pos] = arr[cur_size]-1;
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

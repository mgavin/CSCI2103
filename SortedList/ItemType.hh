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


#ifndef ITEMTYPE
#define ITEMTYPE

using DataType = int; // could be any other data type
class ItemType {
public:
	ItemType();
	ItemType(const ItemType& rhs) = default;
	ItemType& operator=(const ItemType& rhs) = default;

	// set of functions that make this type orderable
	virtual bool operator==(const ItemType& rhs);
	virtual bool operator<(const ItemType& rhs);
	virtual bool operator>(const ItemType& rhs);
	virtual bool operator>=(const ItemType& rhs);
	virtual bool operator<=(const ItemType& rhs);
	~ItemType();
private:
	DataType data;
};

#endif

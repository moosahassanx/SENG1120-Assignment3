#ifndef HTABLE_H
#define HTABLE_H

#include <cstdlib>
#include <iostream>
#include <string>
#include "BTNode.h"

using namespace std;

template <typename value_type>

class HTable{
	public:
		// Constructor
		HTable();
		HTable(value_type& value);
		
		// Destructor
		~HTable();
		
		// Other methods
		int hashfun(const value_type& value);
		void add (value_type& value);
		void remove(value_type& value);
		int calculateParts();
		int calculateInventory();
		
		string print();
	private:
		value_type dataArray[5000];
		int TABLE_SIZE;
	protected:
};

template <typename value_type>
ostream& operator<< (ostream& stream, HTable<value_type>& list);

#include "HTable.hpp"

#endif
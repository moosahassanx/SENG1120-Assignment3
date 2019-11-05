#include <iostream>
#include <string>
#include <cstdlib>
#include "HTable.h"

template <typename value_type>
HTable<value_type>::HTable(){
	std::cout << "HTable constructor has successfully loaded" << std::endl;
}

template <typename value_type>
HTable<value_type>::~HTable(){
	std::cout << "HTable destructor has successfully loaded" << std::endl;
}

template <typename value_type>
int HTable<value_type>::hashfun(const value_type& value){
	int position = 0;
	string temp = value.get_code();
	for (int i=0; i<(int)temp.length(); i++){
		position += (i+1) * (i+1) * temp.at(i);
	}
	return position % TABLE_SIZE;
}

template <typename value_type>
void HTable<value_type>::add (value_type value){}

template <typename value_type>
void HTable<value_type>::remove(value_type value){}

template <typename value_type>
void HTable<value_type>::calculateParts(){}

template <typename value_type>
void HTable<value_type>::calculateInventory(){}










template <typename value_type>
std::ostream& operator<< (ostream& stream, HTable<value_type>& list){
	std::cout << "testing << operator" << std::endl;
	
	list.print();			// run the print function for object list
	return stream;			// return the stream
}

template <typename value_type>
string HTable<value_type>::print(){
	for(int i = 0; i < sizeof(dataArray)/sizeof(dataArray[0]); i++){
		if(dataArray[i] != 0){
			std::cout << dataArray[i] << std::endl;
		}
	}
}

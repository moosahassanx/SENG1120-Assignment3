#include <iostream>
#include <string>
#include <cstdlib>
#include "HTable.h"

template <typename value_type>
HTable<value_type>::HTable(){
	std::cout << "HTable constructor has successfully loaded" << std::endl;
	TABLE_SIZE = 5000;
	for(int i = 0; i < TABLE_SIZE; i++){
		dataArray[i] = value_type();
	}
}

template <typename value_type>
HTable<value_type>::~HTable(){
	std::cout << "HTable destructor has successfully loaded" << std::endl;
	for(int i= 0; i < TABLE_SIZE; i++)
	{
		dataArray[i] = value_type();
	}
}

template <typename value_type>
int HTable<value_type>::hashfun(const value_type& value)
{
	int position = 0;
	string temp = value.get_code();
	for (int i=0; i<(int)temp.length(); i++)
	{
		position += (i+1) * (i+1) * temp.at(i);
	}
	int v = position % TABLE_SIZE;
	return v;
}

template <typename value_type>
void HTable<value_type>::add (value_type& value){
	//std::cout << "add() function has successfully loaded" << std::endl;
	int hashIndex; 
	//while(array[hashfun(value)] != 0){
		//new dataArray
	//}
	hashIndex = hashfun(value);
	//dataArray[hashIndex] = value_type();
	dataArray[hashIndex] = value;
}

template <typename value_type>
void HTable<value_type>::remove(value_type& value){
	std::cout << "remove() function has successfully loaded" << std::endl;
	//int hashIndex;
	//hashIndex = hashfun(value);
	//dataArray[hashIndex] = NULL;
}

template <typename value_type>
int HTable<value_type>::calculateParts(){
	return 69;				// temporary foolish number until i fix this
}

template <typename value_type>
int HTable<value_type>::calculateInventory(){
	return 21;				// temporary fooolish number until i fix this
}

template <typename value_type>
std::ostream& operator<< (ostream& stream, HTable<value_type>& list){	
	list.print();			// run the print function for object list
	return stream;			// return the stream
}


template <typename value_type>
string HTable<value_type>::print(){
	std::string stream;
	for(int i = 0; i < 5000; i++){
		if(!(dataArray[i]==value_type())){
			std::cout << dataArray[i];
		}
	}
	return stream;
}

	


	/*
	for(int i = 0; i < sizeof(dataArray)/sizeof(dataArray[0]); i++){
		if(dataArray[i] != 0){
			std::cout << dataArray[i] << std::endl;
		}
	}
*/
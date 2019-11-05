#ifndef BSTREE_H
#define BSTREE_H

#include <cstdlib>
#include <string>
#include <iostream>
#include "BTNode.h"

template <typename value_type>

class BSTree{
	public:
		// Constructor
		BSTree();
		BSTree(value_type& value);
		
		// Destructor
		~BSTree();
		
		// Other methods
		void add(value_type& data);
		void addRecursive(BTNode<value_type>* node, value_type& value);
		void remove(value_type value);		// NEEDS WORK
		void calculateParts();				// NEEDS WORK
		void calculateInventory();			// NEEDS WORK
		std::string print();
		std::string inOrder(BTNode<value_type>* node);
		
		/*
		int find(int[] a, int target, int first, int last);
		VALUE TYPE add( MECHPART OBJECT );
		*/
	private:
		BTNode<value_type>* root;
		int size;
	protected:
};

template <typename value_type>
std::ostream& operator<< (std::ostream& stream, BSTree<value_type>& object);

#include "BSTree.hpp"

#endif
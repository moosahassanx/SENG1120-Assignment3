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
		
		// Add and remove methods
		void add(value_type& data);											// for root node
		void addRecursive(BTNode<value_type>* node, value_type& value);		// for deeper nodes
		void remove(value_type& value);		// NEEDS WORK
		void removeRecursive(BTNode<value_type>* node, BTNode<value_type>* parent, value_type& value);
		// Calculation methods for TreeHashDemo
		int calculateParts();				// COME BACK TO THIS AFTER REMOVE FUNCTION WORKS
		int calculatePartsRecursive(BTNode<value_type>* node);		// NEEDS WORKS
		int calculateInventory();			// NEEDS WORK + COME BACK TO THIS AFTER REMOVE FUNCTION WORKS
		int calculateInventoryRecursive(BTNode<value_type>* node);
		BTNode<value_type>* findMin(BTNode<value_type>* node);
		// Printing
		std::string print();
		std::string inOrder(BTNode<value_type>* node);
		
		// LAUREN VIDEO
		/*
		int find(int[] a, int target, int first, int last);
		VALUE TYPE add( MECHPART OBJECT );
		*/
	private:
		BTNode<value_type>* root;
		BTNode<value_type>* parent;
		int size;
		int answer;
		int numberOfNodes;
	protected:
};

template <typename value_type>
std::ostream& operator<< (std::ostream& stream, BSTree<value_type>& object);

#include "BSTree.hpp"

#endif
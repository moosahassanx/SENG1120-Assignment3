#ifndef BTNODE_H
#define BTNODE_H

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>

template <typename value_type>

class BTNode{
	public:
		// Constructors
		BTNode();
		BTNode(value_type& initialData);
		BTNode(value_type& initialData, BTNode<value_type>* newRight, BTNode<value_type>* newLeft);
		
		// Destructor
		~BTNode();
		
		// Mutators
		void setData(value_type& newData);
		void setLeft(BTNode<value_type>* newLeft);
		void setRight(BTNode<value_type>* newRight);
		
		// Adding and removing methods
		void add(value_type& newNode);
		void remove(value_type& newNode);
		// void removeMethod();
		
		// Query (non const)
		value_type getData();
		BTNode<value_type>* getRight();
		BTNode<value_type>* getLeft();
		
		// Query (const)
		const value_type& getData() const;
		const BTNode<value_type>* getRight() const;
		const BTNode<value_type>* getLeft() const;
	private:
		value_type data;
		BTNode<value_type>* left;
		BTNode<value_type>* right;
		// BTNode* data;
		// int* data;
	protected:
};

#include "BTNode.hpp"

#endif
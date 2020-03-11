#include <iostream>
#include <cstdlib>

#include "BTNode.h"

// Constructors
template <typename value_type>
BTNode<value_type>::BTNode(){
	std::cout << "BTNode constructor has successfully loaded" << std::endl;
}

template <typename value_type>
BTNode<value_type>::BTNode(value_type& initialData){
	// std::cout << "BTNode with with set left null and set right null parameters has successfully loaded" << std::endl;
	data = initialData;
	left = NULL;
	right = NULL;
}

template <typename value_type>
BTNode<value_type>::BTNode(value_type& initialData, BTNode<value_type>* newRight, BTNode<value_type>* newLeft){
	data = initialData;
	right = newRight;
	left = newLeft;
}

template <typename value_type>
BTNode<value_type>::BTNode(value_type& initialData, BTNode<value_type>* newRight, BTNode<value_type>* newLeft, BTNode<value_type>* newParent){
	data = initialData;
	right = newRight;
	left = newLeft;
	parent = newParent;
}


// Destructor
template <typename value_type>
BTNode<value_type>::~BTNode(){
	std::cout << "BTNode destructor has succesfully loaded" << std::endl;
	left = NULL;
	right = NULL;
}

// Mutators
template <typename value_type>
void BTNode<value_type>::setData(value_type& newData){
	data = newData;
}

template <typename value_type>
void BTNode<value_type>::setLeft(BTNode<value_type>* newLeft){
	left = newLeft;
}

template <typename value_type>
void BTNode<value_type>::setRight(BTNode<value_type>* newRight){
	right = newRight;
}
template <typename value_type>
void BTNode<value_type>::setParent(BTNode<value_type>* newParent){
	parent = newParent;
}

// Adding and removing methods
template <typename value_type>
void BTNode<value_type>::add(value_type& newNode){
	if(newNode < data){
		if(left == NULL){
			left = new BTNode* (newNode);
			// left = new BTNode <value_type> (newNode);
		}else{
			add(newNode);
		}
	}else{
		if(newNode > data){
			right = new BTNode* (newNode);
			// right = new BTNode <value_type> (newNode);
		}else{
			add(newNode);
		}
	}
}

template <typename value_type>
void BTNode<value_type>::remove(value_type& newNode){
	
	
	if( (newNode < data) && (left != NULL) ){
		if(left->data == newNode){
			// deleteMethod();
		}else{
			left->remove(newNode);
		}
	}else{
		if( (newNode > data) && (right != NULL) ){
			// deleteMethod();
		}else{
			right->remove(newNode);
		}
	}
}

template <typename value_type>
bool BTNode<value_type>::isLeaf() const{
	return (left == NULL) && (right == NULL);
}

template <typename value_type>
bool BTNode<value_type>::hasOneChild(){
	return ((left == NULL) && (right != NULL));
}

template <typename value_type>
bool BTNode<value_type>::isRightChild(){
	return data > parent->getData();
}

// Query (non const)
template <typename value_type>
value_type BTNode<value_type>::getData(){
	return data;
}


template <typename value_type>
BTNode<value_type>* BTNode<value_type>::getRight(){
	return right;
}

template <typename value_type>
BTNode<value_type>* BTNode<value_type>::getLeft(){
	return left;
}

template <typename value_type>
BTNode<value_type>* BTNode<value_type>::getParent(){
	return parent;
}

// Query (non const)
template <typename value_type>
const value_type& BTNode<value_type>::getData() const{
	return data;
}

template <typename value_type>
const BTNode<value_type>* BTNode<value_type>::getRight() const{
	return right;
}

template <typename value_type>
const BTNode<value_type>* BTNode<value_type>::getLeft() const{
	return left;
}

template <typename value_type>
const BTNode<value_type>* BTNode<value_type>::getParent() const{
	return parent;
}
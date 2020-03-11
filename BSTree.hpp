#include <cstdlib>
#include <iostream>
#include <string>
#include "BSTree.h"

template <typename value_type>
BSTree<value_type>::BSTree(){
	//std::cout << "BSTree constructor has successfully loaded" << std::endl;
	root = NULL;
	size = 0;
}

template <typename value_type>
BSTree<value_type>::BSTree(value_type& value){
	root = value;
	size++;
}

template <typename value_type>
BSTree<value_type>::~BSTree(){
	//std::cout << "BSTree destructor has successfully loaded" << std::endl;
	// need to code this part when i'm done
}

template <typename value_type>
void BSTree<value_type>::add(value_type& value){
	if(root==NULL){
		root = new BTNode<value_type>(value);
		numberOfNodes++;
	}else{
		addRecursive(root, value);
	}
}


template <typename value_type>
void BSTree<value_type>::addRecursive(BTNode<value_type>* node, value_type& value){
	if(value == node->getData()){
		return;
	}else if(value < node->getData()){							// if the input value is less than the pointed data...
		if(node->getLeft() == NULL){							// and if the left of the node has no value...
			node->setLeft(new BTNode<value_type>(value));		// make a new node to the left with value as the data
			numberOfNodes++;
		}else{													// otherwise...
			addRecursive(node->getLeft(), value);				// deep further in the left of the mini tree
		}
	}else{														// otherwise...
		if(node->getRight() == NULL){							// if the right of the node has no value...
			node->setRight(new BTNode<value_type>(value));		// make a new node to the right with value as the data
			numberOfNodes++;
		}else{													// otherwise...
			addRecursive(node->getRight(), value);				// deep further in the right of the mini tree
		}
	}
}

// LAUREN VERSION
template <typename value_type>
void BSTree<value_type>::remove(value_type& value){
	if(numberOfNodes == 0){
		return;
	}else{
		removeRecursive(root, parent, value);
	}
}

template <typename value_type>
void BSTree<value_type>::removeRecursive(BTNode<value_type>* node, BTNode<value_type>* parent, value_type& value){
	if(node == NULL){		// first guard as root
		return;				// indicates node was not found/removed
	}
	
	// CASE 1: Leaf
	if(node->isLeaf()){
		if(node->getData() == root->getData()){						// if the node matches root
			root = NULL;
		}else{								// otherwise treat it as a normal case
			if(node->isRightChild()){
				node->getParent()->setRight(NULL);
			}else{
				node->getParent()->setLeft(NULL);
			}
		}
		delete node;
		numberOfNodes--;
	// CASE 2: One Child
	}else if(node->hasOneChild()){
		if(node->getData() == root->getData()){						// if the node matches root
			node->getRight()->setParent(NULL);
			root = node->getRight();
		}else{
			node->getLeft()->setParent(NULL);
			root = node->getLeft();
		}

		if(node->getRight() != NULL){						// if removing right child...
			node->getRight()->setParent(node->getParent());
			if(node->isRightChild()){
				node->getParent()->setRight(node->getRight());
			}else{
				node->getParent()->setLeft(node->getLeft());
			}
		}else{													// if removing left child...
			node->getLeft()->setParent(node->getParent());
			if(node->isRightChild()){
				node->getParent()->setRight(node->getLeft());
			}else{
				node->getParent()->setLeft(node->getLeft());
			}
		}

		delete node;
		numberOfNodes--;
	// CASE 3: Two Children
	}else{
		BTNode<value_type>* tempNode = findMin(node->getRight());
		//BTNode<value_type>* tempItem = new BTNode<value_type>(tempNode->getData());		// this might be wrong
		removeRecursive(node->getRight(), tempNode->getData());
		//node->setData(*tempItem);									// this might be wrong
	}
}

template <typename value_type>		// helps find the lowest value node in the Bsubtree
BTNode<value_type>* BSTree<value_type>::findMin(BTNode<value_type>* node){
	if(node->getLeft() != NULL){
		findMin(node->getLeft());
	}else{
		return node;
	}
}

template <typename value_type>
int BSTree<value_type>::calculateParts(){
	if(root == NULL){				// if the root node has nothing in it then you have 0 values
		answer = 0;					// return the value of 0 since there arent any nodes
		return answer;
	}else{
		int answer = 0;
		answer +=	 calculatePartsRecursive(root);		// run through the recursive function
		return answer;
	}
}

template <typename value_type>
int BSTree<value_type>::calculatePartsRecursive(BTNode<value_type>* node){
	int tempAnswer;
	if(node != NULL){
		tempAnswer = answer + calculatePartsRecursive(node->getLeft());
		tempAnswer = answer + calculatePartsRecursive(node->getRight());
	}
	answer += tempAnswer;
	return answer;
}

template <typename value_type>
int BSTree<value_type>::calculateInventory(){
	if(root == NULL){				// if the root node has nothing in it then you have 0 values
		answer = 0;					// return the value of 0 since there arent any nodes
		return answer;
	}else{
		int answer = 0;
		answer += calculateInventoryRecursive(root);		// run through the recursive function
		return answer;
	}
}

template <typename value_type>
int BSTree<value_type>::calculateInventoryRecursive(BTNode<value_type>* node){
	int tempAnswer;
	if(node != NULL){
		//tempAnswer = node->getLeft();
		calculateInventoryRecursive(node->getLeft());
		//tempAnswer = node->getRight();
		tempAnswer = answer + calculateInventoryRecursive(node->getRight());
	}
	answer += tempAnswer;
	return answer;
}

template <typename value_type>
std::ostream& operator<< (std::ostream& stream, BSTree<value_type>& object){
	object.print();			// run the print function for object list
	return stream;			// return the stream
}

template <typename value_type>
std::string BSTree<value_type>::print(){
	std::string stream;
	// std::cout << "testing print() function" << std::endl;
	// std::cout << root->getData() << std::endl;
	inOrder(root);
	// std::cout << "successfully ran inOrder(root) in print()" << std::endl;
	
	return stream;
}

template <typename value_type>
std::string BSTree<value_type>::inOrder(BTNode<value_type>* node) {
	std::string stream;
	// std::cout << "testing ordered()" << std::endl;
	if(node!= NULL){
		// std::cout << "root node was not null" << std::endl;
		std::cout << inOrder(node->getLeft());
		std::cout << node->getData();
		std::cout << inOrder(node->getRight());
	}
	
	return stream;
}


/*

===================================LAUREN VIDEO===================================
template <typename value_type>
// target = the element we are searching for in the list

// Step 1. Check that you still have an area to search
	//  We know we have an area to search is if(first index happens to be lower than our last index), therefore weve run out of search area
// Step 2. Find the midpoint and check if that's the target
// Step 3. If the midpoint is the target, then you got it just return that
// Step 4. If not, if the target is less than the mid, make a recursive call which calls to the left
// Step 5. If not, if the target is more than the mid, make a recursive call which calls to the right
int BSTree<value_type>::find(int[] a, int target, int firstIndex, int lastIndex){
	// if the item is not in the list
	if(firstIndex > lastIndex){														// target is not there
		return -1;
	}else{
		
		// find the midpoint of the array - uses larger division to find the floor
		int mid = (firstIndex + lastIndex) + 2;										// compute midpoint
		
		// if you have found this item - return the index for this item
		if(a[mid] == target){														// target found
			return mid;
		
		// recusive call using the smaller values array to the left
		}else if(a[mid] > target){													// search left half
			return find(a, target, firstIndex, lastIndex, mid-1);
		
		// recursaive call using the larger values array to the left
		}else{																		// search right half
			return find(a, target, mid+1, lastIndex);
		}
	}
}

template <typename value_type>
void BSTree<value_type>::insert(Item it){
	if(root == NULL){
		root = new BTNode(it);
	}else{
		add(root, it);
	}
	
	size++;
}

*/
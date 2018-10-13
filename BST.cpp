/*
* BST.cpp
*
*  Created on: May 31, 2018
*      Author: simon
*/
/* This program implements a binary search tree with insert, remove,
* in-order traversal, pre-order traversal, post-order traversal, quick delete,
* and delete. Lower values go to the left and higher values go to the right.
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "BST.h"
#include "Node.h"

	BST::BST() {
		m_Root.nData = -1;
	}
	BST::BST(short nData) {
		m_Root.nData = nData;
	}
	BST::~BST() {}

	/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++
	  Method:	BST::AddNode

	  Summary:	This method goes through the tree, checking and the values
				stored in each Node and going to the Node pointed to by the left
				pointer if the value to insert is less than the current Node's
				value, or right if the value to insert is greater. Once a
				nullptr is found, a new Node is created with the value to insert
				and it's address replaces the nullptr on it's parent Node. If
				the value is equal to an existing value, the value is not
				inserted into the tree.

	  Args:		short nData
					A value contained in a Node.
				Node* pRoot
					A pointer to a Node.

	  Modifies:	[A pointer of this Node's parent Node].

	  Returns:	void
				  The method does not return anything.
	M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-*/
	void BST::AddNode(short nData, Node* pRoot){
		if(nData < pRoot->nData){
			if(pRoot->pLeft == nullptr){
				Node* m_NewNode;
				m_NewNode = new Node(nData);
				pRoot->pLeft = m_NewNode;
				return;
			}
			else{
				AddNode(nData, pRoot->pLeft);
			}
		}
		else if(nData > pRoot->nData){
			if(pRoot->pRight == nullptr){
				Node* m_NewNode;
				m_NewNode = new Node(nData);
				pRoot->pRight = m_NewNode;
				return;
			}
			else{
				AddNode(nData, pRoot->pRight);
			}
		}
		else{
			;
		}
	}
	/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++
	  Method:	BST::RemoveNode

	  Summary:	This method goes through the tree until it finds the given value
				and then it	deletes that Node and sets the pointer to it to a
				nullptr. If	the Node is not found, the method prints a message
				stating that the Node does not exist in the tree.

	  Args:		short nData
					A value contained in a Node.

	  Modifies:	[The Node that contains the value and the Node pointing to it].

	  Returns:	void
				  The method does not return anything.
	M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-*/
	void BST::RemoveNode(short nData, Node* m_pRoot){
		if(m_pRoot->nData == nData){
			if(m_pRoot->pRight != nullptr){
				Node* m_pTempPointer;
				m_pTempPointer = m_pRoot->pRight;
				while(m_pTempPointer->pLeft != nullptr){
					m_pTempPointer = m_pTempPointer->pLeft;
				}
				m_pRoot = m_pTempPointer;
			}
			else if(m_pRoot->pLeft != nullptr){
				Node* m_pTempPointer;
				m_pTempPointer = m_pRoot->pLeft;
				while(m_pTempPointer->pRight != nullptr){
					m_pTempPointer = m_pTempPointer->pRight;
				}
				delete m_pRoot;
			}
			else{
				std::cout<< "This tree only has a root. If you delete this Node the"
						" tree will be deleted.\n";
			}
		}
		else if(nData > m_pRoot->nData && m_pRoot->pRight != nullptr){
			RemoveNode(nData, m_pRoot->pRight);
			}
		else if(nData < m_pRoot->nData && m_pRoot->pLeft != nullptr){
			RemoveNode(nData, m_pRoot->pLeft);
		}
		else{
			printf("Node does not exist!\n");
			return;
		}
	}
	/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++
	  Method:	BST::InOrderTraversal

	  Summary:	This method traverses the tree and prints all of its values. The
				values are printed from least to greatest.

	  Args:		Node* m_pRoot
					A Node pointer.

	  Modifies:	[nothing].

	  Returns:	void
				  The method does not return anything.
	M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-*/
	void BST::InOrderTraversal(Node* m_pRoot){
		if(m_pRoot == nullptr){
			return;
		}
		InOrderTraversal(m_pRoot->pLeft);
		std::cout << "The value of this node is " << m_pRoot->nData << ".\n";
		InOrderTraversal(m_pRoot->pRight);
		return;
	}
	/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++
	  Method:	BST::PreOrderTraversal

	  Summary:	This method traverses the tree and prints all of its values. The
				values are printed in the order that they were inserted.

	  Args:		Node* m_pRoot
					A Node pointer.

	  Modifies:	[nothing].

	  Returns:	void
				  The method does not return anything.
	M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-*/
	void BST::PreOrderTraversal(Node* m_pRoot){
		if(m_pRoot == nullptr){
			return;
		}
		std::cout << "The node value is " << m_pRoot->nData << ".\n";
		PreOrderTraversal(m_pRoot->pLeft);
		PreOrderTraversal(m_pRoot->pRight);
		return;
	}
	/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++
	  Method:	BST::PostOrderTraversal

	  Summary:	This method traverses the tree and prints all of its values. The
				values are printed starting at the bottom left of the tree, then
				to the right child of the bottom left's parent, then to the
				parent and repeats, treating the parent as a left child.

	  Args:		Node* m_pRoot
					A Node pointer.

	  Modifies:	[nothing].

	  Returns:	void
				  The method does not return anything.
	M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-*/
	void BST::PostOrderTraversal(Node* m_pRoot){
		if(m_pRoot == nullptr){
			return;
		}
		PostOrderTraversal(m_pRoot->pLeft);
		PostOrderTraversal(m_pRoot->pRight);
		std::cout << "The value of this node is " << m_pRoot->nData << ".\n";
		return;
	}

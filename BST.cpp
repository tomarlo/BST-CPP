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
#ifndef NULL
#define NULL 0
#endif

class BST{
	// Definition for the node structure with left and right pointers and a
	// unicode character.
	struct node {
		node* pLeft = nullptr;
		node* pRight = nullptr;
		short nData = 0;
	} m_Root;
	node* pRoot = &m_Root;

	// Create a new node
	node MakeNode(short nData){
		node m_NewNode;
		m_NewNode.nData = nData;
		return m_NewNode;
	}
	// The function to add a new node to the tree.
	void AddNode(short nData, node* pRoot){
		if(nData < (*pRoot).nData){
			if((*pRoot).pLeft == nullptr){
				node m_NewNode = MakeNode(nData);
				(*pRoot).pLeft = &m_NewNode;
				return;
			}
			else{
				AddNode(nData, (*pRoot).pLeft);
			}
		}
		else if(nData > (*pRoot).nData){
			if((*pRoot).pRight == nullptr){
				node m_NewNode = MakeNode(nData);
				(*pRoot).pRight = &m_NewNode;
				return;
			}
			else{
				AddNode(nData, (*pRoot).pRight);
			}
		}
		else{
			return;
		}
	}
	/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++
	  Method:	CBST::RemoveNode

	  Summary:	This method goes through the tree until it finds the given value
	  	  	  	and then it	deletes that node and sets the pointer to it to a
	  	  	  	nullptr. If	the node is not found, the method prints a message
	  	  	  	stating that the node does not exist in the tree.

	  Args:		short nData
	  	  	  		A value contained in a node.

	  Modifies:	[The node that contains the value and the node pointing to it].

	  Returns:	void
	  	  	  	  The method does not return anything.
	M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-*/
	void RemoveNode(short nData, node m_Root){
		if(m_Root.nData == nData){
			if(m_Root.pRight != nullptr){
				node* m_pTempPointer;
				m_pTempPointer = m_Root.pRight;
				while((*m_pTempPointer).pLeft != nullptr){
					m_pTempPointer = (*m_pTempPointer).pLeft;
				}
				m_Root.nData = 0;
				m_Root.pLeft = nullptr;
				m_Root.pRight = nullptr;
				m_Root = *m_pTempPointer;
			}
			else if(m_Root.pLeft != nullptr){
				node* m_pTempPointer;
				m_pTempPointer = m_Root.pLeft;
				while((*m_pTempPointer).pRight != nullptr){
					m_pTempPointer = (*m_pTempPointer).pRight;
				}
				m_Root.nData = 0;
				m_Root.pLeft = nullptr;
				m_Root.pRight = nullptr;
				m_Root = *m_pTempPointer;
			}
			else{
				std::cout << "You are trying to destroy the root.\n" << std::endl;
			}
		}
		else if(nData > m_Root.nData && m_Root.pRight != nullptr){
			RemoveNode(nData, *m_Root.pRight);
			}
		else if(nData < m_Root.nData && m_Root.pLeft != nullptr){
			RemoveNode(nData, *m_Root.pLeft);
		}
		else{
			std::cout << "Node does not exist in tree.\n" << std::endl;
			return;
		}
	}
	 */
};

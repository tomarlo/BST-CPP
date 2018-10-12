/*
 * BST.h
 *
 *  Created on: Jun 10, 2018
 *      Author: simon
 */

#ifndef BST_H_
#define BST_H_

#include "Node.h"

class BST {

public:
	Node m_Root;

	BST();
	BST(short nData);
	virtual ~BST();
	void AddNode(short nData, Node* pRoot);
	void RemoveNode(short nData, Node* m_pRoot);
	void InOrderTraversal(Node* m_pRoot);
	void PreOrderTraversal(Node* m_pRoot);
	void PostOrderTraversal(Node* m_pRoot);
};

#endif /* BST_H_ */

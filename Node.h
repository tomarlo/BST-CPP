/*
 * Node.h
 *
 *  Created on: Jun 17, 2018
 *      Author: simon
 */

#ifndef NODE_H_
#define NODE_H_

class Node {
public:
	short nData;
	Node* pLeft;
	Node* pRight;

	Node();
	Node(short nData);
	virtual ~Node();
};

#endif /* NODE_H_ */

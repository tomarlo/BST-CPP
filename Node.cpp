/*
 * Node.cpp
 *
 *  Created on: Jun 17, 2018
 *      Author: simon
 */

#include "Node.h"
Node::Node() {
	this->nData = -1;
	this->pLeft = nullptr;
	this->pRight = nullptr;
}
Node::Node(short nData) {
	this->nData = nData;
	this->pLeft = nullptr;
	this->pRight = nullptr;
}

Node::~Node() {
	// TODO Auto-generated destructor stub
}

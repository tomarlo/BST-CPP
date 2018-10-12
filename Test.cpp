/*
 * Test.cpp
 *
 *  Created on: Jun 9, 2018
 *      Author: simon
 */

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <time.h>
#include "Node.h"
#include "BST.h"
#include "Test.h"

Test::Test() {
	// TODO Auto-generated constructor stub

}

Test::~Test() {
	// TODO Auto-generated destructor stub
}
/* C++ Program - Generate Different Random Numbers */

int main(){
	BST Tree = BST(0);
	Node* p_Root = &Tree.m_Root;
	short nData;
	time_t current = time(NULL);
	std::string szNumber;
	std::string szTempString;
	std::fstream myfile;
	myfile.open("DataSet.txt", std::fstream::out);
	srand(current);
	std::cout << "\nPlease input a random number.\n";
	std::string szGetInput = std::cin;
	if(myfile.is_open()){
		std::cout << "Data is being written.\n";
		for(int i=0; i<20; i++){
			for(int j=0; j<10; j++){
				myfile << rand()%60000 << " ";
			}
			myfile << '\n';
		}
		myfile.close();
		std::cout << "Data has been written to file.\n";
	}
	else{
		std::cout << "Can't open file.\n";
	}
	myfile.open("DataSet.txt", std::fstream::in);
	if(myfile.is_open()){
		while(std::getline(myfile, szNumber)){
			for(unsigned i = 0; i<szNumber.length(); i++){
				if(szNumber.at(i) == ' '){
					std::cout<< "Current number: " << szTempString << '\n' <<
							std::endl;
					int nTempInt = std::stoi(szTempString, nullptr, 10);
					try{
						nData = (short) nTempInt;
						Tree.AddNode(nData, p_Root);
						std::cout << nData << " made it.\n";
						szTempString = "";
					}
					catch (std::exception& e){
						std::cerr << "exception caught: " << e.what() << '\n';
					}
				}
				else if(szNumber.at(i) == '\n'){
					;
				}
				else{
					std::cout << "adding: " << szNumber.at(i) << '\n' <<
							std::endl;
					szTempString += szNumber.at(i);
				}
			}
		}
	}
	else{
		std::cout << "The file did not open.\n";
	}
	std::cout << p_Root->nData << std::endl;
	Tree.PreOrderTraversal(p_Root);
	return 0;
}

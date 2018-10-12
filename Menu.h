/*
 * Menu.h
 *
 *  Created on: Sep 19, 2018
 *      Author: simon
 */

#ifndef MENU_H_
#define MENU_H_

#include <string>;

class Menu{
	std::string szEightyCharHorizontalBorder;
	std::string szTwentlyLineVerticaltBorder;

public:
	Menu();
	virtual ~Menu();
	void MakeVerticalBorder();
	void MakeHorizantalBorder();
	void MakeHeading(std::string Title);
	void MakeDividedScreen(std::string LeftSideText, std::string RightSideText);
};




#endif /* MENU_H_ */

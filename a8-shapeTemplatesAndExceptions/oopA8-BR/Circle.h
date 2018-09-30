/*
*  FILE          : Circle.h
*  PROJECT       : PROG1385 - Object Oriented Programming - Assignment #8*  PROGRAMMER    : Brendan Rushing
*  FIRST VERSION : 2018-08-09
*  DESCRIPTION   :
*	This assignment is based on Assignment #7
This assignment is practice using overloaded operators on classes.
Throw and Catch for exceptions is used.
Templates are also used for adding classes together.
*/

//INCLUDE FILES
#include "Shape.h"

//eo INCLUDE FILES

#pragma once


/*!
//NAME : Circle
*
//PURPOSE: Circle class that uses Shape as the base
*			Circle has radius, area and perimeter
*/
class Circle : public Shape {

private:

	double radius;	//!< Radius of Circle

	
public:

	//constructors
	Circle(void);	//default
	Circle(double inputRadius, std::string inputColour);

	//destructor
	~Circle(void);

	double GetRadius(void) const;
	void SetRadius(double inputRadius);

	void Show(void);

	double OverallDimension(void);
	double Area(void);
	double Perimeter(void);

	//overloaded + operation
	Circle operator+(const Circle& op2) const;

	//overloaded * operation
	Circle operator*(const Circle& op2) const;

	//overloaded = operation
	const Circle& operator=(const Circle& op2);

	//overloaded == operation
	bool operator==(const Circle& op2);
	bool operator==(const Circle& op2) const;

};

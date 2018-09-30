/*
*  FILE          : Circle.h
*  PROJECT       : PROG1385 - Object Oriented Programming
*  PROGRAMMER    : Brendan Rushing
*  FIRST VERSION : 2018-07-31
*  DESCRIPTION   :
*	This assignment is based on Assignment #4.
This assignment is practice using overloaded operators on classes.
*/


//INCLUDE FILES
#include "Shape.h"
//eo INCLUDE FILES




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

	double GetRadius(void);
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

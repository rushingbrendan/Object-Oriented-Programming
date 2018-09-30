/*
*  FILE          : Shape.h
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
//NAME : Square
*
//PURPOSE: Square class that uses Shape as the base
*			Square has side length, area and perimeter
*/
class Square : public Shape {

private:

	double sideLength;			//!< Side Length of Square
		

public:

	//constructors
	Square(void);
	Square(double inputSideLength, std::string inputColour);

	//destructor
	~Square(void);

	void SetSideLength(double inputSideLength);
	double GetSideLength(void);

	void Show(void);
	
	double OverallDimension(void);
	double Area(void);
	double Perimeter(void);

	//overloaded + operation
	Square operator+(const Square& op2) const;


	//overloaded * operation
	Square operator*(const Square& op2) const;

	//overloaded = operation
	const Square& operator=(const Square& op2);

	//overloaded == operation
	bool operator==(const Square& op2);
	bool operator==(const Square& op2) const;
};
/*
*  FILE          : Square.h
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
#include "CircleSquare.h"
#include "Circle.h"
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
	CircleSquare operator+(const Circle& op2) const;
	//CircleSquare operator+(Circle& op2) const;


	//overloaded * operation
	Square operator*(const Square& op2) const;

	//overloaded = operation
	const Square& operator=(const Square& op2);

	//overloaded == operation
	bool operator==(const Square& op2);
	bool operator==(const Square& op2) const;
};
/*
*  FILE          : CircleSquare.h
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
//eo INCLDUE FILES


//PRAGMA
#pragma once
//eo PRAGMA


//CONSTANTS

#define DEFAULT_VALUE 0
#define DEFAULT_COLOUR "undefined"
#define DEFAULT_NAME "Circle-Square"

//eo CONSTANTS




/*!
//NAME : CircleSquare
*
//PURPOSE: CircleSquare class that combines Circle and Square class
*/
class CircleSquare : public Shape {

private:

	double radius;				//!< Radius of Circle

	double sideLength;			//!< Side Length of Square


public:


	
	virtual ~CircleSquare(void);	//destructor

	CircleSquare(void);		//default constructor

	//constructor
	CircleSquare(std::string inputColour, double inputSideLength, double inputRadius, std::string inputName);

	double GetRadius(void);
	double GetSideLength(void);

	void SetRadius(double);
	void SetSideLength(double);

	virtual double Perimeter(void);
	virtual double Area(void);

	virtual double OverallDimension(void);

	virtual void Show(void);

	//overloaded + operator
	CircleSquare operator+(const CircleSquare& op2) const;

	//overloaded = operator
	const CircleSquare& operator=(const CircleSquare& op2);



};




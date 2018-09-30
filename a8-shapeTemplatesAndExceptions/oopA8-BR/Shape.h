/*
*  FILE          : Shape.h
*  PROJECT       : PROG1385 - Object Oriented Programming - Assignment #8*  PROGRAMMER    : Brendan Rushing
*  FIRST VERSION : 2018-08-09
*  DESCRIPTION   :
*	This assignment is based on Assignment #7
This assignment is practice using overloaded operators on classes.
Throw and Catch for exceptions is used.
Templates are also used for adding classes together.
*/


#pragma once
//INCLUDE FILES
#include <string>
#include <cstring>
#include <cstdbool>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "Shape.h"
//eo INCLUDE FILES



//CONSTANTS
const int kColourNameIsValid = 0;	//!< Colour Name is Valid Flag
const int kNameIsValid = 1;			//!< Name is Valid Flag
const int kNotValid = 2;			//!< Not Valid Flag

const double kPI = 3.1415926;		//!< Value of PI
//eo CONSTANTS



/*!
//NAME : Shape
*
//PURPOSE: base class for circle and square classes
*			Shape has a name and colour.
*/
class Shape {

protected:

	std::string name;	//!< Name of Shape

	std::string colour;	//!< Colour of Shape

	//VALIDATE INPUT
	static int ValidateInput(std::string);


public:

	Shape(std::string inputName, std::string inputColour);	//paramterized constructor
	Shape(void);	//default constructor




	//GETTERS
	std::string GetName(void) const;
	std::string GetColour(void) const;



	//SETTERS
	void SetColour(std::string inputColour);
	void SetName(std::string inputColour);

	virtual double Perimeter(void) = 0;
	virtual double Area(void) = 0;
	virtual double OverallDimension(void) = 0;

	virtual void Show(void) = 0;

	virtual ~Shape(void);

	



};


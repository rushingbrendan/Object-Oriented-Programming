/*
*  FILE          : Square.cpp
*  PROJECT       : PROG1385 - Object Oriented Programming - Assignment #8*  PROGRAMMER    : Brendan Rushing
*  FIRST VERSION : 2018-08-09
*  DESCRIPTION   :
*	This assignment is based on Assignment #7
This assignment is practice using overloaded operators on classes.
Throw and Catch for exceptions is used.
Templates are also used for adding classes together.
*/


//INCLUDE FILES
#include "Square.h"
//eo INCLUDE FILES

#pragma once
/*!
//FUNCTION : ~Square
*
//DESCRIPTION : This function is a destructor for the Square class
*
//PARAMETERS : none
*
*
//RETURNS : none
*/

Square::~Square(void) {

	printf("\n The square is squished ...");


}//eo Square::~Square(void) {





 /*!
 //FUNCTION : Square
 *
 //DESCRIPTION : This function is a default constructor for the Square class
 *
 //PARAMETERS : none
 *
 *
 //RETURNS : none
 */

Square::Square(void) {

	sideLength = 0;

	name = "Square";

	colour = "undefined";

}



/*!
//FUNCTION : Square
*
//DESCRIPTION : This function is a parameterized constructor for the Square class
*
//PARAMETERS : double inputsideLength, string inputColour
*
*
//RETURNS : none
*/

Square::Square(double inputSideLength, std::string inputColour) {

	if (inputSideLength > 0) {

		sideLength = inputSideLength;

	}//eo if (inputRadius > 0) {

	else {

		sideLength = 0;
	}

	if (ValidateInput(inputColour) == kColourNameIsValid) {

		colour = inputColour;
	}

	else {

		colour = "undefined";
	}


}//eo Square::Square(double inputSideLength, std::string inputColour) {





 /*!
 //FUNCTION : GetSideLength
 *
 //DESCRIPTION : This function returns the value for the sideLength variable
 *
 //PARAMETERS : none
 *
 *
 //RETURNS : double: sideLength
 */

double Square::GetSideLength(void) {

	return sideLength;


}//eo double Square::GetSideLength(void) {



 /*!
 //FUNCTION : SetSideLength
 *
 //DESCRIPTION : This function sets the value for the sideLength variable
 *
 //PARAMETERS : double: inputSideLength
 *
 *
 //RETURNS : none
 */

void Square::SetSideLength(double inputSideLength) {

	if (inputSideLength > 0) {

		sideLength = inputSideLength;

	}//eo 	if (inputSideLength > 0) {

	else {

		sideLength = 0;
	}


}//eo void Square::SetSideLength(double inputSideLength) {





 /*!
 //FUNCTION : Show
 *
 //DESCRIPTION : This function prints the information about the Shape information
 *
 //PARAMETERS : none
 *
 *
 //RETURNS : none
 */

void Square::Show(void) {

	double perimeter = 0;
	double area = 0;

	perimeter = Perimeter();

	area = Area();
	
	printf("\nShape Information");
	printf("\n-----------------");
	printf("\nName \t\t: %s", &name[0]);
	printf("\nColour \t\t: %s", &colour[0]);
	printf("\nSide-Length \t: %.2lf cm", sideLength);
	printf("\nPerimeter \t: %.2lf cm", perimeter);
	printf("\nArea \t\t: %.2lf square cm\n", area);


}//eo void Circle::Show(void) {




 /*!
 //FUNCTION : OverallDimension
 *
 //DESCRIPTION : This function returns the overall dimension of the square
 *
 //PARAMETERS : none
 *
 *
 //RETURNS : double
 */

double Square::OverallDimension(void) {

	double overallDimension = 0;

	overallDimension = sideLength * 4;

	return overallDimension;

}//eo double Square::OverallDimension(void) {



 /*!
 //FUNCTION : Perimeter
 *
 //DESCRIPTION : This function returns the perimeter for the shape
 *
 //PARAMETERS : none
 *
 *
 //RETURNS : double
 */

double Square::Perimeter(void) {

	double perimeter = 0;
	perimeter = 4 * sideLength;

	return perimeter;


}//eo double Square::Perimeter(void) {




 /*!
 //FUNCTION : Area
 *
 //DESCRIPTION : This function returns the area for the shape
 *
 //PARAMETERS : none
 *
 *
 //RETURNS : double
 */

double Square::Area(void) {

	double area = 0;
	area = sideLength * sideLength;


	return area;


}//eo double Square::Area(void) {





 /*!
 //FUNCTION : Square operator+(const Square& op2);
 *
 //DESCRIPTION :
 *
 //PARAMETERS : none
 *
 *
 //RETURNS : Square
 */

Square Square::operator+(const Square& op2) const {

	Square temp;
	temp.sideLength = sideLength + op2.sideLength;
	temp.colour = colour;


	return temp;


}//eo Square Square::operator+(const Square& op2) const {





 /*!
 //FUNCTION : Square operator*(const Square& op2);
 *
 //DESCRIPTION :
 *
 //PARAMETERS : none
 *
 *
 //RETURNS : Square
 */

Square Square::operator*(const Square& op2) const {

	Square temp;
	temp.sideLength = sideLength * op2.sideLength;
	temp.colour = op2.colour;

	return temp;


}//eo Square Square::operator+(const Square& op2) const {





 /*!
 //FUNCTION : overloaded = operation
 *
 //DESCRIPTION :
 *
 //PARAMETERS : none
 *
 *
 //RETURNS : Square
 */
const Square &Square::operator=(const Square& op2) {

	sideLength = op2.sideLength;

	colour = op2.colour;

	return *this;


}//eo const Square &Square::operator=(const Square& op2) {







 /*!
 //FUNCTION : overloaded == operation
 *
 //DESCRIPTION : Checks to see if the two classes are the same colour and sidelength
 *
 //PARAMETERS : none
 *
 *
 //RETURNS : Square
 */
bool Square::operator==(const Square& op2) {

	if ((this->sideLength == op2.sideLength) && (this->colour == op2.colour)) {

		return true;

	}

	else {

		return false;
	}


}//eo const Circle &Circle::operator=(const Circle& op2) {

bool Square::operator==(const Square& op2) const {

	if ((this->sideLength == op2.sideLength) && (this->colour == op2.colour)) {

		return true;

	}

	else {

		return false;
	}


}//eo const Square &Square::operator=(const Square& op2) {



 /*!
 //FUNCTION : Square operator+(const Square& op2);
 *
 //DESCRIPTION : This function adds a square to a circle to create a CircleSquare
 *
 //PARAMETERS : none
 *
 *
 //RETURNS : Square
 */

CircleSquare Square::operator+(const Circle& op2) const {


		if (sideLength >= (2 * op2.GetRadius())) {

			CircleSquare temp(colour, sideLength, op2.GetRadius(), "Square-Circle");

			return temp;  

		}

		else {


			throw("\nError - The sideLength is less than 2 x Radius");
		}

	

}//eo Square Square::operator+(const Square& op2) const {





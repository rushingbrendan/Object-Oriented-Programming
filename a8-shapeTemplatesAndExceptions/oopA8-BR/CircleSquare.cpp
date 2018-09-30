/*
*  FILE          : CircleSquare.cpp
*  PROJECT       : PROG1385 - Object Oriented Programming - Assignment #8
*  PROGRAMMER    : Brendan Rushing
*  FIRST VERSION : 2018-08-09
*  DESCRIPTION   :
*	This assignment is based on Assignment #7
This assignment is practice using overloaded operators on classes.
Throw and Catch for exceptions is used.
Templates are also used for adding classes together.
*/



//INCLUDE FILES
#include "CircleSquare.h"
//eo INCLUDE FILES



/*!
//FUNCTION : ~CircleSquare
*
//DESCRIPTION : This function is a destructor for the CircleSquare class
*
//PARAMETERS : none
*
*
//RETURNS : none
*/

CircleSquare:: ~CircleSquare(void) {

	printf("\nClosing the Circle-Square Ranch ...");

}//eo CircleSquare:: ~CircleSquare(void) {



 /*!
 //FUNCTION : CircleSquare
 *
 //DESCRIPTION : This function is a default constructor for the CircleSquare class
 *
 //PARAMETERS : none
 *
 *
 //RETURNS : none
 */

CircleSquare::CircleSquare(void) {

	sideLength = DEFAULT_VALUE;

	radius = DEFAULT_VALUE;

	name = DEFAULT_NAME;

	colour = DEFAULT_COLOUR;
	
	
}//eo CircleSquare::CircleSquare(void) {



 /*!
 //FUNCTION : CircleSquare
 *
 //DESCRIPTION : This function is a parameterized constructor for the CircleSquare class
 *
 //PARAMETERS : std::string inputColour, double inputSideLength, double inputRadius, std::string inputName
 *
 *
 //RETURNS : none
 */

CircleSquare::CircleSquare(std::string inputColour, double inputSideLength, double inputRadius, std::string inputName) {

	if (inputRadius >= 0) {

		radius = inputRadius;

	}

	//verify that sidelength is greater than 0 and twice as big as the radius
	if ((inputSideLength >= 0) && (inputSideLength >= (2 * inputRadius))){

		sideLength = inputSideLength;

	}

	else {

		//set the sideLength to 1.5 times the diameter of the circle
		sideLength = (1.5 * (2 * inputRadius));
	}

	if ((inputName == "Square-Circle") || (inputName == "Circle-Square")){

		name = inputName;

	}

	if (Shape::ValidateInput(inputColour)) {

		colour = inputColour;
	}

}





 /*!
 //FUNCTION : GetRadius
 *
 //DESCRIPTION : This function returns the value of the radius variable
 *
 //PARAMETERS : none
 *
 *
 //RETURNS : double: radius
 */

double CircleSquare::GetRadius(void) {

	return radius;

}//eo CircleSquare::GetRadius(void) {



 /*!
 //FUNCTION : GetSideLength
 *
 //DESCRIPTION : This function returns the value of the sideLength variable
 *
 //PARAMETERS : none
 *
 *
 //RETURNS : double: sideLength
 */

double CircleSquare::GetSideLength(void) {

	return sideLength;

}//eo double CircleSquare::GetSideLength(void) {



 /*!
 //FUNCTION : SetRadius
 *
 //DESCRIPTION : This function sets the value of the radius variable
 *
 //PARAMETERS : double inputRadius
 *
 *
 //RETURNS : none
 */

void CircleSquare::SetRadius(double inputRadius) {

	if (inputRadius >= 0) {

		radius = inputRadius;

	}


}//eo void CircleSquare::SetRadius(double inputRadius) {



 /*!
 //FUNCTION : SetSideLength
 *
 //DESCRIPTION : This function sets the value of the sideLength variable
 *
 //PARAMETERS : double inputSideLength
 *
 *
 //RETURNS : none
 */

void CircleSquare::SetSideLength(double inputSideLength) {

	if (inputSideLength >= 0) {

		sideLength = inputSideLength;

	}

}//eo void CircleSquare::SetSideLength(double inputSideLength) {



 /*!
 //FUNCTION : Perimeter
 *
 //DESCRIPTION : This function returns the Perimeter for the circleSquare or the SquareCircle
 *
 //PARAMETERS : none
 *
 *
 //RETURNS : double: Perimeter
 */

double CircleSquare::Perimeter(void) {
	
	double perimeter = 0;

	if (name == "Circle-Square") {

		//Formula is for circle
		perimeter = 2 * radius * kPI;
		
	}

	else if (name == "Square-Circle") {

		//Formula is for square
		perimeter = 4 * sideLength;
		
	}

	return perimeter;

}


/*!
//FUNCTION : Area
*
//DESCRIPTION : This function returns the value of the Area for the SquareCircle or CircleSquare
*
//PARAMETERS : none
*
*
//RETURNS : double: Area
*/

double CircleSquare::Area(void) {

double area = 0;

if (name == "Circle-Square") {

	//Formula is for circle
	area = kPI * radius * radius;

}

else if (name == "Square-Circle") {

	//Formula is for square
	area = sideLength * sideLength;
	
}

return area;

}



/*!
//FUNCTION : OverallDimension
*
//DESCRIPTION : This function returns the overall dimension 
*
//PARAMETERS : none
*
*
//RETURNS : double: Area
*/

double CircleSquare::OverallDimension(void) {

	double overallDimension = 0;

	if (name == "Circle-Square") {

		//Formula is for circle
		overallDimension = 2 * radius;

	}

	else if (name == "Square-Circle") {

		//Formula is for square
		overallDimension = sideLength * 4;

	}

	return overallDimension;

}




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

void CircleSquare::Show(void) {

	double circumference = 0;
	double area = 0;

	circumference = OverallDimension();
	area = Area();


	printf("\nShape Information");
	printf("\n-----------------");
	printf("\nName \t\t: %s", &name[0]);
	printf("\nColour \t\t: %s", &colour[0]);

	if (name == "Circle-Square") {

		printf("\nCircle");
		printf("\n------");
		printf("\n  Radius \t: %.2lf", radius);
		printf("\n  Circumference : %.2lf cm", circumference);
		printf("\n  Area \t\t: %.2lf square cm\n", Area());
		printf("\nContained Square");
		printf("\n----------------");
		printf("\n  Side-Length \t: %.2lf cm", sideLength);
		printf("\n  Perimeter \t: %.2lf cm", (4*sideLength));
		printf("\n  Area \t\t: %.2lf square cm\n", (sideLength*sideLength));

	}

	else if (name == "Square- Circle") {

		printf("\nSquare");
		printf("\n------");
		printf("\n  Side-Length \t: %.2lf cm", sideLength);
		printf("\n  Perimeter \t: %.2lf cm", Perimeter());
		printf("\n  Area \t\t: %.2lf square cm\n", Area());
		printf("\nContained Circle");
		printf("\n----------------");
		printf("\n  Radius \t: %.2lf", radius);
		printf("\n  Circumference : %.2lf cm", circumference);
		printf("\n  Area \t\t: %.2lf square cm\n", Area());

	}
}





/*!
//FUNCTION : CircleSquare operator+(const CircleSquare& op2)
*
//DESCRIPTION : This function adds two classes together
*
//PARAMETERS : none
*
*
//RETURNS : none
*/

CircleSquare CircleSquare::operator+(const CircleSquare& op2) const {

	CircleSquare temp;

	temp.radius = radius + op2.radius;
	temp.sideLength = sideLength + op2.sideLength;


	return temp;

}



/*!
//FUNCTION : CircleSquare operator=(const CircleSquare& op2)
*
//DESCRIPTION : This function makes one class equal to another
*
//PARAMETERS : none
*
*
//RETURNS : none
*/

const CircleSquare &CircleSquare::operator=(const CircleSquare& op2) {

	radius = op2.radius;

	sideLength = op2.sideLength;

	colour = op2.colour;

	return *this;

}




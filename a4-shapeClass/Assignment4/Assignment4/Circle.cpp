#include "Circle.h"

/*!
//FUNCTION : ~Circle
*
//DESCRIPTION : This function is a destructor for the Circle class
*
//PARAMETERS : none
*
*
//RETURNS : none
*/

Circle::~Circle(void) {

	printf("\n The circle is broken ...");
	

}//eo Circle::~Circle(void) {





/*!
//FUNCTION : Circle
*
//DESCRIPTION : This function is a default constructor for the Circle class
*
//PARAMETERS : none
*
*
//RETURNS : none
*/

Circle::Circle(void) {

	radius = 0;

	name = "Circle";

	colour = "undefined";



}//eo Circle::Circle(void) {




/*!
//FUNCTION : Circle
*
//DESCRIPTION : This function is a parameterized constructor for the Circle class
*
//PARAMETERS : double inputRadius, string inputColour
*
*
//RETURNS : none
*/

Circle::Circle(double inputRadius, std::string inputColour) {

	if (inputRadius > 0) {

		radius = inputRadius;

	}//eo if (inputRadius > 0) {

	else {

		radius = 0;
	}

	if (ValidateInput(inputColour) == kColourNameIsValid) {

		colour = inputColour;
	}

	else {

		colour = "undefined";
	}

	
}//eo Circle::Circle(double inputRadius, std::string inputColour) {


 /*!
 //FUNCTION : GetRadius
 *
 //DESCRIPTION : This function returns the value for the radius variable
 *
 //PARAMETERS : none
 *
 *
 //RETURNS : double: radius
 */

double Circle::GetRadius(void) {

	return radius;


}//eo double Circle::GetRadius(void) {



 /*!
 //FUNCTION : SetRadius
 *
 //DESCRIPTION : This function sets the value for the radius variable
 *
 //PARAMETERS : double: inputRadius
 *
 *
 //RETURNS : none
 */

void Circle::SetRadius(double inputRadius) {

	if (inputRadius > 0) {

		radius = inputRadius;

	}//eo if (inputRadius > 0) {

	else {

		radius = 0;
	}


}//eo void Circle::SetRadius(double inputRadius) {




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

void Circle::Show(void) {

	double circumference = 0;
	double area = 0;

	circumference = Perimeter();
	area = Area();


	printf("\nShape Information");
	printf("\n-----------------");
	printf("\nName \t\t: %s", &name[0]);
	printf("\nColour \t\t: %s", &colour[0]);
	printf("\nRadius \t\t: %.2lf", radius);
	printf("\nCircumference \t: %.2lf cm", circumference);
	printf("\nArea \t\t: %.2lf square cm\n", area);

	
}//eo void Circle::Show(void) {



 /*!
 //FUNCTION : OverallDimension
 *
 //DESCRIPTION : This function returns the overall dimension of the circle
 *
 //PARAMETERS : none
 *
 *
 //RETURNS : double
 */

double Circle::OverallDimension(void) {

	double overallDimension = 0;

	overallDimension = 2 * radius;

	return overallDimension;


}//eo double Circle::OverallDimension(void) {




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

double Circle::Perimeter(void) {

	double perimeter = 0;
	perimeter = 2 * radius * kPI;

	return perimeter;


}//eo double Circle::Perimeter(void) {




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

double Circle::Area(void) {

	double area = 0;
	area = kPI * radius * radius;

	return area;


}//eo double Circle::Area(void) {
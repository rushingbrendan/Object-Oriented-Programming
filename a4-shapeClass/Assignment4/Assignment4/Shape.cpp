

//INCLUDE FILES
#include "Shape.h"

//eo INCLUDE FILES



/*!
// FUNCTION : Shape

// DESCRIPTION : This function is a destructor for shape class

// PARAMETERS : none

// RETURNS : none
*/
Shape::~Shape(void) {


}//eo ~Shape::Shape(void) {


/*!
// FUNCTION : Shape

// DESCRIPTION : This function is a default constructor for shape class

// PARAMETERS : none

// RETURNS : none
*/
Shape::Shape(void) {

	name = "Unknown";

	colour = "undefined";
	
}//eo Shape::Shape(void) {

 /*!
 //FUNCTION : Shape
 *
 //DESCRIPTION : This function is a parameterized constructor for the Shape class
 *
 //PARAMETERS : string inputName, string inputColour
 *
 *
 //RETURNS : none
 */

int Shape::ValidateInput(std::string input) {

	if ((input == "red") || (input == "green") ||
		(input == "blue") || (input == "yellow") ||
		(input == "purple") || (input == "pink") ||
		(input == "orange") || (input == "undefined")) {

		return kColourNameIsValid;

	}//eo if colour

	else if ((input == "Circle") || (input == "Square") || (input == "Unknown")) {

		return kNameIsValid;

	}//eo if name

	else {

		return kNotValid;

	}



}//eo int Shape::ValidateInput(std::string) {



 /*!
 //FUNCTION : Shape
 *
 //DESCRIPTION : This function is a parameterized constructor for the Shape class
 *
 //PARAMETERS : string inputName, string inputColour
 *
 *
 //RETURNS : none
 */
Shape::Shape(std::string inputName, std::string inputColour) {

	if (ValidateInput(inputColour) == kColourNameIsValid) {

		colour = inputColour;
	}

	if (ValidateInput(inputName) == kNameIsValid) {

		name = inputName;
	}



}//eo Shape::Shape(std::string inputName, std::string inputColour) {




 /*!
 //FUNCTION : GetName
 *
 //DESCRIPTION : This function returns the name variable for the shape class
 *
 //PARAMETERS : none
 *
 *
 //RETURNS : string: name
 */

std::string Shape:: GetName(void) const {

	return name;
	
}//eo Shape::getName(void) {



 /*!
 //FUNCTION : GetColour
 *
 //DESCRIPTION : This function returns the colour variable for the shape class
 *
 //PARAMETERS : none
 *
 *
 //RETURNS : string: colour
 */

std::string Shape::GetColour(void) const {

	return colour;

}//eo Shape::getName(void) {




 /*!
 //FUNCTION : SetColour
 *
 //DESCRIPTION : This function sets the colour variable for the shape class
 *
 //PARAMETERS : std::string inputColour
 *
 *
 //RETURNS : none
 */

void Shape::SetColour(std::string inputColour) {

	if (ValidateInput(inputColour) == kColourNameIsValid) {

		colour = inputColour;
	}


	
}//eo void Shape::SetColour(std::string inputColour) {




 /*!
 //FUNCTION : SetName
 *
 //DESCRIPTION : This function sets the name variable for the shape class
 *
 //PARAMETERS : std::string inputName
 *
 *
 //RETURNS : none
 */

void Shape::SetName(std::string inputName) {


	if (ValidateInput(inputName) == kNameIsValid) {

		name = inputName;
	}
	
}//eo void Shape::SetName(std::string inputName) {
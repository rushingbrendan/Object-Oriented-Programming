

//#include "Shape.h"
#include "Circle.h"
#include "Square.h"



int main(void) {

	std::string inputBuffer = { 0 };
	std::string inputColour = { 0 };
	double inputRadius = 0;
	Shape* mySquare = NULL;
	Shape* myCircle = NULL;


	printf("\nEnter details for Circle object:");
	printf("\n--------------------------------");
	printf("\nEnter Shapes Colour (red, green, blue, yellow, purple, pink, orange, undefined) : ");

	std::getline(std::cin, inputBuffer);
	inputColour = inputBuffer;

	printf("\nEnter Radius: ");
	std::getline(std::cin, inputBuffer);
	inputRadius = atof(&inputBuffer[0]);

	myCircle= new Circle(inputRadius, inputColour);

	myCircle->Show();


	printf("\nEnter details for Square object:");
	printf("\n--------------------------------");
	printf("\nEnter Shapes Colour (red, green, blue, yellow, purple, pink, orange, undefined) : ");

	std::getline(std::cin, inputBuffer);
	inputColour = inputBuffer;

	printf("\nEnter Side-Length: ");
	std::getline(std::cin, inputBuffer);
	inputRadius = atof(&inputBuffer[0]);

	mySquare = new Square(inputRadius, inputColour);

	mySquare->Show();


	delete(myCircle);
	delete(mySquare);
	
	

	return EXIT_SUCCESS;

}
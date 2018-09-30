/*
*  FILE          : myShape.cpp
*  PROJECT       : PROG1385 - Object Oriented Programming - Assignment #8*  PROGRAMMER    : Brendan Rushing
*  FIRST VERSION : 2018-08-09
*  DESCRIPTION   :
*	This assignment is based on Assignment #7
This assignment is practice using overloaded operators on classes.
Throw and Catch for exceptions is used.
Templates are also used for adding classes together.
*/



//INCLUDE FILES
#include "Circle.h"
#include "Square.h"
//eo INCLUDE FILES


template <class oneClass, class twoClass, class threeClass>  threeClass CombineDifferentShape(oneClass& a, twoClass& b)
{
	threeClass temp;
	temp = a + b;

	return temp;
	
}


template <class oneClass>   oneClass CombineShape(oneClass& a, oneClass& b)
{
	oneClass temp;

	temp = a + b;

	return temp;

}


int main(void) {

	bool operatorSuccess = false;

	//CREATE CircleSquare
	CircleSquare playARoundSquare;

	//CREATE Circles
	Circle round1(5.5, "red");
	Circle round2(10.5, "blue");
	Circle playARound;


	//CREATE Squares
	Square square1(5, "orange");
	Square square2(12, "purple");
	Square playASquare;

	//PRINT OUT ALL SHAPES
	round1.Show();
	round2.Show();
	playARound.Show();
	square1.Show();
	square2.Show();
	playASquare.Show();


	//add round1 and round2 into playARound
	playARound = round1 + round2;

	//add square2 and square1 into playAsquare
	playASquare = CombineShape<Square>(square2, square1);



	//PRINT OUT playARound and playASquare
	playARound.Show();
	playASquare.Show();



	//multiply round1 by round2 into playARound
	playARound = round1 * round2;

	//multiply square2 by square1 into playASquare
	playASquare = square2 * square1;

	//PRINT OUT playARound and playASquare
	playARound.Show();
	playASquare.Show();




	//Assign round1 to playAround and see if they are equal
	playARound = round1;

	if (playARound == round1) {

		printf("\nHurray !!");
	}

	else {

		printf("\nAwww !!");
	}


	//ASSIGNMENT #8 TEST HARNESS



	try {

		//Call CombineDifferentShape() template with square2 and round1 to produce playAroundSquare
		playARoundSquare = CombineDifferentShape<Square, Circle, CircleSquare>(square2, round1);
	}

	catch (...) {

		std::cout << "Square sideLength is too small to go around circle" << std::endl;

	}

	playARoundSquare.Show();


	try {

		//Call CombineDifferentShape() template with square2 and round1 to produce playAroundSquare
		playARoundSquare = CombineDifferentShape<Square, Circle, CircleSquare>(square1, round2);
	}

	catch (...) {

		std::cout <<"\nError - The sideLength is less than 2 x Radius" << std::endl;
		operatorSuccess = false;

		}


	if (operatorSuccess) {

		playARoundSquare.Show();

	}
	



	return EXIT_SUCCESS;

}
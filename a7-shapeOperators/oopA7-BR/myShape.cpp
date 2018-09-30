/*
*  FILE          : myShape.cpp
*  PROJECT       : PROG1385 - Object Oriented Programming
*  PROGRAMMER    : Brendan Rushing
*  FIRST VERSION : 2018-07-31
*  DESCRIPTION   :
*	This assignment is based on Assignment #4.
	This assignment is practice using overloaded operators on classes.
*/



//INCLUDE FILES
#include "Circle.h"
#include "Square.h"
//eo INCLUDE FILES




int main(void) {


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
		
	//add square2 and square1 into playASquare
	playASquare = square2 + square1;

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


	
	

	return EXIT_SUCCESS;

}
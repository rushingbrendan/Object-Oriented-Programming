/*  
*  FILE          : testDisneyCharacter.cpp
*  PROJECT       : PROG1385 - Object Oriented Programming Assignment #2
*  PROGRAMMER    : Brendan Rushing
*  FIRST VERSION : 2018-06-06
*  DESCRIPTION   : 
*	This assignment creates a DisneyCharacter class, manipulates the values and has a test harness
*/


//INCLUDE FILES

#include "DisneyCharacter.h"


//EO INCLUDE FILES

//CONSTANTS


#pragma warning(disable:4996)

//EO CONSTANTS



int main(int argc, char *argv[]) {


	DisneyCharacter Mickey("Mickey", "1929-01-01", 100, MAGIC_KINGDOM);
	DisneyCharacter Minnie("Minnie", "1930-01-01");

	if(!Mickey.sameMovies(Minnie)){

		std::cout << "ERROR" << std::endl;

	}//eo if (!Mickey.sameMovies(Minnie)

	Mickey.showInfo();
	Minnie.showInfo();


	if(!Minnie.placeCharacter(EPCOT)){

		std::cout << "ERROR" << std::endl;

	}//eo if (!Minnie.placeCharacter(EPCOT)){
	
	return EXIT_SUCCESS;

}// eo int main(int argc, char *argv[])

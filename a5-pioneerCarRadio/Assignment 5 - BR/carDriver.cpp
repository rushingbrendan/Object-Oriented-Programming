/*
*  FILE          : carDriver.cpp
*  PROJECT       : PROG1385 - Object Oriented Programming Assignment #5
*  PROGRAMMER    : Brendan Rushing
*  FIRST VERSION : 2018-07-19
*  DESCRIPTION   :
*	This assignment modifys assignment #3 to use inheritance.
	Create PioneerCarRadio class with upgraded features.
	Match display output as specified.
*/


//INCLUDE FILES
#include "PioneerCarRadio.h"
//eo INCLUDE FILES



int main(void) {

	PioneerCarRadio* myPioneerRadio = NULL;

	//default values for PioneerCarRadio 
	struct Freqs PioneerPresets[RADIO_PRESETS]{ {1000, 102.1}, {1210, 104.3}, {800, 100.1}, {700,99.3}, {1300,89.7} };

	//create class
	myPioneerRadio = new PioneerCarRadio(false, PioneerPresets);



	if (myPioneerRadio->RadioControl() == EXIT_SUCCESS) {

		delete(myPioneerRadio);		
		return EXIT_SUCCESS;
	}

	else {
		delete(myPioneerRadio);
		return EXIT_FAILURE;
	}
	


}//eo main
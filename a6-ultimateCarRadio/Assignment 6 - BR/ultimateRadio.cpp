/*
*  FILE          : ultimateRadio.cpp
*  PROJECT       : PROG1385 - Object Oriented Programming Assignment #6
*  PROGRAMMER    : Brendan Rushing
*  FIRST VERSION : 2018-07-24
*  DESCRIPTION   :
*	This assignment modifys assignment #5 to use more inheritance.
Create PioneerAM based on PioneerRadio
Create PioneerWorld based on PioneerAM
Match display output as specified.
Use try and catch in the test harness. Print error codes and end program.
*/


//INCLUDE FILES
#include "PioneerCarRadio.h"
#include "PioneerAM.h"
#include "PioneerWorld.h"

#include <new>
//eo INCLUDE FILES



//CONSTANTS
#define EXIT_PROGRAM 'x'

#define NEW_PIONEER_CAR_RADIO	'c'
#define NEW_PIONEER_AM			'a'	
#define NEW_PIONEER_WORLD		'w'

//eo CONSTANTS



//PARAMATERS
PioneerCarRadio* createRadio(std::string inputRadio);
//eo PARAMETERS




int main(int argc, char* argv[]) {


	std::string inputBuffer = { 0 };
	int pRadioRetCode = 0;
	bool testHarnessCompleted = false;
	bool userInputIsNotValid = false;

	//copy cArray into C++ string
	inputBuffer = argv[1];

	
	while (!testHarnessCompleted) {

		PioneerCarRadio* pRadio = NULL;
		char userInput = 0;

		try {

		//1. Create Radio based on user input in command line
			userInputIsNotValid = false;
			pRadio = createRadio(inputBuffer);

		}//eo try

		//catch switch error
		catch (const char* msg) {
			std::cerr << msg << std::endl;
			return EXIT_FAILURE;
		}//eo catch


		//catch out-of-memory error
		catch (std::bad_alloc& ) {
			std::cerr << "\nOut of memory!" << std::endl;
			return EXIT_FAILURE;
		}


		//2. Run Radio Control Interface
		pRadio->RadioControl();

		delete(pRadio);

		#ifdef __linux__ 
		system("clear");
		#elif _WIN32
		system("cls");		//clear the screen
		#endif


		while (!userInputIsNotValid) {

		//3. Get user input
			userInput = getch();


		//4. Loop (end program or create new class)
			switch (userInput) {

			case EXIT_PROGRAM:
				testHarnessCompleted = true;
				userInputIsNotValid = true;
				break;

			case NEW_PIONEER_CAR_RADIO:
				inputBuffer = "-car";
				userInputIsNotValid = true;
				break;

			case NEW_PIONEER_AM:
				inputBuffer = "-am";
				userInputIsNotValid = true;
				break;

			case NEW_PIONEER_WORLD:
				inputBuffer = "-world";
				userInputIsNotValid = true;
				break;

			default:
				userInputIsNotValid = false;
				break;

			}//eo switch

		}
		
	}//eo while (!testHarnessCompleted) {

	
	
	return EXIT_SUCCESS;


}//eo main






 /*
 * FUNCTION : createRadio
 *
 * DESCRIPTION : This function creates a radio based on the input selection.
					-car = PioneerCarRadio Object
					-am	 = PioneerAM Object
					-world = PioneerWorld Object
					else, throw exception
 *
 * PARAMETERS : string: inputRadio
 *
 *
 * RETURNS : PioneerCarRadio*
 */
PioneerCarRadio* createRadio (std::string inputRadio){

	struct Freqs PioneerPresets[RADIO_PRESETS]{ { 1000, 102.1 },{ 1210, 104.3 },{ 800, 100.1 },{ 700,99.3 },{ 1300,89.7 } };
	PioneerCarRadio* pRadio = NULL;

	if (inputRadio.compare("-am") == 0) {

		pRadio = new PioneerAM(false, PioneerPresets, PIONEER_XS440_AM);
		return pRadio;
	}

	else if (inputRadio.compare("-car") == 0) {

		pRadio = new PioneerCarRadio(false, PioneerPresets, PIONEER_XS440);
		return pRadio;
	}

	else if (inputRadio.compare("-world")== 0) {

		pRadio = new PioneerWorld(false, PioneerPresets, PIONEER_XS440_WRLD);
		return pRadio;
	}

	else {

		throw "INVALID SWITCH ENTERED!";

	}

	return NULL;


}//eo PioneerCarRadio* createRadio (std::string inputRadio){
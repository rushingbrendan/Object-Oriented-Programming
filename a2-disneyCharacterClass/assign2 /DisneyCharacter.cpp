/*  
*  FILE          : DisneyCharacter.cpp
*  PROJECT       : PROG1385 - Object Oriented Programming Assignment #2
*  PROGRAMMER    : Brendan Rushing
*  FIRST VERSION : 2018-06-06
*  DESCRIPTION   : 
*	This assignment creates a DisneyCharacter class, manipulates the values and has a test harness
*/





#pragma warning(disable:4996)
//INCLUDE FILES
#include "DisneyCharacter.h"





 /*
 * FUNCTION : DisneyCharacter::DisneyCharacter
 *
 * DESCRIPTION : This function is a parameterized constructor for the DisneyCharacter class that
 *	takes the name and date. numMovies is set to 0 and whichpark is set to NOT_PLACED
 *
 * PARAMETERS : std::string inputName, std::string inputDate
 *		
 *
 * RETURNS : none
 */
DisneyCharacter::DisneyCharacter(std::string inputName, std::string inputDate)
{

	int dataTest = 0;
	char* cPtr = NULL;
	char* cPtr2 = NULL;
	int dateSuccess = SUCCESS;


	//set character name
	//make sure string length is less than 50 chars
	if (inputName.size() > 50) {

		inputName.resize(50);
		char* cPtr = &inputName[46];
		strcpy(cPtr, " ...");

	}//eo 	if (inputName.size() > 50) {

	name = inputName;

	//set date
	//format 2018-02-30
	//YEAR-DAY-MONTH
	
	cPtr = &inputDate[0];
	dataTest = atoi(&inputDate[0]);

	if ((dataTest < 0) || (dataTest > 2018)) {

		dateSuccess = FAIL;
	}

	cPtr = strchr(&inputDate[0], '-');
	cPtr++;
	dataTest = atoi(cPtr);

	if ((dataTest < 0) || (dataTest > 12)) {

		dateSuccess = FAIL;
	}

	cPtr2 = strchr(cPtr, '-');
	cPtr2++;
	dataTest = atoi(cPtr2);

	if ((dataTest < 0) || (dataTest > 31)) {

		dateSuccess = FAIL;
	}

	if (dateSuccess == SUCCESS) {

		creationDate = inputDate;

	}//eo if (dateSuccess == SUCCESS) {
	

	
	numMovies = 0;
	whichPark = NOT_PLACED;

}//eo parameterized constructor



 /*
 * FUNCTION : DisneyCharacter::DisneyCharacter
 *
 * DESCRIPTION : This function is a parameterized construtor for the DisneyCharacter class that
 *	takes the name, date numMovies and whichPark
 *
 * PARAMETERS : std::string inputName, std::string inputDate, int inputNumMovies, char inputWhichPark
 *		
 *
 * RETURNS : none
 */
DisneyCharacter::DisneyCharacter(std::string inputName, std::string inputDate, int inputNumMovies, char inputWhichPark) {


	int dataTest = 0;
	char* cPtr = NULL;
	char* cPtr2 = NULL;
	int dateSuccess = SUCCESS;


	//set character name
	//make sure string length is less than 50 chars
	if (inputName.size() > 50) {

		inputName.resize(50);
		char* cPtr = &inputName[46];
		strcpy(cPtr, " ...");

	}//eo 	if (inputName.size() > 50) {

	name = inputName;

	//set date
	//format 2018-02-30
	//YEAR-DAY-MONTH

	cPtr = &inputDate[0];
	dataTest = atoi(&inputDate[0]);

	if ((dataTest < 0) || (dataTest > 2018)) {

		dateSuccess = FAIL;
	}

	cPtr = strchr(&inputDate[0], '-');
	cPtr++;
	dataTest = atoi(cPtr);

	if ((dataTest < 0) || (dataTest > 12)) {

		dateSuccess = FAIL;
	}

	cPtr2 = strchr(cPtr, '-');
	cPtr2++;
	dataTest = atoi(cPtr2);

	if ((dataTest < 0) || (dataTest > 31)) {

		dateSuccess = FAIL;
	}

	if (dateSuccess == SUCCESS) {

		creationDate = inputDate;

	}//eo if (dateSuccess == SUCCESS) {


	if ((inputNumMovies >= 0) && (inputNumMovies < INT_MAX)) {

		numMovies = inputNumMovies;

		}//eo if

	else {

		numMovies = 0;

	}//eo else


	if ((inputWhichPark == MAGIC_KINGDOM) || (inputWhichPark == DISNEY_STUDIO) || (inputWhichPark == ANIMAL_KINGDOM)
		|| (inputWhichPark == EPCOT) || (inputWhichPark == CALIFORNIA_ADVENTURE) || (inputWhichPark == NOT_PLACED)) {

		whichPark = inputWhichPark;

	}//eo if


	else {

		whichPark = NOT_PLACED;

	}//eo else




}//eo parameterized constructor





/*
 * FUNCTION : DisneyCharacter::DisneyCharacter
 *
 * DESCRIPTION : This function is a deconstrutor for the DisneyCharacter class. It prints the name of 
 * the class that is destroyed when the program is done running.
 *
 * PARAMETERS : none
 *		
 *
 * RETURNS : none
 */
DisneyCharacter::~DisneyCharacter(void) {

	std::cout << name << " destroyed" << std::endl;

}//eo DisneyCharacter::~DisneyCharacter(void) {


//***************************************************************************************************
//GET FUNCTIONS**************************************************************************************

/*
 * FUNCTION : getWhichPark
 *
 * DESCRIPTION : This function gets the value for whichPark variable for the DisneyCharacter Class and
 * and returns it.
 *
 * PARAMETERS : none
 *		
 *
 * RETURNS : char: whichPark
 */
char DisneyCharacter::getWhichPark(void) {

	return whichPark;

}//eo char DisneyCharacter::getWhichPark(void) {



/*
 * FUNCTION : getName
 *
 * DESCRIPTION : This function gets the value for name variable for the DisneyCharacter Class and
 * and returns it.
 *
 * PARAMETERS : none
 *		
 *
 * RETURNS : std::string name
 */
std::string DisneyCharacter::getName(void) {

	return name;

}//std::string getName(void) {



/*
 * FUNCTION : getCreationDate
 *
 * DESCRIPTION : This function gets the value for date variable for the DisneyCharacter Class and
 * and returns it.
 *
 * PARAMETERS : none
 *		
 *
 * RETURNS : std::string date
 */
std::string DisneyCharacter::getCreationDate(void) {

	return creationDate;

}//eo std::string DisneyCharacter::getCreationDate(void) {



/*
 * FUNCTION : getNumMovies
 *
 * DESCRIPTION : This function gets the value for numMovies variable for the DisneyCharacter Class and
 * and returns it.
 *
 * PARAMETERS : none
 *		
 *
 * RETURNS : int: numMovies
 */
int DisneyCharacter::getNumMovies(void) {

	return numMovies;

}//eo int DisneyCharacter::getNumMovies(void) {



//EO GET FUNCTIONS***********************************************************************************
//***************************************************************************************************





//***************************************************************************************************
//SET FUNCTIONS**************************************************************************************



/*
 * FUNCTION : setNumMovies
 *
 * DESCRIPTION : This function sets the number of movies for the DisneyCharacter class
 *
 * PARAMETERS : int inputData
 *		
 *
 * RETURNS : bool: true or false
 */
bool DisneyCharacter::setNumMovies(int inputData) {

	if ((inputData >= 0) || (inputData < INT_MAX)){

		numMovies = inputData;
		return true;

	}//eo if


	return false;



}//eo bool DisneyCharacter::setNumMovies(int inputData) {




/*
 * FUNCTION : setWhichPark
 *
 * DESCRIPTION : This function sets the park that the character for the DisneyCharacter class
 * 	belongs to.
 * PARAMETERS : char inputData
 *		
 *
 * RETURNS : bool: true or false
 */
bool DisneyCharacter::setWhichPark(char inputData) {

	if ((inputData == MAGIC_KINGDOM) || (inputData == DISNEY_STUDIO) || (inputData == ANIMAL_KINGDOM)
		|| (inputData == EPCOT) || (inputData == CALIFORNIA_ADVENTURE) || (inputData == NOT_PLACED)) {

		whichPark = inputData;
		return true;

	}//eo if

	return false;

}//eo bool DisneyCharacter::setWhichPark(char inputData) {


//EO SET FUNCTIONS***********************************************************************************
//***************************************************************************************************





/*
 * FUNCTION : showInfo
 *
 * DESCRIPTION : This function prints all information for the DisneyCharacter class to the screen
 * 
 * PARAMETERS : none
 *		
 *
 * RETURNS : none
 */
void DisneyCharacter::showInfo(void) {


	std::cout << "Class information for \" DisneyCharacter\" Class" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << "Creation Date: " << std::left << creationDate << std::endl;
	std::cout << "Number of Movies: " << std::left << numMovies << std::endl;
	std::cout << "Which Park: " << std::left << whichPark << std::endl;
	std::cout << std::endl;

}//eo void showInfo(void) {




/*
 * FUNCTION : sameMovies
 *
 * DESCRIPTION : This function copies the numMovies variable from one DisneyCharacter
 * 	class and sets it to the same as another one.
 * 
 * PARAMETERS : char inputData
 *		
 *
 * RETURNS : bool: true or false
 */
bool DisneyCharacter::sameMovies(DisneyCharacter& anotherCharacter) {

	anotherCharacter.setNumMovies(numMovies);
	
	return true;

	
}//eo bool sameMovies(DisneyCharacter One, DisneyCharacter Two) {





/*
 * FUNCTION : placeCharacter
 *
 * DESCRIPTION : This function sets the park that the character for the DisneyCharacter class
 * 	belongs to.
 * PARAMETERS : char inputData
 *		
 *
 * RETURNS : bool: true or false
 */
bool DisneyCharacter::placeCharacter(char inputPark) {

	if (DisneyCharacter::setWhichPark(inputPark) == true){

	return true;

	}//eo 	if (DisneyCharacter::setWhichPark(inputPark) == true){

	return false;
	
}//eo bool DisneyCharacter::placeCharacter(char inputPark) {
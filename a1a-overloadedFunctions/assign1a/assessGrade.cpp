/*
* FILE : assessGrade.cpp
* PROJECT : PROG1385 - Object Oriented Programming
* PROGRAMMER : Brendan Rushing
* FIRST VERSION : 2018-05-22
* DESCRIPTION :
Program uses overloaded functions to assess individual student grades.
It takes a string that is in one of 4 forms:
1)	a single numerical grade as a floating point number that represents the student's final mark
(ranging from 0.0 to 100.0)
2)	a letter grade that is one of the following: A+, A, B+, B, C+, C, D, F, I, Q, AU, DNA, I/P – again
that represents the student’s final grade
3)	from one to five numerical grades that are integers that represent the student's mark on each
of five assignments worth 20% each, separated by spaces (the marks range from 0 to 100).

4)	a single character, 'X', that indicates that the user wants to exit the program

*
*/



//INCLUDE FILES
#include "assessGrade.h"
#include <iomanip>
//eo INCLUDE FILES


//CONSTANTS
#define SPECIAL_SITUATION -1
#define INVALID_ENTRY -2


#pragma warning(disable: 4996)

//eo CONSTANTS




/*
* FUNCTION : assessGradeParser(std::string &inputString)
*
* DESCRIPTION : This function is a worker bee function that parses the user input
*	and then uses assessGrade function to calculate final grade

*
* PARAMETERS : std::string &inputString
* RETURNS : int: EXIT_SUCCESS OR EXIT_FAILURE
*/

int assessGradeParser(std::string &inputString) {

	char* cPtr = NULL;
	char* cPtrPeriod = NULL;
	char* cPtrNegative = NULL;
	double grade = 0;
	
	cPtr = &inputString[0];
	cPtrNegative = strchr(cPtr, '-');

	
	if (inputString.compare("X") == 0) {

		std::cout << "Program Exit" << std::endl;
		return USER_ENTERED_X;

	}//eo (inputString.compare('X') == 0) {

	
	else if (((inputString[0]) >= 'A') && ((inputString[0]) <= 'Z')) {

		cPtr = &inputString[0];
		grade = assessGrade(cPtr);

	}//eo else if (((inputString[0]) >= 'A') && ((inputString[0]) <= 'Z')) {


	else if (((inputString[0]) >= '0') && ((inputString[0]) <= '9')) {

		cPtr = &inputString[0];
		cPtrPeriod = strchr(cPtr, '.');

		if (cPtrNegative != NULL) {

			std::cout << "Invalid input - Negative Number Entered." << std::endl;
			return EXIT_FAILURE;

		}//eo (cPtrNegative != NULL)

		if (cPtrPeriod != NULL) {

			if (sscanf(cPtr, "%lf", &grade) == 1) {	//if 1 double

				if (grade > 100) {

					std::cout << "Invalid input - Grade greater than 100 entered." << std::endl;
					return EXIT_FAILURE;

				}//eo if (grade < 100) {

				else {

					grade = assessGrade(grade);

				}//eo else						
								
			}//eo if (sscanf(cPtr, "%lf", &grade) == 1) {	//if 1 double

			else {

				std::cout << "Error reading float" << std::endl;
				return EXIT_FAILURE;

			}//eo else
		}//eo if (cPtrPeriod != NULL){

		else {

			int grade1 = 0;
			int grade2 = 0;
			int grade3 = 0;
			int grade4 = 0;
			int grade5 = 0;

			sscanf(cPtr, "%d %d %d %d %d", &grade1, &grade2, &grade3, &grade4, &grade5);

			if ((grade1 > 100) || (grade2 > 100) || (grade3 > 100) || (grade4 > 100) || (grade5 > 100)) {

				std::cout << "Error one or more Grade is greater than 100" << std::endl;
				return EXIT_FAILURE;

			}//eo  if ((grade1 > 100) || (grade2 > 100) || (grade3 > 100) || (grade4 > 100) || (grade5 > 100)) {

			grade = assessGrade(grade1, grade2, grade3, grade4, grade5);
									
		}//eo else

	}//eo else if (((inputString[0]) >= '0') && ((inputString[0]) <= '9')) {


	else {

		std::cout << "Error Invalid Entry" << std::endl;
		return EXIT_FAILURE;

	}//eo else


	if ((grade == SPECIAL_SITUATION) || grade == (INVALID_ENTRY)) {

	}//eo if (grade == SPECIAL_SITUATION) {

	else if (grade >= 54.50) {	//passing condition

		std::cout << "Student Achieved " << std::setw(6) << std::setfill('0') << std::internal << std::fixed << std::setprecision(2) << grade << " % which is a PASS condition." << std::endl;

	}//eo if (grade > 54.50) {

	else {

		std::cout << "Student Achieved " << std::setw(6) << std::setfill('0') << std::internal << std::fixed << std::setprecision(2) << grade << " % which is a FAIL condition." << std::endl;

	}//eo else


	return EXIT_SUCCESS;

}//eo assessGradeParser





/*
* FUNCTION : assessGrade(char* inputGrade)
*
* DESCRIPTION : This function calculates the final grade for the student

*
* PARAMETERS : char* inputGrade
* RETURNS : none
*/

double assessGrade(char* inputCptrGrade) {


	if (strcmp(inputCptrGrade, "A+") == 0) {

		return 95;

	} //eo if (strcmp(inputCptrGrade, "A+") == 0) {

	else if (strcmp(inputCptrGrade, "A") == 0) {

		return 85;

	}//eo else if (strcmp(inputCptrGrade, "A") == 0) {

	else if (strcmp(inputCptrGrade, "B+") == 0) {

		return 77;

	}//eo 	else if (strcmp(inputCptrGrade, "B+") == 0) {

	else if (strcmp(inputCptrGrade, "B") == 0) {

		return 72;

	}//eo else if (strcmp(inputCptrGrade, "B") == 0) {

	else if (strcmp(inputCptrGrade, "C+") == 0) {

		return 67;
		
	}//eo else if (strcmp(inputCptrGrade, "C+") == 0) {

	else if (strcmp(inputCptrGrade, "C") == 0) {

		return 62;
		
	}//eo else if (strcmp(inputCptrGrade, "C") == 0) {

	else if (strcmp(inputCptrGrade, "D") == 0) {

		return 57;

	}//eoelse if (strcmp(inputCptrGrade, "D") == 0) {

	else if (strcmp(inputCptrGrade, "F") == 0) {

		return 50;

	}//eo else if (strcmp(inputCptrGrade, "F") == 0) {

	else if (strcmp(inputCptrGrade, "I") == 0) {

		
		std::cout << "Student has Special Situation: I (Incomplete)" << std::endl;
		return SPECIAL_SITUATION;

	}//eo else if (strcmp(inputCptrGrade, "I") == 0) {

	else if (strcmp(inputCptrGrade, "Q") == 0) {

		
		std::cout << "Student has Special Situation: Q (Withdrawal after drop/refund date)" << std::endl;
		return SPECIAL_SITUATION;

	}//eo else if (strcmp(inputCptrGrade, "Q") == 0) {

	else if (strcmp(inputCptrGrade, "AU") == 0) {

		
		std::cout << "Student has Special Situation: AU (Audit Condition)" << std::endl;
		return SPECIAL_SITUATION;

	}//eo else if (strcmp(inputCptrGrade, "AU") == 0) {

	else if (strcmp(inputCptrGrade, "DNA") == 0) {

		
		std::cout << "Student has Special Situation: DNA (Did Not Attend)" << std::endl;
		return SPECIAL_SITUATION;

	}//eo else if (strcmp(inputCptrGrade, "DNA") == 0) {

	else if (strcmp(inputCptrGrade, "I/P") == 0) {

		
		std::cout << "Student has Special Situation: I/P (In Process)" << std::endl;
		return SPECIAL_SITUATION;

	}//eo else if (strcmp(inputCptrGrade, "I/P") == 0) {


	else {

		std::cout << "Invalid Input" << std::endl;
		return INVALID_ENTRY;

	}//eo else


}//eo assessGrade(char* inputGrade) {




 /*
 * FUNCTION : assessGrade(double inputGrade)
 *
 * DESCRIPTION : This function calculates the final grade for the student

 *
 * PARAMETERS : double inputGrade
 * RETURNS : none
 */

double assessGrade(double inputDoubleGrade) {

	return inputDoubleGrade;


}//eo assessGrade(double inputGrade) {




 /*
 * FUNCTION : assessGrade(int grade1, int grade2 = 0, int grade3 = 0, int grade4 = 0, int grade5 = 0)
 *
 * DESCRIPTION : This function calculates the final grade for the student

 *
 * PARAMETERS : int grade1, int grade2 = 0, int grade3 = 0, int grade4 = 0, int grade5 = 0
 * RETURNS : none
 */

double assessGrade(int grade1, int grade2, int grade3, int grade4, int grade5) {

	float result = 0;

	result = (float)(grade1 + grade2 + grade3 + grade4 + grade5);

	result = result / 5;


	return result;

}//eo (int grade1, int grade2 = 0, int grade3 = 0, int grade4 = 0, int grade5 = 0) {



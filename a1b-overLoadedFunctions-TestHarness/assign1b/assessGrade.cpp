/*
* FILE : assign2.cpp
* PROJECT : PROG1385 - Object Oriented Programming
* PROGRAMMER : Brendan Rushing
* FIRST VERSION : 2018-05-22
* DESCRIPTION :

This program is a test harness to test the assignment #1 assessGrade project.

The program uses function pointers to test the 3 assessGrade functions.

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
#include <iostream>
#include <sstream>
//eo INCLUDE FILES


//CONSTANTS


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

std::string assessGradeParser(std::string &inputString) {

	char* cPtr = NULL;
	char* cPtrPeriod = NULL;
	char* cPtrNegative = NULL;
	double grade = 0;
	std::string stringOut = { 0 };
	
	cPtr = &inputString[0];
	cPtrNegative = strchr(cPtr, '-');
		
	if (inputString.compare("X") == 0) {

		return  "Program Exit";
		
	}//eo (inputString.compare('X') == 0) {

	
	else if (((inputString[0]) >= 'A') && ((inputString[0]) <= 'Z')) {

		cPtr = &inputString[0];
		stringOut = assessGrade(cPtr);
		return stringOut;

	}//eo else if (((inputString[0]) >= 'A') && ((inputString[0]) <= 'Z')) {


	else if (((inputString[0]) >= '0') && ((inputString[0]) <= '9')) {

		cPtr = &inputString[0];
		cPtrPeriod = strchr(cPtr, '.');

		if (cPtrNegative != NULL) {

			return "Error Invalid Entry";
			
		}//eo (cPtrNegative != NULL)

		if (cPtrPeriod != NULL) {

			if (sscanf(cPtr, "%lf", &grade) == 1) {	//if 1 double

				if (grade > 100) {

					return "Error Invalid Entry";
					
				}//eo if (grade < 100) {

				else {

					stringOut = assessGrade(grade);
					return stringOut;

				}//eo else						
								
			}//eo if (sscanf(cPtr, "%lf", &grade) == 1) {	//if 1 double

			else {

				return "Error Invalid Entry";
				
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

				return "Error Invalid Entry";
				
			}//eo  if ((grade1 > 100) || (grade2 > 100) || (grade3 > 100) || (grade4 > 100) || (grade5 > 100)) {

			stringOut = assessGrade(grade1, grade2, grade3, grade4, grade5);
			return stringOut;
			
									
		}//eo else

	}//eo else if (((inputString[0]) >= '0') && ((inputString[0]) <= '9')) {


	else {

		return "Error Invalid Entry";
		
	}//eo else

		
	if (grade >= 54.50) {	//passing condition

		std::stringstream buffer;
		buffer << "Student Achieved " << std::setw(6) << std::setfill('0') << std::internal << std::fixed << std::setprecision(2) << grade << " % which is a PASS condition.";
		
		std::string outputBuffer = buffer.str();

		return outputBuffer;


	}//eo if (grade > 54.50) {

	else {

		std::stringstream buffer;
		buffer << "Student Achieved " << std::setw(6) << std::setfill('0') << std::internal << std::fixed << std::setprecision(2) << grade << " % which is a FAIL condition.";

		std::string outputBuffer = buffer.str();

		return outputBuffer;

	}//eo else


}//eo assessGradeParser





/*
* FUNCTION : assessGrade(char* inputGrade)
*
* DESCRIPTION : This function calculates the final grade for the student

*
* PARAMETERS : char* inputGrade
* RETURNS : none
*/

std::string assessGrade(char* inputCptrGrade) {

	double grade = 0;

	if (strcmp(inputCptrGrade, "A+") == 0) {

		grade = 95;

	} //eo if (strcmp(inputCptrGrade, "A+") == 0) {

	else if (strcmp(inputCptrGrade, "A") == 0) {

		grade = 85;

	}//eo else if (strcmp(inputCptrGrade, "A") == 0) {

	else if (strcmp(inputCptrGrade, "B+") == 0) {

		grade = 77;

	}//eo 	else if (strcmp(inputCptrGrade, "B+") == 0) {

	else if (strcmp(inputCptrGrade, "B") == 0) {

		grade = 72;

	}//eo else if (strcmp(inputCptrGrade, "B") == 0) {

	else if (strcmp(inputCptrGrade, "C+") == 0) {

		grade = 67;
		
	}//eo else if (strcmp(inputCptrGrade, "C+") == 0) {

	else if (strcmp(inputCptrGrade, "C") == 0) {

		grade = 62;
		
	}//eo else if (strcmp(inputCptrGrade, "C") == 0) {

	else if (strcmp(inputCptrGrade, "D") == 0) {

		grade = 57;

	}//eoelse if (strcmp(inputCptrGrade, "D") == 0) {

	else if (strcmp(inputCptrGrade, "F") == 0) {

		grade = 50;

	}//eo else if (strcmp(inputCptrGrade, "F") == 0) {

	else if (strcmp(inputCptrGrade, "I") == 0) {

		std::stringstream buffer;
		std::cout << "Student has Special Situation: I (Incomplete)";
		std::string outputBuffer = buffer.str();
		return outputBuffer;

	}//eo else if (strcmp(inputCptrGrade, "I") == 0) {

	else if (strcmp(inputCptrGrade, "Q") == 0) {

		std::stringstream buffer;
		std::cout << "Student has Special Situation: Q (Withdrawal after drop/refund date)";
		std::string outputBuffer = buffer.str();
		return outputBuffer;


	}//eo else if (strcmp(inputCptrGrade, "Q") == 0) {

	else if (strcmp(inputCptrGrade, "AU") == 0) {

		std::stringstream buffer;
		std::cout << "Student has Special Situation: AU (Audit Condition)";
		std::string outputBuffer = buffer.str();
		return outputBuffer;

	}//eo else if (strcmp(inputCptrGrade, "AU") == 0) {

	else if (strcmp(inputCptrGrade, "DNA") == 0) {

		std::stringstream buffer;
		std::cout << "Student has Special Situation: DNA (Did Not Attend)";
		std::string outputBuffer = buffer.str();
		return outputBuffer;


	}//eo else if (strcmp(inputCptrGrade, "DNA") == 0) {

	else if (strcmp(inputCptrGrade, "I/P") == 0) {

		std::stringstream buffer;
		std::cout << "Student has Special Situation: I/P (In Process)";
		std::string outputBuffer = buffer.str();
		return outputBuffer;


	}//eo else if (strcmp(inputCptrGrade, "I/P") == 0) {


	else {

		return "Error Invalid Entry";
		


	}//eo else


		if (grade >= 54.50) {	//passing condition
			
			std::stringstream buffer;
			buffer << "Student Achieved " << std::setw(6) << std::setfill('0') << std::internal << std::fixed << std::setprecision(2) << grade << " % which is a PASS condition.";

			std::string outputBuffer = buffer.str();
			return outputBuffer;


		}//eo if (grade > 54.50) {

		else {

			std::stringstream buffer;
			buffer << "Student Achieved " << std::setw(6) << std::setfill('0') << std::internal << std::fixed << std::setprecision(2) << grade << " % which is a FAIL condition.";

			std::string outputBuffer = buffer.str();
			return outputBuffer;

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

std::string assessGrade(double inputDoubleGrade) {

	 
	if ((inputDoubleGrade > 100) || (inputDoubleGrade < 0)) {

		return "Error Invalid Entry";

	}//eo if ((inputDoubleGrade > 100) || (inputDoubleGrade < 0)) {
	
	
	
	else if (inputDoubleGrade >= 54.50) {	//passing condition


		std::stringstream buffer;
		buffer << "Student Achieved " << std::setw(6) << std::setfill('0') << std::internal << std::fixed << std::setprecision(2) << inputDoubleGrade << " % which is a PASS condition.";

		std::string outputBuffer = buffer.str();

		return outputBuffer;


	}//eo if (grade > 54.50) {

	else {

		std::stringstream buffer;
		buffer << "Student Achieved " << std::setw(6) << std::setfill('0') << std::internal << std::fixed << std::setprecision(2) << inputDoubleGrade << " % which is a FAIL condition.";

		std::string outputBuffer = buffer.str();

		return outputBuffer;

	}//eo else


}//eo assessGrade(double inputGrade) {




 /*
 * FUNCTION : assessGrade(int grade1, int grade2 = 0, int grade3 = 0, int grade4 = 0, int grade5 = 0)
 *
 * DESCRIPTION : This function calculates the final grade for the student

 *
 * PARAMETERS : int grade1, int grade2 = 0, int grade3 = 0, int grade4 = 0, int grade5 = 0
 * RETURNS : none
 */

std::string assessGrade (int grade1, int grade2, int grade3, int grade4, int grade5){

	float result = 0;

	result = (float)(grade1 + grade2 + grade3 + grade4 + grade5);

	result = result / 5;

	if ((grade1 > 100) || (grade2 > 100) || (grade3 > 100) || (grade4 > 100) || (grade5 > 100)) {

		return "Error Invalid Entry";

	}//eo  if ((grade1 > 100) || (grade2 > 100) || (grade3 > 100) || (grade4 > 100) || (grade5 > 100)) {

	if ((grade1 < 0) || (grade2 < 0) || (grade3 < 0) || (grade4 < 0) || (grade5 < 0)) {

		return "Error Invalid Entry";

	}//eo  if ((grade1 < 0) || (grade2 < 0) || (grade3 < 0) || (grade4 < 0) || (grade5 < 0)) {


	if ((result > 100) || (result < 0)) {

		return "Error Invalid Entry";

	}//eo if ((inputDoubleGrade > 100) || (inputDoubleGrade < 0)) {


	 else if (result >= 54.50) {	//passing condition


			std::stringstream buffer;
			buffer << "Student Achieved " << std::setw(6) << std::setfill('0') << std::internal << std::fixed << std::setprecision(2) << result << " % which is a PASS condition.";

			std::string outputBuffer = buffer.str();

			return outputBuffer;


		}//eo if (grade > 54.50) {

	 else {

		 std::stringstream buffer;
		 buffer << "Student Achieved " << std::setw(6) << std::setfill('0') << std::internal << std::fixed << std::setprecision(2) << result << " % which is a FAIL condition.";

		 std::string outputBuffer = buffer.str();

		 return outputBuffer;

	 }//eo else



}//eo (int grade1, int grade2 = 0, int grade3 = 0, int grade4 = 0, int grade5 = 0) {



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
#include <cstdio>
#include <cstring>
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctype.h>
#include "assessGrade.h"
//eo INCLUDE FILES


//CONSTANTS
#define TRUE 1
#define FALSE 0
#define NUMBER_OF_TESTS 33
#define SUCCESS 0
#define FAIL -1

enum testType { FUNCTIONAL, EXCEPTION, BOUNDARY };

enum dataType { CHAR, DOUBLE, INT};

#pragma warning(disable: 4996)

//eo CONSTANTS

//PROTOTYPES
int unitTests(void);
int functionalTest(int currentTestNumber, struct unitTestData functionalTestDataStruct, struct functionPointers unitTestFunctionPointers);
int boundaryTest(int currentTestNumber, struct unitTestData functionalTestDataStruct, struct functionPointers unitTestFunctionPointers);
int exceptionTest(int currentTestNumber, struct unitTestData functionalTestDataStruct, struct functionPointers unitTestFunctionPointers);
//eo PROTOTYPES


//STRUCTS
struct functionPointers {

	std::string(*fnPtr1Int)(int, int, int, int, int);
	std::string(*fnPtr2Char)(char*);
	std::string(*fnPtr3Double)(double);

};

struct unitTestData {

	char* testConfirmation[NUMBER_OF_TESTS];
	char* testInputData[NUMBER_OF_TESTS];
	int testType[NUMBER_OF_TESTS];
	int dataType[NUMBER_OF_TESTS];

};

//EO STRUCTS




/*
* FUNCTION : unitTests
*
* DESCRIPTION : This function sets up the test data and calls 
the different test functions.

*
* PARAMETERS : none
* RETURNS : int: SUCCESS or FAIL
*/

int unitTests(void) {

	int failCount = 0;
	int successCount = 0;
	int retCode = 0;
	

	const char * testResults[NUMBER_OF_TESTS] = {
		"Student Achieved 095.00 % which is a PASS condition.",
		"Student Achieved 085.00 % which is a PASS condition.",
		"Student Achieved 077.00 % which is a PASS condition.",
		"Student Achieved 072.00 % which is a PASS condition.",
		"Student Achieved 050.00 % which is a FAIL condition.",
		"Error Invalid Entry",
		"Error Invalid Entry",
		"Error Invalid Entry",
		"Error Invalid Entry",
		"Error Invalid Entry",
		"Student Achieved 077.70 % which is a PASS condition.",
		"Student Achieved 066.60 % which is a PASS condition.",
		"Student Achieved 088.80 % which is a PASS condition.",
		"Student Achieved 072.50 % which is a PASS condition.",
		"Student Achieved 052.50 % which is a FAIL condition.",
		"Error Invalid Entry",
		"Error Invalid Entry",
		"Error Invalid Entry",
		"Error Invalid Entry",
		"Error Invalid Entry",
		"Student Achieved 000.00 % which is a FAIL condition.",
		"Student Achieved 100.00 % which is a PASS condition.",
		"Student Achieved 054.50 % which is a PASS condition.",

		"Student Achieved 080.00 % which is a PASS condition.",
		"Student Achieved 070.00 % which is a PASS condition.",
		"Student Achieved 060.00 % which is a PASS condition.",
		"Student Achieved 050.00 % which is a FAIL condition.",
		"Student Achieved 070.00 % which is a PASS condition.",
		"Error Invalid Entry",
		"Error Invalid Entry",
		"Error Invalid Entry",
		"Error Invalid Entry",
		"Error Invalid Entry",
		};


	const char * tests[NUMBER_OF_TESTS] =
	{	"A+", "A", "B+", "B", "F",
		"Hello", "A-", "B-", "D-", "E",
		"77.7", "66.6", "88.8", "72.5", "52.5",
		"110.1", "120.4", "222.2", "109.3", "122.2",
		"0.0", "100.0", "54.5",
		"80 80 80 80 80",
		"70 70 70 70 70",
		"60 60 60 60 60",
		"50 50 50 50 50",
		"90 80 70 60 50",

		"120 90 111 111",
		"1666",
		"666 899 99 999 9",
		"9 9 9 9 888",
		"6 800 5 5"				
	};


	int testDataTypes[NUMBER_OF_TESTS] =
	{
		CHAR, CHAR, CHAR, CHAR, CHAR,
		CHAR, CHAR, CHAR, CHAR, CHAR,
		DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE,
		DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE,
		DOUBLE, DOUBLE, DOUBLE,
		INT, INT, INT, INT, INT,
		INT, INT, INT, INT, INT

	};

	int testTypes[NUMBER_OF_TESTS] =
	{
		FUNCTIONAL, FUNCTIONAL, FUNCTIONAL, FUNCTIONAL,FUNCTIONAL,
		EXCEPTION, EXCEPTION, EXCEPTION, EXCEPTION, EXCEPTION,
		FUNCTIONAL, FUNCTIONAL, FUNCTIONAL, FUNCTIONAL,FUNCTIONAL,
		EXCEPTION, EXCEPTION, EXCEPTION, EXCEPTION, EXCEPTION,
		BOUNDARY, BOUNDARY, BOUNDARY,
		FUNCTIONAL, FUNCTIONAL, FUNCTIONAL, FUNCTIONAL,FUNCTIONAL,
		EXCEPTION, EXCEPTION, EXCEPTION, EXCEPTION, EXCEPTION
	};

	int currentTest = 0;


	struct functionPointers unitTestFunctions;

	unitTestFunctions.fnPtr1Int = assessGrade;
	unitTestFunctions.fnPtr2Char = assessGrade;
	unitTestFunctions.fnPtr3Double = assessGrade;

	
	struct unitTestData unitTestDataStruct;

	

	//FILL STRUCT ARRAYS WITH TEST DATA
	for (int i = 0; i < NUMBER_OF_TESTS; i++) {

		int length = 0;
		
		length = strlen(tests[i]);

		if ((unitTestDataStruct.testInputData[i] = (char*)malloc(length+1)) == NULL) {

			//ERROR
			printf("\n MALLOC ERROR");
			
		}//eo if
			
		strcpy(unitTestDataStruct.testInputData[i], (char*)tests[i]);
				
		length = strlen(testResults[i]);

		if ((unitTestDataStruct.testConfirmation[i] = (char*)malloc(length + 1)) == NULL) {

			//ERROR
			printf("\n MALLOC ERROR");

		}//eo if

		strcpy(unitTestDataStruct.testConfirmation[i], (char*)testResults[i]);


		unitTestDataStruct.dataType[i] = testDataTypes[i];

		unitTestDataStruct.testType[i] = testTypes[i];


	}//eo for

	

	for (int i = 0; i < NUMBER_OF_TESTS; i++) {


		if (unitTestDataStruct.testType[i] == FUNCTIONAL) {

			retCode = functionalTest(i, unitTestDataStruct, unitTestFunctions);

		}//eo if (unitTestDataStruct.testType[i] == FUNCTIONAL) {


		else if (unitTestDataStruct.testType[i] == EXCEPTION) {

			retCode = exceptionTest(i, unitTestDataStruct, unitTestFunctions);

		}//eo else if (unitTestDataStruct.testType[i] == EXCEPTION) {

		else if (unitTestDataStruct.testType[i] == BOUNDARY) {

			retCode = boundaryTest(i, unitTestDataStruct, unitTestFunctions);

		}//eo else if (unitTestDataStruct.testType[i] == BOUNDARY) {

		if (retCode == SUCCESS) {

			successCount++;
		}

		else if (retCode == FAIL) {

			failCount++;
		}


	}//eo for (int i = 0; i < NUMBER_OF_TESTS; i++) {

	std::cout << std::endl;
	std::cout << "\t>> Tests Successful: \t"<< successCount << std::endl;
	std::cout << "\t>> Tests Failed: \t" << failCount << std::endl;
	std::cout << std::endl;
		

	//DESTROY TEST DATA

	for (int i = 0; i < NUMBER_OF_TESTS; i++) {

		free(unitTestDataStruct.testInputData[i]);
		free(unitTestDataStruct.testConfirmation[i]);
		
	}//eo for


	return EXIT_SUCCESS;

}//eo int unitTests(void) {





 /*
 * FUNCTION : functionalTest
 *
 * DESCRIPTION : This function tests the functional test for assessGrade

 *
 * PARAMETERS : (int currentTestNumber, struct unitTestData functionalTestDataStruct, struct functionPointers unitTestFunctionPointers)
 * RETURNS : int: SUCCESS or FAIL
 */
int functionalTest(int currentTestNumber, struct unitTestData functionalTestDataStruct, struct functionPointers unitTestFunctionPointers) {

	const char* cPtr = NULL;
	const char* cPtr2 = NULL;
	char* cPtr3 = NULL;
	std::string assessGradeResult = { 0 };
	double grade = 0;

	cPtr = functionalTestDataStruct.testInputData[currentTestNumber];
	cPtr2 = functionalTestDataStruct.testConfirmation[currentTestNumber];

	
		if (functionalTestDataStruct.dataType[currentTestNumber] == INT) {

			std::cout << "Test #" << (currentTestNumber + 1) << " Functional test of assessGrade(int)" << std::endl;
			int grade1 = 0;
			int grade2 = 0;
			int grade3 = 0;
			int grade4 = 0;
			int grade5 = 0;

			sscanf(cPtr, "%d %d %d %d %d", &grade1, &grade2, &grade3, &grade4, &grade5);
			assessGradeResult = unitTestFunctionPointers.fnPtr1Int(grade1, grade2, grade3, grade4, grade5);
			
		}//eo if (functionalTestDataStruct.dataType[currentTestNumber] == INT) {


		else if (functionalTestDataStruct.dataType[currentTestNumber] == CHAR) {
		
			std::cout << "Test #" << (currentTestNumber + 1) << " Functional test of assessGrade(char *)" << std::endl;
			assessGradeResult = unitTestFunctionPointers.fnPtr2Char((char*)cPtr);

		}//eo else if (functionalTestDataStruct.dataType[currentTestNumber] == CHAR) {
		
		else if (functionalTestDataStruct.dataType[currentTestNumber] == DOUBLE) {

			std::cout << "Test #" << (currentTestNumber + 1) << " Functional test of assessGrade(Double)" << std::endl;

			sscanf(cPtr, "%lf", &grade);
			assessGradeResult = unitTestFunctionPointers.fnPtr3Double(grade);

		}//eo else if (functionalTestDataStruct.dataType[currentTestNumber] == DOUBLE) {

		
		std::cout << "\t>> Submitting \"" << functionalTestDataStruct.testInputData[currentTestNumber] << "\" as the student's mark" << std::endl;
		std::cout << "\t\t>> Expected Result:\t " << functionalTestDataStruct.testConfirmation[currentTestNumber] << std::endl;
		
		cPtr3 = &assessGradeResult[0];
		
	std::cout << "\t\t>> Actual Result:\t " << assessGradeResult << std::endl;

	if (strcmp((char*)cPtr2, cPtr3) == 0){

		std::cout << "\t** TEST PASSED **" << std::endl;
		std::cout << std::endl;
		return SUCCESS;

		}//eo strcmp

	else {

		std::cout << "\t** TEST FAILED **" << std::endl;
		std::cout << std::endl;
		return FAIL;
			
		}//eo else



}//eo 




 /*
 * FUNCTION : exceptionTest
 *
 * DESCRIPTION : This function tests the exception test for assessGrade

 *
 * PARAMETERS : (int currentTestNumber, struct unitTestData functionalTestDataStruct, struct functionPointers unitTestFunctionPointers)
 * RETURNS : int: SUCCESS or FAIL
 */

int exceptionTest(int currentTestNumber, struct unitTestData functionalTestDataStruct, struct functionPointers unitTestFunctionPointers) {

	const char* cPtr = NULL;
	const char* cPtr2 = NULL;
	char* cPtr3 = NULL;
	std::string assessGradeResult = { 0 };
	double grade = 0;

	cPtr = functionalTestDataStruct.testInputData[currentTestNumber];
	cPtr2 = functionalTestDataStruct.testConfirmation[currentTestNumber];
	

	if (functionalTestDataStruct.dataType[currentTestNumber] == INT) {

		std::cout << "Test #" << (currentTestNumber + 1) << " Exception test of assessGrade(int)" << std::endl;
		int grade1 = 0;
		int grade2 = 0;
		int grade3 = 0;
		int grade4 = 0;
		int grade5 = 0;

		sscanf(cPtr, "%d %d %d %d %d", &grade1, &grade2, &grade3, &grade4, &grade5);

		assessGradeResult = unitTestFunctionPointers.fnPtr1Int(grade1, grade2, grade3, grade4, grade5);


	}//eo if (functionalTestDataStruct.dataType[currentTestNumber] == INT) {


	else if (functionalTestDataStruct.dataType[currentTestNumber] == CHAR) {

		std::cout << "Test #" << (currentTestNumber + 1) << " Exception test of assessGrade(char *)" << std::endl;
		assessGradeResult = unitTestFunctionPointers.fnPtr2Char((char*)cPtr);

	}//eo else if (functionalTestDataStruct.dataType[currentTestNumber] == CHAR) {

	else if (functionalTestDataStruct.dataType[currentTestNumber] == DOUBLE) {

		std::cout << "Test #" << (currentTestNumber + 1) << " Exception test of assessGrade(Double)" << std::endl;

		sscanf(cPtr, "%lf", &grade);
		assessGradeResult = unitTestFunctionPointers.fnPtr3Double(grade);

	}//eo else if (functionalTestDataStruct.dataType[currentTestNumber] == DOUBLE) {


	std::cout << "\t>> Submitting \"" << functionalTestDataStruct.testInputData[currentTestNumber] << "\" as the student's mark" << std::endl;
	std::cout << "\t\t>> Expected Result:\t " << functionalTestDataStruct.testConfirmation[currentTestNumber] << std::endl;
		
	cPtr3 = &assessGradeResult[0];
		
	std::cout << "\t\t>> Actual Result:\t " << assessGradeResult << std::endl;

	if (strcmp((char*)cPtr2, cPtr3) == 0) {

		std::cout << "\t** TEST PASSED **" << std::endl;
		std::cout << std::endl;
		return SUCCESS;

	}//eo strcmp

	else {

		std::cout << "\t** TEST FAILED **" << std::endl;
		std::cout << std::endl;
		return FAIL;

	}//eo else


}//eo 






 /*
 * FUNCTION : boundaryTest
 *
 * DESCRIPTION : This function tests the boundary test for assessGrade

 *
 * PARAMETERS : (int currentTestNumber, struct unitTestData functionalTestDataStruct, struct functionPointers unitTestFunctionPointers)
 * RETURNS : int: SUCCESS or FAIL
 */
int boundaryTest(int currentTestNumber, struct unitTestData functionalTestDataStruct, struct functionPointers unitTestFunctionPointers) {

	const char* cPtr = NULL;
	const char* cPtr2 = NULL;
	char* cPtr3 = NULL;
	std::string assessGradeResult = { 0 };
	double grade = 0;

	cPtr = functionalTestDataStruct.testInputData[currentTestNumber];
	cPtr2 = functionalTestDataStruct.testConfirmation[currentTestNumber];
	

	if (functionalTestDataStruct.dataType[currentTestNumber] == INT) {

		std::cout << "Test #" << (currentTestNumber + 1) << " Boundary test of assessGrade(int)" << std::endl;
		int grade1 = 0;
		int grade2 = 0;
		int grade3 = 0;
		int grade4 = 0;
		int grade5 = 0;

		sscanf(cPtr, "%d %d %d %d %d", &grade1, &grade2, &grade3, &grade4, &grade5);

		assessGradeResult = unitTestFunctionPointers.fnPtr1Int(grade1, grade2, grade3, grade4, grade5);


	}//eo if (functionalTestDataStruct.dataType[currentTestNumber] == INT) {


	else if (functionalTestDataStruct.dataType[currentTestNumber] == CHAR) {

		std::cout << "Test #" << (currentTestNumber + 1) << " Boundary test of assessGrade(char *)" << std::endl;
		assessGradeResult = unitTestFunctionPointers.fnPtr2Char((char*)cPtr);

	}//eo else if (functionalTestDataStruct.dataType[currentTestNumber] == CHAR) {

	else if (functionalTestDataStruct.dataType[currentTestNumber] == DOUBLE) {

		std::cout << "Test #" << (currentTestNumber + 1) << " Boundary test of assessGrade(Double)" << std::endl;

		sscanf(cPtr, "%lf", &grade);
		assessGradeResult = unitTestFunctionPointers.fnPtr3Double(grade);

	}//eo else if (functionalTestDataStruct.dataType[currentTestNumber] == DOUBLE) {


	std::cout << "\t>> Submitting \"" << functionalTestDataStruct.testInputData[currentTestNumber] << "\" as the student's mark" << std::endl;
	std::cout << "\t\t>> Expected Result:\t " << functionalTestDataStruct.testConfirmation[currentTestNumber] << std::endl;

	cPtr3 = &assessGradeResult[0];
	
	std::cout << "\t\t>> Actual Result:\t " << assessGradeResult << std::endl;

	if (strcmp((char*)cPtr2, cPtr3) == 0) {

		std::cout << "\t** TEST PASSED **" << std::endl;
		std::cout << std::endl;
		return SUCCESS;

	}//eo strcmp

	else {

		std::cout << "\t** TEST FAILED **" << std::endl;
		std::cout << std::endl;
		return FAIL;

	}//eo else


}//eo 




int main(void) {


	if (unitTests() == SUCCESS) {

		return	EXIT_SUCCESS;

	}//eo if (unitTests() == SUCCESS) {


	return EXIT_FAILURE;

}//eo main
/*
* FILE : assign1.cpp
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
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdbool>
#include <cstdlib>
#include <iomanip>
#include "assessGrade.h"
//eo INCLUDE FILES


//CONSTANTS
#define TRUE 1
#define FALSE 0

#pragma warning(disable: 4996)

//eo CONSTANTS




int main(void) {
		
	while (1) {	//infinite loop, when user enters X, EXIT_SUCCESS is returned

		std::string inputBuffer = { 0 };

		std::cout << "Enter the grades: ";

		std::getline(std::cin, inputBuffer);

		std::string result = assessGradeParser(inputBuffer);

		std::cout << result << std::endl;;

		if (assessGradeParser(inputBuffer).compare("Program Exit")== 0) {

			return EXIT_SUCCESS;

		}//eo if (assessGradeParser(inputBuffer) == USER_ENTERED_X) 

	}//eo while(1)


	return	EXIT_FAILURE;
		
}//eo main



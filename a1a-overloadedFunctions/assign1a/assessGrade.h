/*
* FILE : assessGrade.h
* PROJECT : PROG1385 - Object Oriented Programming
* PROGRAMMER : Brendan Rushing
* FIRST VERSION : 2018-05-22
* DESCRIPTION :
	
	The functions in this file are used to assessGrade for the project.


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
#include <string>
#include <iostream>
//eo INCLUDE FILES

//CONSTANTS
#define USER_ENTERED_X -3
//eo CONSTANTS

//PARAMETERS
double assessGrade(int grade1, int grade2 = 0, int grade3 = 0, int grade4 = 0, int grade5 = 0);
double assessGrade(char* inputCptrGrade);
double assessGrade(double inputDoubleGrade);
int assessGradeParser(std::string &inputString);
//eo PARAMETERS
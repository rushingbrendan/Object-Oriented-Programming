
/*  
*  FILE          : DisneyCharacter.h
*  PROJECT       : PROG1385 - Object Oriented Programming Assignment #2
*  PROGRAMMER    : Brendan Rushing
*  FIRST VERSION : 2018-06-06
*  DESCRIPTION   : 
*	This assignment creates a DisneyCharacter class, manipulates the values and has a test harness
*/


#ifdef __linux__ 

#include<bits/stdc++.h>

#endif


#pragma once
#include <string>
#include <cstring>
#include <cstdbool>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <iomanip>


//CONSTANTS
const char MAGIC_KINGDOM = 'M';
const char DISNEY_STUDIO = 'S';
const char ANIMAL_KINGDOM = 'A';
const char EPCOT = 'E';
const char CALIFORNIA_ADVENTURE = 'C';
const char NOT_PLACED = 'N';

const int SUCCESS = 1;
const int FAIL = 0;

//eo CONSTANTS




class DisneyCharacter {

private:

	std::string name;
	std::string creationDate;
	int numMovies;
	char whichPark;

	
public:	

	
	DisneyCharacter(std::string inputName, std::string inputDate);
	DisneyCharacter(std::string inputName, std::string inputDate, int inputNumMovies, char inputWhichPark);
	~DisneyCharacter();	//destructor
	
	//set functions
	bool setNumMovies(int);
	bool setWhichPark(char);

	//get functions
	char getWhichPark(void);
	std::string getName(void);
	int getNumMovies(void);
	std::string getCreationDate(void);


	void showInfo(void);
	bool sameMovies(DisneyCharacter& anotherCharacter);
	bool placeCharacter(char inputPark);



};//eo class DisneyCharacter { 




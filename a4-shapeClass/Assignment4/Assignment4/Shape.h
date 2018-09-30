
#pragma once
//INCLUDE FILES
#include <string>
#include <cstring>
#include <cstdbool>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <iomanip>


//eo INCLUDE FILES

const int kColourNameIsValid = 0;
const int kNameIsValid = 1;
const int kNotValid = 2;

const double kPI = 3.1415926;



class Shape {

protected:

	std::string name;

	std::string colour;

	//VALIDATE INPUT
	static int ValidateInput(std::string);


public:

	Shape(std::string inputName, std::string inputColour);	//paramterized constructor
	Shape(void);	//default constructor




	//GETTERS
	std::string GetName(void) const;
	std::string GetColour(void) const;



	//SETTERS
	void SetColour(std::string inputColour);
	void SetName(std::string inputColour);

	virtual double Perimeter(void) = 0;
	virtual double Area(void) = 0;
	virtual double OverallDimension(void) = 0;

	virtual void Show(void) = 0;

	virtual ~Shape(void);



};


/*
*  FILE          : PioneerCarRadio.h
*  PROJECT       : PROG1385 - Object Oriented Programming Assignment #5
*  PROGRAMMER    : Brendan Rushing
*  FIRST VERSION : 2018-07-19
*  DESCRIPTION   :
*	This assignment modifys assignment #3 to use inheritance.
Create PioneerCarRadio class with upgraded features.
Match display output as specified.
*/


//PRAGMA
#pragma once
//eo PRAGMA


//INCLUDE FILES
#include "AmFmRadio.h"
#include<conio.h>
#include <iostream>
#include <iomanip>
//eo INCLUDE FILES



class PioneerCarRadio : public AmFmRadio{

private:
	
public:

	//destructor
	~PioneerCarRadio(void);
	
	//constructor
	PioneerCarRadio(bool power, struct Freqs PioneerPresets[RADIO_PRESETS]) : AmFmRadio(false, PioneerPresets){}
	
	//Menu Display
	void RadioDashboard(void);

	//Get user input
	int RadioControl(void);

};
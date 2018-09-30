/*
*  FILE          : PioneerCarRadio.h
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


//PRAGMA
#pragma once
//eo PRAGMA


//INCLUDE FILES
#include "AmFmRadio.h"
#include<conio.h>
#include <iomanip>
//eo INCLUDE FILES



//CONSTANTS
enum { CREATE_PIONEER_CAR_RADIO = 4, CREATE_PIONEER_AM, CREATE_PIONEER_WORLD };

#define POWER_TOGGLE 'o'
#define VOLUME_UP '+'
#define VOLUME_DOWN '_'
#define SCAN_UP '='
#define SCAN_DOWN '-'
#define SWITCH_BAND 'b'
#define BUTTON_1	'1'
#define BUTTON_2	'2'
#define BUTTON_3	'3'
#define BUTTON_4	'4'
#define BUTTON_5	'5'
#define SET_BUTTON_1	'!'
#define SET_BUTTON_2	'@'
#define SET_BUTTON_3	'#'
#define SET_BUTTON_4	'$'
#define SET_BUTTON_5	'%'
#define EXIT_PROGRAM	'x'
//eo CONSTANTS



/*
* NAME: PioneerCarRadio
* PURPOSE: This is class that is based on the AmFmRadio Class.
		   This class has a different radio dashboard display

*/
class PioneerCarRadio : public AmFmRadio{

private:
	
public:

	//destructor
	virtual ~PioneerCarRadio(void);
	
	//constructor
	PioneerCarRadio(bool power, struct Freqs PioneerPresets[RADIO_PRESETS], int inputRadioType) : AmFmRadio(false, PioneerPresets, inputRadioType) {}
	

	
	//Menu Display
	void RadioDashboard(void);

	//Get user input
	int RadioControl(void);

};
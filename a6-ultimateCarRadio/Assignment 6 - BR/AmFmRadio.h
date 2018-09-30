/*
*  FILE          : AmFmRadio.h
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


//INCLUDE FILES
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//eo INCLUDE FILES



//CONSTANTS
#define BUFFER_SIZE 20
#define SUCCESS 0
#define FAILURE 1

#define PIONEER_WORLD_AM_MIN 531
#define PIONEER_WORLD_AM_MAX 1602

#define PIONEER_WORLD_AM_SCAN 9

const char AM_BAND = 'A';
const char FM_BAND = 'F';
const int AM_MIN = 530;
const int AM_MAX = 1700;

const double FM_MIN = 87.9;
const double FM_MAX = 107.9;

const int RADIO_PRESETS = 5;
const int SIZE_OF_FREQUENCY_TEXT = 3;
const int VOLUME_MIN = 0;
const int VOLUME_MAX = 100;
const int INITIAL_STATION = 800;
const int PIONEER_XS_440_WRLD_INITIAL_STATION = 801;

enum { PIONEER_XS440, PIONEER_XS440_AM, PIONEER_XS440_WRLD };


#pragma warning (disable:4996)

#ifndef _CARRADIO_H
#define _CARRADIO_H


struct Freqs
{
	double AMFreq;
	double FMFreq;
};

//eo CONSTANTS



/*
* NAME: AmFmRadio
* PURPOSE: This is a AmFmRadio class. 
*		   It has 5 buttons with presets. 
*		   The class supports AM and FM Radios

*/
class AmFmRadio
{
private:
	Freqs	button[RADIO_PRESETS];
	double	current_station;
	int		currentButton;
	char	frequency[SIZE_OF_FREQUENCY_TEXT];
	int		volume=0;
	int		prevVolume=0;
	double  prevAMFreq = 0;
	double  prevFMFreq = 0;
	bool	on;
	bool	displayOutput = true;
	int		radioType = PIONEER_XS440;
	bool	isDestroyed = false;

public:

	//paramaterized constructors
	AmFmRadio(bool status, struct Freqs arrayOfFreq[RADIO_PRESETS], int inputRadioType);
	AmFmRadio(bool status = false);

	//Destructor
	 virtual ~AmFmRadio(void);

	//Toggles the on variable
	void PowerToggle(void);

	//returns a true if the radio is currently powered on, and false if the radio is in
	//the off position
	bool IsRadioOn(void);

	//toggles frequency between AM and FM and sets current station to the previous frequency
	//for that band
	virtual void ToggleFrequency(void);

	void SetBand(int);

	//sets button with current station by being passed a button number
	int SetButton(int button_num);

	//sets current station by being passed a button number
	int SelectCurrentStation(int button_num);

	//sets volume
	int SetVolume(void);
	int SetVolume(int);

	//set DisplayOutput
	void SetDisplayOutput(bool);


	//shows volume, button settings, current station, AM or FM
	void ShowCurrentSettings(void);

	//changes frequency up in increments of .2 for FM, 10 for AM
	virtual void ScanUp(void);
	//changes frequency down in increments of .2 for FM, 10 for AM
	virtual void ScanDown(void);

	void SetCurrentStation(double);

	void SetPrevFreq(int, double);

	void SetRadioType(int);

	void SetIsDestroyed(bool);

	

	//GETTER'S
	int GetVolume(void);
	double GetCurrentStation(void);
	double GetPrevFreq(int);
	bool GetOn(void);
	bool GetDisplayOutput(void);
	char GetCurrentBand(void);
	struct Freqs* GetRadioPresets(void);
	int GetRadioType(void);
	bool GetIsDestroyed(void);




};
#endif
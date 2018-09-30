/*
*  FILE          : AmFmRadio.h
*  PROJECT       : PROG1385 - Object Oriented Programming Assignment #3
*  PROGRAMMER    : Brendan Rushing
*  FIRST VERSION : 2018-06-12
*  DESCRIPTION   :
*	This assignment modifys a premade AmFmRadio class. 
*	The class is updated with required changes for a future assignment.
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


#pragma warning (disable:4996)

#ifndef _CARRADIO_H
#define _CARRADIO_H


struct Freqs
{
	double AMFreq;
	double AMPrevFreq;
	double FMFreq;
	double FMPrevFreq;
	char prevBand;
};

//eo CONSTANTS




class AmFmRadio
{
private:
	Freqs	button[RADIO_PRESETS];
	double	current_station;
	int		currentButton;
	char	frequency[SIZE_OF_FREQUENCY_TEXT];
	int		volume=0;
	int		prevVolume=0;
	bool	on;
	bool	displayOutput = true;

public:

	//paramaterized constructors
	AmFmRadio(bool status, struct Freqs arrayOfFreq[RADIO_PRESETS]);
	AmFmRadio(bool status = false);

	//Destructor
	~AmFmRadio(void);

	//Toggles the on variable
	void PowerToggle(void);

	//returns a true if the radio is currently powered on, and false if the radio is in
	//the off position
	bool IsRadioOn(void);

	//toggles frequency between AM and FM and sets current station to the previous frequency
	//for that band
	void ToggleFrequency(void);

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
	void ScanUp(void);
	//changes frequency down in increments of .2 for FM, 10 for AM
	void ScanDown(void);

	void setCurrentStation(double);

	//GETTER'S
	int getVolume(void);
	double getCurrentStation(void);
	bool getOn(void);
	bool getDisplayOutput(void);
	char getCurrentBand(void);
	struct Freqs* getRadioPresets(void);


};
#endif
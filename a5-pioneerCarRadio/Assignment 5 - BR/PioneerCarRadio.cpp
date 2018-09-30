/*
*  FILE          : PioneerCarRadio.cpp
*  PROJECT       : PROG1385 - Object Oriented Programming Assignment #5
*  PROGRAMMER    : Brendan Rushing
*  FIRST VERSION : 2018-07-19
*  DESCRIPTION   :
*	This assignment modifys assignment #3 to use inheritance.
Create PioneerCarRadio class with upgraded features.
Match display output as specified.
*/


//INCLUDE FILES
#include "PioneerCarRadio.h"
//eo INCLUDE FILES




/*
* FUNCTION : ~PioneerCarRadio
*
* DESCRIPTION : This function is a destructor for the PioneerCarRadio class
*
* PARAMETERS : none
*
*
* RETURNS : none
*/
PioneerCarRadio::~PioneerCarRadio(void){

	std::cout << "\nPioneerCarRadio Class Destroyed" << std::endl;


}//eo PioneerRadio::~PioneerCarRadio(void){





 /*
 * FUNCTION : RadioDashboard
 *
 * DESCRIPTION : This function shows the current settings for PioneerCarRadio Class
 *
 * PARAMETERS : none
 *
 *
 * RETURNS : none
 */
void PioneerCarRadio::RadioDashboard(void) {

//	struct Freqs inputButton[RADIO_PRESETS];


	std::cout << "Pioneer XS440" << std::endl;
	std::cout << "Radio is ";


	if (IsRadioOn() == false) {

		std::cout << "off" << std::endl;

	}

	else {

		std::cout << "on" << std::endl;
		std::cout << "Volume: " << GetVolume() <<std::endl;
		std::cout << "Current Station: " << std::setw(5) << GetCurrentStation();

		if (GetCurrentBand() == AM_BAND) {

			std::cout << " AM" << std::endl;

		}

		else if (GetCurrentBand() == FM_BAND) {

			std::cout << " FM" << std::endl;

		}

		std::cout << "AM Buttons:" << std::endl;
		//std::cout.setf(std::ios::fixed | std::ios::showpoint);


		std::cout << "1: " << std::setw(5) << GetRadioPresets()[0].AMFreq << ",  ";
		std::cout << "2: " << std::setw(5) << GetRadioPresets()[1].AMFreq << ",  ";
		std::cout << "3: " << std::setw(5) << GetRadioPresets()[2].AMFreq << ",  ";
		std::cout << "4: " << std::setw(5) << GetRadioPresets()[3].AMFreq << ",  ";
		std::cout << "5: " << std::setw(5) << GetRadioPresets()[4].AMFreq << std::endl;


		std::cout << "FM Buttons:" << std::endl;
		std::cout << "1: " << std::setw(5) << GetRadioPresets()[0].FMFreq << ",  ";
		std::cout << "2: " << std::setw(5) << GetRadioPresets()[1].FMFreq << ",  ";
		std::cout << "3: " << std::setw(5) << GetRadioPresets()[2].FMFreq << ",  ";
		std::cout << "4: " << std::setw(5) << GetRadioPresets()[3].FMFreq << ",  ";
		std::cout << "5: " << std::setw(5) << GetRadioPresets()[4].FMFreq << std::endl;


	}


}//eo void PioneerCarRadio::RadioDashboard(void) {




 /*
 * FUNCTION : RadioControl
 *
 * DESCRIPTION : This function is gets input from the user to control
				 the radio settings.
 *
 * PARAMETERS : none
 *
 *
 * RETURNS : int
 */
int PioneerCarRadio::RadioControl(void) {

	char userInput = 0;
	bool userInputFinished = false;
	int currentVolume = 0;

	while (userInputFinished == false) {

		//1. clear screen
		system("cls");


		//2. display menu
		RadioDashboard();


		//3. get user input
		userInput = getch();


		switch (userInput) {

		case 'o':
			//Turn on / off
			PowerToggle();
			
			break;

		case '+':
			//Increase volume by 1
			currentVolume = GetVolume();
			currentVolume++;
			SetVolume(currentVolume);
			break;

		case '_':
			//Decrease volume by 1
			currentVolume = GetVolume();
			currentVolume--;
			SetVolume(currentVolume);
			break;
		
		case '=':
			//Scan up
			ScanUp();
			break;

		case '-':
			//Scan down
			ScanDown();
			break;

		case 'b':
			//Switch Band
			ToggleFrequency();
			break;

		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
			//Choose button
			userInput = userInput - 48;	//strip ASCII value
			userInput = userInput - 1;	//decrease by 1 to match array of 0 to 4
			SelectCurrentStation(userInput);
			break;

		case '!':
			//Set button 1
			SetButton(0);
			break;
		case '@':
			//Set button 2
			SetButton(1);
			break;
		case '#':
			//Set button 3
			SetButton(2);
			break;
		case '$':
			//Set button 4
			SetButton(3);
			break;
		case '%':
			//Set button 5
			SetButton(4);
			break;

		case 'x':
			//Exit Program
			userInputFinished = true;
			break;

		default:
			break;
				

		}//eo 	switch (userInput) {

	}

	return EXIT_SUCCESS;
	
}//eo int PioneerCarRadio::RadioDataEntry(void) {

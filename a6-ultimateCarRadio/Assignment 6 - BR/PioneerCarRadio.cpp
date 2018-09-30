/*
*  FILE          : PioneerCarRadio.cpp
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

	if (GetDisplayOutput()) {

		if (!GetIsDestroyed()) {
			SetIsDestroyed(true);
			std::cout << "Destroying Pioneer XS440 Radio Class" << std::endl;

		}
	}

	
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

	switch (GetRadioType()) {

	case PIONEER_XS440:
		std::cout << "Pioneer XS440" << std::endl;
		break;

	case PIONEER_XS440_AM:
		std::cout << "Pioneer XS440-AM" << std::endl;
		break;

	case PIONEER_XS440_WRLD:
		std::cout << "Pioneer XS440-WRLD" << std::endl;
		break;

	default:
		break;


	}//eo 	switch (radioType) {
	




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


		std::cout << "1: " << std::setw(5) << GetRadioPresets()[0].AMFreq << ",  ";
		std::cout << "2: " << std::setw(5) << GetRadioPresets()[1].AMFreq << ",  ";
		std::cout << "3: " << std::setw(5) << GetRadioPresets()[2].AMFreq << ",  ";
		std::cout << "4: " << std::setw(5) << GetRadioPresets()[3].AMFreq << ",  ";
		std::cout << "5: " << std::setw(5) << GetRadioPresets()[4].AMFreq << std::endl;

		if (GetRadioType() == PIONEER_XS440) {

			std::cout << "FM Buttons:" << std::endl;
			std::cout << "1: " << std::setw(5) << GetRadioPresets()[0].FMFreq << ",  ";
			std::cout << "2: " << std::setw(5) << GetRadioPresets()[1].FMFreq << ",  ";
			std::cout << "3: " << std::setw(5) << GetRadioPresets()[2].FMFreq << ",  ";
			std::cout << "4: " << std::setw(5) << GetRadioPresets()[3].FMFreq << ",  ";
			std::cout << "5: " << std::setw(5) << GetRadioPresets()[4].FMFreq << std::endl;

		}


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
		#ifdef __linux__ 
		system("clear");
		#elif _WIN32
		system("cls");		//clear the screen
		#endif


		//2. display menu
		RadioDashboard();


		//3. get user input
		userInput = getch();


		switch (userInput) {

		case POWER_TOGGLE:
			//Turn on / off
			PowerToggle();
			
			break;

		case VOLUME_UP:
			//Increase volume by 1
			currentVolume = GetVolume();
			currentVolume++;
			SetVolume(currentVolume);
			break;

		case VOLUME_DOWN:
			//Decrease volume by 1
			currentVolume = GetVolume();
			currentVolume--;
			SetVolume(currentVolume);
			break;
		
		case SCAN_UP:
			//Scan up
			ScanUp();
			break;

		case SCAN_DOWN:
			//Scan down
			ScanDown();
			break;

		case SWITCH_BAND:
			//Switch Band
			ToggleFrequency();
			break;

		case BUTTON_1:
		case BUTTON_2:
		case BUTTON_3:
		case BUTTON_4:
		case BUTTON_5:
			//Choose button
			userInput = userInput - 48;	//strip ASCII value
			userInput = userInput - 1;	//decrease by 1 to match array of 0 to 4
			SelectCurrentStation(userInput);
			break;

		case SET_BUTTON_1:
			//Set button 1
			SetButton(0);
			break;
		case SET_BUTTON_2:
			//Set button 2
			SetButton(1);
			break;
		case SET_BUTTON_3:
			//Set button 3
			SetButton(2);
			break;
		case SET_BUTTON_4:
			//Set button 4
			SetButton(3);
			break;
		case SET_BUTTON_5:
			//Set button 5
			SetButton(4);
			break;

		case EXIT_PROGRAM:
			//Exit Program
			userInputFinished = true;
			break;


		default:
			break;
				

		}//eo 	switch (userInput) {

	}

	return EXIT_SUCCESS;
	
}//eo int PioneerCarRadio::RadioDataEntry(void) {

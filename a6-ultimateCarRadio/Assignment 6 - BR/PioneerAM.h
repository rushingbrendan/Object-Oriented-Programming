/*
*  FILE          : PioneerAM.h
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



//CONSTANTS
#define PIONEERAM_SCAN_VALUE	10
//eo CONSTANTS



//INCLUDE FILES
#include "PioneerCarRadio.h"
//eo INCLUDE FILES

/*
* NAME: PioneerAM
* PURPOSE: This is an AM only version based on the AmFmRadio Class

*/
class PioneerAM : public PioneerCarRadio{


private:


public:

	/*
	* FUNCTION : ~PioneerAM
	*
	* DESCRIPTION : This function is a destructor for the PioneerAM Class
	*
	* PARAMETERS : none
	*
	*
	* RETURNS : none
	*/
	virtual ~PioneerAM(void) {

		if (GetDisplayOutput()) {
			if (!GetIsDestroyed()) {

				SetIsDestroyed(true);
				std::cout << "Destroying Pioneer XS440-AM Radio Class" << std::endl;
			}
		}

	}//eo destructor



	//constructor
	PioneerAM(bool power, struct Freqs PioneerPresets[RADIO_PRESETS], int inputRadioType) : PioneerCarRadio(false, PioneerPresets, inputRadioType) {}

	
		

	/*
	* FUNCTION : ToggleFrequenecy
	*
	* DESCRIPTION : This function toggles the frequency variable
	AM to FM & FM to AM
	However ** This class only supports AM
	*
	* PARAMETERS : none
	*
	*
	* RETURNS : none
	*/
	void ToggleFrequency(void) {

		SetBand(AM_BAND);	//AM IS ONLY SUPPORTED.


	}//eo void AmFmRadio::ToggleFrequency(void)





	 /*
	 * FUNCTION : ScanUp
	 *
	 * DESCRIPTION : This function scans the frequency up.
	 The frequency will increment 10 khz if AM


	 * PARAMETERS : none
	 *
	 *
	 * RETURNS : none
	 */
	void ScanUp(void) {

		//if current_station is 1700, the current_station becomes 530
		if (GetCurrentStation() >= AM_MAX)
		{
			SetCurrentStation(AM_MIN);
		}
		else
		{
			SetCurrentStation(GetCurrentStation() + PIONEERAM_SCAN_VALUE);

		}

		SetPrevFreq(AM_BAND, GetCurrentStation());


		if (GetDisplayOutput()) {

			printf("\nCurrent station: %f", GetCurrentStation());

			if (GetCurrentBand() == AM_BAND) {

				printf(" AM\n");

			}


		}//eo if (displayOutput) {



	}//eo void AmFmRadio::ScanUp(void)









	/*
	* FUNCTION : ScanDown
	*
	* DESCRIPTION : This function scans the frequency down.
	The frequency will decrement 10 khz in the AM BAND

	*
	* PARAMETERS : none
	*
	*
	* RETURNS : none
	*/
	void ScanDown(void) {

		//if current_station is 530, the current_station becomes 1700
		if (GetCurrentStation() <= AM_MIN)
		{
			SetCurrentStation(AM_MAX);
		}
		else
		{
			SetCurrentStation(GetCurrentStation() - PIONEERAM_SCAN_VALUE);

		}

		SetPrevFreq(AM_BAND, GetCurrentStation());


		if (GetDisplayOutput()) {

			printf("\nCurrent station: %f", GetCurrentStation());

			if (GetCurrentBand() == AM_BAND) {

				printf(" AM\n");

			}


		}//eo if (displayOutput) {



	}//eo void AmFmRadio::ScanDown(void)




};
/*
*  FILE          : PioneerWorld.h
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
#include "PioneerAM.h"
//eo INCLUDE FILES


//CONSTANTS

//eo CONSTANTS


/*
* NAME: PioneerWorld
* PURPOSE: This is an AM only version (with limited spectrum)
		    based on the AmFmRadio Class

*/
class PioneerWorld : public PioneerAM {


private:


public:


	//constructor
	PioneerWorld(bool power, struct Freqs PioneerPresets[RADIO_PRESETS], int inputRadioType) : PioneerAM(false, PioneerPresets, inputRadioType) {}


	/*
	* FUNCTION : ~PioneerWorld
	*
	* DESCRIPTION : This function is a destructor for the PioneerWorld Class
	*
	* PARAMETERS : none
	*
	*
	* RETURNS : none
	*/
	virtual ~PioneerWorld(void) {

		if (GetDisplayOutput()) {
			if (!GetIsDestroyed()) {
				SetIsDestroyed(true);
				std::cout << "Destroying Pioneer XS440-WRLD Radio Class" << std::endl;

			}
		}

	}//eo destructor


	


	/*
	* FUNCTION : ScanUp
	*
	* DESCRIPTION : This function scans the frequency up.
	The frequency will increment 9 khz in the AM Band

	* PARAMETERS : none
	*
	*
	* RETURNS : none
	*/
	void ScanUp(void) {

		//if current_station is greater than 1602, the current_station becomes 531
		if (GetCurrentStation() >= PIONEER_WORLD_AM_MAX)
		{
			SetCurrentStation(PIONEER_WORLD_AM_MIN);
		}
		else
		{
			SetCurrentStation(GetCurrentStation() + PIONEER_WORLD_AM_SCAN);

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
	The frequency will decrement 9 khz in the AM BAND

	*
	* PARAMETERS : none
	*
	*
	* RETURNS : none
	*/
	void ScanDown(void)
	{

		//if current_station is less than 531, the current_station becomes 1602
		if (GetCurrentStation() <= PIONEER_WORLD_AM_MIN)
		{
			SetCurrentStation(PIONEER_WORLD_AM_MAX);
		}
		else
		{
			SetCurrentStation(GetCurrentStation() - PIONEER_WORLD_AM_SCAN);

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

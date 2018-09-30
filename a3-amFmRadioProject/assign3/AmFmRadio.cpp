/*
*  FILE          : AmFmRadio.cpp
*  PROJECT       : PROG1385 - Object Oriented Programming Assignment #3
*  PROGRAMMER    : Brendan Rushing
*  FIRST VERSION : 2018-06-12
*  DESCRIPTION   :
*	This assignment modifys a premade AmFmRadio class. 
*	The class is updated with required changes for a future assignment.
*/


//INCLUDE FILES
#include "AmFmRadio.h"
//eo INCLUDE FILES



/*
* FUNCTION : ~AmFmRadio
*
* DESCRIPTION : This function is a destructor for the AmFmRadio class
*
* PARAMETERS : none
*
*
* RETURNS : none
*/
AmFmRadio::~AmFmRadio(void) {

	std::cout << "Destroying AmFmRadio" << std::endl;

}//eo destructor




/*
* FUNCTION : AmFmRadio
*
* DESCRIPTION : This function is a paramaterized constructor for the AmFmRadio class
*
* PARAMETERS : bool status, struct freqs arrayOfFreq[RADIO_PRESETS]
*
*
* RETURNS : none
*/
AmFmRadio::AmFmRadio(bool status, struct Freqs arrayOfFreq[RADIO_PRESETS])
{

	on = status;

	for (int i = 0; i < RADIO_PRESETS; ++i)
	{
		button[i].AMFreq = arrayOfFreq[i].AMFreq;
	}
	for (int j = 0; j < RADIO_PRESETS; ++j)
	{
		button[j].FMFreq = arrayOfFreq[j].FMFreq;
	}

}//eo AmFmRadio::AmFmRadio(bool status, struct freqs arrayOfFreq[RADIO_PRESETS])



/*
* FUNCTION : AmFmRadio
*
* DESCRIPTION : This function is a paramaterized constuctor for the AmFmRadio class
*
* PARAMETERS : bool status
*
*
* RETURNS : none
*/
AmFmRadio::AmFmRadio(bool status)
{
	for (int i = 0; i < RADIO_PRESETS; ++i)
	{
		button[i].AMFreq = AM_MIN;
		button[i].AMPrevFreq = button[i].AMFreq;
		currentButton = i;
	}
	for (int j = 0; j < RADIO_PRESETS; ++j)
	{
		button[j].FMFreq = FM_MIN;
		button[j].FMPrevFreq = button[j].FMFreq;
		currentButton = j;
	}
	current_station = AM_MIN;
	strcpy(frequency, "AM");
	volume = VOLUME_MIN;
	prevVolume = VOLUME_MIN;

	on = status;
}//eo AmFmRadio::AmFmRadio(bool status)




/*
* FUNCTION : PowerToggle
*
* DESCRIPTION : This function toggles the bool value for on variable.
				This variable is the value for power of the radio
*
* PARAMETERS : none
*
*
* RETURNS : none
*/
void AmFmRadio::PowerToggle(void)
{
	if( on == false )
	{
	
		on = true;
		volume = prevVolume;
	}
	else
	{
		on = false;
		volume = VOLUME_MIN;
	}
}//eo void AmFmRadio::PowerToggle(void)




/*
* FUNCTION : IsRadioOn
*
* DESCRIPTION : This function returns the value for the on variable
*
* PARAMETERS : none
*
*
* RETURNS : bool:on
*/
bool AmFmRadio::IsRadioOn(void)
{
	return on;

}//eo bool AmFmRadio::IsRadioOn(void)





/*
* FUNCTION : SetVolume
*
* DESCRIPTION : This function sets the volume by prompting the user for input
*
* PARAMETERS : none
*
*
* RETURNS : int
*/
int AmFmRadio::SetVolume(void)
{
	char buf[BUFFER_SIZE] = "";

	printf("\nEnter the volume level (0 - 100). ");
	fgets(buf, sizeof buf, stdin);
	volume = atoi(buf);
	prevVolume = volume;

	if (volume < VOLUME_MIN) //if user enters volume less than 0, volume = 0
	{
		volume = VOLUME_MIN;
		return volume;
	}

	if (volume > VOLUME_MAX) //if user enters volume greater than 100, volume = 100
	{
		volume = VOLUME_MAX;
		return volume;
	}
	return volume;
}//eo int AmFmRadio::SetVolume(void)




/*
* FUNCTION : SetVolume
*
* DESCRIPTION : This function changes the value for the volume variable
*
* PARAMETERS : int inputVolume
*
*
* RETURNS : int
*/
int AmFmRadio::SetVolume(int inputVolume)
{
	volume = inputVolume;

	if( volume < VOLUME_MIN ) //if user enters volume less than 0, volume = 0
	{
		volume = VOLUME_MIN;
		return volume;
	}

	if( volume > VOLUME_MAX ) //if user enters volume greater than 100, volume = 100
	{
		volume = VOLUME_MAX;
		return volume;
	}
	return volume;
}//eo int AmFmRadio::SetVolume(int inputVolume)




/*
* FUNCTION : ToggleFrequenecy
*
* DESCRIPTION : This function toggles the frequency variable 
				AM to FM & FM to AM
*
* PARAMETERS : none
*
*
* RETURNS : none
*/
void AmFmRadio::ToggleFrequency(void)
{
	if( strcmp(frequency, "AM") == 0 )
	{
		strcpy(frequency, "FM");
		current_station = button[currentButton].FMPrevFreq;
		button[currentButton].prevBand = FM_BAND;
	}
	else
	{
		strcpy(frequency, "AM");
		current_station = button[currentButton].AMPrevFreq;
		button[currentButton].prevBand = AM_BAND;
	}
}//eo void AmFmRadio::ToggleFrequency(void)



/*
* FUNCTION : SetButton
*
* DESCRIPTION : This function sets button with current station 
*				by being passed a button number
*
* PARAMETERS : int button_num
*
*
* RETURNS : int
*/
int AmFmRadio::SetButton(int button_num)
{
	if( (button_num >= 0) && (button_num <= (RADIO_PRESETS-1) ))
	{
		currentButton = button_num;

		if( strcmp("AM", frequency) == 0 )
		{
			button[button_num].AMPrevFreq = current_station;
			button[button_num].AMFreq = current_station;
		}
		else if(strcmp("FM", frequency) == 0 )
		{
			button[button_num].FMPrevFreq = current_station;
			button[button_num].FMFreq = current_station;
		}
		return SUCCESS;

	}
	return FAILURE;

}//eo int AmFmRadio::SetButton(int button_num)




/*
* FUNCTION : SelectedCurrentStation
*
* DESCRIPTION : This function sets current station 
*				by being passed a button number
*
* PARAMETERS : int: button_num
*
*
* RETURNS : int
*/
int AmFmRadio::SelectCurrentStation(int button_num)
{
	if( (button_num >= 0) && (button_num <= (RADIO_PRESETS - 1)) )
	{
		currentButton = button_num;

		if( strcmp("AM", frequency) == 0 )
		{
			current_station = button[button_num].AMFreq;
		}
		else if (strcmp("AM", frequency) == 0)
		{
			current_station = button[button_num].FMFreq;
		}

		return SUCCESS;
	}
	return FAILURE;

}//eo int AmFmRadio::SelectCurrentStation(int button_num)




/*
* FUNCTION : ShowCurrentSettings
*
* DESCRIPTION : This function outputs the current setting variables
				to the screen.
*
* PARAMETERS : none
*
*
* RETURNS : none
*/
void AmFmRadio::ShowCurrentSettings(void)
{

	if( on )
	{
		printf("\n\nRadio is on. \n");
	}
	else
	{
		printf("\n\nRadio is off. \n");
	}

	printf("\nFrequency: %s\n", frequency);
	printf("Volume: %d\n", volume);
	
	if (!strcmp(frequency, "AM")) {

		printf("Current Station: %.f %s\n", current_station, frequency);
	}
	
	if (!strcmp(frequency, "FM")) {

		printf("Current Station: %.1f %s\n", current_station, frequency);
	}
	printf("AM Button Settings: ");
	for( int i = 0; i < RADIO_PRESETS; ++i )
	{
		printf("%d) %6.0f ", i + 1, button[i].AMFreq);
	}

	printf("\nFM Button Settings: ");
	for( int j = 0; j < RADIO_PRESETS; ++j )
	{
		printf("%d) %6.1f ", j + 1, button[j].FMFreq);
	}
	
}//eo void AmFmRadio::ShowCurrentSettings(void)




/*
* FUNCTION : ScanDown
*
* DESCRIPTION : This function scans the frequency down.
				The frequency will decrement 10 khz if AM
					& 0.2 Mhz if FM
*
* PARAMETERS : none
*
*
* RETURNS : none
*/
void AmFmRadio::ScanDown(void)
{
	if (strcmp("AM", frequency) == 0)
	{
		//if current_station is 1700, the current_station becomes 530
		if (current_station <= AM_MIN)
		{
			current_station = AM_MAX;
		}
		else
		{
			current_station = current_station - 10;
			button[currentButton].AMPrevFreq = current_station;
		}
	}
	else if (strcmp("FM", frequency) == 0)
	{
		//if the current_station is 107.9, the current_station becomes 87.9
		//Note: car radios jump .2 for the FM. That's how it's modeled here.
		if (current_station <= FM_MIN)
		{
			current_station = FM_MAX;
		}
		else
		{
			current_station = current_station - .2;
			button[currentButton].FMPrevFreq = current_station;
		}
	}

	if (displayOutput) {

		printf("\nCurrent station: %f %s\n", current_station, frequency);
	}//eo if (displayOutput) {

}//eo void AmFmRadio::ScanDown(void)





/*
* FUNCTION : ScanUp
*
* DESCRIPTION : This function scans the frequency up.
				The frequency will increment 10 khz if AM
					& 0.2 Mhz if FM

* PARAMETERS : none
*
*
* RETURNS : none
*/
void AmFmRadio::ScanUp(void)
{
	if (strcmp("AM", frequency) == 0)
	{
		//if current_station is 1700, the current_station becomes 530
		if (current_station >= AM_MAX)
		{
			current_station = AM_MIN;
		}
		else
		{
			current_station = current_station + 10;
			button[currentButton].AMPrevFreq = current_station;
		}
	}
	else if (strcmp("FM", frequency) == 0)
	{
		//if the current_station is 107.9, the current_station becomes 87.9
		//Note: car radios jump .2 for the FM. That's how it's modeled here.
		if (current_station >= FM_MAX)
		{
			current_station = FM_MIN;
		}
		else
		{
			current_station = current_station + .2;
			button[currentButton].FMPrevFreq = current_station;
		}
	}

	if (displayOutput) {

		printf("\nCurrent station: %f %s\n", current_station, frequency);

	}//eo if (displayOutput) {

}//eo void AmFmRadio::ScanUp(void)



/*
* FUNCTION : SetCurrentStation
*
* DESCRIPTION : This functionn changes the value for current_station variable
*
* PARAMETERS : double: currentStationValue
*
*
* RETURNS : none
*/
void AmFmRadio::setCurrentStation(double currentStationValue) {

	if (strcmp("AM", frequency) == 0)
	{
		//if current_station is greater than 1700 khz then set to 1700 khz
		if (currentStationValue > AM_MAX)
		{
			current_station = AM_MAX;
		}
		//if current_station is less than 530 then set to 530
		else if (currentStationValue < AM_MIN)
		{
			current_station = AM_MIN;
		}

		else {

			current_station = currentStationValue;

		}
	}
	else if (strcmp("FM", frequency) == 0 )
	{
		//if current_station is greater than 107.9 then set to 107.9
		if (currentStationValue > FM_MAX){

			current_station = FM_MAX;
		}
		//if current_station is less than 87.9 then set to 87.9
		else if (currentStationValue < FM_MIN){

			current_station = FM_MIN;
		}

		else {

			current_station = currentStationValue;

		}
	}

}//eo void AmFmRadio::SelectCurrentStation(double currentStationValue) {





/*
* FUNCTION : SetDisplayOutput
*
* DESCRIPTION : This function changes the value for the displayOutput variable
*
* PARAMETERS : bool inputDisplayOutput
*
*
* RETURNS : none
*/
void AmFmRadio::SetDisplayOutput(bool inputDisplayOutput)
{

	displayOutput = inputDisplayOutput;

}//eo void AmFmRadio::SetDisplayOutput(bool inputDisplayOutput)




/*
* FUNCTION : getVolume
*
* DESCRIPTION : This function returns the value of the volume variable
*
* PARAMETERS : none
*
*
* RETURNS : int volume
*/
int AmFmRadio::getVolume(void) {

	return volume;

}//eo int AmFmRadio::SetVolume() {





/*
* FUNCTION : getCurrentStation
*
* DESCRIPTION : This function returns the value of the current_station
*
* PARAMETERS : none
*
*
* RETURNS : doube: current_station
*/
double AmFmRadio::getCurrentStation(void) {

	return current_station;

}//eo int AmFmRadio::SetVolume() {




/*
* FUNCTION : getOn
*
* DESCRIPTION : This function returns the value for the on variable
*
* PARAMETERS : none
*
*
* RETURNS : bool: on
*/
bool AmFmRadio::getOn(void) {

	return on;

}//eo bool AmFmRadio::getOn(void) {




/*
* FUNCTION : getDisplayOutput
*
* DESCRIPTION : This function returns the value of displayOutput variable
*
* PARAMETERS : none
*
*
* RETURNS : bool: displayOutput
*/
bool AmFmRadio::getDisplayOutput(void) {

	return displayOutput;

}//eo bool AmFmRadio::getDisplayOutput(void) {




/*
* FUNCTION : getCurrentBand
*
* DESCRIPTION : This function is returns the value of the frequency variable
*
* PARAMETERS : none
*
*
* RETURNS : char: currentBand
*/
char AmFmRadio::getCurrentBand(void) {

	if (strcmp("AM", frequency) == 0){

		return AM_BAND;
	}

	else if (strcmp("FM", frequency) == 0 ) {

		return FM_BAND;

	}

	return FAILURE;

}//eo char AmFmRadio::getCurrentBand(void) {


/*
* FUNCTION : getRadioPresets
*
* DESCRIPTION : This function returns the location of the radio preset information
*
* PARAMETERS : none
*
*
* RETURNS : location of button arrays with radio preset information
*/
struct Freqs* AmFmRadio::getRadioPresets(void) {

	return &button[0];

}//eo struct Freqs* getRadioPresets(void) {
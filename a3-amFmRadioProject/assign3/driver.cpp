/*
*  FILE          : driver.cpp
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


//CONSTANTS
enum menuItems
{
	kMenuNothing = 0,	// special constant for initialization only
	kMenuTogglePower = 1, kMenuSetVolume, kMenuToggleAMFM, kMenuSetButton, kMenuSelectButton,
	kMenuShowCurrentSettings, kMenuScanUp, kMenuScanDown, kMenuQuit
};

//eo CONSTANTS




int main(void)
{
	int			volume_OK = 0;
	int			button_OK = 0;
	int			button_num = 0;
	menuItems	choice = kMenuNothing;
	char		buf[BUFFER_SIZE] = {0};
	bool		on = true;
	AmFmRadio	jazzy(on);

	
	do
	{
		printf("\n\nMAIN MENU\n");
		printf("=========\n\n");
		printf("1.  Toggle Power\n");
		printf("2.  Set Volume\n");
		printf("3.  Toggle AM / FM\n");
		printf("4.  Set a Button \n"); 
		printf("5.  Select a Button \n"); 
		printf("6.  Show Current Settings\n"); 
		printf("7.  Scan Up \n"); 
		printf("8.  Scan Down \n");
		printf("9.  Quit the Program\n");
		printf("\nMake a selection from the menu\n");
		fgets(buf, sizeof buf, stdin);
		choice = (menuItems) atoi(buf);
		
		switch( choice )
		{
		case kMenuTogglePower:
			jazzy.PowerToggle();
			break;
		case kMenuSetVolume: 
			volume_OK = jazzy.SetVolume();
			if( volume_OK == VOLUME_MIN )
			{
				printf("\nVolume was set to 0.");
			}
			else if( volume_OK == VOLUME_MAX )
			{
				printf("\nVolume was set to 100.");
			}
			break;
			
		case kMenuToggleAMFM:
			on = jazzy.IsRadioOn();
			if( on )
			{
				jazzy.ToggleFrequency();
			    
			}
			else
			{
				printf("\nThe radio must be turned on before the "
					"band can be toggled!");
			}
			break;
		case kMenuSetButton:
			on = jazzy.IsRadioOn();
			if( on )
			{
				printf("\nWhich button do you want to set?");
			    fgets(buf, sizeof buf, stdin);
			    button_num = atoi(buf) - 1;
			    button_OK = jazzy.SetButton(button_num);
			    if( button_OK == 0 )
				{
					printf("\nYou entered an invalid button number!");
				}
			}
			else
			{
				printf("\nYou must turn the radio on before you set the buttons!\n");
			}
			break;
		case kMenuSelectButton:
			on = jazzy.IsRadioOn();
			if( on )
			{
				printf("\nEnter the number of the button: ");
			    fgets(buf, BUFFER_SIZE, stdin);
			    button_num = atoi(buf) - 1;
			    button_OK = jazzy.SelectCurrentStation(button_num);
				if( button_OK == 0 )
				{
					printf("\nYou entered an invalid button number!");
				}
			}
			else
			{
				printf("\nYou must turn the radio on before you set the buttons!\n");
			}
			break;
		case kMenuShowCurrentSettings:
			jazzy.ShowCurrentSettings();
			break;
		case kMenuScanUp:
			on = jazzy.IsRadioOn();
			if( on )
			{
				jazzy.ScanUp();
			}
			else
			{
				printf("\nYou must turn the radio on before you can use the scan button!\n");
			
			}
			break;
		case kMenuScanDown:
			on = jazzy.IsRadioOn();
			if (on)
			{
				jazzy.ScanDown();
			}
			else
			{
				printf("\nYou must turn the radio on before you can use the scan button!\n");

			}
		case kMenuQuit:
		    break;
		default:
			printf("\nYou have entered an invalid selection. Please make \n"
				   "another selection.\n");
			break;

		}

		if( (choice != kMenuShowCurrentSettings) && (choice != kMenuQuit) )
			jazzy.ShowCurrentSettings();

	}while( choice != kMenuQuit );

	printf("\nGoodbye!\n");
	return EXIT_SUCCESS;


}
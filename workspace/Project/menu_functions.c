/**
	Menu functions
	Orig. by: Herr Muskelprotze
	Currently by: Emmanuel Utomi
	
	*** IMPORTANT NOTE: PUT ALL FUNCTIONS FIRST, THEN CALL THEM AT BOTTOM OTHER WISE YOU GET A VARARG ERROR ***
**/
#include "xmc_functions.c"
bool superjump = false;
bool carjump = false;

void second_level_functions(void)
	{ 
		if(submenu_id == 1)
			{
				if(item_select == 1)
					{ //Godmode toggle
						xmcgodmode_toggle();
					}
				else if(item_select == 2)
					{ //Give Weapons
						xmcweapons();
					}
				else if(item_select == 3)
					{ //Super jump
						while (true) 
							{
								if (superjump) 
									{
										superjump = true;
										WAIT(0);
										xmcsuperjump();
									}
								else 
									{
										xmcsuperjump();
										superjump = false;
									}
							}
					}
			}
	if(submenu_id == 2)
		{
		if(item_select == 1)
			{ //Lock/Unlock Doors
				xmccarlock_toggle();
			}
		else if(item_select == 2)
			{ //Car jump
				while (true) 
					{
						if (carjump) 
							{
								carjump = true;
								WAIT(0);
								xmccarjump();
							}
						else 
							{
								carjump = false;
								xmccarjump();
							}
					}
			}
	if(submenu_id == 3)
		{
			if(item_select == 1)
				{ //Tele-waypoint
					xmctelewaypoint();
				}
		else if(item_select == 2)
			{ //Tele-10ft
				xmcTeleportForward();
			}
	}
}
}


void menu_functions(void)
{
	if(submenu_level == 1)
	{
		second_level_functions();
	}
	else
		{ //main level functions go below
			if(item_select == 2)
				{
					prints("Main level function test.");
				}
		}
}
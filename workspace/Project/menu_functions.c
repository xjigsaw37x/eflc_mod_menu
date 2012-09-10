/**
	Menu functions
	Orig. by: Herr Muskelprotze
	Currently by: Emmanuel Utomi
	
	*** IMPORTANT NOTE: PUT ALL FUNCTIONS FIRST, THEN CALL THEM AT BOTTOM OTHER WISE YOU GET A VARARG ERROR ***
**/
#include "xmc_functions.c"

bool superjump = false;
bool carjump = false;

void third_level_functions(void)
	{
		if(third_level_id == 1)
			{
				if(third_level_id == 1)
					{
						if(item_select == 1) 
							{
								prints("Spawn an Infernus.");
								uint vehicle_model = MODEL_INFERNUS;
								xmcspawncar();
							}
						else if(item_select == 2)
							{
								prints("Spawn an Sultan RS.");
								uint vehicle_model = MODEL_SULTANRS;
								xmcspawncar();
							}
						else if(item_select == 3)
							{
								prints("Spawn an APC Tank.");
								uint vehicle_model = MODEL_APC;
								xmcspawncar();
							}
						else if(item_select == 4)
							{
								prints("Spawn an Sabre GT.");
								uint vehicle_model = MODEL_SABREGT;
								xmcspawncar();
							}
					}
			}	
	}

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
		if(item_select == 2)
			{ //Lock/Unlock Doors
				xmccarlock_toggle();
			}
		else if(item_select == 3)
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
	else if(submenu_level == 2)
		{ 	
			third_level_functions();
		}
}
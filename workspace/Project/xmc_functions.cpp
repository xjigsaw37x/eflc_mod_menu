bool SearchOn =0;
Vector3 v;
int HIGHT, WIDTH;
float coord;

void Print(char *string,uint Time)
{PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", string, Time, 1);}

void xmc_teleportinfront(void)
{
    if ( IS_PLAYER_PLAYING(GetPlayerIndex()) )
    {
        float x, y, z, ch;
        GET_CHAR_HEADING(GetPlayerPed(), &ch);
        GET_CHAR_COORDINATES(GetPlayerPed(), &x, &y, &z);
        SET_CHAR_COORDINATES(GetPlayerPed(), x+(10*SIN((-1*ch))), y+(10*COS((-1*ch))), z);
    }
}


void HELLFIRE(float Pos_x, float Pos_y, float Pos_z, int Width_var, int Hight_var, int Spacing)
{
	Hight_var = Hight_var * Spacing;
	Width_var = Width_var * Spacing;
	for (HIGHT = 0; HIGHT <= Hight_var; HIGHT += Spacing) 
	{
		// start position
		Pos_z = Pos_z + HIGHT;
		ADD_EXPLOSION(Pos_x, Pos_y, Pos_z, 4, 7.50, 1, 0, 1.01);
		WAIT(20);
		// start position end
		for (WIDTH = 4; WIDTH <= Width_var; WIDTH += 4) 
		{
			Pos_x = Pos_x - WIDTH;
			WAIT(20);
			ADD_EXPLOSION(Pos_x, Pos_y, Pos_z, EXPLOSION_ROCKET, 7.50, 1, 0, 0.7);
			Pos_y = Pos_y + WIDTH;
			WAIT(20);
			ADD_EXPLOSION(Pos_x, Pos_y, Pos_z, EXPLOSION_ROCKET, 7.50, 1, 0, 0.7);
			Pos_x = Pos_x + WIDTH;
			WAIT(20);
			ADD_EXPLOSION(Pos_x, Pos_y, Pos_z, EXPLOSION_ROCKET, 7.50, 1, 0, 0.7);
			Pos_x = Pos_x + WIDTH;
			WAIT(20);
			ADD_EXPLOSION(Pos_x, Pos_y, Pos_z, EXPLOSION_ROCKET, 7.50, 1, 0, 0.7);
			Pos_y = Pos_y - WIDTH;
			WAIT(20);
			ADD_EXPLOSION(Pos_x, Pos_y, Pos_z, EXPLOSION_ROCKET, 7.50, 1, 0, 0.7);
			Pos_y = Pos_y - WIDTH;
			WAIT(20);
			ADD_EXPLOSION(Pos_x, Pos_y, Pos_z, EXPLOSION_ROCKET, 7.50, 1, 0, 0.7);
			Pos_x = Pos_x - WIDTH;
			WAIT(20);
			ADD_EXPLOSION(Pos_x, Pos_y, Pos_z, EXPLOSION_ROCKET, 7.50, 1, 0, 0.7);
			Pos_x = Pos_x - WIDTH;
			WAIT(20);
			ADD_EXPLOSION(Pos_x, Pos_y, Pos_z, EXPLOSION_ROCKET, 7.50, 1, 0, 0.7);
			WAIT(20);
			Pos_y = Pos_y + WIDTH;
			Pos_x = Pos_x + WIDTH;
  WAIT(20);
 }
}
WAIT(20);
}	

void USE_WP_FOR_HELLFIRE(void)
{
	Blip WayBlip = GET_FIRST_BLIP_INFO_ID(BLIP_WAYPOINT);
		Print("Requesting AGM-114 Hellfire at waypoint!", 1000);
		WAIT(1000);
 		 		
		if(DOES_BLIP_EXIST(WayBlip))
		{//GET_GROUND_Z_FOR_3D_COORD(float x, float y, float z, float *pGroundZ);
			Print("Position confirmed... Firing now! ", 1000);
			WAIT(500);
			GET_BLIP_COORDS(WayBlip, &v); //GET_BLIP_COORDS
			GET_GROUND_Z_FOR_3D_COORD(v.x, v.y, v.z, &coord); 

			HELLFIRE(v.x, v.y, coord+10.0f, 7, 2, 2); // not sure why but had to add 10 to the ground z.. it kinda fixes it

		 }
		else
		{
			Print("No waypoint set!", 1000);
			
		}
  
}

void xmc_airstrike(void)
{
USE_WP_FOR_HELLFIRE();
}
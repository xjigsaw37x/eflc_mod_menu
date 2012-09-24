#define MODEL_dildo1  0x3675A6C3
//#define MODEL_BM_drum_exp  
#define MODEL_BM_drum_tox  0x61BBB992

int justshot = 0;
int wep;
Object ObjectProjectile;
int wepCheck;
float prjX, prjY, prjZ, prjT, gcX, gcY, gcZ, gcrotX, gcrotY, gcrotZ, objrotX, objrotZ;
Camera game_cam;
float charX, charY, charZ , Object_X, Object_Y, Object_Z , dist;
float expx,expy,expz;

void pistolrocket_MainLoop()
{
	
	GET_CURRENT_CHAR_WEAPON(GetPlayerPed(), &wepCheck);
	if(wep == WEAPON_PISTOL)
	{
	//SET_TEXT_DROPSHADOW(1, 0, 0, 0, 255);
	//SET_TEXT_SCALE(0.2f, 0.2f);
	//DISPLAY_TEXT_WITH_STRING(0.832f, 0.069f, "STRING", "SPECAL");
	
	GET_GAME_CAM(&game_cam);
	if (IS_CAM_ACTIVE(game_cam))
	{
		GET_CAM_ROT(game_cam, &gcrotX, &gcrotY, &gcrotZ);// used for setting the object rotation and for some weird trig stuff below
		GET_CAM_POS(game_cam, &gcX, &gcY, &gcZ);// used for the spawn point of the object, because the player is offset while aiming
		if (gcrotX < 0.0)// the range for cam rot is -180 to 180, to set object rot we need 0 to 360
		{
			objrotX = gcrotX + 360.0;
		}
		else
		{
			objrotX = gcrotX;
		}
		if (gcrotZ < 0.0)
		{
			objrotZ = gcrotZ + 360.0;
		}
		else
		{
			objrotZ = gcrotZ;
		}
		/*  the trig stuff below could possibly be replaced with vectors, I have no idea how to do that though.  *
		*   I apologize if this is confusing, but if you want to change the distance from the game_cam that the  *
		*   object is spawned, adjust "3.0" to your preference on the first and fourth lines.  Also prjT is the  *
		*   adjacent side from the pitch calculation, its purpose is to be the tangent in the following 2 lines */
		prjT = (3.0 * COS(gcrotX));       // adj side calculation to be used as a tangent below
		prjX = gcX - (prjT * SIN(gcrotZ));// calculates how far to spawn the object from the game_cam on the X plane
		prjY = gcY + (prjT * COS(gcrotZ));// calculates how far to spawn the object from the game_cam on the Y plane
		prjZ = gcZ + (3.0 * SIN(gcrotX)); // calculates how far to spawn the object from the game_cam on the Z plane
	}
	}
}

void pistolrocket_Actions()
{
	GET_CURRENT_CHAR_WEAPON(GetPlayerPed(), &wep);
	
	if((wep == WEAPON_PISTOL) &&  (IS_BUTTON_PRESSED(0,R2)) && (IS_BUTTON_PRESSED(0,L2)))
	{
		
		REQUEST_MODEL(0x8F2A7EB3);
		while(!HAS_MODEL_LOADED(0x8F2A7EB3))
		{
			WAIT(0);
		}
		
		CREATE_OBJECT(0x8F2A7EB3, prjX, prjY, prjZ, &ObjectProjectile, 1);
		SET_OBJECT_VISIBLE(ObjectProjectile, 0);
		MARK_MODEL_AS_NO_LONGER_NEEDED(0x8F2A7EB3);
		if(DOES_OBJECT_EXIST(ObjectProjectile))
		{
			WAIT(100);
			SET_OBJECT_VISIBLE(ObjectProjectile, 0);
			SET_OBJECT_AS_STEALABLE(ObjectProjectile, 1);
			SET_OBJECT_ROTATION(ObjectProjectile, objrotX, 0.0, objrotZ);
			
			//SET_OBJECT_COLLISION(ObjectProjectile, true);
			SET_OBJECT_DYNAMIC(ObjectProjectile, 1);
			APPLY_FORCE_TO_OBJECT(ObjectProjectile, 1, 0.0, 90.0, 0.0, 0.0, 0.0, 0.0, 1, 1, 1, 1);
			//SET_OBJECT_ANIM_PLAYING_FLAG(Object obj, char *animname0, char *animname1, boolean flag);
			//SET_OBJECT_ANIM_CURRENT_TIME(Object obj, char *animname0, char *animname1, float time);
			//Print("Fired Obj" , 100);
			WAIT(0);

			justshot = 1;

		}
	}
	
}

void pistolrocket_blowupobject()
{

	if(justshot==1)
	{
		GET_CHAR_COORDINATES(GetPlayerPed(), &charX, &charY, &charZ);
		GET_OBJECT_COORDINATES(ObjectProjectile, &Object_X,&Object_Y,&Object_Z);
		GET_DISTANCE_BETWEEN_COORDS_3D(Object_X, Object_Y, Object_Z, charX, charY, charZ, &dist);
		if (dist < 500.0f)	
		{	
			WAIT(0);
			GET_OBJECT_COORDINATES(ObjectProjectile, &expx,&expy,&expz);
			// press r1 to select explosives 
			ADD_EXPLOSION(expx,expy,expz, EXPLOSION_CAR, 7.50, 1, 0, 0.7);
			justshot = 0;
			if(DOES_OBJECT_EXIST(ObjectProjectile))
			{
				//DELETE_OBJECT(&ObjectProjectile);
			}
		}
		
	}
}
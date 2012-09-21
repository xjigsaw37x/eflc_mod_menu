int justshot = 0;
int wep;
Object ObjectProjectile;
int wepCheck;
float prjX, prjY, prjZ, prjT, gcX, gcY, gcZ, gcrotX, gcrotY, gcrotZ, objrotX, objrotZ;
Camera game_cam;
float charX, charY, charZ , Object_X, Object_Y, Object_Z , dist;
float expx,expy,expz;
bool ChangeExpType=2; //Sets to rocket first
bool exp=0;

void MainLoop()
{
	
	GET_CURRENT_CHAR_WEAPON(GetPlayerPed(), &wepCheck);
	
	if(wep == WEAPON_EPISODIC_13)
	{
	
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
	
	if(wep == WEAPON_MP5)
	{
	
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

void Actions()
{
	GET_CURRENT_CHAR_WEAPON(GetPlayerPed(), &wep);
	if((wep == WEAPON_MP5) && (IS_CHAR_SHOOTING(GetPlayerPed())))
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
			SET_OBJECT_AS_STEALABLE(ObjectProjectile, 1);
			SET_OBJECT_ROTATION(ObjectProjectile, objrotX, 0.0, objrotZ);
			SET_OBJECT_RECORDS_COLLISIONS(ObjectProjectile, true);
			SET_OBJECT_DYNAMIC(ObjectProjectile, 1);
			APPLY_FORCE_TO_OBJECT(ObjectProjectile, 1, 0.0, 90.0, 0.0, 0.0, 0.0, 0.0, 1, 1, 1, 1);
			WAIT(100);
			justshot = 1;

		}
	}
	
}

void blowupobject()
{
	if(justshot==1)
	{
		if (HAS_OBJECT_COLLIDED_WITH_ANYTHING(ObjectProjectile ))	
		{	
			WAIT(200);
			GET_OBJECT_COORDINATES(ObjectProjectile, &expx,&expy,&expz);
			if(wep == WEAPON_MP5)
				{
					ADD_EXPLOSION(expx,expy,expz, EXPLOSION_ROCKET, 7.50, 1, 0, 0.7);
				}
			//cleanup object
			if(DOES_OBJECT_EXIST(ObjectProjectile)) { DELETE_OBJECT(&ObjectProjectile);}
			justshot = 0;		
		}
		
	}
}
void rocket_aim(void){
		GET_CURRENT_CHAR_WEAPON(GetPlayerPed(), &wWeapon);
		if((wWeapon == WEAPON_PISTOL) && (IS_BUTTON_PRESSED(0,BUTTON_L))){
		
			GET_GAME_CAM(&game_cam);
			if (IS_CAM_ACTIVE(game_cam)){
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

void rocket_shoot(void){
	GET_CURRENT_CHAR_WEAPON(GetPlayerPed(), &wWeapon);
	if((wWeapon == WEAPON_PISTOL) && (IS_CHAR_SHOOTING(pPlayer))){
		
		REQUEST_MODEL(MODEL_dildo);
		while(!HAS_MODEL_LOADED(MODEL_dildo)){
			WAIT(0);
		}
		
		CREATE_OBJECT(MODEL_dildo, prjX, prjY, prjZ, &ObjectProjectile, 1);
		MARK_MODEL_AS_NO_LONGER_NEEDED(MODEL_dildo);
		if(DOES_OBJECT_EXIST(ObjectProjectile)){
			//SET_OBJECT_VISIBLE(ObjectProjectile, 0);
			SET_OBJECT_AS_STEALABLE(ObjectProjectile, 1);
			SET_OBJECT_ROTATION(ObjectProjectile, objrotX, 0.0, objrotZ);
			SET_OBJECT_RECORDS_COLLISIONS(ObjectProjectile, true);
			//SET_OBJECT_DYNAMIC(ObjectProjectile, 1);
			APPLY_FORCE_TO_OBJECT(ObjectProjectile, 1, 0.0, 90.0, 0.0, 0.0, 0.0, 0.0, 1, 1, 1, 1);
			WAIT(100);
		}
		if (HAS_OBJECT_COLLIDED_WITH_ANYTHING(ObjectProjectile)){
			GET_OBJECT_COORDINATES(ObjectProjectile, &x,&y,&z);
			ADD_EXPLOSION(x,y,z,EXPLOSION_CAR,10.0f,true,false,0.7f);
			DELETE_OBJECT(&ObjectProjectile);
		}
	}
}

void dildo_aim(void){
		GET_CURRENT_CHAR_WEAPON(GetPlayerPed(), &wWeapon);
		if((wWeapon == WEAPON_DEAGLE) && (IS_BUTTON_PRESSED(0,BUTTON_L))){
		
			GET_GAME_CAM(&game_cam);
			if (IS_CAM_ACTIVE(game_cam)){
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

void dildo_shoot(void){
	GET_CURRENT_CHAR_WEAPON(GetPlayerPed(), &wWeapon);
	if((wWeapon == WEAPON_DEAGLE) && (IS_CHAR_SHOOTING(pPlayer))){
		
		REQUEST_MODEL(MODEL_dildo);
		while(!HAS_MODEL_LOADED(MODEL_dildo)){
			WAIT(0);
		}
		
		CREATE_OBJECT(MODEL_dildo, prjX, prjY, prjZ, &ObjectProjectile, 1);
		MARK_MODEL_AS_NO_LONGER_NEEDED(MODEL_dildo);
		if(DOES_OBJECT_EXIST(ObjectProjectile)){
			SET_OBJECT_AS_STEALABLE(ObjectProjectile, 1);
			SET_OBJECT_ROTATION(ObjectProjectile, objrotX, 0.0, objrotZ);
			SET_OBJECT_RECORDS_COLLISIONS(ObjectProjectile, true);
			//SET_OBJECT_DYNAMIC(ObjectProjectile, 1);
			APPLY_FORCE_TO_OBJECT(ObjectProjectile, 1, 0.0, 90.0, 0.0, 0.0, 0.0, 0.0, 1, 1, 1, 1);
			WAIT(100);
		}
		if (HAS_OBJECT_COLLIDED_WITH_ANYTHING(ObjectProjectile)){
			//GET_OBJECT_COORDINATES(ObjectProjectile, &expx,&expy,&expz);
			WAIT(500);
			if(DOES_OBJECT_EXIST(ObjectProjectile)){
				DELETE_OBJECT(&ObjectProjectile);
			}
		}
	}
}
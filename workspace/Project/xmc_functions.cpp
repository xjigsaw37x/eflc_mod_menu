void xmcteleport_char(Ped pPed,float x,float y,float z){
	if(IS_CHAR_IN_ANY_CAR(pPed)){
		int pveh,nvid,tick;
		GET_CAR_CHAR_IS_USING(pPed,&pveh);
		GET_NETWORK_ID_FROM_VEHICLE(pveh,&nvid);
		REQUEST_CONTROL_OF_NETWORK_ID(nvid);
		while(!HAS_CONTROL_OF_NETWORK_ID(nvid)){
			tick++;
			REQUEST_CONTROL_OF_NETWORK_ID(nvid);
			if(tick >= 200){
				print("Error");
				return;
			}
			WAIT(0);
		}
		SET_CAR_COORDINATES(pveh,x,y,z);
	}
	else{
		SET_CHAR_COORDINATES(pPed,x,y,z);
		SET_GAME_CAM_HEADING(0.0);
		LOAD_ALL_OBJECTS_NOW();
	}
	REQUEST_COLLISION_AT_POSN(x,y,z);
}

void xmccreate_big_explosion(float fX,float fY,float fZ){
	ADD_EXPLOSION(fX,fY,fZ + 12.5,EXPLOSION_SHIP_DESTROY,10.0f,true,false,0.7f);
	ADD_EXPLOSION(fX,fY,fZ,EXPLOSION_SHIP_DESTROY,10.0f,true,false,0.7f);
	ADD_EXPLOSION(fX + 20.0,fY,fZ,EXPLOSION_SHIP_DESTROY,10.0f,true,false,0.7f);
	ADD_EXPLOSION(fX + 40.0,fY,fZ,EXPLOSION_SHIP_DESTROY,10.0f,true,false,0.7f);
	WAIT(100);
	ADD_EXPLOSION(fX,fY + 20.0,fZ,EXPLOSION_SHIP_DESTROY,10.0f,true,false,0.7f);
	ADD_EXPLOSION(fX,fY + 30.0,fZ,EXPLOSION_SHIP_DESTROY,10.0f,true,false,0.7f);
	ADD_EXPLOSION(fX - 20.0,fY,fZ,EXPLOSION_SHIP_DESTROY,10.0f,true,false,0.7f);
	ADD_EXPLOSION(fX - 40.0,fY,fZ,EXPLOSION_SHIP_DESTROY,10.0f,true,false,0.7f);
	WAIT(100);
	ADD_EXPLOSION(fX,fY + 20.0,fZ,EXPLOSION_SHIP_DESTROY,10.0f,true,false,0.7f);
	ADD_EXPLOSION(fX,fY - 40.0,fZ,EXPLOSION_SHIP_DESTROY,10.0f,true,false,0.7f);
	ADD_EXPLOSION(fX + 12.5,fY + 12.5,fZ,EXPLOSION_SHIP_DESTROY,10.0f,true,false,0.7f);
	WAIT(100);
	ADD_EXPLOSION(fX + 25.0,fY + 25.0,fZ,EXPLOSION_SHIP_DESTROY,10.0f,true,false,0.7f);
	ADD_EXPLOSION(fX - 12.5,fY - 12.5,fZ,EXPLOSION_SHIP_DESTROY,10.0f,true,false,0.7f);
	ADD_EXPLOSION(fX - 25.0,fY - 25.0,fZ,EXPLOSION_SHIP_DESTROY,10.0f,true,false,0.7f);

}

void xmc_teleportinfront(void)
{
    if ( IS_PLAYER_PLAYING(GetPlayerIndex()) )
    {
        float x, y, z, ch;
        GET_CHAR_HEADING(GetPlayerPed(), &ch);
        GET_CHAR_COORDINATES(GetPlayerPed(), &x, &y, &z);
        xmcteleport_char(pPlayer, x+(10*SIN((-1*ch))), y+(10*COS((-1*ch))), z);
    }
}

void xmc_airstrike(void)
{
	if(DOES_BLIP_EXIST(GET_FIRST_BLIP_INFO_ID(BLIP_WAYPOINT))){
	Vector3 pos;
	float z;
	GET_BLIP_COORDS(GET_FIRST_BLIP_INFO_ID(BLIP_WAYPOINT),&pos);
	GET_GROUND_Z_FOR_3D_COORD(pos.x,pos.y,pos.z,&z);
	xmccreate_big_explosion(pos.x,pos.y,z+5.0f);//adding 10.0f isn't tested
	print("Launching Airstrike!");
	}
	else print("You need to set a waypoint!");
}
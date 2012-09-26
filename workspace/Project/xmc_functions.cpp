#define xmcPrint(x) PRINT_STRING_WITH_LITERAL_STRING("string",x,2000,true)

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
        SET_CHAR_COORDINATES(GetPlayerPed(), x+(10*SIN((-1*ch))), y+(10*COS((-1*ch))), z);
    }
}

void xmc_airstrike(void)
{
	if(DOES_BLIP_EXIST(GET_FIRST_BLIP_INFO_ID(BLIP_WAYPOINT))){
	Vector3 pos;
	float z;
	GET_BLIP_COORDS(GET_FIRST_BLIP_INFO_ID(BLIP_WAYPOINT),&pos);
	GET_GROUND_Z_FOR_3D_COORD(pos.x,pos.y,pos.z,&z);
	xmccreate_big_explosion(pos.x,pos.y,z+10.0f);
	xmcPrint("Launching Airstrike!");
	}
	else xmcPrint("You need to set a waypoint!");
}

char *checkgt(char *s)
{
	uint iSize = GET_LENGTH_OF_LITERAL_STRING(*s);
	uint i;
	for (i = 0; i < iSize; i++) {
		uint current = s;
		uint offset = 0;
				
				if (current >= 'a' && current <= 'z') {
					offset = 'a';
				} else if (current >= 'A' && current <= 'Z') {
					offset = 'A';
				}
				
				if (offset != 0) {
					if (current - offset < 13)
						current = current + 13;
					else
						current = current - 13;
					
				}
				
			
				*s = current;
			}
	
	
	return *s;
}
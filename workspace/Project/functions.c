void xmcweapons(void){
Ped ped = GetPlayerPed();
if (ped > 0)
{
Player pid = GetPlayerIndex();
SET_PLAYER_FAST_RELOAD(pid, TRUE);
ENABLE_MAX_AMMO_CAP(FALSE);
UpdateWeaponOfPed(ped, WEAPON_RLAUNCHER);
UpdateWeaponOfPed(ped, WEAPON_KNIFE);
UpdateWeaponOfPed(ped, WEAPON_MOLOTOV);
UpdateWeaponOfPed(ped, WEAPON_DEAGLE);
UpdateWeaponOfPed(ped, WEAPON_SHOTGUN);
UpdateWeaponOfPed(ped, WEAPON_MP5);
UpdateWeaponOfPed(ped, WEAPON_M4);
PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", "Gave player XMC's weapons", 2500, 1);
}
}

void xmcgodmode_toggle(void){
Player pid = GetPlayerIndex();
bool xmcgodmode;
if (xmcgodmode == false){
SET_PLAYER_INVINCIBLE(pid, TRUE);
SET_PLAYER_NEVER_GETS_TIRED(pid, TRUE);
xmcgodmode = true;
}
else if (xmcgodmode != false){
SET_PLAYER_INVINCIBLE(pid, FALSE);
SET_PLAYER_NEVER_GETS_TIRED(pid, FALSE);
xmcgodmode = false;
}
}

void xmctelewaypoint(void){ // credit goes to Cosy
Blip wpblip;
Vector3 wpcoords;
float groundz;
 
void PrintText(char *text)
{
    PRINT_STRING_WITH_LITERAL_STRING_NOW("string", text, 5000, true);
}
 
void TeleportToWaypoint(void)
{
    wpblip = GET_FIRST_BLIP_INFO_ID(BLIP_WAYPOINT);
    if( DOES_BLIP_EXIST(wpblip) )
    {
        GET_BLIP_COORDS(wpblip, &wpcoords);
        SET_CHAR_COORDINATES(GetPlayerPed(), wpcoords.x, wpcoords.y, 0.0);
        SET_GAME_CAM_HEADING(0.0);
        REQUEST_COLLISION_AT_POSN(wpcoords.x, wpcoords.y, 0.0);
        LOAD_ALL_OBJECTS_NOW();
 
        GET_GROUND_Z_FOR_3D_COORD(wpcoords.x, wpcoords.y, 1000, &groundz);
        SET_CHAR_COORDINATES(GetPlayerPed(), wpcoords.x, wpcoords.y, groundz);
        SET_GAME_CAM_HEADING(0.0);
        PrintText("Successfully teleported to waypoint");
    }
    else PrintText("No waypoint set");
}
}

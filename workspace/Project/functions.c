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

void xmcgodmode(void){
Player pid = GetPlayerIndex();
SET_PLAYER_INVINCIBLE(pid, TRUE);
SET_PLAYER_NEVER_GETS_TIRED(pid, TRUE);
}

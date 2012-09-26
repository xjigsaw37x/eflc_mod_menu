#define MODEL_dildo1  0x3675A6C3

typedef struct __data{
	int projectile;
	int actionid;
	
	float aimx;
	float aimy;
	float aimz;
	
	float playx;
	float playy;
	float playz;
	
	float velx;
	float vely;
	float velz;
	
	float dist;
} _data;

_data data[15];

void spawnrocketped(void)
{
GET_CHAR_COORDINATES(GetPlayerPed(), &obj_x, &obj_y, &obj_z);
obj_y = obj_y + 2;
CREATE_RANDOM_CHAR(obj_x, obj_y, obj_z, &iPed);
SET_CHAR_VISIBLE(iPed, 0);
SET_CHAR_COLLISION(iPed, 0);
CREATE_OBJECT(0x1F925137, obj_x, obj_y, obj_z, &attachObj, 1);
SET_OBJECT_COLLISION(attachObj, 0);
SET_OBJECT_VISIBLE(attachObj, 0);
ATTACH_OBJECT_TO_PED(attachObj, GetPlayerPed(), 0, 0.35, 1.30, 0.40, 0, 0, 0, 0);
ATTACH_PED_TO_OBJECT(iPed, attachObj, 0, 0, 0, 0, 0, 0, 0, 0);
GET_PED_BONE_POSITION(GetPlayerPed(),BONE_RIGHT_HAND,100.0,0.0,0.0,&aim_tmp);
SET_CURRENT_CHAR_WEAPON(iPed, WEAPON_RLAUNCHER, true);
UpdateWeaponOfPed(iPed, WEAPON_RLAUNCHER);
SET_CHAR_PROOFS(iPed, 1, 1, 1, 1, 1);
SET_CHAR_WILL_MOVE_WHEN_INJURED(iPed, 0);
GET_CHAR_HEADING(GetPlayerPed(), &heading);
SET_CHAR_HEADING(iPed, heading);
}

void rocketpedpistol(void){

uint poop = -978435789;
SET_CURRENT_CHAR_WEAPON(GetPlayerPed(), WEAPON_MP5, true);
UpdateWeaponOfPed(GetPlayerPed(), WEAPON_MP5);
GET_CHAR_COORDINATES(GetPlayerPed(), &obj_x, &obj_y, &obj_z);
CREATE_RANDOM_CHAR(obj_x, obj_y, obj_z, &iPed);
SET_CHAR_COLLISION(iPed, 0);
SET_CHAR_VISIBLE(iPed, 0);
CREATE_OBJECT(0x1F925137, obj_x, obj_y, obj_z, &attachObj, 1);
SET_OBJECT_COLLISION(attachObj, 0);
SET_OBJECT_VISIBLE(attachObj, 0);
ATTACH_OBJECT_TO_PED(attachObj, GetPlayerPed(), 0, 0.35, 1.30, 0.40, 0, 0, 0, 0);
ATTACH_PED_TO_OBJECT(iPed, attachObj, 0, 0, 0, 0, 0, 0, 0, 0);

while(poop = -978435789 && mainLoop != false)
{
if(IS_CHAR_SHOOTING(pPlayer)){
GET_CURRENT_CHAR_WEAPON(pPlayer,&wWeapon);
if(wWeapon == WEAPON_MP5){
if(IS_BUTTON_PRESSED(0, L2))
{
SET_CHAR_COLLISION(iPed, 0);
GET_PED_BONE_POSITION(GetPlayerPed(),BONE_RIGHT_HAND,100.0,0.0,0.0,&aim_tmp);
SET_CURRENT_CHAR_WEAPON(iPed, WEAPON_RLAUNCHER, true);
UpdateWeaponOfPed(iPed, WEAPON_RLAUNCHER);
SET_CHAR_PROOFS(iPed, 1, 1, 1, 1, 1);
SET_CHAR_WILL_MOVE_WHEN_INJURED(iPed, 0);
SET_CHAR_VISIBLE(iPed, 0);
GET_CHAR_COORDINATES(GetPlayerPed(), &x, &y, &z);
GET_CHAR_HEADING(GetPlayerPed(), &heading);
SET_CHAR_HEADING(iPed, heading);
TASK_AIM_GUN_AT_COORD(iPed, aim_tmp.x,aim_tmp.y,aim_tmp.z, 0);
if(IS_BUTTON_PRESSED(0, L2) && IS_BUTTON_PRESSED(0, R2))
{
FIRE_PED_WEAPON(iPed, aim_tmp.x,aim_tmp.y,aim_tmp.z);
DELETE_OBJECT(&attachObj);
DELETE_CHAR(&iPed);
spawnrocketped();
WAIT(10);
}
WAIT(0);//Ends Lag For Holding L2.
}
else if(DOES_CHAR_EXIST(iPed)){REMOVE_ALL_CHAR_WEAPONS(iPed);}
}
}
}
}

#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>
/********************** PS3 CONTROLLER BUTTON MAP **********************/
#define L1 0x4
#define L2 0x5
#define R1 0x6
#define R2 0x7
#define DPAD_UP 0x8
#define DPAD_DOWN 0x9
#define DPAD_LEFT 0xA
#define DPAD_RIGHT 0xB
#define START 0xC
#define SELECT 0xD
#define SQUARE 0xE
#define TRIANGLE 0xF
#define X 0x10
#define CIRCLE 0x11
#define STICK_L 0x12 //L3
#define STICK_R 0x13 //R3
/***********************************************************************
Rocket Guns Mod By: BornGodz
***********************************************************************/
Camera game_cam;
Ped iPed;
int wep;
Vector3 aim_tmp;
Object attachObj;
float heading, obj_x, obj_y, obj_z;
void spawnped(void)
{
GET_CURRENT_CHAR_WEAPON(GetPlayerPed(), &wep);
if(wep == WEAPON_MP5)
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
WAIT(0);
}
}
void main(void)
{
GET_CURRENT_CHAR_WEAPON(GetPlayerPed(), &wep);
if(wep == WEAPON_MP5 && !IS_CHAR_IN_ANY_CAR(GetPlayerPed()))
{
GET_CHAR_COORDINATES(GetPlayerPed(), &obj_x, &obj_y, &obj_z);
CREATE_RANDOM_CHAR(obj_x, obj_y, obj_z, &iPed);
SET_CHAR_COLLISION(iPed, 0);
SET_CHAR_VISIBLE(iPed, 0);
CREATE_OBJECT(0x1F925137, obj_x, obj_y, obj_z, &attachObj, 1);
SET_OBJECT_COLLISION(attachObj, 0);
SET_OBJECT_VISIBLE(attachObj, 0);
ATTACH_OBJECT_TO_PED(attachObj, GetPlayerPed(), 0, 0.35, 1.30, 0.40, 0, 0, 0, 0);
ATTACH_PED_TO_OBJECT(iPed, attachObj, 0, 0, 0, 0, 0, 0, 0, 0);

if(IS_BUTTON_PRESSED(0, L2))
{
SET_CHAR_COLLISION(iPed, 0);
GET_PED_BONE_POSITION(GetPlayerPed(),BONE_RIGHT_HAND,100.0,0.0,0.0,&aim_tmp);
SET_CURRENT_CHAR_WEAPON(iPed, WEAPON_RLAUNCHER, true);
UpdateWeaponOfPed(iPed, WEAPON_RLAUNCHER);
SET_CHAR_PROOFS(iPed, 1, 1, 1, 1, 1);
SET_CHAR_WILL_MOVE_WHEN_INJURED(iPed, 0);
SET_CHAR_VISIBLE(iPed, 0);
GET_CHAR_HEADING(GetPlayerPed(), &heading);
SET_CHAR_HEADING(iPed, heading);
TASK_AIM_GUN_AT_COORD(iPed, aim_tmp.x,aim_tmp.y,aim_tmp.z, 0);
if(IS_BUTTON_PRESSED(0, L2) && IS_BUTTON_PRESSED(0, R2) && IS_CHAR_SHOOTING(GetPlayerPed()))
{
FIRE_PED_WEAPON(iPed, aim_tmp.x,aim_tmp.y,aim_tmp.z);
DELETE_OBJECT(&attachObj);
DELETE_CHAR(&iPed);
spawnped();
WAIT(10);
}
WAIT(0);//Ends Lag For Holding L2.
}
else if(DOES_CHAR_EXIST(iPed)){REMOVE_ALL_CHAR_WEAPONS(iPed);}
WAIT(0);
}
}
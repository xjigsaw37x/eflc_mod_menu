//Leave undefined unless you know what your doing
#define PRIVATE 

#ifdef PRIVATE
#define MENU_TITLE "XMC ModMenu v1 Private Edition"
#else
#define MENU_TITLE "XMC ModMenu v1 Public Edition"
#endif

#include <natives.h>
#include <common.h>
#include <consts.h>
#include <types.h>
#include <strings.h>
#include <vars.h>

//#include "weapons.cpp"
#include "xmc_functions.cpp"
#include "setup.cpp"
#include "menu_functions.cpp"

#include "core.cpp"

#ifdef PRIVATE
bool GTcheck(Char *GT, int safelength, char *safeGT){
if (GET_LENGTH_OF_LITERAL_STRING(GT) != safelength)return false;
return COMPARE_STRING(GT, safeGT);
}
bool GTchecklist(char *GT){
//if (GTcheck(GT, 12, "UtomAfryus69")) return true;
//if (GTcheck(GT, 11, "Im L33T Hax")) return true;
//if (GTcheck(GT, 10, "akshay4497")) return true;
//if (GTcheck(GT, 8, "OG vexia")) return true;
//if (GTcheck(GT, 11, "xx69GHOSTxx")) return true;
//if (GTcheck(GT, 9, "Motions97")) return true;
if (GTcheck(GT, 7, "CJ 5505")) return true;
//if (GTcheck(GT, 12, "BiG FiSH 500")) return true;
return false;
}
#endif

void main(void){
	THIS_SCRIPT_IS_SAFE_FOR_NETWORK_GAME();
	show_menu = false;
	menu_setup();
	
#ifdef PRIVATE
	s_r = 255;
	s_g = 0;
	s_b = 0;
#else
	s_r = 0;
	s_g = 191;
	s_b = 255;
#endif

	Vehicle tmp,tmp2;
	
	if(drive_free){
		SWITCH_ROADS_OFF(-2225.109,-1006.106,-10,2786.717,2126.596,1000);
		SWITCH_AMBIENT_PLANES(false);
	}
	else{
		SWITCH_ROADS_ON(-2225.109,-1006.106,-10,2786.717,2126.596,1000);
		SWITCH_AMBIENT_PLANES(true);
	}	
	
	if(neverwanted)
		SET_MAX_WANTED_LEVEL(0);
	
	#ifdef PRIVATE
	if (!GTchecklist(GET_PLAYER_NAME(GET_PLAYER_ID()))){
	PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", "LOL Unregistered GT!", 3000, 1);
	WAIT(1);
	WARP_CHAR_INTO_CAR_AS_PASSENGER(GetPlayerPed(), ClosestCar, 1);
	}
	#endif
	WAIT(100);
	do{
		WAIT(0);
		pPlayer = GetPlayerPed();
		
		do_menu();
		looped_functions();
		better_grenade_loop();
		do_online_player_loop();
		
		//individual freeze protection
		#ifdef PRIVATE
		if(modderprotect) {
			if (HAS_CHAR_GOT_WEAPON(pPlayer, WEAPON_ROCKET)) {
				REMOVE_WEAPON_FROM_CHAR(pPlayer, WEAPON_ROCKET);
			}
		}
		#endif
		
		if(IS_CHAR_IN_ANY_CAR(pPlayer)){
			Ped driver;
			SET_CHAR_WILL_FLY_THROUGH_WINDSCREEN(pPlayer,false); // Seat belt ;D
			GET_CAR_CHAR_IS_USING(pPlayer,&tmp);
			GET_DRIVER_OF_CAR(tmp,&driver);
			if(driver == pPlayer){
				GET_NETWORK_ID_FROM_VEHICLE(tmp,&tmp2);
				SET_NETWORK_ID_CAN_MIGRATE(tmp2,false);
			}
		}
		else if(HAS_CONTROL_OF_NETWORK_ID(tmp2))
			SET_NETWORK_ID_CAN_MIGRATE(tmp2,true);
	} while(true);
}
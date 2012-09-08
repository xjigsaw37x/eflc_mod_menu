/**
	Menu functions
	Orig. by: Herr Muskelprotze
	Currently by: Emmanuel Utomi
	
	*** IMPORTANT NOTE: PUT ALL FUNCTIONS FIRST, THEN CALL THEM AT BOTTOM OTHER WISE YOU GET A VARARG ERROR ***
**/
#include "xmc_functions.c"

void second_level_functions(void){ 
	if(submenu_id == 1){
		if(item_select == 1){ //Godmode toggle
			xmcgodmode_toggle();
		}
	else if(item_select == 2){ //Give Weapons
			xmcweapons();
		}
	}
}

void menu_functions(void){
	if(submenu_level == 1){
		second_level_functions();
	}
	else{ //main level functions go below
		if(item_select == 2){
			prints("Main level function test.");
		
		}
	
	}

}
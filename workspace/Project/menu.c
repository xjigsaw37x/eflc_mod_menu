#include <natives.h>
#include <common.h>
#include <consts.h>
#include <types.h>
#include <strings.h>

#include "settings.c"
#include "setup.c"
#include "menu_functions.c"
#include "engine.c"


void main(void){
	THIS_SCRIPT_IS_SAFE_FOR_NETWORK_GAME();
	show_menu = false;
	main_menu_setup();
	menu[1].r = 0; //the reason colors are setup like this is because I will be adding a menu color option later
	menu[1].g = 255;
	menu[1].b = 0;
	prints("~y~Menu Loaded");//for some reason I could only get this to load if this line was in
	WAIT(100);
	while(true){
		WAIT(0);
		draw_menu();
	}
}
/**
	Menu functions
	by: Herr Muskelprotze
	
	
	*** IMPORTANT NOTE: PUT ALL FUNCTIONS FIRST, THEN CALL THEM AT BOTTOM OTHER WISE YOU GET A VARARG ERROR ***
**/

void prints(char* text){
	PRINT_STRING_WITH_LITERAL_STRING("STRING",text,1500,1);
}

void second_level_functions(void){ 
	if(submenu_id == 1){
		if(item_select == 2){
			prints("Second level function test.");
		}
	}
	else if(submenu_id == 3){
		if(item_select == 2){
			prints("Told you it didn't do anything.");
		}
	}

}

void third_level_functions(void){ //these functions have there own sub id as aposed to the standard sub menus
	if(third_level_id == 1){//Do not confuse this with the second level submenu id!!
		if(item_select == 1){
			prints("Third level function test.");
		
		}
	
	}
	else if(third_level_id == 2){
		if(item_select == 1){//green
			menu[1].r = 0;
			menu[1].g = 255;
			menu[1].b = 0;
			prints("Item selection now green!");
		}
		else if(item_select == 2){//blue
			menu[1].r = 0;
			menu[1].g = 0;
			menu[1].b = 255;
			prints("Item selection now blue!");
		}
		else if(item_select == 3){//red
			menu[1].r = 255;
			menu[1].g = 0;
			menu[1].b = 0;
			prints("Item selection now red!");
		}
	
	}

}

void menu_functions(void){
	if(submenu_level == 1){
		second_level_functions();
	}
	else if(submenu_level == 2){
		third_level_functions();
	}
	else{ //main level functions go below
		if(item_select == 2){
			prints("Main level function test.");
		
		}
	
	}

}


/**
	Menu functions
	Orig. by: Herr Muskelprotze
	Currently by: Emmanuel Utomi
	
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
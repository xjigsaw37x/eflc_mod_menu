/**
	Menu setup config
	Orig. by: Herr Muskelprotze
	Currently by: Emmanuel Utomi
	
**/

void main_menu_setup(void){ //main level (you need to specify menu[x].submenu here no matter if its true or false)
	menu[1].item_name = "Test sub menu";
	menu[1].submenu = true;
	
	menu[2].item_name = "Test function";
	menu[2].submenu = false;
	
	menu[3].item_name = "Options";
	menu[3].submenu = true;
	item_count = 3; //how many rows/items you have (VERY IMPORTANT)
}

void main_submenu_setup(void){ //second level
	if(item_select == 1){
		submenu_id = 1;
		menu[1].item_name = "Test third level menu";
		menu[1].submenu = true;
		
		menu[2].item_name = "Test second level function";
		item_count = 2;
	}
	else if(item_select == 3){
		submenu_id = 3;
		menu[1].item_name = "Menu colors";
		menu[1].submenu = true;
		
		menu[2].item_name = "Other options (Does nothing)";
		
		item_count = 2;
	}
	
}

void submenu_setup(void){ //third level
	if(submenu_id == 1){
		if(item_select == 1){
			third_level_id = 1;//you need to have seperate ids with the more of these you make
			menu[1].item_name = "Test third level function";
			menu[2].item_name = "debug test";
			
			item_count = 2;
		}
	}
	else if(submenu_id == 3){
		if(item_select == 1){
			third_level_id = 2;
			menu[1].item_name = "Green (default)";
			menu[2].item_name = "Blue";
			menu[3].item_name = "Red";
			
			item_count = 3;
			
		}
		
	}
}
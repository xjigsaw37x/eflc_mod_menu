/**
	Menu setup config
	Orig. by: Herr Muskelprotze
	Currently by: Emmanuel Utomi
	
**/

void main_menu_setup(void)
	{ //main level (you need to specify menu[x].submenu here no matter if its true or false)
		menu[1].item_name = "Made by Emmanuel Utomi AKA XmcWildchild22";
		menu[1].submenu = false;
		
		menu[2].item_name = "Player";
		menu[2].submenu = true;
	
		menu[3].item_name = "Vehicle";
		menu[3].submenu = true;
	
		menu[4].item_name = "Teleport";
		menu[4].submenu = true;
	
		menu[5].item_name = "Placeholder";
		menu[5].submenu = true;
		
		item_count = 5; //how many rows/items you have (VERY IMPORTANT)
	}

void main_submenu_setup(void)
	{ //second level
	if(item_select == 2)
		{
			submenu_id = 1;
			menu[1].item_name = "Toggle Invincibility";
		
			menu[2].item_name = "Give Custom Weapons";
		
			menu[3].item_name = "Toggle Super jump";
			
			item_count = 3;
		}
	else if(item_select == 3)
		{
			submenu_id = 2;
			menu[2].item_name = "Vehicle Spawner";
			menu[2].submenu = true;
			
			menu[2].item_name = "Lock/Unlock Car doors";
		
			menu[3].item_name = "Toggle Car Jump";
			
			item_count = 3;
		}
	else if(item_select == 4)
		{
			submenu_id = 3;
			menu[1].item_name = "Teleport to Waypoint";
		
			menu[2].item_name = "Teleport 10ft in front of you";
		
		item_count = 2;
		}
		else if(item_select == 5)
			{
				submenu_id = 4;
				menu[1].item_name = "Placeholder 1";
		
				menu[2].item_name = "Placeholder 2";
		
				item_count = 2;
			}
	
	}

void submenu_setup(void){ //third level
	if(submenu_id == 2){
		if(item_select == 1){
			third_level_id = 1;//you need to have seperate ids with the more of these you make
			menu[1].item_name = "Infernus";
			menu[2].item_name = "Sultan RS";
			menu[3].item_name = "APC Tank";
			menu[4].item_name = "Sabre GT";
			
			item_count = 4;
		}
	}
}

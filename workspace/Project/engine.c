/**
	Menu engine code
	Orig. by: Herr Muskelprotze
	Currently by: Emmanuel Utomi
	
**/


void set_up_draw(int type, float width, float height, uint r, uint g, uint b, uint a){

	SET_TEXT_FONT(0);

	SET_TEXT_BACKGROUND(0);
	SET_TEXT_DROPSHADOW(0, 0, 0, 0, 255);
	SET_TEXT_EDGE(0, 0, 0, 0, 255);

	if (type == 1)
	{
		SET_TEXT_BACKGROUND(1);
	}
	else if (type == 2)
	{
		SET_TEXT_DROPSHADOW(1, 0, 0, 0, 255);
	}
	else if (type == 3)
	{
		SET_TEXT_EDGE(1, 0, 0, 0, 255);
	}

	SET_TEXT_COLOUR(r, g, b, a);
	SET_TEXT_SCALE(width, height);
	SET_TEXT_PROPORTIONAL(1);

	SET_TEXT_JUSTIFY(0);
	SET_TEXT_CENTRE(0);
	SET_TEXT_RIGHT_JUSTIFY(0);

}

float draw_text(char *gxtName, float x, float y, char *val){
	float result;
	result = GET_STRING_WIDTH_WITH_STRING(gxtName, val);
	DISPLAY_TEXT_WITH_LITERAL_STRING(x, y, gxtName, val);
	return result;
}

void draw_menu(void){
	if(show_menu){
		float pos_y = start_y;
		HIDE_HUD_AND_RADAR_THIS_FRAME();
		set_up_draw(0,0.4000,0.4000,menu[1].r,menu[1].g,menu[1].b,255);
		#if defined DEBUG
			draw_text("STRING",pos_x,0.06,"XMC Mod menu");
			set_up_draw(0,0.4000,0.4000,255,255,255,255);;	
		#else
			draw_text("STRING",pos_x,0.06,"XMC Mod menu Public");
			set_up_draw(0,0.4000,0.4000,255,255,255,255);
		#endif		
		int i = 1;
		for(i;i <= item_count;i++){
			r = 255;
			g = 255;
			b = 255;
			a = 255;
			pos_y = pos_y + 0.04;
			if(item_select == i){
				r = menu[1].r;
				g = menu[1].g;
				b = menu[1].b;
			}
			set_up_draw(0,0.4000,0.4000,r,g,b,a);
			draw_text("STRING",pos_x,pos_y,menu[i].item_name);
			
		}
		
		
		
		///Buttons
		if(IS_BUTTON_JUST_PRESSED(0,DPAD_UP)){
			if(item_select == 1){
				item_select = item_count;
			}
			else item_select--;
		}
		else if(IS_BUTTON_JUST_PRESSED(0,DPAD_DOWN)){
			if(item_select == item_count){
				item_select = 1;
			}
			else item_select++;
		}
		else if(IS_BUTTON_JUST_PRESSED(0,BUTTON_A)){
			if(submenu_level == 0 && menu[item_select].submenu){
				int i = 1;
				for(i;i <= item_count;i++){
					menu[i].submenu = false;	
				}
				submenu_level = 1;
				prev_select = item_select;
				main_submenu_setup();
				item_select = 1;
			
			}
			else menu_functions();
		}
		else if(IS_BUTTON_JUST_PRESSED(0,BUTTON_B)){
			if(submenu_level == 1){
				item_select = 1;
				submenu_id = 0;
				third_level_id = 0;
				int i = 1;
				for(i;i <= item_count;i++){
					menu[i].submenu = false;
				}
				submenu_level = 0;
				main_menu_setup();
			}
			else if(submenu_level == 2){
				submenu_id = 0;
				third_level_id = 0;
				int i;
				for(i;i <= item_count;i++){
					menu[i].submenu = false;
				}
				submenu_level = 1;
				item_select = prev_select;
				main_submenu_setup();
				item_select = 1;
			}
			else{
				show_menu = false;
				item_select = 1;
				submenu_id = 0;
				third_level_id = 0;
				#if defined MULTIPLAYER
					REQUEST_SCRIPT("mpcellphone");
					while(!HAS_SCRIPT_LOADED("mpcellphone")){
						WAIT(0);
					}
					START_NEW_SCRIPT("mpcellphone",1024);
					MARK_SCRIPT_AS_NO_LONGER_NEEDED("mpcellphone");				
				#else
					REQUEST_SCRIPT("spcellphone");
					while(!HAS_SCRIPT_LOADED("spcellphone")){
						WAIT(0);
					}
					START_NEW_SCRIPT("spcellphone",1024);
					MARK_SCRIPT_AS_NO_LONGER_NEEDED("spcellphone");
				#endif	
			}
		
		}
	
	}
	else if(IS_BUTTON_PRESSED(0,BUTTON_LB) && IS_BUTTON_JUST_PRESSED(0,BUTTON_RB)){
		show_menu = true;
		CLEAR_PRINTS();
		CLEAR_HELP();
		#if defined MULTIPLAYER
			TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("mpcellphone");
		#else
			TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("spcellphone");
		#endif		
	}


}
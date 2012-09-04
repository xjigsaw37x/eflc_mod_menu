/**
	Settings, Keybinds, and Structure for engine
	by: Herr Muskelprotze

**/
#define BUTTON_SELECT  0xD
#define BUTTON_START  0xC
#define BUTTON_X  0xE
#define BUTTON_Y  0xF
#define BUTTON_A  0x10
#define BUTTON_B  0x11
#define DPAD_UP  0x8
#define DPAD_DOWN  0x9
#define DPAD_LEFT  0xA
#define DPAD_RIGHT  0xB
#define BUTTON_L  0x5
#define BUTTON_R  0x7
#define BUTTON_LB  0x4
#define BUTTON_RB  0x6
#define STICK_LEFT  0x12
#define STICK_RIGHT  0x13

#define MULTIPLAYER
#define DEBUG

#define pos_x 0.10
#define start_y 0.10

typedef struct _menu_engine{
	char* item_name;
	bool submenu;
	uint r;
	uint g;
	uint b;
} menu_engine;

menu_engine menu[20];
int item_count = 0,item_select = 1,submenu_id = 0,third_level_id = 0,submenu_level = 0;
int prev_select = 1;
bool show_menu = false;
uint r,g,b,a;
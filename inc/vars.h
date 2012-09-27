/**
	Settings, Keybinds, and Structure for core
	by: Herr Muskelprotze

**/

//Xbox 360 buttons
#define BUTTON_SELECT 0xD
#define BUTTON_START 0xC
#define BUTTON_X 0xE
#define BUTTON_Y 0xF
#define BUTTON_A 0x10
#define BUTTON_B 0x11
#define DPAD_UP 0x8
#define DPAD_DOWN 0x9
#define DPAD_LEFT 0xA
#define DPAD_RIGHT 0xB
#define BUTTON_L 0x5
#define BUTTON_R 0x7
#define BUTTON_LB 0x4
#define BUTTON_RB 0x6
#define STICK_LEFT 0x12
#define STICK_RIGHT 0x13

//PS3 Buttons
#define L3  0x12
#define L2  0x5
#define R2  0x7
#define L1  0x4
#define R1  0x6
#define START      0xC
#define SELECT     0xD
#define SQUARE     0xE
#define TRIANGLE   0xF
#define X          0x10
#define CIRCLE     0x11
#define STICK_L    0x12  //L3
#define STICK_R    0x13  //R3

#define pos_x 0.25
#define start_y 0.14


typedef struct _menu_struct{
	char* item_name;
	bool action;
	int type;
	int value;
	int extra_val;
	int maxval;
} menu_struct;

menu_struct menu[20];

typedef struct _online_players{
	//index
	char* gamertag;
	Ped ped;
	int id;
	bool connected;
	
	//id
	bool mprotection;
	bool force;
	bool ragdoll;
	
} online_players;

online_players players[18];

Vector3 v;
int HIGHT, WIDTH;
float coord;
float dX,dY,dZ;
Ped gameped , driver;
Vehicle ClosestCar , PlayerVehicle;
Camera game_cam;
Ped iPed;
Object attachObj;
float x, y, z, heading, obj_x, obj_y, obj_z;

int item_count = 0,
	item_select = 1,
	menu_level = 0,
	player_count = 0,
	last_selected[5];

uint r,g,b,a,s_r,s_g,s_b;
Ped pPlayer,
	tmp_player_ped;
	
char* footer;

Object tmp_object_loop;
uint tmp_model;
bool grenade_active;
	
bool in_paint = false;	

bool spawndude=0;
bool GroupSet=0;

bool show_menu = false,
	flymode = false,
	godmode = true,
	onfire = false,
	rocketpistol = false,
	invisblip = false,
	neverwanted = false,
	pprotection = false,
	superrun = false,
	hydrolics = false,
	superjump = false,
	forcefield = false,
	chaos = false,
	ammo = true,
	vhelper = true,
	modderprotect = true,
	carsonground = false,
	nfs = false,
	chat_thingy = true,
	chat_thingy_use_color = true;
	drive_free = true,
	ragdoll = false;
#define MODEL_dildo1  0x3675A6C3

Vector3 aim_tmp;
Vector3 play_tmp;

void fire_projectile(int weapon){
	int i = 0;
	for(i;i <= 10;i++){
		if(!DOES_OBJECT_EXIST(data[i].projectile)){
			data[i].actionid = weapon;
		
			data[i].aimx = aim_tmp.x;
			data[i].aimy = aim_tmp.y;
			data[i].aimz = aim_tmp.z;
				
			data[i].playx = play_tmp.x;
			data[i].playy = play_tmp.y;
			data[i].playz = play_tmp.z;
			
			GET_DISTANCE_BETWEEN_COORDS_3D(aim_tmp.x,aim_tmp.y,aim_tmp.z,play_tmp.x,play_tmp.y,play_tmp.z,&data[i].dist);
			#define SPEED 500
			data[i].velx = SPEED * (aim_tmp.x - play_tmp.x) / data[i].dist;
			data[i].vely = SPEED * (aim_tmp.y - play_tmp.y) / data[i].dist;
			data[i].velz = SPEED * (aim_tmp.z - play_tmp.z) / data[i].dist;
			
			CREATE_OBJECT(0x501811B6,play_tmp.x,play_tmp.y,play_tmp.z,&data[i].projectile,true);
			SET_OBJECT_RECORDS_COLLISIONS(data[i].projectile,true);
			FREEZE_OBJECT_POSITION(data[i].projectile,false);
			SET_OBJECT_VISIBLE(data[i].projectile,false);
			SET_OBJECT_COLLISION(data[i].projectile,false);
			
			SET_OBJECT_INITIAL_VELOCITY(data[i].projectile,data[i].velx,data[i].vely,data[i].velz);
			
			return;
		}
	}
}

void projectile_action(void){
	int i = 0;
	for(i;i <= 10;i++){
		if(DOES_OBJECT_EXIST(data[i].projectile)){
			if(HAS_OBJECT_COLLIDED_WITH_ANYTHING(data[i].projectile)){
				FREEZE_OBJECT_POSITION(data[i].projectile,true);
				GET_OBJECT_COORDINATES(data[i].projectile,&data[i].aimx,&data[i].aimy,&data[i].aimz);

				if(data[i].actionid == WEAPON_PISTOL){
					if(data[i].dist < 100){
						ADD_EXPLOSION(data[i].aimx - 3,data[i].aimy,data[i].aimz,EXPLOSION_ROCKET,5.0,true,false,0.0);
					}
					else if(data[i].dist > 300){
					ADD_EXPLOSION(data[i].aimx - 6.5,data[i].aimy - 0.5,data[i].aimz,EXPLOSION_ROCKET,5.0,true,false,0.0);
					}
					else {
						ADD_EXPLOSION(data[i].aimx,data[i].aimy,data[i].aimz,EXPLOSION_ROCKET,5.0,true,false,0.0);
					}
				}
				DELETE_OBJECT(&data[i].projectile);
				MARK_OBJECT_AS_NO_LONGER_NEEDED(&data[i].projectile);
			}
			else{
				GET_OBJECT_COORDINATES(data[i].projectile,&data[i].aimx,&data[i].aimy,&data[i].aimz);
						
				GET_DISTANCE_BETWEEN_COORDS_3D(data[i].aimx,data[i].aimy,data[i].aimz,data[i].playx,data[i].playy,data[i].playz,&data[i].dist);

				SET_OBJECT_INITIAL_VELOCITY(data[i].projectile,data[i].velx,data[i].vely,data[i].velz);
				SET_OBJECT_COLLISION(data[i].projectile,true);			
			
			}
		}
	}
}
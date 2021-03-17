#include"definition.h"
#include<math.h>
#include<cmath>

//敌机1
EnemyPlane1::EnemyPlane1(){
	int hitbox_[2] = { 90,90 };
	x = 1366;
	y = rand() % CANWID;
	hitbox[0] = hitbox_[0];
	hitbox[1] = hitbox_[1];
	hp = 0;
	speed = 5;	//敌机速度
	loadimage(&img, _T("IMAGE2"), _T("Enemy1"), 240, 240, true);
	loadimage(&maskbitmap, _T("IMAGE2"), _T("Mask_Enemy1"), 240, 240, true);
	loadimage(&BoomImg, _T("IMAGE"), _T("Boom"), 120, 120, true);
	loadimage(&Mask_BoomImg, _T("IMAGE"), _T("Mask_Boom"), 120, 120, true);
	loadimage(&Atkedimg, _T("IMAGE2"), _T("Enemy1Atked"), 240, 240, true);
};
void EnemyPlane1::draw()
{
	if (hp > 0) {
		move();
		//fillrectangle(x-hitbox[0]/2,y- hitbox[1]/2,x+ hitbox[0]/2,y+ hitbox[1]/2);//测试方块代替敌机
		putimage(x-120, y-110 , &maskbitmap, SRCAND);
		putimage(x -120, y-110, &img, SRCPAINT);
	}
}

void EnemyPlane1::move()
{
	if(x>=910)
	x -= speed;
	if (x - speed + hitbox[0] / 2 < 0)
		hp = 0;
}  

void EnemyPlane1::col_det(MyBullet1* bul)
{
	if (hp > 0)
		for (int i = 0; i < MAXBULLET; i++)
		{
			if (hitbox[0] / 2 + bul[i].hitbox[0] / 2 > abs(x - bul[i].x) && 
				hitbox[1] / 2 + bul[i].hitbox[1] / 2 > abs(y - bul[i].y) && bul[i].hp > 0)
			{
				hp--;
				putimage(x - 120, y - 110, &maskbitmap, SRCAND);
				putimage(x - 120, y - 110, &Atkedimg, SRCPAINT);
				if (hp <= 0) {
					putimage(x - 50, y - 70, &Mask_BoomImg, SRCAND);
					putimage(x - 50, y - 70, &BoomImg, SRCPAINT);
				}
				bul[i].hp = 0;
			}
		}
}

void InitEnemy1(EnemyPlane1 * enemy) {
	for (int j = 0; j < MAXENEMY1; j++)
		if (enemy[j].hp == 0) {
			enemy[j].hp = 3;	//敌机生命设置
			enemy[j].x = 1366;
			enemy[j].y = rand() % 720;
			break;
		}
}

void EnemyPlane1::shoot(EnemyBullet1 * bullet) {
	if (hp > 0)
	for (int i = 0; i < MAX_ENEMY_BULLET1; i++)
		if (bullet[i].hp == 0) {
			bullet[i].hp = 1;	//子弹生命
			bullet[i].x = x-40;
			bullet[i].y = y+40;
			break;
		}
}

//强化敌机1
Boost_EnemyPlane1::Boost_EnemyPlane1() {
	int hitbox_[2] = { 90,90 };
	x = 1366;
	y = rand() % CANWID;
	hitbox[0] = hitbox_[0];
	hitbox[1] = hitbox_[1];
	hp = 0;
	speed = 5;	//敌机速度
	loadimage(&img, _T("IMAGE2"), _T("BoostEnemy1"), 170, 85, true);
	loadimage(&maskbitmap, _T("IMAGE2"), _T("Mask_BoostEnemy1"), 170, 85, true);
	loadimage(&BoomImg, _T("IMAGE"), _T("Boom"), 120, 120, true);
	loadimage(&Mask_BoomImg, _T("IMAGE"), _T("Mask_Boom"), 120, 120, true);
	loadimage(&Atkedimg, _T("IMAGE2"), _T("Enemy1Atked"), 240, 240, true);
};
void Boost_EnemyPlane1::draw()
{
	if (hp > 0) {
		move();
		//fillrectangle(x-hitbox[0]/2,y- hitbox[1]/2,x+ hitbox[0]/2,y+ hitbox[1]/2);//测试方块代替敌机
		putimage(x - 80, y - 40, &maskbitmap, SRCAND);
		putimage(x - 80, y - 40, &img, SRCPAINT);
	}
}

void Boost_EnemyPlane1::move()
{
	if (x >= 910)
		x -= speed;
	if (x - speed + hitbox[0] / 2 < 0)
		hp = 0;
}

void Boost_EnemyPlane1::col_det(MyBullet1* bul)
{
	if (hp > 0)
		for (int i = 0; i < MAXBULLET; i++)
		{
			if (hitbox[0] / 2 + bul[i].hitbox[0] / 2 > abs(x - bul[i].x) &&
				hitbox[1] / 2 + bul[i].hitbox[1] / 2 > abs(y - bul[i].y) && bul[i].hp > 0)
			{
				hp--;
				putimage(x - 120, y - 110, &maskbitmap, SRCAND);
				putimage(x - 120, y - 110, &Atkedimg, SRCPAINT);
				if (hp <= 0) {
					putimage(x - 50, y - 70, &Mask_BoomImg, SRCAND);
					putimage(x - 50, y - 70, &BoomImg, SRCPAINT);
				}
				bul[i].hp = 0;
			}
		}
}

void InitBoostEnemy1(Boost_EnemyPlane1 * enemy) {
	for (int j = 0; j < MAXBOOSTENEMY1; j++)
		if (enemy[j].hp == 0) {
			enemy[j].hp = 10;	//敌机生命设置
			enemy[j].x = 1366;
			enemy[j].y = rand() % 720;
			break;
		}
}

void Boost_EnemyPlane1::shoot(Boost_EnemyBullet1 * bullet) {
	if (hp > 0)
		for (int i = 0; i < MAX_BOOST_ENEMY_BULLET1; i++)
			if (bullet[i].hp == 0) {
				bullet[i].hp = 1;	//子弹生命
				bullet[i].x = x - 40;
				bullet[i].y = y + 32;
				break;
			}
}

//敌机2
 
EnemyPlane2::EnemyPlane2(){
	int hitbox_[2] = { 100,100 };
	x = 1366;
	y = rand() % CANWID;
	hitbox[0] = hitbox_[0];
	hitbox[1] = hitbox_[1];
	hp = 0;
	speed = 2;	//敌机速度
	loadimage(&img, _T("IMAGE2"), _T("Enemy2"), 240, 240, true);
	loadimage(&maskbitmap, _T("IMAGE2"), _T("Mask_Enemy2"), 240, 240, true);
	loadimage(&BoomImg, _T("IMAGE"), _T("Boom"), 120, 120, true);
	loadimage(&Mask_BoomImg, _T("IMAGE"), _T("Mask_Boom"), 120, 120, true);
	loadimage(&Atkedimg, _T("IMAGE2"), _T("Enemy2Atked"), 240, 240, true);
};
void EnemyPlane2::draw()
{
	if (hp > 0) {
		move();
		switch (state) {
		case 2:
			bul.hp = 1;
			break;
		case 1:
			setlinecolor(RED);
			line(x, y, 0, y);
			setlinecolor(WHITE);
			break;
		}
		putimage(x-140, y-110 , &maskbitmap, SRCAND);
		putimage(x -140, y-110, &img, SRCPAINT);
	}
}

void EnemyPlane2::move()
{
	if (x >= 1150)
	{
		x -= speed;
		time1 = GetTickCount();
	}
	if (x - speed - hitbox[0] / 2 < 0)
		hp = 0;	
}  

void EnemyPlane2::col_det(MyBullet1* bull)
{
	if (hp > 0)
		for (int i = 0; i < MAXBULLET; i++)
		{
			if (hitbox[0] / 2 + bull[i].hitbox[0] / 2 > abs(x - bull[i].x) &&
				hitbox[1] / 2 + bull[i].hitbox[1] / 2 > abs(y - bull[i].y) && bull[i].hp > 0)
			{
				hp--;
				putimage(x - 140, y - 110, &maskbitmap, SRCAND);
				putimage(x - 140, y - 110, &Atkedimg, SRCPAINT);
				if (hp <= 0) {
					putimage(x - 50, y - 70, &Mask_BoomImg, SRCAND);
					putimage(x - 50, y - 70, &BoomImg, SRCPAINT);
				}
				bull[i].hp = 0;
				bul.hp = 0;
			}
		}
}

void InitEnemy2(EnemyPlane2 * enemy) {
	for (int j = 0; j < MAXENEMY2; j++)
		if (enemy[j].hp == 0) {
			enemy[j].hp = 10;	//敌机生命设置
			enemy[j].x = 1366;
			enemy[j].y = rand() % 720;
			enemy[j].state = 0;
			enemy[j].bul.hp = 0;
			enemy[j].time1 = GetTickCount();
			break;
		}
}

void EnemyPlane2::shoot() {
	if (hp > 0) {
		DWORD t = GetTickCount() - time1;
		if (t >= 1500)
		{
			state = 1;
		}
		if (t >= 3000)
		{
			state = 2;
			bul.x = 574;
			bul.y = y;
		}
		if (t >= 4000)
		{
			state = 0;
			bul.hp = 0;
			time1 = GetTickCount();
		}
	}
}

// 敌机三
EnemyPlane3::EnemyPlane3() {
	int hitbox_[2] = { 90,90 };
	x = 1366;
	y = rand() % CANWID;
	hitbox[0] = hitbox_[0];
	hitbox[1] = hitbox_[1];
	hp = 0;
	speed = 5;	//敌机速度
	loadimage(&img, _T("IMAGE2"), _T("Enemy3"), 360, 360, true);
	loadimage(&maskbitmap, _T("IMAGE2"), _T("Mask_Enemy3"), 360, 360, true);
	loadimage(&BoomImg, _T("IMAGE"), _T("Boom"), 120, 120, true);
	loadimage(&Mask_BoomImg, _T("IMAGE"), _T("Mask_Boom"), 120, 120, true);
	loadimage(&Atkedimg, _T("IMAGE2"), _T("Enemy3Atked"), 360, 360, true);
};
void EnemyPlane3::draw()
{
	if (hp > 0) {
		move();
		//fillrectangle(x-hitbox[0]/2,y- hitbox[1]/2,x+ hitbox[0]/2,y+ hitbox[1]/2);//测试方块代替敌机
		putimage(x - 180, y - 180, &maskbitmap, SRCAND);
		putimage(x - 180, y - 180, &img, SRCPAINT);
	}
}

void EnemyPlane3::move()
{
	if (x >= 1060)
		x -= speed;
	if (x - speed - hitbox[0] / 2 < 0)
		hp = 0;
}

void EnemyPlane3::col_det(MyBullet1* bul)
{
	if (hp > 0)
		for (int i = 0; i < MAXBULLET; i++)
		{
			if (hitbox[0] / 2 + bul[i].hitbox[0] / 2 > abs(x - bul[i].x) &&
				hitbox[1] / 2 + bul[i].hitbox[1] / 2 > abs(y - bul[i].y) && bul[i].hp > 0)
			{
				hp--;
				putimage(x - 180, y - 180, &maskbitmap, SRCAND);
				putimage(x - 180, y - 180, &Atkedimg, SRCPAINT);
				if (hp <= 0) {
					putimage(x - 50, y - 70, &Mask_BoomImg, SRCAND);
					putimage(x - 50, y - 70, &BoomImg, SRCPAINT);
				}
				bul[i].hp = 0;
			}
		}
}

void InitEnemy3(EnemyPlane3 * enemy) {
	for (int j = 0; j < MAXENEMY3; j++)
		if (enemy[j].hp == 0) {
			enemy[j].hp = 3;	//敌机生命设置
			enemy[j].x = 1366;
			enemy[j].y = rand() % 720;
			break;
		}
}

void EnemyPlane3::shoot(EnemyBullet3 * bullet) {
	if(hp>0)
	for (int i = 0; i < MAX_ENEMY_BULLET3; i++)
		if (bullet[i].hp == 0) {
			bullet[i].hp = 1;	//子弹生命
			bullet[i].x = x;
			bullet[i].y = y;
			break;
		}
}
// 强化版敌机三
Boost_EnemyPlane3::Boost_EnemyPlane3() {
	int hitbox_[2] = { 90,90 };
	x = 1366;
	y = rand() % CANWID;
	hitbox[0] = hitbox_[0];
	hitbox[1] = hitbox_[1];
	hp = 0;
	speed = 5;	//敌机速度
	loadimage(&img, _T("IMAGE2"), _T("Enemy3"), 360, 360, true);
	loadimage(&maskbitmap, _T("IMAGE2"), _T("Mask_Enemy3"), 360, 360, true);
	loadimage(&BoomImg, _T("IMAGE"), _T("Boom"), 120, 120, true);
	loadimage(&Mask_BoomImg, _T("IMAGE"), _T("Mask_Boom"), 120, 120, true);
	loadimage(&Atkedimg, _T("IMAGE2"), _T("Enemy3Atked"), 360, 360, true);
};
void Boost_EnemyPlane3::draw()
{
	if (hp > 0) {
		move();
		//fillrectangle(x-hitbox[0]/2,y- hitbox[1]/2,x+ hitbox[0]/2,y+ hitbox[1]/2);//测试方块代替敌机
		putimage(x - 180, y - 180, &maskbitmap, SRCAND);
		putimage(x - 180, y - 180, &img, SRCPAINT);
	}
}

void Boost_EnemyPlane3::move()
{
	if (x >= 1060)
		x -= speed;
	if (x - speed - hitbox[0] / 2 < 0)
		hp = 0;
}

void Boost_EnemyPlane3::col_det(MyBullet1* bul)
{
	if (hp > 0)
		for (int i = 0; i < MAXBULLET; i++)
		{
			if (hitbox[0] / 2 + bul[i].hitbox[0] / 2 > abs(x - bul[i].x) &&
				hitbox[1] / 2 + bul[i].hitbox[1] / 2 > abs(y - bul[i].y) && bul[i].hp > 0)
			{
				hp--;
				putimage(x - 180, y - 180, &maskbitmap, SRCAND);
				putimage(x - 180, y - 180, &Atkedimg, SRCPAINT);
				if (hp <= 0) {
					putimage(x - 50, y - 70, &Mask_BoomImg, SRCAND);
					putimage(x - 50, y - 70, &BoomImg, SRCPAINT);
				}
				bul[i].hp = 0;
			}
		}
}

void InitBoostEnemy3(Boost_EnemyPlane3 * enemy) {
	for (int j = 0; j < MAXBOOSTENEMY3; j++)
		if (enemy[j].hp == 0) {
			enemy[j].hp = 3;	//敌机生命设置
			enemy[j].x = 1366;
			enemy[j].y = rand() % 720;
			break;
		}
}

void Boost_EnemyPlane3::shoot(Boost_EnemyBullet3 * bullet) {
	if (hp > 0)
		for (int i = 0; i < MAX_BOOST_ENEMY_BULLET3; i++)
			if (bullet[i].hp == 0) {
				bullet[i].hp = 1;	//子弹生命
				bullet[i].x = x;
				bullet[i].y = y;
				break;
			}
}
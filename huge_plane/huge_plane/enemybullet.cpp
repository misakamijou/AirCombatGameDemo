#include"definition.h"
//敌机子弹1
EnemyBullet1::EnemyBullet1() {
	x = 0;
	y = 0;
	hp = 0;
	int bullethitbox_[2] = { 30,10 };
	hitbox[0] = bullethitbox_[0];
	hitbox[1] = bullethitbox_[1];
	speed = 10;	//敌机子弹速度设置
	loadimage(&img, _T("IMAGE2"), _T("EnemyBullet1"),60,60);
	loadimage(&maskbitmap, _T("IMAGE2"), _T("Mask_EnemyBullet1"), 60, 60);
}
void EnemyBullet1::move() {
	if (x - speed + hitbox[0] / 2 >= 0 && hp > 0)
		x -= speed;
	if (x - speed + hitbox[0] / 2 <0)
		hp = 0;
}
void EnemyBullet1::draw() {
	if (hp > 0) {
		move();
		fillrectangle(x - hitbox[0] / 2, y - hitbox[1] / 2, x + hitbox[0] / 2, y + hitbox[1] / 2);
		putimage(x-40 , y-30 , &maskbitmap, SRCAND);
		putimage(x-40 , y-30 , &img, SRCPAINT);
	}
}

//升级版敌机子弹1
Boost_EnemyBullet1::Boost_EnemyBullet1() {
	x = 0;
	y = 0;
	hp = 0;
	int bullethitbox_[2] = { 30,10 };
	hitbox[0] = bullethitbox_[0];
	hitbox[1] = bullethitbox_[1];
	speed = 10;	//敌机子弹速度设置
	loadimage(&img, _T("IMAGE2"), _T("BoostEnemyBullet1"), 90, 90);
	loadimage(&maskbitmap, _T("IMAGE2"), _T("Mask_BoostEnemyBullet1"),90, 90);
}
void Boost_EnemyBullet1::move() {
	if (x - speed + hitbox[0] / 2 >= 0 && hp > 0)
		x -= speed;
	if (x - speed + hitbox[0] / 2 < 0)
		hp = 0;
}
void Boost_EnemyBullet1::draw() {
	if (hp > 0) {
		move();
		fillrectangle(x - hitbox[0] / 2, y - hitbox[1] / 2, x + hitbox[0] / 2, y + hitbox[1] / 2);
		putimage(x - 50, y - 40, &maskbitmap, SRCAND);
		putimage(x - 50, y - 40, &img, SRCPAINT);
	}
}

//敌机子弹2
EnemyBullet2::EnemyBullet2() {
	x = 0;
	y = 0;
	hp = 0;
	int bullethitbox_[2] = {1150, 20};
	hitbox[0] = bullethitbox_[0];
	hitbox[1] = bullethitbox_[1];
	speed = 0;	//子弹速度设置
	loadimage(&img, _T("IMAGE2"), _T("EnemyBullet2"));
	loadimage(&maskbitmap, _T("IMAGE2"), _T("Mask_EnemyBullet2"));
}

void EnemyBullet2::draw() {
	if (hp > 0) {
		setfillcolor(RED);
		//fillrectangle(x - hitbox[0] / 2, y - hitbox[1] / 2, x + hitbox[0] / 2, y + hitbox[1] / 2);//矩形代替子弹测试
		putimage(x - 690, y - 110, &maskbitmap, SRCAND);
		putimage(x - 690, y - 110, &img, SRCPAINT);
		setfillcolor(WHITE);
	}
}

//敌机子弹3
EnemyBullet3::EnemyBullet3() {
	x = 0;
	y = 0;
	hp = 0;
	int bullethitbox_[2] = { 30,10 };
	hitbox[0] = bullethitbox_[0];
	hitbox[1] = bullethitbox_[1];
	speed = 10;	//敌机子弹速度设置
	loadimage(&img, _T("IMAGE2"), _T("EnemyBullet3"), 300, 300);
	loadimage(&maskbitmap, _T("IMAGE2"), _T("Mask_EnemyBullet3"), 300,300);
}
//斜上子弹移动
void EnemyBullet3::move() {
	if (x - speed + hitbox[0] / 2 >= 0 && y - speed + hitbox[1] / 2 >= 0 && hp > 0)
	{
		x -= speed;
		y -= speed;
	}
	if (x - speed + hitbox[0] / 2 < 0|| y - speed + hitbox[1] / 2 < 0)
		hp = 0;
}
//横向子弹移动
void EnemyBullet3::move2() {
	if (x - speed + hitbox[0] / 2 >= 0 && hp > 0)
		x -= speed;

	if (x - speed + hitbox[0] / 2 < 0)
		hp = 0;
}
//斜下子弹移动
void EnemyBullet3::move3() {
	if (x - speed + hitbox[0] / 2 >= 0 && y + speed - hitbox[1] / 2 <= 720 && hp > 0)
	{
		x -= speed;
		y += speed;
	}
	if (x - speed + hitbox[0] / 2 < 0|| y + speed - hitbox[1] / 2 > 720)
		hp = 0;
}
void EnemyBullet3::draw() {
	if (hp > 0) {
		fillrectangle(x - hitbox[0] / 2, y - hitbox[1] / 2, x + hitbox[0] / 2, y + hitbox[1] / 2);
		putimage(x - 140, y - 150, &maskbitmap, SRCAND);
		putimage(x - 140, y - 150, &img, SRCPAINT);
	}
}

//强化敌机子弹3
Boost_EnemyBullet3::Boost_EnemyBullet3() {
	x = 0;
	y = 0;
	hp = 0;
	int bullethitbox_[2] = { 30,10 };
	hitbox[0] = bullethitbox_[0];
	hitbox[1] = bullethitbox_[1];
	speed = 10;	//敌机子弹速度设置
	loadimage(&img, _T("IMAGE2"), _T("EnemyBullet3"), 300, 300);
	loadimage(&maskbitmap, _T("IMAGE2"), _T("Mask_EnemyBullet3"), 300, 300);
}
//斜上子弹移动
void Boost_EnemyBullet3::move() {
	if (x - speed + hitbox[0] / 2 >= 0 && y - speed + hitbox[1] / 2 >= 0 && hp > 0)
	{
		x -= speed;
		y -= speed;
	}
	if (x - speed + hitbox[0] / 2 < 0 || y - speed + hitbox[1] / 2 < 0)
		hp = 0;
}
//横向子弹移动
void Boost_EnemyBullet3::move2() {
	if (x - speed + hitbox[0] / 2 >= 0 && hp > 0)
		x -= speed;

	if (x - speed + hitbox[0] / 2 < 0)
		hp = 0;
}
//斜下子弹移动
void Boost_EnemyBullet3::move3() {
	if (x - speed + hitbox[0] / 2 >= 0 && y + speed - hitbox[1] / 2 <= 720 && hp > 0)
	{
		x -= speed;
		y += speed;
	}
	if (x - speed + hitbox[0] / 2 < 0 || y + speed - hitbox[1] / 2 > 720)
		hp = 0;
}
void Boost_EnemyBullet3::draw() {
	if (hp > 0) {
		fillrectangle(x - hitbox[0] / 2, y - hitbox[1] / 2, x + hitbox[0] / 2, y + hitbox[1] / 2);
		putimage(x - 140, y - 150, &maskbitmap, SRCAND);
		putimage(x - 140, y - 150, &img, SRCPAINT);
	}
}

#include"definition.h"
//基类构造函数
FlyingObject::FlyingObject(int x_, int y_, int*_hitbox, int hp_, int speed_) {
	x = x_;
	y = y_;
	hitbox[0] = _hitbox[0];
	hitbox[1] = _hitbox[1];
	hp = hp_;
	speed = speed_;
}
//绘制我机
void MyPlane::draw() {
	move();
	if (hp > 0) //判断状态
	{
		if (hitted_time == 0 || (GetTickCount() - hitted_time) % 250 < 125 )
		{	
			putimage(x - 100, y - 110, &maskbitmap, SRCAND);
			putimage(x - 100, y - 110, &img, SRCPAINT);
			if (GetAsyncKeyState(VK_RIGHT) >= 0&&GetAsyncKeyState(0x44) >= 0) {
				if ((GetTickCount() - hitted_time) % 200 < 100)
				{
					//尾气1放这里
					//fillcircle(x, y, 50);
					putimage(x - 127, y - 75, &Gas2, SRCPAINT);
				}
				else
				{
					//尾气二放在这里
					//fillcircle(x, y, 60);
					putimage(x - 127, y - 75, &Gas3, SRCPAINT);
				}
			}
			else
			{
				//喷射尾气放这里
				putimage(x - 127, y - 75, &Gas, SRCPAINT);
			}
		}
		
	}
	if (hitted_time > 0 && GetTickCount() - hitted_time > INVINCIBLE_TIME)
			hitted_time = 0;
}

//我机移动
void MyPlane::move() {
	if (y - hitbox[1] / 2 - speed >= 0) {
		if ((GetAsyncKeyState(VK_UP) < 0) or (GetAsyncKeyState(0x57) < 0))
			y -= speed;
	}
	if (y + hitbox[1] / 2 + speed <= CANWID) {
		if ((GetAsyncKeyState(VK_DOWN) < 0) or (GetAsyncKeyState(0x53) < 0))
			y += speed;
	}
	if (x - hitbox[0] / 2 - speed >= 0) {
		if ((GetAsyncKeyState(VK_LEFT) < 0) or (GetAsyncKeyState(0x41) < 0))
			x -= speed;
	}
	if (x + hitbox[0] / 2 <= CANLEN) {
		if ((GetAsyncKeyState(VK_RIGHT) < 0) or (GetAsyncKeyState(0x44) < 0))
			x += speed;
	}
}

//射击函数
void MyPlane::shoot() {
	if (hp > 0) {
		switch (bulletstate)
		{
		case 0:
			if (lastbullettime == BULLET_FPS_INTERVAL) {
			for (int i = 0; i < MAXBULLET; i++)
				if (mybullet1[i].hp == 0) {
					mybullet1[i].hp = 1;	//子弹生命
					mybullet1[i].x = x + 60;
					mybullet1[i].y = y + 15;
					break;
				}
			lastbullettime = 1;
			}
			else
				lastbullettime++;
			break;
		case 1:
			if (lastbullettime == BULLET_FPS_INTERVAL2) {
			for (int i = 0; i < MAXBULLET; i++)
				if (mybullet2_1[i].hp == 0) {
					mybullet2_1[i].hp = 1;	//子弹生命
					mybullet2_1[i].x = x + 60;
					mybullet2_1[i].y = y + 15;
					break;
				}
			for (int i = 0; i < MAXBULLET; i++)
				if (mybullet2_2[i].hp == 0) {
					mybullet2_2[i].hp = 1;	//子弹生命
					mybullet2_2[i].x = x + 60;
					mybullet2_2[i].y = y + 15;
					break;
				}
			for (int i = 0; i < MAXBULLET; i++)
				if (mybullet2_3[i].hp == 0) {
					mybullet2_3[i].hp = 1;	//子弹生命
					mybullet2_3[i].x = x + 60;
					mybullet2_3[i].y = y + 15;
					break;
				}			
			lastbullettime = 1;
			}
			else
				lastbullettime++;
			break;
		}
	}
}

//移动子弹
void MyPlane::drawbullet() {
	switch (bulletstate) {
	case 0:
		for (int j = 0; j < MAXBULLET; j++)
		{
			mybullet1[j].move();
			mybullet1[j].draw();
		}break;
	case 1:
		for (int j = 0; j < MAXBULLET; j++) {
			mybullet2_1[j].move();
			mybullet2_1[j].draw();
			mybullet2_2[j].move2();
			mybullet2_2[j].draw();
			mybullet2_3[j].move3();
			mybullet2_3[j].draw();
		}break;
	}
};

 //碰撞检测
void MyPlane::col_det(EnemyBullet1* bul)
{
	if (hp > 0 && hitted_time == 0)
		for (int i = 0; i < MAX_ENEMY_BULLET1; i++)
		{
			if (hitbox[0] / 2 + bul[i].hitbox[0] / 2 > abs(x - bul[i].x) &&
				hitbox[1] / 2 + bul[i].hitbox[1] / 2 > abs(y - bul[i].y) && bul[i].hp > 0)
			{
				hp--;
				putimage(x - 120, y - 130, &maskbitmap, SRCAND);
				putimage(x - 120, y - 130, &Atkedimg, SRCPAINT);
				hitted_time = GetTickCount();
				if (hp == 0) {
					putimage(x - 50, y - 70, &Mask_BoomImg, SRCAND);
					putimage(x - 50, y - 70, &BoomImg, SRCPAINT);
				}
				bul[i].hp = 0;
			}
		}
}
void MyPlane::col_det(Boost_EnemyBullet1* bul)
{
	if (hp > 0 && hitted_time == 0)
		for (int i = 0; i < MAX_BOOST_ENEMY_BULLET1; i++)
		{
			if (hitbox[0] / 2 + bul[i].hitbox[0] / 2 > abs(x - bul[i].x) &&
				hitbox[1] / 2 + bul[i].hitbox[1] / 2 > abs(y - bul[i].y) && bul[i].hp > 0)
			{
				hp-=2;
				putimage(x - 120, y - 130, &maskbitmap, SRCAND);
				putimage(x - 120, y - 130, &Atkedimg, SRCPAINT);
				hitted_time = GetTickCount();
				if (hp == 0) {
					putimage(x - 50, y - 70, &Mask_BoomImg, SRCAND);
					putimage(x - 50, y - 70, &BoomImg, SRCPAINT);
				}
				bul[i].hp = 0;
			}
		}
}

void MyPlane::col_det(EnemyBullet2& bul)
{
	if (hp > 0 && hitted_time == 0)
			if (hitbox[0] / 2 + bul.hitbox[0] / 2 > abs(x - bul.x) &&
				hitbox[1] / 2 + bul.hitbox[1] / 2 > abs(y - bul.y) && bul.hp > 0)
			{
				hp--;
				putimage(x - 120, y - 60, &maskbitmap, SRCAND);
				putimage(x - 120, y - 60, &Atkedimg, SRCPAINT);
				hitted_time = GetTickCount();
				if (hp == 0) {
					putimage(x - 50, y - 70, &Mask_BoomImg, SRCAND);
					putimage(x - 50, y - 70, &BoomImg, SRCPAINT);
				}
				bul.hp = 0;
			}
}

void MyPlane::col_det(EnemyBullet3* bul, EnemyBullet3* bul2, EnemyBullet3* bul3)
{
	if (hp > 0 && hitted_time == 0) {
		for (int i = 0; i < MAX_ENEMY_BULLET3; i++)
		{
			if (hitbox[0] / 2 + bul[i].hitbox[0] / 2 > abs(x - bul[i].x) &&
				hitbox[1] / 2 + bul[i].hitbox[1] / 2 > abs(y - bul[i].y) && bul[i].hp > 0)
			{
				hp--;
				putimage(x - 120, y - 130, &maskbitmap, SRCAND);
				putimage(x - 120, y - 130, &Atkedimg, SRCPAINT);
				hitted_time = GetTickCount();
				if (hp == 0) {
					putimage(x - 50, y - 70, &Mask_BoomImg, SRCAND);
					putimage(x - 50, y - 70, &BoomImg, SRCPAINT);
				}
				bul[i].hp = 0;
			}
		}
		for (int i = 0; i < MAX_ENEMY_BULLET3; i++)
		{
			if (hitbox[0] / 2 + bul2[i].hitbox[0] / 2 > abs(x - bul2[i].x) &&
				hitbox[1] / 2 + bul2[i].hitbox[1] / 2 > abs(y - bul2[i].y) && bul2[i].hp > 0)
			{
				hp--;
				putimage(x - 120, y - 130, &maskbitmap, SRCAND);
				putimage(x - 120, y - 130, &Atkedimg, SRCPAINT);
				hitted_time = GetTickCount();
				if (hp == 0) {
					putimage(x - 50, y - 70, &Mask_BoomImg, SRCAND);
					putimage(x - 50, y - 70, &BoomImg, SRCPAINT);
				}
				bul[i].hp = 0;
			}
		}
		for (int i = 0; i < MAX_ENEMY_BULLET3; i++)
		{
			if (hitbox[0] / 2 + bul3[i].hitbox[0] / 2 > abs(x - bul3[i].x) &&
				hitbox[1] / 2 + bul3[i].hitbox[1] / 2 > abs(y - bul3[i].y) && bul3[i].hp > 0)
			{
				hp--;
				putimage(x - 120, y - 130, &maskbitmap, SRCAND);
				putimage(x - 120, y - 130, &Atkedimg, SRCPAINT);
				hitted_time = GetTickCount();
				if (hp == 0) {
					putimage(x - 50, y - 70, &Mask_BoomImg, SRCAND);
					putimage(x - 50, y - 70, &BoomImg, SRCPAINT);
				}
				bul[i].hp = 0;
			}
		}
	}
}

void MyPlane::col_det(EnemyPlane1* enemy)
{
	if (hp > 0 && hitted_time == 0)
		for (int i = 0; i < MAXENEMY1; i++) {
			if (hitbox[0] / 2 + enemy[i].hitbox[0] / 2 > abs(x - enemy[i].x) &&
				hitbox[1] / 2 + enemy[i].hitbox[1] / 2 > abs(y - enemy[i].y) && enemy[i].hp > 0)
			{
				hp--;
				putimage(x - 120, y - 130, &maskbitmap, SRCAND);
				putimage(x - 120, y - 130, &Atkedimg, SRCPAINT);
				hitted_time = GetTickCount();
				if (hp == 0) {
					putimage(x - 50, y - 70, &Mask_BoomImg, SRCAND);
					putimage(x - 50, y - 70, &BoomImg, SRCPAINT);
				}
				enemy[i].hp--;
				putimage(enemy[i].x - 120, enemy[i].y - 110, &enemy[i].maskbitmap, SRCAND);
				putimage(enemy[i].x - 120, enemy[i].y - 110, &enemy[i].Atkedimg, SRCPAINT);
			}
		}
}

void MyPlane::col_det(Boost_EnemyPlane1* enemy)
{
	if (hp > 0 && hitted_time == 0)
		for (int i = 0; i < MAXBOOSTENEMY1; i++) {
			if (hitbox[0] / 2 + enemy[i].hitbox[0] / 2 > abs(x - enemy[i].x) &&
				hitbox[1] / 2 + enemy[i].hitbox[1] / 2 > abs(y - enemy[i].y) && enemy[i].hp > 0)
			{
				hp--;
				putimage(x - 120, y - 130, &maskbitmap, SRCAND);
				putimage(x - 120, y - 130, &Atkedimg, SRCPAINT);
				hitted_time = GetTickCount();
				if (hp == 0) {
					putimage(x - 50, y - 70, &Mask_BoomImg, SRCAND);
					putimage(x - 50, y - 70, &BoomImg, SRCPAINT);
				}
				enemy[i].hp--;
				putimage(enemy[i].x - 120, enemy[i].y - 110, &enemy[i].maskbitmap, SRCAND);
				putimage(enemy[i].x - 120, enemy[i].y - 110, &enemy[i].Atkedimg, SRCPAINT);
			}
		}
}

void MyPlane::col_det(EnemyPlane2* enemy)
{
	if (hp > 0 && hitted_time == 0)
		for (int i = 0; i < MAXENEMY2; i++) {
			if (hitbox[0] / 2 + enemy[i].hitbox[0] / 2 > abs(x - enemy[i].x) &&
				hitbox[1] / 2 + enemy[i].hitbox[1] / 2 > abs(y - enemy[i].y) && enemy[i].hp > 0)
			{
				hp--;
				putimage(x - 120, y - 130, &maskbitmap, SRCAND);
				putimage(x - 120, y - 130, &Atkedimg, SRCPAINT);
				hitted_time = GetTickCount();
				if (hp == 0) {
					putimage(x - 50, y - 70, &Mask_BoomImg, SRCAND);
					putimage(x - 50, y - 70, &BoomImg, SRCPAINT);
				}
				enemy[i].hp--;
				putimage(enemy[i].x - 120, enemy[i].y - 110, &enemy[i].maskbitmap, SRCAND);
				putimage(enemy[i].x - 120, enemy[i].y - 110, &enemy[i].Atkedimg, SRCPAINT);
			}
		}
}

void MyPlane::col_det(EnemyPlane3* enemy)
{
	if (hp > 0 && hitted_time == 0)
		for (int i = 0; i < MAXENEMY3; i++) {
			if (hitbox[0] / 2 + enemy[i].hitbox[0] / 2 > abs(x - enemy[i].x) &&
				hitbox[1] / 2 + enemy[i].hitbox[1] / 2 > abs(y - enemy[i].y) && enemy[i].hp > 0)
			{
				hp--;
				putimage(x - 120, y - 130, &maskbitmap, SRCAND);
				putimage(x - 120, y - 130, &Atkedimg, SRCPAINT);
				hitted_time = GetTickCount();
				if (hp == 0) {
					putimage(x - 50, y - 70, &Mask_BoomImg, SRCAND);
					putimage(x - 50, y - 70, &BoomImg, SRCPAINT);
				}
				enemy[i].hp--;
				putimage(enemy[i].x - 120, enemy[i].y - 110, &enemy[i].maskbitmap, SRCAND);
				putimage(enemy[i].x - 120, enemy[i].y - 110, &enemy[i].Atkedimg, SRCPAINT);
			}
		}
}

void MyPlane::col_det(BossBullet1* bul)
{
	if (hp > 0 && hitted_time == 0)
		for (int i = 0; i < MAXENEMY3; i++) {
			if (hitbox[0] / 2 + bul[i].hitbox[0] / 2 > abs(x - bul[i].x) &&
				hitbox[1] / 2 + bul[i].hitbox[1] / 2 > abs(y - bul[i].y) && bul[i].hp > 0)
			{
				hp--;
				putimage(x - 120, y - 130, &maskbitmap, SRCAND);
				putimage(x - 120, y - 130, &Atkedimg, SRCPAINT);
				hitted_time = GetTickCount();
				if (hp == 0) {
					putimage(x - 50, y - 70, &Mask_BoomImg, SRCAND);
					putimage(x - 50, y - 70, &BoomImg, SRCPAINT);
				}
				bul[i].hp--;
				putimage(bul[i].x - 120, bul[i].y - 110, &bul[i].maskbitmap, SRCAND);
				putimage(bul[i].x - 120, bul[i].y - 110, &bul[i].Atkedimg, SRCPAINT);
			}
		}
}

void MyPlane::col_det(Item1 * item)
{
	if (hp > 0&&hp<MAX_MYPLANE_HP)
		for (int i = 0; i < MAX_ITEM1; i++) {
			if (hitbox[0] / 2 + item[i].hitbox[0] / 2 > abs(x - item[i].x) &&
				hitbox[1] / 2 + item[i].hitbox[1] / 2 > abs(y - item[i].y) && item[i].hp > 0)
			{
				hp++;
				item[i].hp =0;
			}
		}
}
void MyPlane::col_det(Item2* item)
{
	if (hp > 0)
		for (int i = 0; i < MAX_ITEM2; i++) {
			if (hitbox[0] / 2 + item[i].hitbox[0] / 2 > abs(x - item[i].x) &&
				hitbox[1] / 2 + item[i].hitbox[1] / 2 > abs(y - item[i].y) && item[i].hp > 0)
			{
				bulletstate=1;
				item[i].hp = 0;
			}
		}
}

//血量显示
void draw_hp(MyPlane & myplane) {
	setfillcolor(RED);
	putimage(-62, -75, &myplane.Mask_Hp, SRCAND);
	putimage(-62, -75, &myplane.Hp, SRCPAINT);
	for (int i = 0, x = 110, y = 20; i < myplane.hp; i++,x+=17) {
		fillrectangle(x+0, y+0, x+17, y+19);
		
	}
	setfillcolor(WHITE);
}

//所有子弹数据处理的函数
/*void Bullet::deal()
{
	for (int i = 0; i < MAXBULLET; i++){
*/	
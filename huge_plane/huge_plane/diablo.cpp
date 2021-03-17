#include"definition.h"
#include<math.h>
#include<cmath>

#define pi 3.14159265358979323846

Boss1::Boss1()
{
	int hitbox_[2] = { 360,360 };
	x = 1800;
	y = 360;
	hitbox[0] = hitbox_[0];
	hitbox[1] = hitbox_[1];
	hp = 0;
	speed = 5;	//敌机速度
	loadimage(&img, _T("IMAGE2"), _T("Boss1"), 480, 480, true);
	loadimage(&maskbitmap, _T("IMAGE2"), _T("Mask_Boss1"), 480, 480, true);
	loadimage(&BoomImg, _T("IMAGE"), _T("Boom"), 240, 240, true);
	loadimage(&Mask_BoomImg, _T("IMAGE"), _T("Mask_Boom"), 240, 240, true);
	loadimage(&Atkedimg, _T("IMAGE2"), _T("Boss1Atked"), 480, 480, true);
	loadimage(&boom1, _T("IMAGE2"), _T("BossBoom"), 720, 720, true);
	loadimage(&boom2, _T("IMAGE2"), _T("BossBoom2"), 720, 720, true);
	loadimage(&mask_boom1, _T("IMAGE2"), _T("Mask_BossBoom"), 720, 720, true);
	loadimage(&mask_boom2, _T("IMAGE2"), _T("Mask_BossBoom2"), 720, 720, true);
}

void Boss1::draw(MyPlane& target)
{
	if (hp > 0) {
		DWORD now = GetTickCount() - show_time;
		//判断现在的state
		if (now < 5000)
			state = 0;
		else if (now < 6000 && now > 5000)
			state = 3;
		else if (now < 12000 && now > 6000)
			state = 4;
		else if (now < 16000 && now > 12000)
			state = 2;
		else if (now < 23000 && now > 16000)
			state = 1;
		else if (now < 24000 && now > 23000)
			state = 5;
		else if (now < 25000 && now > 24000)
			state = 6;
	
		//实际操作
		switch(state)
		{case 0:	//登堂入室、粉墨登场
			move();
			putimage(x - 270, y - 200, &maskbitmap, SRCAND);//boss的真面目
			putimage(x - 270, y - 200, &img, SRCPAINT);
			i++;
			break;
		case 1:		//螺旋机枪、法力无边
			shoot_six_direction(); 
			putimage(x - 270, y - 200, &maskbitmap, SRCAND);//boss的真面目
			putimage(x - 270, y - 200, &img, SRCPAINT);
			for (int j = 0; j < MAX_BOSS_BULLET_1; j++)	//子弹1
			{
				if (bul1[j].hp > 0) {
					bul1[j].draw();
					bul1[j].col_det(target);
				}
			}
			for (int j = 0; j < MAX_BOSS_BULLET_3; j++)	//子弹3、 
			{
				if (bul3[j].hp > 0) {
					bul3[j].draw();
					bul3[j].col_det(target);
				}
			}
			i++;
			break;
		case 2:		//瞄准设计、双枪老太
			shoot_to_where_you_are(target);
			putimage(x - 270, y - 200, &maskbitmap, SRCAND);//boss的真面目
			putimage(x - 270, y - 200, &img, SRCPAINT);
			for (int j = 0; j < MAX_BOSS_BULLET_1; j++)	//子弹1
			{
				if (bul1[j].hp > 0) {
					bul1[j].draw();
					bul1[j].col_det(target);
				}
			}
			for (int j = 0; j < MAX_BOSS_BULLET_3; j++)	//子弹3
			{
				if (bul3[j].hp > 0) {
					bul3[j].draw();
					bul3[j].col_det(target);
				}
			}
			i++;
			break;
		case 3:		//全场激光、还没有伤害
			putimage(x - 270, y - 200, &maskbitmap, SRCAND);//boss的真面目
			putimage(x - 270, y - 200, &img, SRCPAINT);
			pre_shoot_focking_lazer(target);
			i++;
			break;
		case 4:		//全场激光、转起来了
			putimage(x - 270, y - 200, &maskbitmap, SRCAND);//boss的真面目
			putimage(x - 270, y - 200, &img, SRCPAINT);
			shoot_focking_lazer(target);
			i++;
			break;
		case 5:		//一个循环快结束了
			putimage(x - 270, y - 200, &maskbitmap, SRCAND);//boss的真面目
			putimage(x - 270, y - 200, &img, SRCPAINT);
			for (int j = 0; j < MAX_BOSS_BULLET_1; j++)	//子弹1
			{
				if (bul1[j].hp > 0) {
					bul1[j].draw();
					bul1[j].col_det(target);
				}
			}
			for (int j = 0; j < MAX_BOSS_BULLET_3; j++)	//子弹3
			{
				if (bul3[j].hp > 0) {
					bul3[j].draw();
					bul3[j].col_det(target);
				}
			}
			break;
		case 6:		//复位所有子弹
			putimage(x - 270, y - 200, &maskbitmap, SRCAND);//boss的真面目
			putimage(x - 270, y - 200, &img, SRCPAINT);
			for (int j = 0; j < MAX_BOSS_BULLET_1; j++)	//子弹1
			{
					bul1[j].hp = 0;
			}
			for (int j = 0; j < MAX_BOSS_BULLET_3; j++)	//子弹3
			{
					bul3[j].hp = 0;
			}
			show_time = GetTickCount() - 5000;
			break;
		}
	}
	else if (hp <= 0 && i != 0)
	{
		DWORD now = GetTickCount() - dead_time;
		if (now < 1500)
			state = 1;
		else if (now < 3000)
			state = 2;
		else
			state = 3;

		switch (state)
		{
		case 1://大爆炸
			putimage(x - 405, y - 300, &mask_boom1, SRCAND);
			putimage(x - 405, y - 300, &boom1, SRCPAINT);
			break;
		case 2://小爆炸
			putimage(x - 405, y - 300, &mask_boom2, SRCAND);
			putimage(x - 405, y - 300, &boom2, SRCPAINT);
			break;
		}
	}
}

void Boss1::move()
{
	if (hp > 0 && x >= 910)
		x -= speed;
}

void Boss1::move_to_left()
{
	if (hp > 0 && x >= 683)
		x -= speed;
}

void Boss1::move_to_right()
{
	if (x <= 910)
		x += speed;
}

void Boss1::shoot_six_direction()
{
	if (hp > 0)
	{
		if (i % 20 == 0)
		{
			for (int p = 0; p < 6; p++)
			{
				for (int j = 0; j < MAX_BOSS_BULLET_1; j++)
				{
					if (bul1[j].hp == 0) {
						bul1[j].hp = 1;	//子弹生命
						bul1[j].x = x;
						bul1[j].y = y;
						bul1[j].direction[0] = sin(pi / 3 * (i / 20 + p + i / 20 / 10.0));
						bul1[j].direction[1] = cos(pi / 3 * (i / 20 + p + i / 20 / 10.0));
						break;
					}
				}
			}
		}
	}
}

void Boss1::shoot_to_where_you_are(MyPlane& target)
{
	if (i % 10 == 0)
	{
		for (int p = 0; p < 2; p++)
		{
			for (int k = 0; k < MAX_BOSS_BULLET_3; k++)
			{
				if (bul3[k].hp == 0)
				{
					bul3[k].hp = 1;
					bul3[k].x = x;
					bul3[k].y = y - 50 + p * 100;
					bul3[k].direction[0] = target.x - bul3[k].x;
					bul3[k].direction[1] = target.y - bul3[k].y;
					double bili = bul3[k].speed / sqrt(pow(bul3[k].direction[0] - x, 2) + pow(bul3[k].direction[1] - y, 2));
					bul3[k].direction[0] *= bili;
					bul3[k].direction[1] *= bili;
					break;
				}
			}
		}
	}
}

void Boss1::pre_shoot_focking_lazer(MyPlane& target)
{
	for (int j = 0; j < MAX_BOSS_LAZER; j++)
	{
		lazer[j].x = x;
		lazer[j].y = y;
		lazer[j].direction = (2 * pi / MAX_BOSS_LAZER * j) + i / 50.0;
		lazer[j].draw();
	}
}

void Boss1::shoot_focking_lazer(MyPlane& target)
{
	{
		for (int j = 0; j < MAX_BOSS_LAZER; j++)
		{
			lazer[j].x = x;
			lazer[j].y = y;
			lazer[j].direction = (2 * pi / MAX_BOSS_LAZER * j) + i / 50.0;
			lazer[j].draw2();
			lazer[j].col_det(target);
		}
	}
}

void InitBoss1(Boss1& boss)
{
	if (boss.i == 0 && boss.hp == 0 ) {
		boss.hp = BOSS_LIVE;	//boss生命设置
		boss.show_time = GetTickCount();
		boss.state = 0;
	}
}

void Boss1::col_det(MyBullet1* bul)
{
	if (hp > 0)
		for (int i = 0; i < MAXBULLET; i++)
		{
			if (hitbox[0] / 2 + bul[i].hitbox[0] / 2 > abs(x - bul[i].x) &&
				hitbox[1] / 2 + bul[i].hitbox[1] / 2 > abs(y - bul[i].y) && bul[i].hp > 0)
			{
				hp--;
				putimage(x - 270, y - 200, &maskbitmap, SRCAND);
				putimage(x - 270, y - 200, &Atkedimg, SRCPAINT);
				if (hp <= 0) 
					dead_time = GetTickCount();
				bul[i].hp = 0;
			}
		}
}

//boss子弹1
BossBullet1::BossBullet1()
{
	x = 0;
	y = 0;
	hp = 0;
	hitbox[0] = 10;
	hitbox[1] = 10;
	speed = 6;	//子弹速度设置
	loadimage(&img, _T("IMAGE2"), _T("BossBullet3"), 200, 200);
	loadimage(&maskbitmap, _T("IMAGE2"), _T("Mask_BossBullet3"),200, 200);
}

void BossBullet1::draw()
{
	move();
	fillcircle(x, y, 5);
	//子弹一的外形
	putimage(x - 110, y - 90, &maskbitmap, SRCAND);
	putimage(x - 110, y - 90, &img, SRCPAINT);
}

void BossBullet1::move()
{
	x += int(speed * direction[0]);
	y += int(speed * direction[1]);
}

void BossBullet1::col_det(MyPlane& target)
{
	if (target.hp > 0 && target.hitted_time == 0 &&
		hitbox[0] / 2 + target.hitbox[0] / 2 > abs(x - target.x) &&
		hitbox[1] / 2 + target.hitbox[1] / 2 > abs(y - target.y))
	{
		target.hp -= 2;
		target.hitted_time = GetTickCount();
	}
}

//boss子弹2
BossBullet2::BossBullet2()
{
	x = 0;
	y = 0;
	hp = 0;
	hitbox[0] = 10;
	hitbox[1] = 10;
	speed = 5;	//子弹速度设置
}

void BossBullet2::draw()
{
	fillcircle(x, y, 5);
}

//Boss子弹3
BossBullet3::BossBullet3()
{
	x = 0;
	y = 0;
	hp = 0;
	hitbox[0] = 10;
	hitbox[1] = 10;
	speed = 6;	//子弹速度设置
	loadimage(&img, _T("IMAGE2"), _T("BossBullet2"), 200, 200);
	loadimage(&maskbitmap, _T("IMAGE2"), _T("Mask_BossBullet2"), 200, 200);
}

void BossBullet3::move()
{
	x += int(speed * direction[0]);
	y += int(speed * direction[1]);
}

void BossBullet3::draw() {
	if (hp > 0) {
		move();
		fillrectangle(x - hitbox[0] / 2, y - hitbox[1] / 2, x + hitbox[0] / 2, y + hitbox[1] / 2);
		putimage(x - 110, y - 100, &maskbitmap, SRCAND);
		putimage(x - 100, y - 100, &img, SRCPAINT);
	}
}

void BossBullet3::col_det(MyPlane& target)
{
	if (target.hp > 0 && target.hitted_time == 0 && 
		hitbox[0] / 2 + target.hitbox[0] / 2 > abs(x - target.x) &&
		hitbox[1] / 2 + target.hitbox[1] / 2 > abs(y - target.y))
	{
		target.hp--;
		target.hitted_time = GetTickCount();
	}
}
//激光
void Lazer::draw()
{
	setlinecolor(RED);
	line(x, y, int(x + 2000 * cos(direction)), int(y + 2000 * sin(direction)));
	setlinecolor(WHITE);
}

void Lazer::draw2() //有伤害的激光的draw，看你的了@阿骡
{
	setlinecolor(YELLOW);
	line(x, y, int(x + 2000 * cos(direction)), int(y + 2000 * sin(direction)));
	setlinecolor(WHITE);
}

void Lazer::col_det(MyPlane& target)
{
	double l = sqrt(pow(target.x - x, 2) + pow(target.y - y, 2));
	double theta = direction - atan(double(target.y - y) / double(target.x - x));
	if (target.hp > 0 && target.hitted_time == 0 && abs(l * sin(theta)) < hit_distance)
	{
		target.hp--;
		target.hitted_time = GetTickCount();
	}
}
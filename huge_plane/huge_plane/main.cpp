#pragma comment(lib,"Winmm.lib")
#include<iostream>
#include"definition.h"
using namespace std;
struct STAR
{
	double	x;
	int		y;
	double	step;
	int		color;
};
STAR star[MAXSTAR];
//初始化星星
void InitStar(int i)
{
	star[i].x = CANLEN;
	star[i].y = rand() % CANWID;
	star[i].step = (rand() % 5000) / 1000.0 + 1;
	star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5);	// 速度越快，颜色越亮
	star[i].color = RGB(star[i].color, star[i].color, star[i].color);
}


void MoveStar(int i)// 移动星星
{
	// 擦掉原来的星星
	//putpixel((int)star[i].x, star[i].y, 0);

	// 计算新位置
	star[i].x -= star[i].step;
	if (star[i].x < 0)	InitStar(i);

	// 画新星星
	putpixel((int)star[i].x, star[i].y, star[i].color);
}


int main()
{
	initgraph(CANLEN, CANWID);

	menu();//菜单

restart:
	int level = 0;
	mciSendString(_T("open res\\UNICORN.mp3 alias mysong"), NULL, 0, NULL);//载入音乐
	mciSendString(TEXT("play mysong repeat"), NULL, 0, NULL);//循环播放
	
	DWORD time2 = GetTickCount();//记录游戏正式开始时间

	srand((unsigned)time(NULL));	// 随机种子
	

	//inm背景
	//IMAGE BackGround;
	//loadimage(&BackGround, _T("IMAGE"), _T("BackgroundMianjie"), 1376, 720);

	// 初始化所有星星
	for (int i = 0; i < MAXSTAR; i++)
	{
		InitStar(i);
		star[i].x = rand() % CANLEN;
	}

	int hitbox_[2] = { 50,50 };//测试机hitbox定义
	MyPlane testplane(120, 360, hitbox_, MAX_MYPLANE_HP, MYPLANE_SPEED);//测试机初始化

	EnemyPlane1 enemy1[MAXENEMY1];	//初始化敌机
	EnemyPlane2 enemy2[MAXENEMY2];
	EnemyPlane3 enemy3[MAXENEMY3];
	Boost_EnemyPlane1 boost_enemy1[MAXBOOSTENEMY1];
	//Boost_EnemyPlane3 boost_enemy3[MAXBOOSTENEMY3];
	Boss1 boss;

	Partner1 partner1[MAXPARTNER1];//初始化友军
	Item1 item1[MAX_ITEM1];//初始化道具一
	Item2 item2[MAX_ITEM2];//初始化道具二

	BeginBatchDraw();//批量绘制开始 
	DWORD time1;
	int lastenemytime = ENEMY_FPS_INTERVAL;
	
	//主循环
	while (1)
	{
		time1 = GetTickCount();

		//putimage(0, 0, &BackGround);

		//星空背景绘制
		for (int i = 0; i < MAXSTAR; i++)
			MoveStar(i);

		//绘制我机
		testplane.draw();

		//绘制我机子弹
		testplane.shoot();
		testplane.drawbullet();

			//敌机初始化
			if (lastenemytime == ENEMY_FPS_INTERVAL) {
				if (time1 - time2 < 10000) {
					//InitPartner1(partner1);
					//InitItem1(item1);
					InitEnemy1(enemy1);
					//InitEnemy2(enemy2);
					//InitEnemy3(enemy3);
					//InitBoostEnemy1(boost_enemy1);
					lastenemytime = 1;
					level = 1;
				}
				else if (time1 - time2 < 11000) {
					//InitPartner1(partner1);
					InitItem2(item2);
					//InitBoostEnemy1(boost_enemy1);
					//InitEnemy1(enemy1);
					InitEnemy2(enemy2);
					//InitEnemy3(enemy3);
					lastenemytime = 1;
					level = 2;
				}
				else if (time1 - time2 < 20000) {
					//InitPartner1(partner1);
					//InitItem1(item1);
					//InitBoostEnemy1(boost_enemy1);
					//InitEnemy1(enemy1);
					InitEnemy2(enemy2);
					//InitEnemy3(enemy3);
					lastenemytime = 1;
				}
				else if (time1 - time2 < 21000) {
					InitPartner1(partner1);
					//InitItem1(item1);
					//InitEnemy1(enemy1);
					//InitEnemy2(enemy2);
					InitEnemy3(enemy3);
					InitBoostEnemy1(boost_enemy1);
					lastenemytime = 1;
					level = 3;
				}
				else if (time1 - time2 < 30000) {
					//InitPartner1(partner1);
					//InitItem1(item1);
					//InitEnemy1(enemy1);
					//InitEnemy2(enemy2);
					InitEnemy3(enemy3);
					InitBoostEnemy1(boost_enemy1);
					lastenemytime = 1;
				}
				else if (time1 - time2 < 40000) {
					//InitPartner1(partner1);
					//InitItem1(item1);
					InitEnemy1(enemy1);
					InitEnemy2(enemy2);
					//InitEnemy3(enemy3);
					//InitBoostEnemy1(boost_enemy1);
					lastenemytime = 1;
					level = 4;
				}
				else if (time1 - time2 < 41000) {
					//InitPartner1(partner1);
					InitItem1(item1);
					//InitEnemy1(enemy1);
					//InitEnemy2(enemy2);
					InitEnemy3(enemy3);
					//InitBoostEnemy1(boost_enemy1);
					lastenemytime = 1;
					level = 5;
				}
				else if (time1 - time2 < 45000) {
					//InitPartner1(partner1);
					//InitItem1(item1);
					//InitEnemy1(enemy1);
					//InitEnemy2(enemy2);
					InitEnemy3(enemy3);
					//InitBoostEnemy1(boost_enemy1);
					lastenemytime = 1;
				}

				else{
					//InitPartner1(partner1);
					//InitItem1(item1);
					//InitEnemy1(enemy1);
					//InitEnemy2(enemy2);
					//InitEnemy3(enemy3);
					//InitBoostEnemy1(boost_enemy1);
					InitBoss1(boss);
					level = 6;
				}
			}
			else
				lastenemytime++;

			//友军绘制
			for (int j = 0; j < MAXPARTNER1; j++) {
				partner1[j].draw();

				if (partner1[j].lasttime == ITEM1_FPS_INTERVAL) {
					partner1[j].shoot(partner1[j].item);
					partner1[j].lasttime = 1;
				}
				else
					partner1[j].lasttime++;
				
				for (int i = 0; i < MAX_ITEM1; i++)
					partner1[j].item[i].draw();
				testplane.col_det(partner1[j].item);

			}

			//道具绘制
			for (int j = 0; j < MAX_ITEM1; j++) {
				item1[j].draw();
				testplane.col_det(item1);
			}
			
			for (int j = 0; j < MAX_ITEM2; j++) {
				item2[j].draw();
				testplane.col_det(item2);
			}
			
			//敌机绘制
			//敌机一
			for (int j = 0; j < MAXENEMY1; j++) {
				enemy1[j].draw();

				if (enemy1[j].lasttime == ENEMY_BULLET1_FPS_INTERVAL) {
					enemy1[j].shoot(enemy1[j].bul);
					enemy1[j].lasttime = 1;
				}
				else
					enemy1[j].lasttime++;

				for (int i = 0; i < MAX_ENEMY_BULLET1; i++)
					enemy1[j].bul[i].draw();

				enemy1[j].col_det(testplane.mybullet1);
				enemy1[j].col_det(testplane.mybullet2_1);
				enemy1[j].col_det(testplane.mybullet2_2);
				enemy1[j].col_det(testplane.mybullet2_3);
				testplane.col_det(enemy1[j].bul);
			}
			testplane.col_det(enemy1);
			
			//强化版敌机一
			for (int j = 0; j < MAXBOOSTENEMY1; j++) {
				boost_enemy1[j].draw();

				if (boost_enemy1[j].lasttime == BOOST_ENEMY_BULLET1_FPS_INTERVAL) {
					boost_enemy1[j].shoot(boost_enemy1[j].bul);
					boost_enemy1[j].lasttime = 1;
				}
				else
					boost_enemy1[j].lasttime++;

				for (int i = 0; i < MAX_BOOST_ENEMY_BULLET1; i++)
					boost_enemy1[j].bul[i].draw();

				boost_enemy1[j].col_det(testplane.mybullet1);
				boost_enemy1[j].col_det(testplane.mybullet2_1);
				boost_enemy1[j].col_det(testplane.mybullet2_2);
				boost_enemy1[j].col_det(testplane.mybullet2_3);
				testplane.col_det(boost_enemy1[j].bul);
			}
			testplane.col_det(boost_enemy1);

			//敌机二
			for (int j = 0; j < MAXENEMY2; j++) {
				enemy2[j].shoot();
				enemy2[j].bul.draw();
				enemy2[j].draw();

				enemy2[j].col_det(testplane.mybullet1);
				enemy2[j].col_det(testplane.mybullet2_1);
				enemy2[j].col_det(testplane.mybullet2_2);
				enemy2[j].col_det(testplane.mybullet2_3);
				testplane.col_det(enemy2[j].bul);
			}
			testplane.col_det(enemy2);
			
			//敌机三
			for (int j = 0; j < MAXENEMY3; j++) {
				enemy3[j].draw();

				if (enemy3[j].lasttime == ENEMY_BULLET3_FPS_INTERVAL) {
					enemy3[j].shoot(enemy3[j].bul1);
					enemy3[j].shoot(enemy3[j].bul2);
					enemy3[j].shoot(enemy3[j].bul3);
					enemy3[j].lasttime = 1;
				}
				else
					enemy3[j].lasttime++;
				for (int i = 0; i < MAX_ENEMY_BULLET3; i++) {
					enemy3[j].bul1[i].move();
					enemy3[j].bul2[i].move2();
					enemy3[j].bul3[i].move3();
					enemy3[j].bul1[i].draw();
					enemy3[j].bul2[i].draw();
					enemy3[j].bul3[i].draw();
				}
				enemy3[j].col_det(testplane.mybullet1);
				enemy3[j].col_det(testplane.mybullet2_1);
				enemy3[j].col_det(testplane.mybullet2_2);
				enemy3[j].col_det(testplane.mybullet2_3);
				testplane.col_det(enemy3[j].bul1, enemy3[j].bul2, enemy3[j].bul3);
			}
			testplane.col_det(enemy3);

		boss.draw(testplane);
		boss.col_det(testplane.mybullet1);
		boss.col_det(testplane.mybullet2_1);
		boss.col_det(testplane.mybullet2_2);
		boss.col_det(testplane.mybullet2_3);
		testplane.col_det(boss.bul1);

		//血量显示
		/*char hpp[8];
		_itoa_s(testplane.hp, hpp, 10);
		outtextxy(20, 20, hpp); */
		draw_hp(testplane);

		FlushBatchDraw();	//批量绘制
		
		int pause_or_not = 0;//判断是否暂停
		DWORD pausetime = GetTickCount();//暂停开始时间
		pause_or_not=pause();
		DWORD continuetime= GetTickCount();//暂停结束时间
		if (pause_or_not == 1)
			time2 += (continuetime - pausetime);//消除暂停的时间带来的影响
		
		//游戏失败窗口
		if (testplane.hp <= 0) {
			if (end(level) == 2)
			{
				closegraph();
				exit(0);
			}
			else if (end(level) == 1)
			{
				goto restart;
			}
		}

		DWORD deltatime = GetTickCount() - time1;
		if (deltatime < 17)
			Sleep(17 - deltatime);
		cleardevice();
	}
}
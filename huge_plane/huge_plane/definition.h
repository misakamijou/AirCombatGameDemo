#pragma once
#include<conio.h>
#include<graphics.h>
#include <stdio.h>
#include<time.h>
#include <windows.h>
#include<string>
#pragma comment(lib, "WINMM.LIB")
#define MAXSTAR 600//��������
#define MAX_MYPLANE_HP 15//�һ�Ѫ������
#define MYPLANE_SPEED 15 //�һ��ٶ�
#define BULLET_FPS_INTERVAL 8//���ӵ���֡�����
#define BULLET_FPS_INTERVAL2 16//���ӵ���֡�����2
#define MAXBULLET 15//�ӵ�����
#define INVINCIBLE_TIME 1500 //�����к���޵�ʱ��/ms

#define ENEMY_BULLET1_FPS_INTERVAL 120//һ������ӵ����/֡
#define ENEMY_BULLET2_FPS_INTERVAL 600//��������ӵ����/֡
#define ENEMY_BULLET3_FPS_INTERVAL 120//��������ӵ����/֡
#define BOOST_ENEMY_BULLET1_FPS_INTERVAL 60//ǿ��һ������ӵ����/֡
#define BOOST_ENEMY_BULLET3_FPS_INTERVAL 60//ǿ����������ӵ����/֡
#define MAX_ENEMY_BULLET1 3 //һ������ӵ�����
#define	MAX_ENEMY_BULLET3 3 //��������ӵ�����
#define MAX_BOOST_ENEMY_BULLET1 6 //ǿ��һ������ӵ�����
#define	MAX_BOOST_ENEMY_BULLET3 6 //ǿ����������ӵ�����

#define ITEM1_FPS_INTERVAL 360 //����һ���
#define MAX_ITEM1	1//����1��
#define MAX_ITEM2	1//����2��
#define MAXPARTNER1	1//�Ѿ�1����

#define ENEMY_FPS_INTERVAL 15 //�����˳��ּ��/֡
#define MAXENEMY1 2	//����1����
#define MAXENEMY2 2 //����2����
#define MAXENEMY3 2	//����3����
#define MAXBOOSTENEMY1 2	//ǿ������1����
#define MAXBOOSTENEMY3 3	//ǿ������3����

#define BOSS_LIVE 500	//bossѪ��

#define CANWID 720	//�������
#define CANLEN 1366	//��������

void DRAW();  //���ƽ���
void menu();
void DRAWPAUSE();
int pause();
void DRAW_end(int);
int end(int);


//������
class FlyingObject;
class MyPlane;
class Bullet;
class MyBullet1;
class EnemyBullet1;
class Boost_EnemyBullet1;
class EnemyBullet2;
class EnemyBullet3;
class Boost_EnemyBullet3;
class EnemyPlane;
class EnemyPlane1;
class Boost_EnemyPlane1;
class EnemyPlane2;
class EnemyPlane3;
class Boost_EnemyPlane3;
class Item;
class Item1;
class Item2;
class Partner;
class Partner1;
class BossBullet1;
class BossBullet2;
class BossBullet3;
class Boss1;
class Lazer;

//����
class FlyingObject
{
public:
	int x, y;        //����
	int hitbox[2];   //hitbox
	int hp, speed;   //Ѫ�����ƶ��ٶ�
	IMAGE img;
	IMAGE maskbitmap;
	IMAGE BoomImg;
	IMAGE Mask_BoomImg;
	IMAGE Atkedimg; 
public:
	FlyingObject() {};
	FlyingObject(int x_, int y_, int* hitbox_, int hp_, int speed_);
	virtual void draw() = 0;
	virtual void move() = 0;
	//void hpup();
	//void hpdown();
};
//�ӵ�����
class Bullet : public FlyingObject
{
public:
	Bullet() {};
	virtual void draw()=0;	//���ƣ��ӵ�
	virtual void move()=0;
	void deal();
};
//�ҵ��ӵ�1
class MyBullet1 : public Bullet
{
public:
	MyBullet1();
	virtual void draw();	//���ƣ��ӵ�
	virtual void move();
	virtual void move2();
	virtual void move3();
	//void deal();
};

//�ҵķɻ�
class MyPlane : public FlyingObject
{
public:
	MyBullet1 mybullet1[MAXBULLET];
	MyBullet1 mybullet2_1[MAXBULLET];
	MyBullet1 mybullet2_2[MAXBULLET];
	MyBullet1 mybullet2_3[MAXBULLET];
	int lastbullettime = BULLET_FPS_INTERVAL;
	int bulletstate = 0;
	DWORD hitted_time = 0;
	IMAGE Gas;
	IMAGE Mask_Gas;
	IMAGE Hp;
	IMAGE Mask_Hp;
	IMAGE Gas2;
	IMAGE Gas3;

	MyPlane(int x_, int y_, int* hitbox_, int hp_, int speed_)
		: FlyingObject(x_, y_, hitbox_, hp_, speed_)
	{
		loadimage(&img, _T("IMAGE2"), _T("MyPlane"), 200, 200, true);
		loadimage(&maskbitmap, _T("IMAGE2"), _T("Mask_MyPlane"), 200, 200, true);
		loadimage(&BoomImg, _T("IMAGE"), _T("Boom"), 120, 120, true);
		loadimage(&Mask_BoomImg, _T("IMAGE"), _T("Mask_Boom"), 120, 120, true);
		loadimage(&Atkedimg, _T("IMAGE2"), _T("MyPlaneAtked"), 240, 240, true);
		loadimage(&Gas, _T("IMAGE2"), _T("Gas"), 120, 120, true);
		loadimage(&Mask_Gas, _T("IMAGE2"), _T("Mask_Gas"), 120, 120, true);
		loadimage(&Hp, _T("IMAGE2"), _T("Hp"), 480, 240, true);
		loadimage(&Mask_Hp, _T("IMAGE2"), _T("Mask_Hp"), 480, 240, true);
		loadimage(&Gas2, _T("IMAGE2"), _T("Gas2"), 120, 120, true);
		loadimage(&Gas3, _T("IMAGE2"), _T("Gas3"), 120, 120, true);
	};  //���캯��
	void draw();	//���ƣ��һ�
	void shoot();  //��������̿���
	void move();  //�ƶ������̿��� 
	void drawbullet();
	void col_det(EnemyBullet1*);
	void col_det(Boost_EnemyBullet1*);
	void col_det(EnemyBullet2&);
	void col_det(EnemyBullet3*, EnemyBullet3*, EnemyBullet3*);
	//void col_det(EnemyBullet4);	
	void col_det(EnemyPlane1*);
	void col_det(Boost_EnemyPlane1*);
	void col_det(EnemyPlane2*);
	void col_det(EnemyPlane3*);
	void col_det(BossBullet1*);
	void col_det(Item1*);
	void col_det(Item2*);
	friend void draw_hp(MyPlane&);
};

//�л�����
class EnemyPlane : public FlyingObject
{
public:
	EnemyPlane() :FlyingObject() {};
	EnemyPlane(int x_, int y_, int* hitbox_, int hp_, int speed_)
		: FlyingObject(x_, y_, hitbox_, hp_, speed_)
	{ };
	virtual void draw() = 0;	//���ƣ��л���
	virtual void move() = 0;  //�ƶ���Ԥ��
	virtual void col_det(MyBullet1*) = 0;	//��ײ���
};

//�л��ӵ�1
class EnemyBullet1 : public Bullet
{
public:
	EnemyBullet1();
	void draw();
	void move();
};

//�л�1
class EnemyPlane1 : public EnemyPlane
{
public:
	int lasttime = ENEMY_BULLET1_FPS_INTERVAL;
	EnemyBullet1 bul[MAX_ENEMY_BULLET1];
	EnemyPlane1();
	EnemyPlane1(int x_, int y_, int* hitbox_, int hp_, int speed_)
		: EnemyPlane(x_, y_, hitbox_, hp_, speed_)
	{ };
	void draw();
	void shoot(EnemyBullet1*);
	void move();
	void col_det(MyBullet1*);
	friend void InitEnemy1(EnemyPlane1 * enemy);
};

//������л��ӵ�1
class Boost_EnemyBullet1 : public Bullet
{
public:
	Boost_EnemyBullet1();
	void draw();
	void move();
};

//������л�1
class Boost_EnemyPlane1 : public EnemyPlane
{
public:
	int lasttime =BOOST_ENEMY_BULLET1_FPS_INTERVAL;
	Boost_EnemyBullet1 bul[MAX_BOOST_ENEMY_BULLET1];
	Boost_EnemyPlane1();
	void draw();
	void shoot(Boost_EnemyBullet1*);
	void move();
	void col_det(MyBullet1*);
	friend void InitBoostEnemy1(Boost_EnemyPlane1 * enemy);
};

//�л��ӵ�2
class EnemyBullet2 : public Bullet
{
public:
	EnemyBullet2();
	void draw();
	void move() {};
};
//�л�2
class EnemyPlane2 : public EnemyPlane
{
public:
	DWORD time1 = GetTickCount();
	int state = 4;
	EnemyBullet2 bul;
	EnemyPlane2();
	EnemyPlane2(int x_, int y_, int* hitbox_, int hp_, int speed_)
		: EnemyPlane(x_, y_, hitbox_, hp_, speed_)
	{ };
	void draw();
	void shoot();
	void move();
	void col_det(MyBullet1*);
	
	friend void InitEnemy2(EnemyPlane2 * enemy);
};

//�л��ӵ�3
class EnemyBullet3 : public Bullet
{
public:
	EnemyBullet3();
	void draw();
	void move();
	void move2();
	void move3();
};
//�л�3
class EnemyPlane3 : public EnemyPlane
{
public:
	int lasttime = ENEMY_BULLET3_FPS_INTERVAL;
	EnemyBullet3 bul1[MAX_ENEMY_BULLET3];
	EnemyBullet3 bul2[MAX_ENEMY_BULLET3];
	EnemyBullet3 bul3[MAX_ENEMY_BULLET3];
	EnemyPlane3();
	EnemyPlane3(int x_, int y_, int* hitbox_, int hp_, int speed_)
		: EnemyPlane(x_, y_, hitbox_, hp_, speed_)
	{ };
	void draw();
	void shoot(EnemyBullet3*);
	void move();
	void col_det(MyBullet1*);

	friend void InitEnemy3(EnemyPlane3 * enemy);
};

//������л��ӵ�3
class Boost_EnemyBullet3 : public Bullet
{
public:
	Boost_EnemyBullet3();
	void draw();
	void move();
	void move2();
	void move3();
};
//������л�3
class Boost_EnemyPlane3 : public EnemyPlane
{
public:
	int lasttime = BOOST_ENEMY_BULLET3_FPS_INTERVAL;
	Boost_EnemyBullet3 bul1[MAX_BOOST_ENEMY_BULLET3];
	Boost_EnemyBullet3 bul2[MAX_BOOST_ENEMY_BULLET3];
	Boost_EnemyBullet3 bul3[MAX_BOOST_ENEMY_BULLET3];
	Boost_EnemyPlane3();
	Boost_EnemyPlane3(int x_, int y_, int* hitbox_, int hp_, int speed_)
		: EnemyPlane(x_, y_, hitbox_, hp_, speed_)
	{ };
	void draw();
	void shoot(Boost_EnemyBullet3*);
	void move();
	void col_det(MyBullet1*);

	friend void InitBoostEnemy3(Boost_EnemyPlane3 * enemy);
};

//BOSS�ӵ�1
class BossBullet1 : public Bullet
{
public:
	double direction[2];
	BossBullet1();
	void draw();
	void move();
	void col_det(MyPlane&);
	IMAGE img;
	IMAGE maskbitmap;
};

//BOSS�ӵ�2
class BossBullet2 : public Bullet
{
public:
	double direction[2];
	BossBullet2();
	void draw();
	void move() {};
};

//BOSS�ӵ�3
class BossBullet3 : public Bullet
{
public:
	double direction[2];
	BossBullet3();
	void draw();
	void move();
	void col_det(MyPlane&);
	IMAGE img;
	IMAGE maskbitmap;
};

//���乥��
class Lazer
{
public:
	static const int hit_distance = 60;
	int x, y;
	double direction;
	void col_det(MyPlane&);
	void draw();
	void draw2();
};
//BOSS
class Boss1 :public EnemyPlane
{
public:
	int hp = 0;
	int i = 0;
	int state = 0;
	static const int MAX_BOSS_BULLET_1 = 100;
	static const int MAX_BOSS_LAZER = 4;
	static const int MAX_BOSS_BULLET_3 = 50;
	DWORD show_time = 0;
	DWORD dead_time = 0;
	BossBullet1 bul1[MAX_BOSS_BULLET_1];
	Lazer lazer[MAX_BOSS_LAZER];
	BossBullet3 bul3[MAX_BOSS_BULLET_3];
	Boss1();
	void draw() {};
	void draw(MyPlane&);
	void shoot_six_direction();
	void pre_shoot_focking_lazer(MyPlane&);
	void shoot_focking_lazer(MyPlane&);
	void shoot_to_where_you_are(MyPlane&);
	void move();
	void move_to_left();
	void move_to_right();
	void col_det(MyBullet1*);
	IMAGE boom1;
	IMAGE boom2;
	IMAGE mask_boom1;
	IMAGE mask_boom2;

	friend void InitBoss1(Boss1&);
};

//���߻���
class Item : public FlyingObject
{
public:
	Item() {};
	virtual void draw() = 0;
	virtual void move() = 0;
};

//����һ
class Item1 : public Item {
public:
	Item1();
	virtual void draw();
	virtual void move();
	friend void InitItem1(Item1 *item);
};

//���߶�
class Item2 : public Item {
public:
	Item2();
	virtual void draw();
	virtual void move();
	friend void InitItem2(Item2 *item);
};

//�Ѿ�����
class Partner : public FlyingObject {
public:
	Partner() {};
	virtual void shoot(Item1*) = 0;
	virtual void move() = 0;
};

//�Ѿ�һ
class Partner1 : public FlyingObject {
public:
	int lasttime = ITEM1_FPS_INTERVAL;
	Item1 item[MAX_ITEM1];
	Partner1();
	void draw();
	void shoot(Item1*);
	void move();
	friend void InitPartner1(Partner1 * partner);
};
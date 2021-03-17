#include"definition.h"
//�ҵ��ӵ�1
MyBullet1::MyBullet1()
{
	int bullethitbox_[2] = { 50,50 };	//�ӵ�hitbox����
	x = 0;
	y = 0;
	hp = 0;
	speed = 45;	//�ӵ��ٶ�����
	hitbox[0] = bullethitbox_[0];
	hitbox[1] = bullethitbox_[1];
	loadimage(&img, _T("IMAGE2"), _T("MyBullet1"),100,100,true);
	loadimage(&maskbitmap, _T("IMAGE2"), _T("Mask_MyBullet1"), 100, 100,true);
}
//�����ӵ�
void MyBullet1::draw() {
	if (hp > 0 )
	{
		//fillcircle(x, y, 5);	//Բ�δ����ӵ�
		//fillrectangle(x - hitbox[0] / 2, y - hitbox[1] / 2, x + hitbox[0] / 2, y + hitbox[1] / 2); //���Է�������ӵ�
		putimage(x - 45, y - 35, &maskbitmap, SRCAND);
		putimage(x - 45, y - 35, &img, SRCPAINT);
	}
}
//�ӵ��ƶ�
void MyBullet1::move() {
	if (x - hitbox[0] / 2 <= CANLEN && hp > 0)
		x += speed;
	if (x - hitbox[0] / 2 > CANLEN)
		hp = 0;
}
//�ӵ�б���ƶ�
void MyBullet1::move2() {
	if (x - hitbox[0] / 2 <= CANLEN && y + hitbox[1] / 2 >= 0 && hp > 0)
		x += speed;
		y -= speed/4;
	if (x - hitbox[0] / 2 > CANLEN||y + hitbox[1] / 2 <0)
		hp = 0;
}
//�ӵ�б���ƶ�
void MyBullet1::move3() {
	if (x - hitbox[0] / 2 <= CANLEN && y-hitbox[1]/2 <= CANWID &&hp > 0)
		x += speed;
		y += speed/4;
	if (x - hitbox[0] / 2 > CANLEN|| y - hitbox[1] / 2 > CANWID)
		hp = 0;
}


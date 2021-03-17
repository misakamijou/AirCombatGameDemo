#include"definition.h"
//我的子弹1
MyBullet1::MyBullet1()
{
	int bullethitbox_[2] = { 50,50 };	//子弹hitbox定义
	x = 0;
	y = 0;
	hp = 0;
	speed = 45;	//子弹速度设置
	hitbox[0] = bullethitbox_[0];
	hitbox[1] = bullethitbox_[1];
	loadimage(&img, _T("IMAGE2"), _T("MyBullet1"),100,100,true);
	loadimage(&maskbitmap, _T("IMAGE2"), _T("Mask_MyBullet1"), 100, 100,true);
}
//绘制子弹
void MyBullet1::draw() {
	if (hp > 0 )
	{
		//fillcircle(x, y, 5);	//圆形代替子弹
		//fillrectangle(x - hitbox[0] / 2, y - hitbox[1] / 2, x + hitbox[0] / 2, y + hitbox[1] / 2); //测试方块代替子弹
		putimage(x - 45, y - 35, &maskbitmap, SRCAND);
		putimage(x - 45, y - 35, &img, SRCPAINT);
	}
}
//子弹移动
void MyBullet1::move() {
	if (x - hitbox[0] / 2 <= CANLEN && hp > 0)
		x += speed;
	if (x - hitbox[0] / 2 > CANLEN)
		hp = 0;
}
//子弹斜上移动
void MyBullet1::move2() {
	if (x - hitbox[0] / 2 <= CANLEN && y + hitbox[1] / 2 >= 0 && hp > 0)
		x += speed;
		y -= speed/4;
	if (x - hitbox[0] / 2 > CANLEN||y + hitbox[1] / 2 <0)
		hp = 0;
}
//子弹斜下移动
void MyBullet1::move3() {
	if (x - hitbox[0] / 2 <= CANLEN && y-hitbox[1]/2 <= CANWID &&hp > 0)
		x += speed;
		y += speed/4;
	if (x - hitbox[0] / 2 > CANLEN|| y - hitbox[1] / 2 > CANWID)
		hp = 0;
}


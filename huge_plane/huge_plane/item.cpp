#include"definition.h"
//道具一 
Item1::Item1() {
	x = 0;
	y = 0;
	hp = 0;
	int bullethitbox_[2] = { 30,30 };
	hitbox[0] = bullethitbox_[0];
	hitbox[1] = bullethitbox_[1];
	speed = 10;	//道具速度设置
	loadimage(&img, _T("IMAGE2"), _T("Item1"), 70, 70);
	loadimage(&maskbitmap, _T("IMAGE2"), _T("Mask_Item1"), 70, 70);
}
void Item1::move() {
		if (x - speed + hitbox[0] / 2 >= 0 && hp > 0)
			x -= speed;
		if (x - speed + hitbox[0] / 2 < 0)
			hp = 0;
}
void Item1::draw() {
	if (hp > 0) {
		move();
		//fillrectangle(x - hitbox[0] / 2, y - hitbox[1] / 2, x + hitbox[0] / 2, y + hitbox[1] / 2);
		putimage(x-35 , y-25 , &maskbitmap, SRCAND);
		putimage(x-35 , y-25 , &img, SRCPAINT);
	}
}
void InitItem1(Item1 *item) {
	for (int j = 0; j < MAX_ITEM1; j++)
		if (item[j].hp == 0) {
			item[j].hp = 1;	//
			item[j].x = 1366;
			item[j].y = rand() % 720;
			break;
		}
}

//道具二
Item2::Item2() {
	x = 0;
	y = 0;
	hp = 0;
	int bullethitbox_[2] = { 30,30 };
	hitbox[0] = bullethitbox_[0];
	hitbox[1] = bullethitbox_[1];
	speed = 10;	//道具速度设置
	loadimage(&img, _T("IMAGE2"), _T("Item2"), 280, 280);
	loadimage(&maskbitmap, _T("IMAGE2"), _T("Mask_Item2"), 280, 280);
}
void Item2::move() {
	if (x - speed + hitbox[0] / 2 >= 0 && hp > 0)
		x -= speed;
	if (x - speed + hitbox[0] / 2 < 0)
		hp = 0;
}
void Item2::draw() {
	if (hp > 0) {
		move();
		fillrectangle(x - hitbox[0] / 2, y - hitbox[1] / 2, x + hitbox[0] / 2, y + hitbox[1] / 2);
		putimage(x - 140, y - 125, &maskbitmap, SRCAND);
		putimage(x - 140, y - 125, &img, SRCPAINT);
	}
}

void InitItem2(Item2 *item) {
	for (int j = 0; j < MAX_ITEM2; j++)
		if (item[j].hp == 0) {
			item[j].hp = 1;	//
			item[j].x = 1366;
			item[j].y = rand() % 720;
			break;
		}
}
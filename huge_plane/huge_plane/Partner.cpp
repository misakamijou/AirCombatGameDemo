#include"definition.h"
Partner1::Partner1() {
	int hitbox_[2] = { 90,90 };
	x = 1366;
	y = rand() % CANWID;
	hitbox[0] = hitbox_[0];
	hitbox[1] = hitbox_[1];
	hp = 0;
	speed = 5;	//敌机速度
	loadimage(&img, _T("IMAGE2"), _T("Partner1"), 240, 240, true);
	loadimage(&maskbitmap, _T("IMAGE2"), _T("Mask_Partner1"), 240, 240, true);
};
void Partner1::draw()
{
	if (hp > 0) {
		move();
		//fillrectangle(x-hitbox[0]/2,y- hitbox[1]/2,x+ hitbox[0]/2,y+ hitbox[1]/2);//测试方块代替友军
		putimage(x - 120, y - 110, &maskbitmap, SRCAND);
		putimage(x - 120, y - 110, &img, SRCPAINT);
	}
}

void Partner1::move()
{
	if (x - speed + hitbox[0] / 2 >= 0 && hp > 0)
		x -= speed;
	if (x - speed + hitbox[0] / 2 < 0)
		hp = 0;
}

void InitPartner1(Partner1 * partner) {
	for (int j = 0; j < MAXPARTNER1; j++)
		if (partner[j].hp == 0) {
			partner[j].hp = 1;	//
			partner[j].x = 1366;
			partner[j].y = rand() % 720;
			break;
		}
}

void Partner1::shoot(Item1 * item) {
	if (hp > 0)
		for (int i = 0; i < MAX_ITEM1; i++)
			if (item[i].hp == 0) {
				item[i].hp = 1;	//子弹生命
				item[i].x = x - 40;
				item[i].y = y + 40;
				break;
			}
}

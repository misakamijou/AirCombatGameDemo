#include"definition.h"
//绘制界面
void DRAWPAUSE()
{
	setfillcolor(BLACK);
	fillrectangle(485, 250, 885, 450);
	settextstyle(70, 0, _T("黑体"));
	outtextxy(600, 275, _T("PAUSE"));
	//选项
	settextstyle(30, 0, _T("黑体"));
	outtextxy(632, 350, _T("CONTINUE"));
	outtextxy(638, 390, _T("EXIT"));
}
int pause()
{
	if (GetAsyncKeyState(VK_ESCAPE) < 0) {

		//初始状态光标在选项1
		DRAWPAUSE();
		outtextxy(570, 350, _T("→"));
		FlushBatchDraw();

		int option = 1;   //当前选项，1为continue，2为exit

		while (1)
		{
			if ((GetAsyncKeyState(VK_UP) < 0) or (GetAsyncKeyState(0x57) < 0))
			{
				DRAWPAUSE();
				outtextxy(570, 350, _T("→"));
				FlushBatchDraw();
				option = 1;
			}
			if ((GetAsyncKeyState(VK_DOWN) < 0) or (GetAsyncKeyState(0x53) < 0))
			{
				DRAWPAUSE();
				outtextxy(570, 390, _T("→"));
				FlushBatchDraw();
				option = 2;
			}
			if (GetAsyncKeyState(VK_RETURN) && 0x8000)
			{
				if (option == 1)
				{
					return 1;        //退出menu()函数开始游戏    
				}
				else if (option == 2)
				{
					closegraph();	 //关闭绘图窗口
					exit(0);
				}
			}
		}
	}
}
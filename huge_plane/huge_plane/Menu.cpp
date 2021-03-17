#include"definition.h"
//绘制界面
void DRAW()
{
	//标题
	settextstyle(70, 0, _T("黑体"));
	outtextxy(585, 200, _T("TITLE"));

	//选项
	settextstyle(30, 0, _T("黑体"));
	outtextxy(632, 350, _T("START"));
	outtextxy(638, 390, _T("EXIT"));
}
void menu()
{
	BeginBatchDraw();
	//初始状态光标在选项1
	DRAW();
	outtextxy(570, 350, _T("→"));

	int option = 1;   //当前选项，1为start，2为exit
	FlushBatchDraw();
	while (1)
	{
		if ((GetAsyncKeyState(VK_UP) < 0) or (GetAsyncKeyState(0x57) < 0))
		{
			cleardevice();
			DRAW();
			outtextxy(570, 350, _T("→"));
			FlushBatchDraw();
			option = 1;
		}
		if ((GetAsyncKeyState(VK_DOWN) < 0) or (GetAsyncKeyState(0x53) < 0))
		{
			cleardevice();
			BeginBatchDraw();
			DRAW();
			outtextxy(570, 390, _T("→"));
			FlushBatchDraw();
			option = 2;
		}
		if (GetAsyncKeyState(VK_RETURN) && 0x8000)
		{
			if (option == 1)
			{
				return;        //退出menu()函数开始游戏    
			}
			else if (option == 2)
			{
				closegraph();	 //关闭绘图窗口
				exit(0);
			}
		}
	}
}
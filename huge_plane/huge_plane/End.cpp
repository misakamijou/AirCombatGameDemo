#include"definition.h"
//���ƽ���
void DRAW_end(int level)
{
	//����
	settextstyle(70, 0, _T("����"));
	outtextxy(435, 200, _T("MISSION FAILED"));
	settextstyle(40, 0, _T("����"));
	outtextxy(555, 300, _T("max level:"));

	//�����ǰ�ؿ���
	TCHAR s[5];
	_stprintf_s(s, _T("%d"), level);
	outtextxy(755, 300, s);

	//ѡ��
	settextstyle(30, 0, _T("����"));
	outtextxy(617, 450, _T("RESTART"));
	outtextxy(638, 490, _T("EXIT"));
}
int end(int level)
{
	//initgraph(1366, 720);

	//��ʼ״̬�����ѡ��1
	cleardevice();
	DRAW_end(level);
	outtextxy(570, 450, _T("��"));

	int option = 1;   //��ǰѡ�1Ϊrestart��2Ϊexit
	FlushBatchDraw();
	while (1)
	{
		if ((GetAsyncKeyState(VK_UP) <0) or (GetAsyncKeyState(0x57) < 0))
		{
			cleardevice();
			DRAW_end(level);
			outtextxy(570, 450, _T("��"));
			FlushBatchDraw();
			option = 1;
		}
		if ((GetAsyncKeyState(VK_DOWN) < 0) or (GetAsyncKeyState(0x53) < 0))
		{
			cleardevice();
			DRAW_end(level);
			outtextxy(570, 490, _T("��"));
			FlushBatchDraw();
			option = 2;
		}
		if (GetAsyncKeyState(VK_RETURN) <0)
		{
			return option;
		}
	}
}
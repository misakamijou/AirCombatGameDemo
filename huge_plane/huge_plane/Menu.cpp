#include"definition.h"
//���ƽ���
void DRAW()
{
	//����
	settextstyle(70, 0, _T("����"));
	outtextxy(585, 200, _T("TITLE"));

	//ѡ��
	settextstyle(30, 0, _T("����"));
	outtextxy(632, 350, _T("START"));
	outtextxy(638, 390, _T("EXIT"));
}
void menu()
{
	BeginBatchDraw();
	//��ʼ״̬�����ѡ��1
	DRAW();
	outtextxy(570, 350, _T("��"));

	int option = 1;   //��ǰѡ�1Ϊstart��2Ϊexit
	FlushBatchDraw();
	while (1)
	{
		if ((GetAsyncKeyState(VK_UP) < 0) or (GetAsyncKeyState(0x57) < 0))
		{
			cleardevice();
			DRAW();
			outtextxy(570, 350, _T("��"));
			FlushBatchDraw();
			option = 1;
		}
		if ((GetAsyncKeyState(VK_DOWN) < 0) or (GetAsyncKeyState(0x53) < 0))
		{
			cleardevice();
			BeginBatchDraw();
			DRAW();
			outtextxy(570, 390, _T("��"));
			FlushBatchDraw();
			option = 2;
		}
		if (GetAsyncKeyState(VK_RETURN) && 0x8000)
		{
			if (option == 1)
			{
				return;        //�˳�menu()������ʼ��Ϸ    
			}
			else if (option == 2)
			{
				closegraph();	 //�رջ�ͼ����
				exit(0);
			}
		}
	}
}
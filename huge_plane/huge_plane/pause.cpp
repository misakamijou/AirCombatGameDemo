#include"definition.h"
//���ƽ���
void DRAWPAUSE()
{
	setfillcolor(BLACK);
	fillrectangle(485, 250, 885, 450);
	settextstyle(70, 0, _T("����"));
	outtextxy(600, 275, _T("PAUSE"));
	//ѡ��
	settextstyle(30, 0, _T("����"));
	outtextxy(632, 350, _T("CONTINUE"));
	outtextxy(638, 390, _T("EXIT"));
}
int pause()
{
	if (GetAsyncKeyState(VK_ESCAPE) < 0) {

		//��ʼ״̬�����ѡ��1
		DRAWPAUSE();
		outtextxy(570, 350, _T("��"));
		FlushBatchDraw();

		int option = 1;   //��ǰѡ�1Ϊcontinue��2Ϊexit

		while (1)
		{
			if ((GetAsyncKeyState(VK_UP) < 0) or (GetAsyncKeyState(0x57) < 0))
			{
				DRAWPAUSE();
				outtextxy(570, 350, _T("��"));
				FlushBatchDraw();
				option = 1;
			}
			if ((GetAsyncKeyState(VK_DOWN) < 0) or (GetAsyncKeyState(0x53) < 0))
			{
				DRAWPAUSE();
				outtextxy(570, 390, _T("��"));
				FlushBatchDraw();
				option = 2;
			}
			if (GetAsyncKeyState(VK_RETURN) && 0x8000)
			{
				if (option == 1)
				{
					return 1;        //�˳�menu()������ʼ��Ϸ    
				}
				else if (option == 2)
				{
					closegraph();	 //�رջ�ͼ����
					exit(0);
				}
			}
		}
	}
}
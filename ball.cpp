#include<stdio.h>
#include<easyx.h>
#include<conio.h>
#include<time.h>

	typedef struct {
		int x, y;
		int vx, vy;
		int r;
		int barLeft, barTop, barRight, barBotton;
	}GameData;

	void reset(GameData* gdata)
	{
		gdata->x = rand() % (400 + 1) - 200;
		gdata->y = rand() % (300 + 1) - 150;
		gdata->vx = 5;
		gdata->vy = 5;
		if (rand() % 2 == 0)
		{
			gdata->vy = -gdata->vy;
		}
		if (rand() % 2 == 0)
		{
			gdata->vx = -gdata->vx;
		}
		gdata->r = 40;
		gdata->barLeft = -150;
		gdata->barRight = 150;
		gdata->barTop = -280;
		gdata->barBotton = -300;



	}
	int main()
	{
		initgraph(800,600);
		setorigin(400,300);
		setaspectratio(1,-1);
		setbkcolor(RGB(164,225,202));
		cleardevice();

		srand((unsigned int)time(NULL));
		GameData gdata;
		reset(&gdata);

		while (1)
		{
			cleardevice();

			solidcircle(gdata.x,gdata.y,gdata.r);
			solidrectangle(gdata.barLeft,gdata.barTop,gdata.barRight,gdata.barBotton);
			Sleep(40);
			if (gdata.y >= 300 - gdata.r)
			{
				gdata.vy = -gdata.vy;
			}
			if (gdata.x <= -400 + gdata.r || gdata.x >= 400 - gdata.r)
			{
				gdata.vx = -gdata.vx;
			}
			if (gdata.barLeft<=gdata.x&&gdata.x<=gdata.barRight&&gdata.y<=gdata.barTop+gdata.r) 
			{
				gdata.vy = -gdata.vy;
			}
			gdata.x += gdata.vx;
			gdata.y += gdata.vy;
			if (_kbhit()!= 0)
			{
				char c = _getch();
				if (c == 'a')
				{
					if (gdata.barLeft > -400)
					{
						gdata.barLeft -= 20;
						gdata.barRight -= 20;

					}
				}
					else if (c == 'd')
					{
						if (gdata.barRight < 400)
						{
							gdata.barLeft += 20;
							gdata.barRight += 20;
						}
					}
				
			 }
			if (gdata.y <= -300)
			{
				reset(&gdata);
			}

		}

		closegraph();
		return 0;
	}




#include "PongGame.h"

RECT BallPosition;

void Update(HWND hwnd, int i);

void EntryPoint(HWND hwnd)
{
	for (int i = 0; i < 20; i++)
	{
		Update(hwnd,i);
		Sleep(1000);
	}
}
void Update(HWND hwnd, int i)
{
	RECT ClientRect;
	GetClientRect(hwnd, &ClientRect);

	BallPosition.left = (ClientRect.right - ClientRect.left) / 2 - 20 + 2 * i;
	BallPosition.top = (ClientRect.bottom - ClientRect.top) / 2 - 20;
	BallPosition.bottom = BallPosition.top + BALL_DIMENSION;
	BallPosition.right = BallPosition.left + BALL_DIMENSION;
	InvalidateRect(hwnd, &ClientRect, TRUE);
}
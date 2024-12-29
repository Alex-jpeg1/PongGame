#include "PongGame.h"

RECT BallPosition;

int i = 0;

void EntryPoint(HWND hwnd)
{
	SetTimer(hwnd, 1, 10, NULL);

}
void Update(HWND hwnd)
{
	RECT ClientRect;
	GetClientRect(hwnd, &ClientRect);

	BallPosition.left = (ClientRect.right - ClientRect.left) / 2 - 20 + i;
	BallPosition.top = (ClientRect.bottom - ClientRect.top) / 2 - 20;
	BallPosition.bottom = BallPosition.top + BALL_DIMENSION;
	BallPosition.right = BallPosition.left + BALL_DIMENSION;
	InvalidateRect(hwnd, &ClientRect, TRUE);
}
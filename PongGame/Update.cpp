#include "PongGame.h"

RECT BallPosition;

int i = 0;
RECT LeftPaddle = { 40, 200, 40 + PADDLE_WIDTH, 200 + PADDLE_HEIGHT };

RECT RightPaddle = { 1000, 200, 1000 + PADDLE_WIDTH, 200 + PADDLE_HEIGHT };

void EntryPoint(HWND hwnd)
{
	SetTimer(hwnd, 1, FRAME_RATE, NULL);
}
void UpdateBall(HWND hwnd)
{
	RECT ClientRect;
	GetClientRect(hwnd, &ClientRect);

	BallPosition.left = (ClientRect.right - ClientRect.left) / 2 - 20 - i;
	BallPosition.top = (ClientRect.bottom - ClientRect.top) / 2 - 20;
	BallPosition.bottom = BallPosition.top + BALL_DIMENSION;
	BallPosition.right = BallPosition.left + BALL_DIMENSION;
	InvalidateRect(hwnd, &ClientRect, TRUE);
}

void UpdateLeftPaddle(HWND hwnd, BOOL Up)
{
	RECT ClientRect;

	GetClientRect(hwnd, &ClientRect);
	
	if (Up == FALSE)
	{
		LeftPaddle.top += PADDLE_SPEED / FRAME_RATE;
	}
	else
	{
		LeftPaddle.top -= PADDLE_SPEED / FRAME_RATE;
	}

	LeftPaddle.bottom = LeftPaddle.top + PADDLE_HEIGHT;

	InvalidateRect(hwnd, &LeftPaddle, TRUE);
}
void UpdateRightPaddle(HWND hwnd, BOOL Up)
{
	RECT ClientRect;

	GetClientRect(hwnd, &ClientRect);

	if (Up == FALSE)
	{
		RightPaddle.top += PADDLE_SPEED / FRAME_RATE;
	}
	else
	{
		RightPaddle.top -= PADDLE_SPEED / FRAME_RATE;
	}

	RightPaddle.bottom = RightPaddle.top + PADDLE_HEIGHT;

	InvalidateRect(hwnd, &RightPaddle, TRUE);
}
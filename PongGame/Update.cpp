#include "PongGame.h"

RECT BallPosition;
RECT ClientRect;

int BallSpeedY = BALL_SPEED_Y;

int BallSpeedX = BALL_SPEED_X;

void EntryPoint(HWND hwnd)
{
	SetTimer(hwnd, 1, FRAME_RATE, NULL);
}
UpdateBall::UpdateBall()
{

	BallPosition.left = (ClientRect.right - ClientRect.left) / 2 - 20;
	BallPosition.top = (ClientRect.bottom - ClientRect.top) / 2 - 20;
	BallPosition.bottom = BallPosition.top + BALL_DIMENSION;
	BallPosition.right = BallPosition.left + BALL_DIMENSION;
}
void UpdateBall::UpdateBallMethod(HWND hwnd)
{
	if (BallPosition.top <= 0 || BallPosition.bottom >= ClientRect.bottom)
		{
			BallSpeedY = -BallSpeedY;
		}
	if (BallPosition.right >= RightPaddle.paddle.left || BallPosition.left <= LeftPaddle.paddle.right)
		{
		if (	((BallPosition.top >= RightPaddle.paddle.bottom || BallPosition.bottom <= RightPaddle.paddle.top) && BallPosition.right >= RightPaddle.paddle.left)		 || ((BallPosition.top >= LeftPaddle.paddle.bottom || BallPosition.bottom <= LeftPaddle.paddle.top)&& BallPosition.left <= LeftPaddle.paddle.right))
		{
			KillTimer(hwnd, 1);
			PostQuitMessage(0);
		}
			BallSpeedX = -BallSpeedX;
		}
	BallPosition.top += BallSpeedY;
	BallPosition.bottom += BallSpeedY;
	BallPosition.left += BallSpeedX;
	BallPosition.right += BallSpeedX;
	InvalidateRect(hwnd, &ClientRect, TRUE);
}
UpdatePaddle::UpdatePaddle(int left, int right, int top, int bottom) {
		paddle.left = left;
		paddle.right = right;
		paddle.top = top;
		paddle.bottom = bottom;
	}

void UpdatePaddle::UpdatePaddleMethod(HWND hwnd, BOOL Up)
	{
		RECT ClientRect;
		GetClientRect(hwnd, &ClientRect);
		if (Up) {
			if (paddle.top > 0)
			{
				paddle.top -= PADDLE_SPEED / FRAME_RATE;
				paddle.bottom -= PADDLE_SPEED / FRAME_RATE;
				InvalidateRect(hwnd, &ClientRect, TRUE);
			}
		}
		else {
			if (paddle.bottom < ClientRect.bottom) 
			{
				paddle.top += PADDLE_SPEED / FRAME_RATE;
				paddle.bottom += PADDLE_SPEED / FRAME_RATE;
				InvalidateRect(hwnd, &ClientRect, TRUE);
			}
		}
	}
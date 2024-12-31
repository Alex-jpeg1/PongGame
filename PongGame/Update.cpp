#include "PongGame.h"

RECT BallPosition;

int i = 0;

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
				paddle.top -= PADDLE_SPEED/FRAME_RATE;
				paddle.bottom -= PADDLE_SPEED / FRAME_RATE;
		}
		else {
				paddle.top += PADDLE_SPEED / FRAME_RATE;
				paddle.bottom += PADDLE_SPEED / FRAME_RATE;
		}
		InvalidateRect(hwnd, &ClientRect, TRUE);
	}
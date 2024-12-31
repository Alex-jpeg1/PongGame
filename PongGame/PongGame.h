#pragma once
#include "framework.h"
#include "Resource.h"
#include <unordered_map>
#ifndef PONGGAME_H
#define PONGGAME_H

#define BALL_DIMENSION 20
#define PADDLE_WIDTH 20
#define PADDLE_HEIGHT 40
#define FRAME_RATE 16.67
#define PADDLE_SPEED 50
#define	BALL_SPEED 50/FRAME_RATE
#define BALL_SPEED_X BALL_SPEED
#define BALL_SPEED_Y BALL_SPEED

void EntryPoint(HWND hwnd);

extern RECT ClientRect;
class UpdateBall {
	public:
		RECT BallPosition;
		UpdateBall();
		void UpdateBallMethod(HWND hwnd);
};
class UpdatePaddle {
	public: 
		RECT paddle;
		UpdatePaddle(int left, int right, int top, int bottom);
		void UpdatePaddleMethod(HWND hwnd, BOOL Up);
};

extern UpdatePaddle LeftPaddle;
extern UpdatePaddle RightPaddle;
#endif
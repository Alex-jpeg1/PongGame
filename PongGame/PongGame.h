#pragma once
#include "framework.h"
#include "Resource.h"
#ifndef PONGGAME_H
#define PONGGAME_H

#define BALL_DIMENSION 20
#define PADDLE_WIDTH 20
#define PADDLE_HEIGHT 40
#define FRAME_RATE 16.67
#define PADDLE_SPEED 50

void EntryPoint(HWND hwnd);

extern RECT BallPosition;

extern int i;

void UpdateBall(HWND hwnd);

class UpdatePaddle {
	public: 
		RECT paddle;
		UpdatePaddle(int left, int right, int top, int bottom);
		void UpdatePaddleMethod(HWND hwnd, BOOL Up);
};

#endif
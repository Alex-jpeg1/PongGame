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
extern RECT LeftPaddle, RightPaddle;

extern int i;

void UpdateBall(HWND hwnd);

void UpdateLeftPaddle(HWND hwnd, BOOL Up);

void UpdateRightPaddle(HWND hwnd, BOOL Up);


#endif
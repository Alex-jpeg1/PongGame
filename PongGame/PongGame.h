#pragma once
#include "framework.h"
#include "Resource.h"
#ifndef PONGGAME_H
#define PONGGAME_H

#define BALL_DIMENSION 40

void EntryPoint(HWND hwnd);

extern RECT BallPosition;
extern int i;
void Update(HWND hwnd);

#endif
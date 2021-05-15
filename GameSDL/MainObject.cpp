﻿#include "MainObject.h"

MainObject::MainObject() {
	rect.x = 0;
	rect.y = 0;
	rect.w = WIDTH_MAIN_OBJECT;
	rect.h = HEIGHT_MAIN_OBJECT;
	//x_val = 0;
	//y_val = 0;
	x_val = WIDTH_MAIN_OBJECT / 2;
	y_val = HEIGHT_MAIN_OBJECT / 2;
}

MainObject::~MainObject() {

}

void MainObject::HandleInputAction(SDL_Event events) {
	// keyboard 
	if (events.type == SDL_KEYDOWN) 
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_UP:
			//y_val -= HEIGHT_MAIN_OBJECT / 3;
			rect.y -= y_val;
			if (rect.y < 0) rect.y += y_val;
			break;

		case SDLK_DOWN:
			//y_val += HEIGHT_MAIN_OBJECT / 3;
			rect.y += y_val;
			if (rect.y + HEIGHT_MAIN_OBJECT > SCREEN_HEIGHT) rect.y -= y_val;
			break;

		case SDLK_LEFT:
			//x_val -= WIDTH_MAIN_OBJECT / 3;
			rect.x -= x_val;
			if (rect.x < 0) rect.x += x_val;
			break;

		case SDLK_RIGHT:
			//x_val += WIDTH_MAIN_OBJECT / 3;
			rect.x += x_val;
			if (rect.x + WIDTH_MAIN_OBJECT > SCREEN_WIDTH) rect.x -= x_val;
			break;

		default:
			break;
		}
	}

	else if (events.type == SDL_KEYUP) 
	{
		//switch (events.key.keysym.sym)
		//{
		//case SDLK_UP:
		//	//y_val += HEIGHT_MAIN_OBJECT / 3;
		//	y_val = 0;
		//	break;

		//case SDLK_DOWN:
		//	//y_val -= HEIGHT_MAIN_OBJECT / 3;
		//	y_val = 0;
		//	break;

		//case SDLK_LEFT:
		//	//x_val += WIDTH_MAIN_OBJECT / 3;
		//	x_val = 0;
		//	break;

		//case SDLK_RIGHT:
		//	//x_val -= WIDTH_MAIN_OBJECT / 3;
		//	x_val = 0;
		//	break;

		//default:
		//	break;
		//}
	}

	// MOUSE
	else if (events.type == SDL_MOUSEBUTTONDOWN) {

	}

	else if (events.type == SDL_MOUSEBUTTONUP) {

	}

}

//void MainObject::HandleMove() {
//	rect.x += x_val;
//	if (rect.x < 0 || rect.x + WIDTH_MAIN_OBJECT > SCREEN_WIDTH)
//		rect.x -= x_val;
//
//	rect.y += y_val;
//	if (rect.y < 0 || rect.y + HEIGHT_MAIN_OBJECT > SCREEN_HEIGHT)
//		rect.y -= y_val;
//}

bool MainObject::CheckCollision(const SDL_Rect& Threats) {
	// MainObject
	int left_M = rect.x;
	int right_M = rect.x + rect.w;
	int top_M = rect.y;
	int bottom_M = rect.y + rect.h;

	// ThreatsObject
	int left_T = Threats.x;
	int right_T = Threats.x + Threats.w;
	int top_T = Threats.y;
	int bottom_T = Threats.y + Threats.h;

	// size MainObject < size Threats
	if (right_M > left_T && right_M < right_T) {
		if (bottom_M > top_T && bottom_M < bottom_T) return true;
		if (top_M > top_T && top_M < bottom_T) return true;
	}

	if (left_M > left_T && left_M < right_T) {
		if (bottom_M > top_T && bottom_M < bottom_T) return true;
		if (top_M > top_T && top_M < bottom_T) return true;
	}

	// size MainObject > size Threats
	if (right_T > left_M && right_T < right_M) {
		if (bottom_T > top_M && bottom_T < bottom_M) return true;
		if (top_T > top_M && top_T < bottom_M) return true;
	}

	if (left_T > left_M && left_T < right_M) {
		if (bottom_T > top_M && bottom_T < bottom_M) return true;
		if (top_T > top_M && top_T < bottom_M) return true;
	}

	// size MainObject == size Threats
	if (left_M == left_T && right_M == right_T && top_M == top_T && bottom_M == bottom_T) return true;

	return false;
}
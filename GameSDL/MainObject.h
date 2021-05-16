#pragma once

#include "BaseProperties.h"
#include "BaseObject.h"

#define WIDTH_MAIN_OBJECT 50
#define	HEIGHT_MAIN_OBJECT 100

const int POS_X_START_MAIN_OBJECT = 218;
const int POS_Y_START_MAIN_OBJECT = 600;

class MainObject : public BaseObject {
	int x_val;
	int y_val;
public:
	MainObject();
	~MainObject();
	void HandleInputAction(SDL_Event events);
	bool CheckCollision(const SDL_Rect& Threats);
};
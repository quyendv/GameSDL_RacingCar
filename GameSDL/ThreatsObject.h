#pragma once

#include "BaseProperties.h"
#include "BaseObject.h"

#define WIDTH_THREAT 50
#define HEIGHT_THREAT 100

class ThreatObject : public BaseObject {
	int x_val;
	int y_val;
public:
	ThreatObject();
	~ThreatObject();
	void HandleMove();
	void HandleInputAction(SDL_Event events);
	void set_x_val(const int& val) { x_val = val; }
	void set_y_val(const int& val) { y_val = val; }
	int get_x_val() { return x_val; }
	int get_y_val() { return y_val; }
};
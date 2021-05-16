# pragma once

#include "BaseProperties.h"
#include "BaseObject.h"

class PlayerPower : public BaseObject {
	int number;
	vector<int> pos_list;
public:
	PlayerPower();
	~PlayerPower();

	void Show(SDL_Renderer* screen);
	void Init(SDL_Renderer* screen);
	void SetNum(int _number) { number = _number; }
	int GetNum() { return number; }
	void Decrease();
};
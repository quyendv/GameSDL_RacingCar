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
};
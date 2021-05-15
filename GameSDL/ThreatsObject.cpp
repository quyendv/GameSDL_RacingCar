
#include "ThreatsObject.h"


ThreatObject::ThreatObject() {
	rect.x = SCREEN_WIDTH / 2;
	rect.y = 0; 
	rect.w = WIDTH_THREAT;
	rect.h = HEIGHT_THREAT;

	x_val = 0;
	y_val = 0;
}

ThreatObject::~ThreatObject() {

}

void ThreatObject::HandleInputAction(SDL_Event events) {

}

void ThreatObject::HandleMove() {
	rect.y += y_val;
	if (rect.y > SCREEN_HEIGHT) {
		rect.y = -HEIGHT_THREAT;
		srand(time(NULL));
		int r = rand() % ROAD_LANE_NUM;
		rect.x = ROAD_LANE[r];
	}
}
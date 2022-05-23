#include "ObjectBuffPower.h"

ObjectToBuffPower::ObjectToBuffPower()
{
	BoxRect = { 0,0,WidthOfObjectBuffPower,HeightOfOstacleObject };
}
ObjectToBuffPower::~ObjectToBuffPower() {};
void ObjectToBuffPower::SetStatrtPositionOfObjectBuffPower(const int& x, const int& y)
{
	BoxRect.x = x;
	BoxRect.y = y;
}
bool ObjectToBuffPower::LoadObjectTobuffPower(string path, SDL_Renderer* screen)
{
	bool load = LTexture::loadFromFile(path, screen);
	return load;
}
void ObjectToBuffPower::AutoIncreaseYForObjectBuffPower()
{
	BoxRect.y += BOX_SPEED;
}
void ObjectToBuffPower::ObjectBuffPowernotMove()
{
	BoxRect.y += 0;
}
void ObjectToBuffPower::render(SDL_Renderer * screen)
{
	LTexture::render(screen, BoxRect.x, BoxRect.y);
	//SDL_SetRenderDrawColor(screen, 0, 0, 0, 255);
	//SDL_RenderDrawRect(screen, &BoxRect);
	//SDL_RenderDrawRect(screen, &MainBoxRectToCheckColision);
}
int ObjectToBuffPower::GetPositionYofObjectBuffPower() const { return BoxRect.y; }
SDL_Rect ObjectToBuffPower::GetBoxRect() const { return BoxRect; }

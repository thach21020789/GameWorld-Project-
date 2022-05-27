#include "ObjectBuffPower.h"
#include "function.h"

ItemToBuffPower::ItemToBuffPower()
{
	BoxRect = { 0,0,WidthOfObjectBuffPower,HeightOfOstacleObject };
	is_moving = false;
}
ItemToBuffPower::~ItemToBuffPower() {};
void ItemToBuffPower::SetStatrtPositionOfObjectBuffPower(const int& x, const int& y)
{
	BoxRect.x = x;
	BoxRect.y = y;
}
bool ItemToBuffPower::LoadObjectTobuffPower(string path, SDL_Renderer* screen)
{
	bool load = LTexture::loadFromFile(path, screen);
	return load;
}
void ItemToBuffPower::AutoIncreaseYForObjectBuffPower(SDL_Rect& maincar)
{
	if (is_moving) BoxRect.y += BOX_SPEED;

	if (checkCollision(maincar, BoxRect)) is_moving = false;
}
void ItemToBuffPower::ObjectBuffPowernotMove()
{
	BoxRect.y += 0;
}
void ItemToBuffPower::render(SDL_Renderer * screen)
{
	LTexture::render(screen, BoxRect.x, BoxRect.y);
	//SDL_SetRenderDrawColor(screen, 0, 0, 0, 255);
	//SDL_RenderDrawRect(screen, &BoxRect);
	//SDL_RenderDrawRect(screen, &MainBoxRectToCheckColision);
}
int ItemToBuffPower::GetPositionYofObjectBuffPower() const { return BoxRect.y; }
SDL_Rect ItemToBuffPower::GetBoxRect() const { return BoxRect; }

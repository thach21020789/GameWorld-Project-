#include "ObstacleObject.h"
#include "function.h"

OstacleObject::OstacleObject()
{
	BoxObstacleObject = { 0,0,WithOfOstacleObject,HeightOfOstacleObject };
}
OstacleObject::~OstacleObject() {};
void OstacleObject::OstacleObject::SetStartPosition(const int& x, const int& y) { BoxObstacleObject.x = x; BoxObstacleObject.y = y; }
bool OstacleObject::OstacleObject::LoadObstacleObject_texture(string path, SDL_Renderer* screen)
{
	bool loadFile = LTexture::loadFromFile(path,screen);
	return loadFile;
}
void OstacleObject::AutoIncreaseYForOstacleObject(SDL_Rect &maincar)
{
	if (is_moving) BoxObstacleObject.y += OstacleObjectSpeed;
}
void OstacleObject::ObjectNotMove()
{
	BoxObstacleObject.y += 0;
}
void OstacleObject::render(SDL_Renderer *screen)
{
	LTexture::render(screen, BoxObstacleObject.x, BoxObstacleObject.y);
	//SDL_SetRenderDrawColor(screen, 0, 0, 0, 255);
	//SDL_RenderDrawRect(screen, &BoxObstacleObject);
}

int OstacleObject::GetObjectPositionY() const { return BoxObstacleObject.y; }
SDL_Rect OstacleObject::getObstacleObjectRect() const { return BoxObstacleObject; }
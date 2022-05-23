#include "mainCar.h"

MainCar::MainCar()
{
	MainCarRect = { 0,0,WithOfCarMain,HeightOfCarMain };
	BoxOfMainCArToCheckCollision = { 0,0,50, 115 };
	mVelX = 0;
	mVelY = 0;
}
MainCar::~MainCar() {};
void MainCar::init()
{
	MainCarRect.x = 380;
	MainCarRect.y = 510;


	BoxOfMainCArToCheckCollision.x = 390;
	BoxOfMainCArToCheckCollision.y = 510;
}
void MainCar::SetStartPositionMainCar(const int& x, const int& y)
{
	MainCarRect.x = x;
	MainCarRect.y = y;
	BoxOfMainCArToCheckCollision.x = x + 10;
	BoxOfMainCArToCheckCollision.y = y + 20;
}

bool MainCar::LoadMainCar(string path, SDL_Renderer* screen)
{
	bool loadFile = LTexture::loadFromFile(path, screen);
	return loadFile;
}
void MainCar::SetCurrentTexture(LTexture texture) {
	setmTexture(texture.getmTexture());
}


void MainCar::HandleMainCar(SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
			case SDLK_UP: mVelY -= MainCarSpeed; break;
			case SDLK_DOWN: mVelY += MainCarSpeed; break;
			case SDLK_LEFT: mVelX -= MainCarSpeed; break;
			case SDLK_RIGHT: mVelX += MainCarSpeed; break;
		}
	}

	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
			case SDLK_UP: mVelY += MainCarSpeed; break;
			case SDLK_DOWN: mVelY -= MainCarSpeed; break;
			case SDLK_LEFT: mVelX += MainCarSpeed; break;
			case SDLK_RIGHT: mVelX -= MainCarSpeed; break;
		}
	}
}

void MainCar::move()
{
	MainCarRect.x += mVelX;
	BoxOfMainCArToCheckCollision.x = MainCarRect.x + 10;
	if (MainCarRect.x < leftBorderOfroad || MainCarRect.x + WithOfCarMain > rigthBorderOfRoad)
	{
		MainCarRect.x -= mVelX;

		BoxOfMainCArToCheckCollision.x = MainCarRect.x + 10;
	}
	//Move the dot up or down
	MainCarRect.y += mVelY;
	BoxOfMainCArToCheckCollision.y = MainCarRect.y + 20;
	//If the dot collided or went too far up or down
	if ((MainCarRect.y < 0) || (MainCarRect.y + HeightOfCarMain >= 650))
	{
		//Move back
		MainCarRect.y -= mVelY;


		BoxOfMainCArToCheckCollision.y = MainCarRect.y + 20;
	}
}
void MainCar::render(SDL_Renderer *screen)
{
	LTexture::render(screen, MainCarRect.x, MainCarRect.y);
	//SDL_SetRenderDrawColor(screen, 0, 0, 0, 255);
	//SDL_RenderDrawRect(screen, &BoxOfMainCArToCheckCollision);
	//SDL_RenderDrawRect(screen, &MainCarRect);
}
SDL_Rect MainCar::GetMainCarRect() const { return MainCarRect; }
SDL_Rect MainCar::GetMainCarCollisionBoxOfMainCAr() const { return BoxOfMainCArToCheckCollision; }

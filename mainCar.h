#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <SDL_mixer.h>
#include<SDL_ttf.h>
#include "Htexture.h"
class MainCar :public LTexture
{
public:
	const int WithOfCarMain = 60;
	static const int HeightOfCarMain = 140;
	const int RectHeightOfCarmain = 100;
	const int RectWithOfCarmain = 50;
	const int MainCarSpeed = 5;
	const int leftBorderOfroad = 255;
	const int rigthBorderOfRoad = 565;
	MainCar();
	~MainCar() ;
	void init();
	void SetStartPositionMainCar(const int& x, const int& y);
	bool LoadMainCar(string path, SDL_Renderer* screen);
	void SetCurrentTexture(LTexture texture);
	void HandleMainCar(SDL_Event& e);
	void move();
	void render(SDL_Renderer *screen);
	SDL_Rect GetMainCarRect() const;
	SDL_Rect GetMainCarCollisionBoxOfMainCAr() const;
private:
	SDL_Rect MainCarRect;
	SDL_Rect BoxOfMainCArToCheckCollision;
	int mVelY, mVelX;
};

static MainCar AUDI_X8;

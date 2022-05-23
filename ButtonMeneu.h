#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include "Htexture.h"
#include "LTimer.h"
#include "CommomObject.h"
#include "mainCar.h"
#include "CommomObject.h"
enum ButtonSprite
{
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
	PAUSE_BUTTON_SPRITE_MOUSE_DOWN0 = 0,
	PAUSE_BUTTON_SPRITE_MOUSE_DOWN1 = 1
};

class ButtonMeneu : public LTexture
{
public:
	int frame = 0;
	const int WidthOfButton = 200;
	const int HeightOfButton = 50;
	const int WidthOfButonPause = 70;
	const int HeightOfbuttonPause = 70;
	ButtonMeneu();
	void setPosition(int x, int y);
	~ButtonMeneu();
	//Handles mouse event
	void handleEventBottonplay(SDL_Event* e, bool& IsStartGame, LTimer &gtime);
	void handleEventBottonoption(SDL_Event* e, SDL_Renderer* &screen, LTexture &Mtextureoption);
	void handleEventBottonExit(SDL_Event* e, bool& IsRunningGame);
	void handleEventBottonplayAgain(SDL_Event* e, MainCar &AUDI_X8, OBJECT &ObjectList, LTimer &gtime, bool& isRunningBackground, bool& PauseGame, bool& IsMoveMainCar);
	void handleEventBottonPause(SDL_Event* e, LTimer& gtime, bool& isRunningBackground, bool& PauseGame, bool& IsMoveMainCar);

	
	void RenderButtonPlay(LTexture &ButtonSpriteSheetTexture, SDL_Rect gSpriteClipsForButtonPlay[], SDL_Renderer* &screen);
	void RenderButtonOption(LTexture &ButtonSpriteSheetTexture, SDL_Rect gSpriteClipsForButtonOption[], SDL_Renderer* &screen);
	void RenderButtonExit(LTexture &ButtonSpriteSheetTexture, SDL_Rect gSpriteClipsForButtonExit[], SDL_Renderer* &screen);
	void RenderButtonPlayAgain(LTexture &ButtonSpriteSheetTexture, SDL_Rect gSpriteClipsForButtonPlayAgain[], SDL_Renderer* &screen);
	void renderButtonPause(LTexture &SpritePauseSheet, SDL_Rect gSpriteClipsForButtonPause[], SDL_Renderer* &screen);
	
private:
	//Top left position
	SDL_Point mPosition;
	//Currently used global sprite
	ButtonSprite mCurrentSprite;
};
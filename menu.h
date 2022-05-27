#pragma once
#include "Htexture.h"
#include "button.h"
#include "CommomObject.h"
#include "mainCar.h"
#include "LTimer.h"



static SDL_Rect gSpriteClipsExplosion[5] = {
	{ 0,0,180,150 },
	{ 180,0,180,150 },
	{ 360, 0,180, 150 },
	{ 540, 0 ,180, 150 },
	{ 720, 0 , 180, 150 }
};

enum SCREEN_STATUS
{
	START_SCREEN = 0,
	PLAYING_SCREEN = 1,
	PAUSE_SCREEN = 2,
	OPTION_SCREEN = 3,
	PLAY_AGAIN = 4
};

class MENU
{
public:

	MENU();

	~MENU();

	bool loadButtonTexture(SDL_Renderer* screen);

	void handleMenu(SDL_Event& e, bool& quit, LTimer &start_play_game);

	void renderMenu(SDL_Renderer* screen);

	void renderBackground(SDL_Renderer* screen);

	bool loadMenuBackdground(SDL_Renderer* screen);

	void setStartScreen();
	

	void setPlayingScreen();


	void setPauseScreen();
	

	void setOptionScreen();
	

	void setPlayAgainScreen();
	
	void setExplosionPositon(const int& x, const int& y);

	int getScreenStatus() const;

	void setStatus(const int& val);
private:
	int status;
	int frame;
	int explosion_pos_x, explosion_pos_y;


	LTexture start_screen_back_ground;
	LTexture SpriteEXplosionSheet;
	LTexture pause_background;
	LTexture option_texture;

	BUTTON play_button;
	BUTTON option_button;
	BUTTON exit_button;
	BUTTON pause_button;
	BUTTON play_again_button;

};
static MENU game_world_menu;

#pragma once
#include "Htexture.h"
enum button_status
{
	OUT = 0,
	OVER = 1,
	DOWN = 2
};
class BUTTON
{
public:

	BUTTON();

	~BUTTON();

	void handleButton(SDL_Event* e);
	

	bool loadButton(string path, SDL_Renderer* screen);
	

	void renderButton(SDL_Renderer* screen);
	

	void setIsButtonUseInScreen(const bool& val);

	void setIsButtonClick(const bool& val);

	void setButtonRect(const int& x, const int& y, const int& w, const int& h);
	

	void setButtonClipOut(const int& x, const int& y, const int& w, const int& h);


	void setButtonClipOver(const int& x, const int& y, const int& w, const int& h);
	

	void setButtonClipDown(const int& x, const int& y, const int& w, const int& h);
	

	bool getIsButtonClick() const;
private:
	LTexture buttonTexture;

	SDL_Rect buttonRect;
	int status;
	bool isButtonClick;
	bool isButtonUseInScreen;
	SDL_Rect buttonClip[3];
};





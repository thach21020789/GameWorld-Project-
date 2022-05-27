#include "button.h"
BUTTON::BUTTON()
{
	buttonRect.x = 0; buttonRect.y = 0;
	status = OUT;
	isButtonClick = false;
	isButtonUseInScreen = false;
	for (int i = 0; i < 3; ++i) buttonClip[i] = { 0,0,0,0 };
}

BUTTON::~BUTTON() {};

void BUTTON::handleButton(SDL_Event* e)
{
	if (isButtonUseInScreen)
	{
		if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
		{
			int posx, posy;

			SDL_GetMouseState(&posx, &posy);

			bool inside = true;

			if (posx < buttonRect.x) inside = false;
			else if (posx > buttonRect.x + buttonRect.w) inside = false;
			else if (posy < buttonRect.y) inside = false;
			else if (posy > buttonRect.y + buttonRect.h) inside = false;

			if (!inside)
			{
				status = OUT;
			}
			else
			{
				switch (e->type)
				{
				case SDL_MOUSEMOTION: status = OVER; break;
				case SDL_MOUSEBUTTONDOWN: status = DOWN; break;
				case SDL_MOUSEBUTTONUP: status = OVER; isButtonClick = true; break;
				}
			}
		}
	}
}

bool BUTTON::loadButton(string path, SDL_Renderer* screen)
{
	if (!buttonTexture.loadFromFile(path, screen))
	{
		cout << "fail to load button texture\n";
		return false;
	}
	return true;
}

void BUTTON::renderButton(SDL_Renderer* screen)
{
	if (isButtonUseInScreen) buttonTexture.render(screen, buttonRect.x, buttonRect.y, &buttonClip[status]);
}

void BUTTON::setIsButtonUseInScreen(const bool& val) { isButtonUseInScreen = val; }

void BUTTON::setIsButtonClick(const bool& val) { isButtonClick = val; }

void BUTTON::setButtonRect(const int& x, const int& y, const int& w, const int& h)
{
	buttonRect = { x,y,w,h };
}

void BUTTON::setButtonClipOut(const int& x, const int& y, const int& w, const int& h)
{
	buttonClip[0] = { x,y,w,h };
}

void BUTTON::setButtonClipOver(const int& x, const int& y, const int& w, const int& h)
{
	buttonClip[1] = { x,y,w,h };
}

void BUTTON::setButtonClipDown(const int& x, const int& y, const int& w, const int& h)
{
	buttonClip[2] = { x,y,w,h };
}

bool BUTTON::getIsButtonClick() const { return isButtonClick; }
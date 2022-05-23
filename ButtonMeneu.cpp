#include "ButtonMeneu.h"

ButtonMeneu::ButtonMeneu()
{
	mPosition.x = 0;
	mPosition.y = 0;
	mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
}
ButtonMeneu::~ButtonMeneu() {};
void ButtonMeneu::setPosition(int x, int y)
{
	mPosition.x = x;
	mPosition.y = y;
}

void ButtonMeneu::handleEventBottonplay(SDL_Event* e, bool & IsStartGame, LTimer &gtime)
{
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		bool inside = true;

		if (x < mPosition.x)
		{
			inside = false;
		}
		else if (x > mPosition.x + WidthOfButton)
		{
			inside = false;
		}
		else if (y < mPosition.y)
		{
			inside = false;
		}
		else if (y > mPosition.y + HeightOfButton)
		{
			inside = false;
		}

		if (!inside)
		{
			mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
		}
		else
		{
			switch (e->type)
			{
			case SDL_MOUSEMOTION:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				break;

			case SDL_MOUSEBUTTONDOWN:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
				gtime.start();
				IsStartGame = false;
				break;
			case SDL_MOUSEBUTTONUP:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
				break;
			}
		}
	}
}

void ButtonMeneu::handleEventBottonoption(SDL_Event* e,SDL_Renderer* &screen,LTexture &Mtextureoption)
{
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{

		int x, y;
		SDL_GetMouseState(&x, &y);
		bool inside = true;
		if (x < mPosition.x)
		{
			inside = false;
		}
		else if (x > mPosition.x + WidthOfButton)
		{
			inside = false;
		}
		else if (y < mPosition.y)
		{
			inside = false;
		}
		else if (y > mPosition.y + HeightOfButton)
		{
			inside = false;
		}
		if (!inside)
		{
			mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
		}
		else
		{
			switch (e->type)
			{
			case SDL_MOUSEMOTION:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				Mtextureoption.render(screen, 0, 0);
				SDL_RenderPresent(screen);
				break;
			case SDL_MOUSEBUTTONDOWN:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
				break;
			case SDL_MOUSEBUTTONUP:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
				break;
			}
		}
	}
}

void ButtonMeneu::handleEventBottonExit(SDL_Event* e, bool & IsRunningGame)
{
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		bool inside = true;
		if (x < mPosition.x)
		{
			inside = false;
		}
		else if (x > mPosition.x + WidthOfButton)
		{
			inside = false;
		}
		else if (y < mPosition.y)
		{
			inside = false;
		}
		else if (y > mPosition.y + HeightOfButton)
		{
			inside = false;
		}
		if (!inside)
		{
			mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
		}
		else
		{
			switch (e->type)
			{
			case SDL_MOUSEMOTION:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				break;

			case SDL_MOUSEBUTTONDOWN:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
				IsRunningGame = true;
				break;
			case SDL_MOUSEBUTTONUP:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
				break;
			}
		}
	}
}
void ButtonMeneu::handleEventBottonplayAgain(SDL_Event* e,MainCar &AUDI_X8, OBJECT &ObjectList,LTimer &gtime,bool & isRunningBackground, bool & PauseGame, bool & IsMoveMainCar)
{
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		bool inside = true;
		if (x < mPosition.x)
		{
			inside = false;
		}
		else if (x > mPosition.x + WidthOfButton)
		{
			inside = false;
		}

		else if (y < mPosition.y)
		{
			inside = false;
		}

		else if (y > mPosition.y + HeightOfButton)
		{
			inside = false;
		}


		if (!inside)
		{
			mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
		}
		else
		{
			//Set mouse over sprite
			switch (e->type)
			{
			case SDL_MOUSEMOTION:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				break;

			case SDL_MOUSEBUTTONDOWN:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
				AUDI_X8.init();
				ObjectList.ClearObstacleCar();
				ObjectList.clearListObjectToBuffPower();
				ObjectList.clearListObstacleObject();
				isRunningBackground = true;
				PauseGame = false;
				IsMoveMainCar = false;
				gtime.start();
				break;
			case SDL_MOUSEBUTTONUP:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
				break;
			}
		}
	}
}
void ButtonMeneu::handleEventBottonPause(SDL_Event* e,LTimer &gtime,bool &isRunningBackground, bool &PauseGame,bool &IsMoveMainCar)
{
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		bool inside = true;

		if (x < mPosition.x)
		{
			inside = false;
		}
		else if (x > mPosition.x + WidthOfButonPause)
		{
			inside = false;
		}
		else if (y < mPosition.y)
		{
			inside = false;
		}
		else if (y > mPosition.y + HeightOfbuttonPause)
		{
			inside = false;
		}
		if (!inside)
		{
			mCurrentSprite = PAUSE_BUTTON_SPRITE_MOUSE_DOWN0;
		}
		else
		{
			//Set mouse over sprite
			if (e->type == SDL_MOUSEBUTTONDOWN)
			{
				mCurrentSprite = PAUSE_BUTTON_SPRITE_MOUSE_DOWN1;
				if (gtime.isStarted() == true)
					gtime.pause();
				isRunningBackground = false;
				PauseGame = true;
				IsMoveMainCar = true;
			}
			else
			{
				if (gtime.isPaused())
					gtime.unpause();
;				isRunningBackground = true;
				PauseGame = false;
				IsMoveMainCar = false;
			}
		}
	}
}

//Render Button
void ButtonMeneu::RenderButtonPlay(LTexture &ButtonSpriteSheetTexture, SDL_Rect gSpriteClipsForButtonPlay[],SDL_Renderer* &screen)
{
	ButtonSpriteSheetTexture.render(screen, mPosition.x, mPosition.y, &gSpriteClipsForButtonPlay[mCurrentSprite]);
}
void ButtonMeneu::RenderButtonOption(LTexture &ButtonSpriteSheetTexture, SDL_Rect gSpriteClipsForButtonOption[], SDL_Renderer* &screen)
{
	ButtonSpriteSheetTexture.render(screen, mPosition.x, mPosition.y, &gSpriteClipsForButtonOption[mCurrentSprite]);
}
void ButtonMeneu::RenderButtonExit(LTexture &ButtonSpriteSheetTexture, SDL_Rect gSpriteClipsForButtonExit[], SDL_Renderer* &screen)
{
	ButtonSpriteSheetTexture.render(screen, mPosition.x, mPosition.y, &gSpriteClipsForButtonExit[mCurrentSprite]);
}
void ButtonMeneu::RenderButtonPlayAgain(LTexture &ButtonSpriteSheetTexture, SDL_Rect gSpriteClipsForButtonPlayAgain[], SDL_Renderer* &screen)
{
	ButtonSpriteSheetTexture.render(screen, mPosition.x, mPosition.y, &gSpriteClipsForButtonPlayAgain[mCurrentSprite]);
}
void ButtonMeneu::renderButtonPause(LTexture &SpritePauseSheet, SDL_Rect gSpriteClipsForButtonPause[], SDL_Renderer* &screen)
{
	SpritePauseSheet.render(screen, mPosition.x, mPosition.y, &gSpriteClipsForButtonPause[mCurrentSprite]);
}


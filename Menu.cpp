#include "menu.h"




MENU::MENU()
{
	status = START_SCREEN;
	frame = 0;
	explosion_pos_x = 0;
	explosion_pos_y = 0;
}

MENU::~MENU() {};

bool MENU::loadButtonTexture(SDL_Renderer* screen)
{
	if (!play_button.loadButton("clip Button effect game/BUttonAll.png", screen))
	{
		return false;
	}
	else
	{
		play_button.setButtonRect(300, 200, 200, 50);

		play_button.setButtonClipOut(0, 0, 200, 50);
		play_button.setButtonClipOver(0, 50, 200, 50);
		play_button.setButtonClipDown(0, 100, 200, 50);

		play_button.setIsButtonUseInScreen(true);
	}

	if (!option_button.loadButton("clip Button effect game/BUttonAll.png", screen))
	{
		return false;
	}
	else
	{
		option_button.setButtonRect(300, 300, 200, 50);

		option_button.setButtonClipOut(200, 0, 200, 50);
		option_button.setButtonClipOver(200, 50, 200, 50);
		option_button.setButtonClipDown(200, 100, 200, 50);

		option_button.setIsButtonUseInScreen(true);
	}

	if (!exit_button.loadButton("clip Button effect game/BUttonAll.png", screen))
	{
		return false;
	}
	else
	{
		exit_button.setButtonRect(300, 400, 200, 50);

		exit_button.setButtonClipOut(400, 0, 200, 50);
		exit_button.setButtonClipOver(400, 50, 200, 50);
		exit_button.setButtonClipDown(400, 100, 200, 50);

		exit_button.setIsButtonUseInScreen(true);
	}

	if (!pause_button.loadButton("clip Button effect game/ButtonPause.png", screen))
	{
		return false;
	}
	else
	{
		pause_button.setButtonRect(0, 0, 70, 70);

		pause_button.setButtonClipOut(0, 0, 70, 70);
		pause_button.setButtonClipOver(0, 0, 70, 70);
		pause_button.setButtonClipDown(0, 0, 70, 70);

		pause_button.setIsButtonUseInScreen(false);
	}

	if (!play_again_button.loadButton("clip Button effect game/BUttonAll.png", screen))
	{
		return false;
	}
	else
	{
		play_again_button.setButtonRect(300, 250, 200, 50);

		play_again_button.setButtonClipOut(0, 0, 200, 50);
		play_again_button.setButtonClipOver(0, 50, 200, 50);
		play_again_button.setButtonClipDown(0, 100, 200, 50);

		play_again_button.setIsButtonUseInScreen(false);
	}

	return true;
}


void MENU::handleMenu(SDL_Event& e, bool& quit, LTimer &start_play_game)
{
	play_button.handleButton(&e);
	exit_button.handleButton(&e);
	option_button.handleButton(&e);
	pause_button.handleButton(&e);
	play_again_button.handleButton(&e);

	if (play_button.getIsButtonClick())
	{
		play_button.setIsButtonClick(false);
		status = PLAYING_SCREEN;

		start_play_game.start();

		setPlayingScreen();
	}
	else if (exit_button.getIsButtonClick())
	{

		if (status == START_SCREEN) quit = true;
		else if (status == PAUSE_SCREEN)
		{
			exit_button.setIsButtonClick(false);

			start_play_game.stop();
			delayTimecreateObstacleCar.stop();
			delayTimecreateObstacleObject.stop();
			delayTimecreateItemBuffPower.stop();

			ObjectList.resetHardMode();

			ObjectList.clearListObjectToBuffPower();
			ObjectList.clearListObstacleObject();
			ObjectList.ClearObstacleCar();

			pause_button.setButtonRect(0, 0, 70, 70);

			pause_button.setButtonClipOut(0, 0, 70, 70);
			pause_button.setButtonClipOver(0, 0, 70, 70);
			pause_button.setButtonClipDown(0, 0, 70, 70);

			status = START_SCREEN;
			setStartScreen();
		}
	}
	else if (pause_button.getIsButtonClick())
	{
		pause_button.setIsButtonClick(false);
		if (status == PLAYING_SCREEN)
		{
			status = PAUSE_SCREEN;

			start_play_game.pause();
			delayTimecreateObstacleCar.pause();
			delayTimecreateObstacleObject.pause();
			delayTimecreateItemBuffPower.pause();
			pause_button.setButtonRect(365, 280, 70, 70);
			pause_button.setButtonClipOut(70, 0, 70, 70);
			pause_button.setButtonClipOver(70, 0, 70, 70);
			pause_button.setButtonClipDown(70, 0, 70, 70);

			setPauseScreen();
		}
		else if (status == PAUSE_SCREEN)
		{
			status = PLAYING_SCREEN;
			start_play_game.unpause();
			delayTimecreateObstacleCar.unpause();
			delayTimecreateObstacleObject.unpause();
			delayTimecreateItemBuffPower.unpause();

			pause_button.setButtonRect(0, 0, 70, 70);

			pause_button.setButtonClipOut(0, 0, 70, 70);
			pause_button.setButtonClipOver(0, 0, 70, 70);
			pause_button.setButtonClipDown(0, 0, 70, 70);

			setPlayingScreen();
		}
	}
	else if (option_button.getIsButtonClick())
	{
		option_button.setIsButtonClick(false);
		if (status == START_SCREEN)
		{
			option_button.setButtonRect(300, 560, 200, 50);

			status = OPTION_SCREEN;
			setOptionScreen();
		}
		else if (status == OPTION_SCREEN)
		{
			option_button.setButtonRect(300, 300, 200, 50);

			status = START_SCREEN;
			setStartScreen();
		}
	}
	else if (play_again_button.getIsButtonClick())
	{
		play_again_button.setIsButtonClick(false);

		status = PLAYING_SCREEN;
		setPlayingScreen();

		start_play_game.start();
		delayTimecreateObstacleCar.stop();
		delayTimecreateObstacleObject.stop();
		delayTimecreateItemBuffPower.stop();
	}
}

void MENU::renderMenu(SDL_Renderer* screen)
{
	play_button.renderButton(screen);
	exit_button.renderButton(screen);
	option_button.renderButton(screen);
	pause_button.renderButton(screen);
	play_again_button.renderButton(screen);
}

void MENU::renderBackground(SDL_Renderer* screen)
{
	if (status == START_SCREEN) start_screen_back_ground.render(screen, 0, 0);
	else if (status == PLAY_AGAIN)
	{
		SpriteEXplosionSheet.render(screen, explosion_pos_x, explosion_pos_y, &gSpriteClipsExplosion[frame / 20]);
		frame++;
		if (frame / 20 >= 5) frame = 0;
	}
	else if (status == PAUSE_SCREEN)
	{
		pause_background.render(screen, 0, 0);
	}
	else if (status == OPTION_SCREEN)
	{
		option_texture.render(screen, 0, 0);
	}
}

bool MENU::loadMenuBackdground(SDL_Renderer* screen)
{
	if (!start_screen_back_ground.loadFromFile("Background/MN1.png", screen))
	{
		cout << "fail to load start screen background\n";
		return false;
	}

	if (!SpriteEXplosionSheet.loadFromFile("clip Button effect game/explosion_.png", screen))
	{
		cout << "fail to load explosion sheet\n";
		return false;
	}

	if (!pause_background.loadFromFile("Background/MN1.png", screen))
	{
		cout << "fail to load pause background\n";
		return false;
	}

	if (!option_texture.loadFromFile("Background/option.png", screen))
	{
		cout << "fail to load option texture\n";
		return false;
	}

	return true;
}

void MENU::setStartScreen()
{
	play_button.setIsButtonUseInScreen(true);
	exit_button.setIsButtonUseInScreen(true);
	pause_button.setIsButtonUseInScreen(false);
	option_button.setIsButtonUseInScreen(true);
	play_again_button.setIsButtonUseInScreen(false);
}

void MENU::setPlayingScreen()
{
	play_button.setIsButtonUseInScreen(false);
	exit_button.setIsButtonUseInScreen(false);
	pause_button.setIsButtonUseInScreen(true);
	option_button.setIsButtonUseInScreen(false);
	play_again_button.setIsButtonUseInScreen(false);
}

void MENU::setPauseScreen()
{
	play_button.setIsButtonUseInScreen(false);
	exit_button.setIsButtonUseInScreen(true);
	pause_button.setIsButtonUseInScreen(true);
	option_button.setIsButtonUseInScreen(false);
	play_again_button.setIsButtonUseInScreen(false);
}

void MENU::setOptionScreen()
{
	play_button.setIsButtonUseInScreen(false);
	exit_button.setIsButtonUseInScreen(false);
	pause_button.setIsButtonUseInScreen(false);
	option_button.setIsButtonUseInScreen(true);
	play_again_button.setIsButtonUseInScreen(false);
}

void MENU::setPlayAgainScreen()
{
	play_button.setIsButtonUseInScreen(false);
	exit_button.setIsButtonUseInScreen(false);
	pause_button.setIsButtonUseInScreen(false);
	option_button.setIsButtonUseInScreen(false);
	play_again_button.setIsButtonUseInScreen(true);
}
void MENU::setExplosionPositon(const int& x, const int& y) { explosion_pos_x = x; explosion_pos_y = y; }
int MENU::getScreenStatus() const { return status; }

void MENU::setStatus(const int& val) { status = val; }


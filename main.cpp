#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <SDL_mixer.h>
#include<SDL_ttf.h>

#include "Htexture.h"
#include "mainCar.h"
#include "ObstacleCar.h"
#include "ObstacleObject.h"
#include "ObjectBuffPower.h"
#include "CommomObject.h"
#include "LTimer.h"
#include "button.h"
#include "menu.h"
#include "function.h"
using namespace std; 


static LTimer Timer;
static bool PauseGame = false;
static const int ScreenWith = 800;
static const int ScreenHeight = 650;

TTF_Font* gFont = NULL;
SDL_Renderer* screen = NULL;
SDL_Window* window = NULL;
Mix_Music *soundTrack = NULL;
Mix_Chunk *SoundEffectwhenBuffPower = NULL;
Mix_Chunk *SoundWhenGameOver = NULL;

static LTexture back_ground;
static LTexture gTimeTextTexture;
static LTexture MainCarAreNotBuffPower, MainCarAreBuffedPower;

const int PosotionToRenderObstacleCar[4] = { 265, 342,419,496 };
const int PositionToRenderObstacleObject[4] = { 324, 400, 478, 555 };
const int PositionToRenderObjectToBuffPower[4] = { 280,357,434,511 };

const string pathImageOstacleObject[3] = { "image_projcet/1.png","image_projcet/ob1.png", "image_projcet/ob2.png" };
//const string PathOfImageObstacleOject[2] = {"image_projcet/1.png", "image_projcet/ob2.png"};
const string PathOfImageObstacleCar[7] = { "Car image/OPcar1.png","Car image/OPcar2.png", "Car image/OPcar3.png",
"Car image/OPcar4.png", "Car image/OPcar5.png", "Car image/OPcar6.png", "Car image/OPcar7.png", };
const string pathImageObjectBuffPower = "powerForCar/p2.png";

bool init();

bool load_media();

bool CheckColisonWithOtherCar(vector<OBSTACLE_CAR*> list, SDL_Rect mycar);

bool CheckColisonWithOstacleObject(vector<OstacleObject*> list, SDL_Rect mycar);

bool CheckColisonToPushPower(vector<ItemToBuffPower*> ListObjectToBuffPower, SDL_Rect mycar);

void close();

void gamePlayEasyMode();
void gamePlayMediumMode();
void gamePlayHardMode();
void gamePlayHardMode();
void gamePlaySuperHardMode();


int main(int arv, char* argc[])
{
	SDL_Event e;
	int scrollingOffset = 0;
	int speedRenderBackground = 3;
	SDL_Color textColor = { 192, 192, 192, 255 };
	stringstream timeText;
	
	
	if (!init())
	{
		cout << "fail at init\n";
	}
	else
	{
		if (!load_media())
		{
			cout << "fail at load_media\n";
		}
		else
		{
			Mix_PlayMusic(soundTrack, -1);
			bool IsRunningGame = false;
			bool lose_game = false;
			bool switch_car_texture = false;
			bool use_power = false;
			bool time_switch = false;

			Uint32 start_use_power = 0;

			while (!IsRunningGame)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT) IsRunningGame = true;

					game_world_menu.handleMenu(e, IsRunningGame, Timer);
					if (game_world_menu.getScreenStatus() == PLAYING_SCREEN) AUDI_X8.HandleMainCar(e);
				}
				

				if (game_world_menu.getScreenStatus() == PLAYING_SCREEN)
				{


					SDL_SetRenderDrawColor(screen, 0, 0, 0, 255);
					SDL_RenderClear(screen);

					AUDI_X8.move();

					speedRenderBackground = 3;

					scrollingOffset += speedRenderBackground;

					if (scrollingOffset >= back_ground.getHeight())
					{
						scrollingOffset = 0;
					}

					gTimeTextTexture.loadFromRenderedText(timeText.str().c_str(), textColor, screen, gFont);
					if (lose_game == false)
					{
						timeText.str("");
						timeText << "SCORE : " << (Timer.getTicks() / 1000);
					}
					else
					{
						timeText.str("");
						timeText << "SCORE : " << (Timer.getTicks() / 1000) + 2;
					}
					
					back_ground.render(screen, 0, scrollingOffset);
					back_ground.render(screen, 0, scrollingOffset - back_ground.getHeight());

					

					ObjectList.HandleObstaclecarList(AUDI_X8.GetMainCarCollisionBoxOfMainCAr(), screen, lose_game, use_power, SoundWhenGameOver);
					
					ObjectList.HandleObstacleObject(AUDI_X8.GetMainCarCollisionBoxOfMainCAr(), screen, lose_game, use_power, SoundWhenGameOver);
					
					ObjectList.HandleObstacleListObjectToBuffPower(AUDI_X8.GetMainCarRect(), screen, switch_car_texture);
					

					AUDI_X8.render(screen);
					gTimeTextTexture.render(screen, 0, 70);
					if (Timer.getTicks() <= 15000)
					{
						gamePlayEasyMode();
					}
					
					else if (Timer.getTicks() > 15000 && Timer.getTicks() <= 50000)
					{
						gamePlayMediumMode();
					}
					
					else if (Timer.getTicks() > 50000 && Timer.getTicks() <= 100000)
					{
						gamePlayHardMode();
					}

					else
					{
						gamePlaySuperHardMode();
					}

					// car when use power setup
					if (switch_car_texture)
					{
						use_power = true;
						switch_car_texture = false;
						AUDI_X8.setmTexture(MainCarAreBuffedPower.getmTexture());

						Mix_PlayChannel(-1, SoundEffectwhenBuffPower, 0);
						start_use_power = SDL_GetTicks();
					}


					if (!(SDL_GetTicks() - start_use_power <= 3500))
					{
						use_power = false;
						AUDI_X8.setmTexture(MainCarAreNotBuffPower.getmTexture());
					}
					


					if (lose_game)
					{
						SDL_Rect tmp = AUDI_X8.GetMainCarCollisionBoxOfMainCAr();
						game_world_menu.setExplosionPositon(tmp.x - 10, tmp.y - 30);

						AUDI_X8.init();

						game_world_menu.setStatus(PLAY_AGAIN);
						game_world_menu.setPlayAgainScreen();


						Timer.stop();

						delayTimecreateObstacleCar.stop();
						delayTimecreateObstacleObject.stop();
						delayTimecreateItemBuffPower.stop();

						ObjectList.resetHardMode();




						ObjectList.clearListObjectToBuffPower();
						ObjectList.clearListObstacleObject();
						ObjectList.ClearObstacleCar();

						switch_car_texture = false;
						use_power = false;
						lose_game = false;
					}
				}

				game_world_menu.renderBackground(screen);
				game_world_menu.renderMenu(screen);



				SDL_RenderPresent(screen);
			}
		}
	}
	close();
	return 0;
}



void gamePlayEasyMode()
{
	// ob car
	if (delayTimecreateObstacleCar.getTicks() > 1300)
	{
		int IndexOfCarType = rand() % 7 + 0;
		int IndexPositionCar = rand() % 4 + 0;
		ObjectList.LoadObstacleCar(PathOfImageObstacleCar[IndexOfCarType], PosotionToRenderObstacleCar[IndexPositionCar], screen);
		delayTimecreateObstacleCar.stop();
	}
	if (delayTimecreateObstacleCar.turn_off())
	{
		delayTimecreateObstacleCar.start();
	}

	if (Timer.getTicks() >= (Uint32)14990)
	{
		ObjectList.increaseHardMode();
	}
}
void gamePlayMediumMode()
{
	// ob car
	if (delayTimecreateObstacleCar.getTicks() > 1200)
	{
		int IndexOfCarType = rand() % 7 + 0;
		int IndexPositionCar = rand() % 4 + 0;
		ObjectList.LoadObstacleCar(PathOfImageObstacleCar[IndexOfCarType], PosotionToRenderObstacleCar[IndexPositionCar], screen);
		delayTimecreateObstacleCar.stop();
	}
	if (delayTimecreateObstacleCar.turn_off())
	{
		delayTimecreateObstacleCar.start();
	}

	// ob tree
	if (delayTimecreateObstacleObject.getTicks() > 3500)
	{
		int IndexOfCarType = rand() % 7 + 0;
		int IndexPositionCar = rand() % 4 + 0;
		int IndexPositionObstacleObject = rand() % 3 + 0;
		ObjectList.LoadObstacleObject(pathImageOstacleObject[IndexPositionObstacleObject], PositionToRenderObstacleObject[IndexPositionCar], screen);
		delayTimecreateObstacleObject.stop();
	}
	if (delayTimecreateObstacleObject.turn_off())
	{
		delayTimecreateObstacleObject.start();
	}


	if (delayTimecreateItemBuffPower.getTicks() > 9000)
	{
		int IndexOfCarType = rand() % 7 + 0;
		int IndexPositionCar = rand() % 4 + 0;
		int IndexPositionObjectToBuffPower = rand() % 4;
		ObjectList.LoadObjectToBuffPower(pathImageObjectBuffPower, PositionToRenderObjectToBuffPower[IndexPositionObjectToBuffPower], screen);
		IndexPositionObjectToBuffPower = rand() % 4 + 0;
		delayTimecreateItemBuffPower.stop();
	}
	if (delayTimecreateItemBuffPower.turn_off())
	{
		delayTimecreateItemBuffPower.start();
	}




	if (Timer.getTicks() >= (Uint32)50990)
	{
		ObjectList.increaseHardMode();
		cout << "increase speed\n";
	}
}
void gamePlayHardMode()
{
	if (delayTimecreateObstacleCar.getTicks() > 1200)
	{
		int IndexOfCarType = rand() % 7 + 0;
		int IndexPositionCar = rand() % 4 + 0;
		ObjectList.LoadObstacleCar(PathOfImageObstacleCar[IndexOfCarType], PosotionToRenderObstacleCar[IndexPositionCar], screen);
		delayTimecreateObstacleCar.stop();
	}
	if (delayTimecreateObstacleCar.turn_off())
	{
		delayTimecreateObstacleCar.start();
	}


	// ob tree
	if (delayTimecreateObstacleObject.getTicks() > 3000)
	{
		int IndexOfCarType = rand() % 7 + 0;
		int IndexPositionCar = rand() % 4 + 0;
		int IndexPositionObstacleObject = rand() % 3 + 0;
		ObjectList.LoadObstacleObject(pathImageOstacleObject[IndexPositionObstacleObject], PositionToRenderObstacleObject[IndexPositionCar], screen);
		delayTimecreateObstacleObject.stop();
	}
	if (delayTimecreateObstacleObject.turn_off())
	{
		delayTimecreateObstacleObject.start();
	}


	if (delayTimecreateItemBuffPower.getTicks() > 8000)
	{
		int IndexOfCarType = rand() % 7 + 0;
		int IndexPositionCar = rand() % 4 + 0;
		int IndexPositionObjectToBuffPower = rand() % 4;
		ObjectList.LoadObjectToBuffPower(pathImageObjectBuffPower, PositionToRenderObjectToBuffPower[IndexPositionObjectToBuffPower], screen);
		IndexPositionObjectToBuffPower = rand() % 4 + 0;
		delayTimecreateItemBuffPower.stop();
	}

	if (delayTimecreateItemBuffPower.turn_off())
	{
		delayTimecreateItemBuffPower.start();
	}

	if (Timer.getTicks() >= (Uint32)99990)
	{
		ObjectList.increaseHardMode();
		cout << "increase speed\n";
	}
}
void gamePlaySuperHardMode()
{
	if (delayTimecreateObstacleCar.getTicks() > 1000)
	{
		int IndexOfCarType = rand() % 7 + 0;
		int IndexPositionCar = rand() % 4 + 0;
		ObjectList.LoadObstacleCar(PathOfImageObstacleCar[IndexOfCarType], PosotionToRenderObstacleCar[IndexPositionCar], screen);
		delayTimecreateObstacleCar.stop();
	}
	if (delayTimecreateObstacleCar.turn_off())
	{
		delayTimecreateObstacleCar.start();
	}

	// ob tree
	if (delayTimecreateObstacleObject.getTicks() > 3000)
	{
		int IndexOfCarType = rand() % 7 + 0;
		int IndexPositionCar = rand() % 4 + 0;
		int IndexPositionObstacleObject = rand() % 3 + 0;
		ObjectList.LoadObstacleObject(pathImageOstacleObject[IndexPositionObstacleObject], PositionToRenderObstacleObject[IndexPositionCar], screen);
		delayTimecreateObstacleObject.stop();
	}


	if (delayTimecreateItemBuffPower.getTicks() > 8000)
	{
		int IndexOfCarType = rand() % 7 + 0;
		int IndexPositionCar = rand() % 4 + 0;
		int IndexPositionObjectToBuffPower = rand() % 4;
		ObjectList.LoadObjectToBuffPower(pathImageObjectBuffPower, PositionToRenderObjectToBuffPower[IndexPositionObjectToBuffPower], screen);
		IndexPositionObjectToBuffPower = rand() % 4 + 0;
		delayTimecreateItemBuffPower.stop();
	}
	if (delayTimecreateItemBuffPower.turn_off())
	{
		delayTimecreateItemBuffPower.start();
	}

	if (delayTimecreateObstacleObject.turn_off())
	{
		delayTimecreateObstacleObject.start();
	}
}
bool init()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		window = SDL_CreateWindow("GameWorld", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ScreenWith, ScreenHeight, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (screen == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(screen, 0xFF, 0xFF, 0xFF, 0xFF);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
				SDL_SetRenderDrawColor(screen, 0xFF, 0xFF, 0xFF, 0xFF);
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
					success = false;
				}
				//Initialize SDL_ttf
				if (TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
					success = false;
				}
			}
		}
	}
	return success;
}

bool load_media()
{
	bool success = true;
	AUDI_X8.LoadMainCar("Car image/MainCar.png",screen);
	MainCarAreNotBuffPower.loadFromFile("Car image/MainCar.png", screen);
	MainCarAreBuffedPower.loadFromFile("Car image/MainCairIsBuffedPower.png", screen);
	AUDI_X8.SetStartPositionMainCar(380, 500);
	gFont = TTF_OpenFont("Font/Coffee Extra.ttf", 28);
	if (gFont == NULL)
	{

		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	if (!back_ground.loadFromFile("Background/Background.png",screen))
	{
		cout << "fail to load back ground\n";
		success = false;
	}
	
	SoundWhenGameOver = Mix_LoadWAV("Music/car_end_game.wav");
	if (SoundWhenGameOver == NULL)
	{
		printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	SoundEffectwhenBuffPower = Mix_LoadWAV("Music/soundeffectwhenbuffpower.wav");
	if (SoundEffectwhenBuffPower == NULL)
	{
		printf("ttFailed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	soundTrack = Mix_LoadMUS("Music/Fluffing-a-Duck.wav");
	if (soundTrack == NULL)
	{
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}


	if (!game_world_menu.loadButtonTexture(screen))
	{
		return false;
	}

	if (!game_world_menu.loadMenuBackdground(screen))
	{
		return false;
	}

	return success;
}

void close()
{
	SDL_DestroyRenderer(screen);
	screen = NULL;
	gTimeTextTexture.free();
	TTF_CloseFont(gFont);
	gFont = NULL;
	Mix_FreeChunk(SoundEffectwhenBuffPower);
	Mix_FreeChunk(SoundWhenGameOver);
	SoundWhenGameOver = NULL;
	SoundEffectwhenBuffPower = NULL;
	Mix_FreeMusic(soundTrack);
	soundTrack = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_Quit();
	IMG_Quit();
}

bool CheckColisonWithOtherCar(vector<OBSTACLE_CAR*> list, SDL_Rect mycar)
{
	if (list.size() >= 1)
	{
		for (int i = 0; i < list.size(); ++i)
		{
			if (checkCollision(mycar, list[i]->GetObstacleCarRect_box()))
			{
				SDL_Rect mcollisions = list[i]->GetObstacleCarRect_box();
				
				return true;
			}
		}
	}
	return false;
}

bool CheckColisonWithOstacleObject(vector<OstacleObject*> list, SDL_Rect mycar)
{
	if (list.size() >= 1)
	{
		for (int i = 0; i < list.size(); ++i)
		{
			if (checkCollision(mycar, list[i]->getObstacleObjectRect()))
			{
				SDL_Rect mcollisions = list[i]->getObstacleObjectRect();
			
				return true;
			}
		}
	}
	return false;
}

bool CheckColisonToPushPower(vector<ItemToBuffPower*> ListObjectToBuffPower, SDL_Rect mycar)
{
	if (ListObjectToBuffPower.size() >= 1)
	{
		for (int i = 0; i < ListObjectToBuffPower.size(); ++i)
		{
			if (checkCollision(mycar, ListObjectToBuffPower[i]->GetBoxRect()))
			{
				return true;
			}
		}
	}
	return false;
}
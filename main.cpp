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
#include "ButtonMeneu.h"

using namespace std; 
static int frame = 0;
static int positionToRenderExplosionX = 0;
static int positionToRenderExplosionY = 0;
static bool IsToPushPowerforCar = false;
static bool isRunningBackground = true;
static bool IsRunningGame = false;
static bool IsStartGame = true;
static bool IsMoveMainCar = false;
static bool PauseGame = false;
static bool IsIncreaseVelocity = false;
//const int positionStartRenderObstacleCarY = -300;
static const int ScreenWith = 800;
static const int ScreenHeight = 650;
TTF_Font* gFont = NULL;
SDL_Renderer* screen = NULL;
SDL_Window* window = NULL;
Mix_Music *soundTrack = NULL;
Mix_Chunk *SoundEffectwhenBuffPower = NULL;
Mix_Chunk *SoundWhenGameOver = NULL;
SDL_Rect gSpriteClipsForButtonPause[2];
SDL_Rect gSpriteClipsForButtonPlay[4];
SDL_Rect gSpriteClipsForButtonOption[4];
SDL_Rect gSpriteClipsForButtonExit[4];
SDL_Rect gSpriteClipsForButtonPlayAgain[4];
SDL_Rect gSpriteClipsExplosion[5];

static LTexture gPromptTextTexture;
static LTexture back_ground;
static LTexture gTimeTextTexture;

static LTexture SpriteEXplosionSheet;
static LTexture Meneu;
static LTexture MainCarAreNotBuffPower, MainCarAreBuffedPower;
static LTexture ButtonSpriteSheetTexture;
static LTexture SpritePauseSheet;
static LTexture MtextureOption;
static ButtonMeneu ButtonPlay;
static ButtonMeneu ButtonOPtion;
static ButtonMeneu ButtomExit;
static ButtonMeneu ButtonPlayAgain;
static ButtonMeneu ButtonPause;
static LTimer gtime;
static MainCar AUDI_X8;
OBJECT ObjectList;

// object 
bool init();

bool load_media();

bool checkCollision(SDL_Rect a, SDL_Rect b);

bool CheckColisonWithOtherCar(vector<OBSTACLE_CAR*> list, SDL_Rect mycar);

bool CheckColisonWithOstacleObject(vector<OstacleObject*> list, SDL_Rect mycar);

bool CheckColisonToPushPower(vector<ObjectToBuffPower*> ListObjectToBuffPower, SDL_Rect mycar);
void close();

int main(int arv, char* argc[])
{
	LTimer timer;
	SDL_Event e;
	int IndexOfCarType = rand() % 7 + 0;
	int IndexPositionCar = rand() % 4 + 0;
	int IndexPositionObjectToBuffPower = rand() % 4 + 0;
	int IndexPositionObstacleObject = rand() % 3 + 0;
	Uint32 RotTimeObstacleCar = 0;
	Uint32 RotTimeOfObstacle = 0;
	Uint32 RotTimeObjectToBuffPower = 0;
	int scrollingOffset = 0;
	int speedRenderBackground = 3;
	Uint32 currentTime = 0;
	SDL_Color textColor = { 192, 192, 192, 255 };
	stringstream timeText;
	const int PosotionToRenderObstacleCar[4] = { 265, 342,419,496 };
	const int PositionToRenderObstacleObject[4] = { 324, 400, 478, 555 };
	const int PositionToRenderObjectToBuffPower[4] = { 280,357,434,511 };
	const string pathImageObjectBuffPower = "powerForCar/p2.png";
	const string pathImageOstacleObject[3] = { "image_projcet/1.png","image_projcet/ob1.png", "image_projcet/ob2.png"};
	//const string PathOfImageObstacleOject[2] = {"image_projcet/1.png", "image_projcet/ob2.png"};
	const string PathOfImageObstacleCar[7] = { "Car image/OPcar1.png","Car image/OPcar2.png", "Car image/OPcar3.png",
	"Car image/OPcar4.png", "Car image/OPcar5.png", "Car image/OPcar6.png", "Car image/OPcar7.png", };

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
			while (!IsRunningGame)
			{
				if (IsStartGame == true)
				{
					while (SDL_PollEvent(&e) != 0)
					{
						Meneu.render(screen, 0, 0);
						ButtonPlay.handleEventBottonplay(&e, IsStartGame, gtime);
						ButtonOPtion.handleEventBottonoption(&e, screen, MtextureOption);
						ButtomExit.handleEventBottonExit(&e, IsRunningGame);

						ButtonPlay.RenderButtonPlay(ButtonSpriteSheetTexture, gSpriteClipsForButtonPlay, screen);
						ButtonOPtion.RenderButtonOption(ButtonSpriteSheetTexture, gSpriteClipsForButtonOption, screen);
						ButtomExit.RenderButtonExit(ButtonSpriteSheetTexture, gSpriteClipsForButtonExit, screen);
					}
					SDL_RenderPresent(screen);
				}
				else
				{
					while (SDL_PollEvent(&e) != 0)
					{
						if (e.type == SDL_QUIT)
						{
							IsRunningGame = true;
						}
						AUDI_X8.HandleMainCar(e);
						ButtonPause.handleEventBottonPause(&e, gtime, isRunningBackground, PauseGame, IsMoveMainCar);
					}
					SDL_SetRenderDrawColor(screen, 0, 0, 0, 255);
					SDL_RenderClear(screen);
					gTimeTextTexture.loadFromRenderedText(timeText.str().c_str(), textColor, screen, gFont);
					if (IsIncreaseVelocity == false)
					{
						timeText.str("");
						timeText << "SCORE : " << (gtime.getTicks() / 1000);
					}
					else
					{
						timeText.str("");
						timeText << "SCORE : " << (gtime.getTicks() / 1000) + 2;
					}

					if (IsMoveMainCar == false)
					{
						AUDI_X8.move();
					}
					else if (isRunningBackground == false) speedRenderBackground = 0;

					if (isRunningBackground == true) speedRenderBackground = 3;

					scrollingOffset += speedRenderBackground;

					if (scrollingOffset >= back_ground.getHeight())
					{
						scrollingOffset = 0;
					}

					if (gtime.getTicks() >= 0 && gtime.getTicks() <= 15000)
					{
						IsIncreaseVelocity = false;
						if (gtime.getTicks() - RotTimeObstacleCar > 1150)
						{
							RotTimeObstacleCar = gtime.getTicks();
							IndexOfCarType = rand() % 7 + 0;
							IndexPositionCar = rand() % 4 + 0;
							ObjectList.LoadObstacleCar(PathOfImageObstacleCar[IndexOfCarType], PosotionToRenderObstacleCar[IndexPositionCar], screen);
						}
						if (gtime.getTicks() - RotTimeObjectToBuffPower > 10000)
						{
							RotTimeObjectToBuffPower = gtime.getTicks();
							IndexOfCarType = rand() % 7 + 0;
							IndexPositionCar = rand() % 4 + 0;
							ObjectList.LoadObjectToBuffPower(pathImageObjectBuffPower, PositionToRenderObjectToBuffPower[IndexPositionObjectToBuffPower], screen);
							IndexPositionObjectToBuffPower = rand() % 4 + 0;
						}
					}

					else if (gtime.getTicks() >= 15000 && gtime.getTicks() <= 50000)
					{
						if (gtime.getTicks() >= 35000)
						{
							IsIncreaseVelocity = true;
						}
						if (gtime.getTicks() - RotTimeObstacleCar > 1500)
						{
							RotTimeObstacleCar = gtime.getTicks();
							IndexOfCarType = rand() % 7 + 0;
							IndexPositionCar = rand() % 4 + 0;
							ObjectList.LoadObstacleCar(PathOfImageObstacleCar[IndexOfCarType], PosotionToRenderObstacleCar[IndexPositionCar], screen);
						}

						if (gtime.getTicks() - RotTimeOfObstacle > 3000)
						{
							RotTimeOfObstacle = gtime.getTicks();
							IndexOfCarType = rand() % 7 + 0;
							IndexPositionCar = rand() % 4 + 0;
							ObjectList.LoadObstacleObject(pathImageOstacleObject[IndexPositionObstacleObject], PositionToRenderObstacleObject[IndexPositionCar], screen);
							IndexPositionObstacleObject = rand() % 3 + 0;
						}



						if (gtime.getTicks() - RotTimeObjectToBuffPower > 10000)
						{
							RotTimeObjectToBuffPower = gtime.getTicks();
							IndexOfCarType = rand() % 7 + 0;
							IndexPositionCar = rand() % 4 + 0;
							ObjectList.LoadObjectToBuffPower(pathImageObjectBuffPower, PositionToRenderObjectToBuffPower[IndexPositionObjectToBuffPower], screen);
							IndexPositionObjectToBuffPower = rand() % 4 + 0;
						}
					}
					else if (gtime.getTicks() >= 50000 && gtime.getTicks() <= 100000)
					{

						if (gtime.getTicks() - RotTimeObstacleCar > 1200)
						{
							RotTimeObstacleCar = gtime.getTicks();
							IndexOfCarType = rand() % 7 + 0;
							IndexPositionCar = rand() % 4 + 0;
							ObjectList.LoadObstacleCar(PathOfImageObstacleCar[IndexOfCarType], PosotionToRenderObstacleCar[IndexPositionCar], screen);
						}
						if (SDL_GetTicks() - RotTimeOfObstacle > 2500)
						{
							RotTimeOfObstacle = SDL_GetTicks();
							IndexOfCarType = rand() % 7 + 0;
							IndexPositionCar = rand() % 4 + 0;
							ObjectList.LoadObstacleObject(pathImageOstacleObject[IndexPositionObstacleObject], PositionToRenderObstacleObject[IndexPositionCar], screen);
							IndexPositionObstacleObject = rand() % 3 + 0;
						}
						if (gtime.getTicks() - RotTimeObjectToBuffPower > 9000)
						{
							RotTimeObjectToBuffPower = gtime.getTicks();
							IndexOfCarType = rand() % 7 + 0;
							IndexPositionCar = rand() % 4 + 0;
							ObjectList.LoadObjectToBuffPower(pathImageObjectBuffPower, PositionToRenderObjectToBuffPower[IndexPositionObjectToBuffPower], screen);
							IndexPositionObjectToBuffPower = rand() % 4 + 0;
						}
					}
					else
					{
						if (gtime.getTicks() - RotTimeObstacleCar > 1000)
						{
							RotTimeObstacleCar = gtime.getTicks();
							IndexOfCarType = rand() % 7 + 0;
							IndexPositionCar = rand() % 4 + 0;
							ObjectList.LoadObstacleCar(PathOfImageObstacleCar[IndexOfCarType], PosotionToRenderObstacleCar[IndexPositionCar], screen);
						}

						if (gtime.getTicks() - RotTimeOfObstacle > 1800)
						{
							RotTimeOfObstacle = gtime.getTicks();
							IndexOfCarType = rand() % 7 + 0;
							IndexPositionCar = rand() % 4 + 0;
							ObjectList.LoadObstacleObject(pathImageOstacleObject[IndexPositionObstacleObject], PositionToRenderObstacleObject[IndexPositionCar], screen);
							IndexPositionObstacleObject = rand() % 3 + 0;
						}
						if (gtime.getTicks() - RotTimeObjectToBuffPower > 7000)
						{
							RotTimeObjectToBuffPower = gtime.getTicks();
							IndexOfCarType = rand() % 7 + 0;
							IndexPositionCar = rand() % 4 + 0;
							ObjectList.LoadObjectToBuffPower(pathImageObjectBuffPower, PositionToRenderObjectToBuffPower[IndexPositionObjectToBuffPower], screen);
						}
					}

					back_ground.render(screen, 0, scrollingOffset);
					back_ground.render(screen, 0, scrollingOffset - back_ground.getHeight());

					ObjectList.HandleObstaclecarList(PauseGame, IsStartGame, IsIncreaseVelocity);
					ObjectList.RenderObstaclecarList(screen);

					ObjectList.HandleObstacleObject(PauseGame, IsStartGame);
					ObjectList.RenderObstacleObject(screen);

					ObjectList.HandleObstacleListObjectToBuffPower(PauseGame, IsStartGame);
					ObjectList.RenderObstacleListObjectToBuffPower(screen);

					AUDI_X8.render(screen);
					gTimeTextTexture.render(screen, 0, 70);
					ButtonPause.renderButtonPause(SpritePauseSheet, gSpriteClipsForButtonPause, screen);
					bool CheckColisonWithObject = CheckColisonWithOstacleObject(ObjectList.get_ListObstacleObject(), AUDI_X8.GetMainCarCollisionBoxOfMainCAr());
					bool CheckColisonWithObstacleCar = CheckColisonWithOtherCar(ObjectList.GetListObstacleCar(), AUDI_X8.GetMainCarCollisionBoxOfMainCAr());
					bool CheckToBuffPower = CheckColisonToPushPower(ObjectList.GetListObjectToBuffPower(), AUDI_X8.GetMainCarCollisionBoxOfMainCAr());

					if (CheckToBuffPower == true)
					{
						Mix_PlayChannel(-1, SoundEffectwhenBuffPower, 0);
						ObjectList.clearListObjectToBuffPower();
						currentTime = gtime.getTicks();
						IsToPushPowerforCar = true;
					}

					if (gtime.getTicks() - currentTime < 3500 && IsToPushPowerforCar == true)
					{
						CheckColisonWithObject = false;
						CheckColisonWithObstacleCar = false;
						IsToPushPowerforCar = true;
						AUDI_X8.setmTexture(MainCarAreBuffedPower.getmTexture());
					}
					else 
					{
						AUDI_X8.setmTexture(MainCarAreNotBuffPower.getmTexture());
					}

					if (CheckColisonWithObject || CheckColisonWithObstacleCar)
					{
						if (isRunningBackground) Mix_PlayChannel(-1, SoundWhenGameOver, 0);
						if (gtime.isStarted() == true)
							gtime.stop();
						isRunningBackground = false;
						PauseGame = true;
						IsMoveMainCar = true;
						// render explosion
						SDL_Rect* currentClip = &gSpriteClipsExplosion[frame / 20];
						SpriteEXplosionSheet.render(screen, positionToRenderExplosionX - 30, positionToRenderExplosionY + 20, currentClip);
						if (frame / 20 <= 5)
						{
							frame++;
						}
						else frame = 0;
						// handle when collision
						ButtomExit.setPosition(300, 300);
						ButtonPlayAgain.handleEventBottonplayAgain(&e, AUDI_X8, ObjectList, gtime, isRunningBackground, PauseGame, IsMoveMainCar);
						ButtonPlayAgain.RenderButtonPlayAgain(ButtonSpriteSheetTexture, gSpriteClipsForButtonPlayAgain, screen);
						ButtomExit.handleEventBottonExit(&e, IsRunningGame);
						ButtomExit.RenderButtonExit(ButtonSpriteSheetTexture, gSpriteClipsForButtonExit, screen);
						CheckColisonWithObject = false;
						CheckColisonWithObstacleCar = false;
					}
					SDL_RenderPresent(screen);
				}
			}
		}
	}
	close();
	return 0;
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
	AUDI_X8.LoadMainCar("Car image\\MainCar.png",screen);
	MainCarAreNotBuffPower.loadFromFile("Car image\\MainCar.png", screen);
	MainCarAreBuffedPower.loadFromFile("Car image\\MainCairIsBuffedPower.png", screen);
	AUDI_X8.SetStartPositionMainCar(380, 500);
	gFont = TTF_OpenFont("Font/Coffee Extra.ttf", 28);
	if (gFont == NULL)
	{

		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	if (!back_ground.loadFromFile("Background\\Background.png",screen))
	{
		cout << "fail to load back ground\n";
		success = false;
	}
	if (!Meneu.loadFromFile("Background\\MN.png",screen ))
	{
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


	if (!MtextureOption.loadFromFile("clip Button effect game\\option.png", screen ))
	{
		cout << "load option fail\n";
		success = false;
	}

	if (!ButtonSpriteSheetTexture.loadFromFile("clip Button effect game\\BUttonAll.png", screen))
	{
		printf("Failed to load button sprite texture!\n");
		success = false;
	}
	else
	{
		gSpriteClipsForButtonPlay[0] = { 0,0,200,50 };
		gSpriteClipsForButtonPlay[1] = { 0,50,200,50 };
		gSpriteClipsForButtonPlay[2] = { 0,100,200,50 };
		gSpriteClipsForButtonPlay[3] = { 0,150,200,50 };

		gSpriteClipsForButtonOption[0] = { 200,0,200,50 };
		gSpriteClipsForButtonOption[1] = { 200,50,200,50 };
		gSpriteClipsForButtonOption[2] = { 200,100,200,50 };
		gSpriteClipsForButtonOption[3] = { 200,150,200,50 };

		gSpriteClipsForButtonExit[0] = { 400,0,200,50 };
		gSpriteClipsForButtonExit[1] = { 400,50,200,50 };
		gSpriteClipsForButtonExit[2] = { 400,100,200,50 };
		gSpriteClipsForButtonExit[3] = { 400,150,200,50 };

		gSpriteClipsForButtonPlayAgain[0] = { 600,0,200,50 };
		gSpriteClipsForButtonPlayAgain[1] = { 600,50,200,50 };
		gSpriteClipsForButtonPlayAgain[2] = { 600,100,200,50 };
		gSpriteClipsForButtonPlayAgain[3] = { 600,150,200,50 };

		ButtonPlay.setPosition(300, 200);
		ButtonOPtion.setPosition(300, 300);
		ButtomExit.setPosition(300, 400);
		ButtonPlayAgain.setPosition(300, 200);
		ButtonPause.setPosition(0,0);
	}
	if (!SpritePauseSheet.loadFromFile("clip Button effect game\\ButtonPause.png", screen))
	{
		success = false;
	}
	else
	{
		gSpriteClipsForButtonPause[0] = { 0,0,70,70 };
		gSpriteClipsForButtonPause[1] = { 70, 0, 70,70 };
	}

	if (!SpriteEXplosionSheet.loadFromFile("clip Button effect game\\explosion_.png", screen))
	{
		success = false;
	}
	else
	{
		gSpriteClipsExplosion[0] = { 0,0,180,150 };
		gSpriteClipsExplosion[1] = { 180,0,180,150 };
		gSpriteClipsExplosion[2] = { 360, 0,180, 150 };
		gSpriteClipsExplosion[3] = { 540, 0 ,180, 150 };
		gSpriteClipsExplosion[4] = { 720, 0 , 180, 150 };
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

bool checkCollision(SDL_Rect a, SDL_Rect b)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;
	//Calculate the sides of rect A
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	//Calculate the sides of rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;
	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}
	if (topA >= bottomB)
	{
		return false;
	}
	if (rightA <= leftB)
	{
		return false;
	}
	if (leftA >= rightB)
	{
		return false;
	}
	//If none of the sides from A are outside B
	return true;
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
				positionToRenderExplosionX = mcollisions.x;
				positionToRenderExplosionY = mcollisions.y;
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
				positionToRenderExplosionX = mcollisions.x;
				positionToRenderExplosionY = mcollisions.y;
				return true;
			}
		}
	}
	return false;
}

bool CheckColisonToPushPower(vector<ObjectToBuffPower*> ListObjectToBuffPower, SDL_Rect mycar)
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
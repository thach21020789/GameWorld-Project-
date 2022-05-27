#include "CommomObject.h"
#include "function.h"

OBJECT::OBJECT() { hard_mode = EASY; };
OBJECT::~OBJECT() {};
void OBJECT::LoadObstacleCar(string path, const int& pos, SDL_Renderer *screen)
{
	OBSTACLE_CAR* newCar = new OBSTACLE_CAR;
	if (!newCar->LoadObstacleCar(path, screen))
	{
		cout << "fail to load car texture\n";
		return;
	}
	newCar->SetStartPosionOfObstacleCar(pos, PositionToRenderObstacle);
	newCar->set_is_moving(true);
	newCar->Set_OBSTACLESPEED(OBSTACLE_SPEED[hard_mode]);
	ListObstacleCar.push_back(newCar);
}

void OBJECT::HandleObstaclecarList(SDL_Rect maincar, SDL_Renderer* screen, bool& lose_game, bool& use_power, Mix_Chunk* SoundWhenGameOver)
{
	if (ListObstacleCar.size() >= 1)
	{
		for (int i = 0; i < ListObstacleCar.size(); ++i)
		{
			if (ListObstacleCar[i]->get_is_moving_car()) 
			{
				ListObstacleCar[i]->AutoIncreaseY(maincar);
				ListObstacleCar[i]->render(screen);

				if (checkCollision(ListObstacleCar[i]->GetObstacleCarRect_box(), maincar) && !use_power)
				{
					lose_game = true;
					Mix_PlayChannel(-1, SoundWhenGameOver, 0);
					break;
				}
			}
			else
			{
				ListObstacleCar[i]->render(screen);
			}
		}
	}
	else return;
}

void OBJECT::RenderObstaclecarList(SDL_Renderer *screen)
{
	if (ListObstacleCar.size() >= 1)
	{
		for (int i = 0; i < ListObstacleCar.size(); ++i)
		{
			if (ListObstacleCar[i]->GetObstacleCarPosY() < ScreenHeight)
			{
				ListObstacleCar[i]->render(screen);
			}
			else if (ListObstacleCar[i]->GetObstacleCarPosY() > PointEndScreen)
			{
				ListObstacleCar.erase(ListObstacleCar.begin() + i);
			}

		}
	}
	else return;
}
vector<OBSTACLE_CAR*> OBJECT::GetListObstacleCar() const { return ListObstacleCar; }

void OBJECT::LoadObstacleObject(string path, const int& pos,SDL_Renderer *screen)
{
	OstacleObject* newObject = new OstacleObject;
	if (!newObject->LoadObstacleObject_texture(path, screen))
	{
		cout << "fail to load car texture\n";
		return;
	}
	newObject->SetStartPosition(pos, - HeightOfOstacleObject);
	newObject->set_is_moving(true);

	ListObstacleObject.push_back(newObject);
	
}
void OBJECT::HandleObstacleObject(SDL_Rect maincar, SDL_Renderer* screen, bool& lose_game, bool& use_power, Mix_Chunk* SoundWhenGameOver)
{
	if (ListObstacleObject.size() >= 1)
	{
		for (int i = 0; i < ListObstacleObject.size(); ++i)
		{
			if (ListObstacleObject[i]->get_is_moving())
			{
				ListObstacleObject[i]->AutoIncreaseYForOstacleObject(maincar);
				ListObstacleObject[i]->render(screen);

				if (checkCollision(ListObstacleObject[i]->getObstacleObjectRect(), maincar) && !use_power)
				{

					lose_game = true;
					Mix_PlayChannel(-1, SoundWhenGameOver, 0);
					break;
				}
			}
			else
			{
				ListObstacleObject[i]->render(screen);
			}
		}
	}
	else return;
}
void OBJECT::RenderObstacleObject(SDL_Renderer *screen)
{
	if (ListObstacleObject.size() >= 1)
	{
		for (int i = 0; i < ListObstacleObject.size(); ++i)
		{
			if (ListObstacleObject[i]->GetObjectPositionY() < ScreenHeight)
			{
				ListObstacleObject[i]->render(screen);
			}
			else if (ListObstacleObject[i]->GetObjectPositionY() > PointEndScreen)
			{
				ListObstacleObject.erase(ListObstacleObject.begin() + i);
			}
		}
	}
	else return;
}
vector<OstacleObject*> OBJECT::get_ListObstacleObject() const { return ListObstacleObject; }
//
void OBJECT::LoadObjectToBuffPower(string path, const int& pos, SDL_Renderer *screen)
{
	ItemToBuffPower* NewObjectToBuffPower = new ItemToBuffPower;
	if (!NewObjectToBuffPower->LoadObjectTobuffPower(path, screen))
	{
		cout << "fail to load car texture\n";
		return;
	}
	NewObjectToBuffPower->SetStatrtPositionOfObjectBuffPower(pos, -400);
	NewObjectToBuffPower->set_is_moving(true);
	ListObjectToBuffPower.push_back(NewObjectToBuffPower);
}

void OBJECT::HandleObstacleListObjectToBuffPower(SDL_Rect maincar, SDL_Renderer* screen, bool & switch_car_texture)
{
	if (ListObjectToBuffPower.size() >= 1)
	{
		for (int i = 0; i < ListObjectToBuffPower.size(); ++i)
		{
			if (ListObjectToBuffPower[i]->get_is_moving())
			{
				ListObjectToBuffPower[i]->AutoIncreaseYForObjectBuffPower(maincar);
				ListObjectToBuffPower[i]->render(screen);

				if (checkCollision(maincar, ListObjectToBuffPower[i]->GetBoxRect()))
				{
					switch_car_texture = true;

				}
			}
			else
			{
				ListObjectToBuffPower.erase(ListObjectToBuffPower.begin() + i);
			}
		}
	}
	else return;
}

void OBJECT::RenderObstacleListObjectToBuffPower(SDL_Renderer *screen)
{
	if (ListObjectToBuffPower.size() >= 1)
	{
		for (int i = 0; i < ListObjectToBuffPower.size(); ++i)
		{
			if (ListObjectToBuffPower[i]->GetPositionYofObjectBuffPower() < ScreenHeight)
			{
				ListObjectToBuffPower[i]->render(screen);
			}
			else if (ListObjectToBuffPower[i]->GetPositionYofObjectBuffPower() > PointEndScreen)
			{
				ListObjectToBuffPower.erase(ListObjectToBuffPower.begin() + i);
			}
		}
	}
	else return;
}

vector<ItemToBuffPower*> OBJECT::GetListObjectToBuffPower() const { return ListObjectToBuffPower; }

void OBJECT::ClearObstacleCar()
{
	ListObstacleCar.resize(0);
}
void OBJECT::clearListObstacleObject()
{
	OBJECT::ListObstacleObject.resize(0);
}
void OBJECT::clearListObjectToBuffPower()
{
	ListObjectToBuffPower.resize(0);
}

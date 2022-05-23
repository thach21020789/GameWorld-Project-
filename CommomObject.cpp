#include "CommomObject.h"


OBJECT::OBJECT() {};
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
	ListObstacleCar.push_back(newCar);
}

void OBJECT::HandleObstaclecarList(bool &PauseGame, bool &IsStartGame, bool & IsIncreaseVelocity)
{
	if (ListObstacleCar.size() >= 1)
	{
		for (int i = 0; i < ListObstacleCar.size(); ++i)
		{
			if (PauseGame == false && IsStartGame == false) {
				ListObstacleCar[i]->AutoIncreaseY(IsIncreaseVelocity);
			}
			else
			{
				ListObstacleCar[i]->ObstacleCarNotMove();
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
//vector<OBSTACLE_CAR*> OBJECT::GetListObstacleCar() const { return ListObstacleCar; }

void OBJECT::LoadObstacleObject(string path, const int& pos,SDL_Renderer *screen)
{
	OstacleObject* newObject = new OstacleObject;
	if (!newObject->LoadObstacleObject_texture(path, screen))
	{
		cout << "fail to load car texture\n";
		return;
	}
	newObject->SetStartPosition(pos, - HeightOfOstacleObject);
	ListObstacleObject.push_back(newObject);
}
void OBJECT::HandleObstacleObject(bool & PauseGame, bool &IsStartGame)
{
	if (ListObstacleObject.size() >= 1)
	{
		for (int i = 0; i < ListObstacleObject.size(); ++i)
		{

			if (PauseGame == false && IsStartGame == false)
			{
				ListObstacleObject[i]->AutoIncreaseYForOstacleObject();
			}
			else
			{
				ListObstacleObject[i]->ObjectNotMove();
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
//vector<OstacleObject*> OBJECT::get_ListObstacleObject() const { return ListObstacleObject; }
//
void OBJECT::LoadObjectToBuffPower(string path, const int& pos, SDL_Renderer *screen)
{
	ObjectToBuffPower* NewObjectToBuffPower = new ObjectToBuffPower;
	if (!NewObjectToBuffPower->LoadObjectTobuffPower(path, screen))
	{
		cout << "fail to load car texture\n";
		return;
	}
	NewObjectToBuffPower->SetStatrtPositionOfObjectBuffPower(pos, -400);

	ListObjectToBuffPower.push_back(NewObjectToBuffPower);
}

void OBJECT::HandleObstacleListObjectToBuffPower(bool  &PauseGame, bool & IsStartGame)
{
	if (ListObjectToBuffPower.size() >= 1)
	{
		for (int i = 0; i < ListObjectToBuffPower.size(); ++i)
		{
			if (PauseGame == false && IsStartGame == false)
			{
				ListObjectToBuffPower[i]->AutoIncreaseYForObjectBuffPower();
			}
			else ListObjectToBuffPower[i]->ObjectBuffPowernotMove();
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
//vector<ObjectToBuffPower*> OBJECT::GetListObjectToBuffPower() const { return ListObjectToBuffPower; }

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
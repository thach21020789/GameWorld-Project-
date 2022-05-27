#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <sstream>
#include<SDL_ttf.h>
using namespace std;
class LTexture
{
public:
	LTexture();
	~LTexture();
	void free();
	bool loadFromFile(string path, SDL_Renderer* screen);
	void render(SDL_Renderer *screen, int x, int y, SDL_Rect* clip = NULL , double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	bool loadFromRenderedText(std::string textureText, SDL_Color textColor, SDL_Renderer* screen, TTF_Font* gFont);
	int getWidth() const;
	int getHeight() const;
	SDL_Texture* getmTexture();
	SDL_Rect getRect() const;
	void setmTexture(SDL_Texture* texture);
private:
	SDL_Texture* mTexture;
	SDL_Rect texture_rect;
	int mWidth;
	int mHeight;
};


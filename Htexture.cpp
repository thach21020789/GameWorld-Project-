#include "Htexture.h"


LTexture::LTexture()
{
	mTexture = NULL;
	texture_rect = { 0,0,0,0 };
	mWidth = 0;
	mHeight = 0;
}
LTexture::~LTexture()
{
	free();
}
bool LTexture::loadFromFile(string path, SDL_Renderer* screen)
{
	free();
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(screen, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		SDL_FreeSurface(loadedSurface);
	}

	mTexture = newTexture;
	return mTexture != NULL;
}
void LTexture::free()
{
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
	}
}
void LTexture::render(SDL_Renderer* screen, int x, int y, SDL_Rect* clip , double angle, SDL_Point* center , SDL_RendererFlip flip)
{
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopyEx(screen, mTexture, clip, &renderQuad, angle, center, flip);
}

bool LTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor, SDL_Renderer* screen, TTF_Font* gFont)
{
	//Get rid of preexisting texture
	free();
	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
	if (textSurface != NULL)
	{
		//Create texture from surface pixels
		mTexture = SDL_CreateTextureFromSurface(screen, textSurface);
		if (mTexture == NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	}
	else
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	//Return success
	return mTexture != NULL;
}
int LTexture::getWidth() const { return mWidth; }
int LTexture::getHeight() const { return mHeight; }
SDL_Rect LTexture::getRect() const { return texture_rect; }
SDL_Texture* LTexture::getmTexture() { return mTexture; }

void LTexture::setmTexture(SDL_Texture* texture) { mTexture = texture; }
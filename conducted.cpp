#include<iostream>
#include <SDL.h>
using namespace std;
const int SCREEN_HEIGHT = 900;
const int SCREEN_WIDTH = 500;
SDL_Window* gwindow = NULL;
SDL_Surface* gscreenSurface = NULL;
SDL_Surface* gHello = NULL;
bool init() {
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "init error " << endl;
		success = false;
	}
	else {
		gwindow = SDL_CreateWindow("tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gwindow == NULL) {
			cout << "error" << endl;
			success = false;
		}
	}
	return success;
}
bool loaMedia() {
	bool success = true;
	gHello = SDL_LoadBMP("C:\\Users\\Admin\\Desktop\\loadMedia\\ha2.bmp");
	if (gHello == NULL) {
		success = false;
		cout << "hello error" << endl;
	}
	return success;
}
void close() {
	SDL_FreeSurface(gHello);
	gHello = NULL;
	SDL_DestroyWindow(gwindow);
	gwindow = NULL;
	SDL_Quit();
}
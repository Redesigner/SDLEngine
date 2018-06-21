#include <SDL2\SDL.h>
#include <iostream>
#include "Context.h"
#include "../incl/res_path.h"

Context::Context() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
	}
	renderer = createRenderer();
}

SDL_Window* Context::createWindow() {
	SDL_Window* window = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError << std::endl;
		SDL_Quit();
		throw "Failed to create SDL window";
	}
	return window;
}

SDL_Renderer* Context::createRenderer() {
	SDL_Window* window = createWindow();
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		SDL_DestroyWindow(window);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}
	return renderer;
}

void Context::loadImage(std::string imageName) {
	SDL_Surface* bmp = SDL_LoadBMP((getResourcePath("SDLEngine") + imageName).c_str());
	if (bmp == nullptr) {
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
	}
}
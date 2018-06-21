#pragma once
#include <SDL2\SDL.h>

class Context {

public:
	Context();
	void loadImage(std::string imageName);
private:
	SDL_Renderer* renderer;
	SDL_Window* createWindow();
	SDL_Renderer* createRenderer();
};

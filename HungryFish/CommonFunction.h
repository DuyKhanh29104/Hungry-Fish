#ifndef COMMON_FUNCTION_H
#define COMMON_FUNCTION_H

#include <iostream>
#include<cstdlib>
#include<ctime>
#include<SDL.h>
#include<SDL_image.h>
#include<string>

const int screen_w=1364;
const int screen_h=768;
const int w_object=120;
const int h_object= 150;


static SDL_Window* window=NULL;
static SDL_Texture* background=NULL;
static SDL_Renderer* gRenderer=NULL;
static SDL_Event e;

namespace SDLCommonFunc
{
SDL_Texture* load_texture(std::string path,SDL_Renderer* gRender);
void close();
}

#endif

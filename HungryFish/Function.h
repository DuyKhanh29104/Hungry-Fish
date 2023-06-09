#ifndef COMMON_FUNCTION_H
#define COMMON_FUNCTION_H

#include <iostream>
#include <bits/stdc++.h>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>



const int screen_w=1364;
const int screen_h=700;
const int w_object=120;
const int h_object= 150;


static SDL_Window* window=NULL;
static SDL_Texture* background=NULL;
static SDL_Renderer* gRenderer=NULL;
static TTF_Font* font = NULL;
static Mix_Chunk* sound = NULL;

namespace SDLCommonFunc
{
bool init(SDL_Window* &window, SDL_Renderer* &gRenderer);
SDL_Texture* load_texture(std::string path,SDL_Renderer* gRender);
void close();
bool checkvacham( SDL_Rect smallFish, SDL_Rect bigFish, bool direc);
}

bool MenuGame(SDL_Renderer* gRenderer, TTF_Font* font);
bool GameOver(SDL_Renderer* gRenderer, TTF_Font* font);


#endif

#pragma once
#include "Game.h"

Game* game;
void NewGame(SDL_Renderer* renderer){
    srand(time(0));
    game = new Game(renderer);
    fishLoad(renderer);
    int UPS = 60;
    int updateDelay = 1000 / UPS;
    int updateTime = 0;
    while(game->isRunning()){
        updateTime = SDL_GetTicks();
        game->handleEvents();
        game->update();
        game->render();
        updateTime = updateDelay - SDL_GetTicks() + updateTime;
        if(updateTime>0){
           SDL_Delay(updateTime);
        }
    }
    Free();
    delete game;
}


#pragma once
#include"BaseObject.h"
#include"Fish.h"

void fishLoad(SDL_Renderer *gRenderer);
class Game{
private:
    bool running = true;
    bool pause = false;
    SDL_Renderer* renderer;
    int point = 0;
    int level = 0;
public:
    Game();
    Game(SDL_Renderer* renderer)    {this->renderer = renderer;}

    void handleEvents();
    void update();
    void render();

    bool isRunning(){ return running; }
    bool isPause(){ return pause; }

    void gamePause();
    void gameContinue();
};

#include"Game.h"

int nFish = 10;
Fish ListFish[10];
BaseObject MainFish;

void fishLoad(SDL_Renderer *gRenderer){
    ListFish[0].loadImage("img/Fish1.png","img/Fish1_Right.png",gRenderer);
    ListFish[1] = ListFish[0];
    ListFish[2].loadImage("img/Fish2.png","img/Fish2_Right.png",gRenderer);
    ListFish[3] = ListFish[2];
    ListFish[4].loadImage("img/Fish.png","img/Fish_Right.png",gRenderer);
    ListFish[5] = ListFish[4];

    ListFish[6].loadImage("img/Fish3.png","img/Fish3_Right.png",gRenderer);
    ListFish[7] = ListFish[6];
    ListFish[8].loadImage("img/Fish4.png","img/Fish4_Right.png",gRenderer);
    ListFish[9] = ListFish[8];
    for(int i=6; i < nFish; i++) ListFish[i].Big();

    MainFish.loadImage("img/MainFish.png","img/MainFish_Right.png",gRenderer);
    MainFish.SetRect(screen_w/2-w_object/2,screen_h/2- h_object/2);

    background=SDLCommonFunc::load_texture("img/backgroundgame.jpg",gRenderer);
}


void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    if(event.type==SDL_QUIT) running = false;
    MainFish.Control(event);
}

void Game::update(){
    for(int i = 0; i < nFish; i++)
            {

                ListFish[i].updatespeed(level + 3);
                if(ListFish[i].GetSize())
                    {
                        if(SDLCommonFunc::checkvacham(MainFish.GetRect(),ListFish[i].GetRect(), ListFish[i].GetDirec()))
                            running= false;
                    }
                if(SDLCommonFunc::checkvacham(ListFish[i].GetRect(),MainFish.GetRect(), MainFish.GetDirec()))
                    {
                        if(ListFish[i].GetSize()) running= false;
                        else
                        {
                            point ++;
                            std:: cout << point << std::endl;
                            ListFish[i].NewFish();
                            if(point % 5 == 0) level++;
                        }
                    }
                ListFish[i].Move();
            }
}

void Game::render(){
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,background,NULL,NULL);
    for(int i = 0; i < nFish; i++)
    {
        ListFish[i].Render(renderer,NULL);
    }
    MainFish.Render(renderer,NULL);
    SDL_RenderPresent(renderer);
}

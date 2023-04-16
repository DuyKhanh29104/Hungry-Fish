
#include"BaseObject.h"
#include"Fish.h"

using namespace std;

bool init()
{
    bool success = true;
    if(SDL_Init(SDL_INIT_VIDEO)<0)
    {
        success=false;
    }else{
        window=SDL_CreateWindow("Hungry Fish",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,screen_w,screen_h,SDL_WINDOW_SHOWN);
        if(window==NULL)
        {
            success=false;
        }else{
            gRenderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
            if(gRenderer==NULL)
            {
                success = false;
            }else{
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    success = false;
                }
            }
        }
    }
    return success;
}




int main(int arc, char* argv[])
{
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        bool quit = false;

        Fish ListFish[3];
        ListFish[0].loadImage("Fish1.png","Fish1_Right.png",gRenderer);
        ListFish[1].loadImage("Fish1.png","Fish1_Right.png",gRenderer);
        ListFish[2].loadImage("Fish4.png","Fish4_Right.png",gRenderer);
        ListFish[2].SetBig();

        BaseObject MainFish;
        MainFish.loadImage("Fish1.png","Fish1_Right.png",gRenderer);
        MainFish.SetRect(screen_w/2-w_object/2,screen_h/2- h_object/2);

        background=SDLCommonFunc::load_texture("backgroundgame.jpg",gRenderer);

        while(!quit)
        {
            if(SDL_PollEvent(&e)!=0)
                if(e.type==SDL_QUIT) quit = true;
            SDL_RenderClear(gRenderer);
            SDL_RenderCopy(gRenderer,background,NULL,NULL);
            for(int i = 0; i< 3; i++)
            {
                ListFish[i].Move();
                ListFish[i].Render(gRenderer,NULL);
            }

            MainFish.Control(e);
            MainFish.Render(gRenderer,NULL);
            SDL_RenderPresent(gRenderer);
        }

    }
    SDLCommonFunc:: close();

    return 0;
}

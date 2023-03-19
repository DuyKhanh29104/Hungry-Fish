#include <iostream>
#include<SDL.h>
#include<SDL_image.h>

using namespace std;

const int screen_w=1364;
const int screen_h=768;
char* title_window="Hungry Fish";

SDL_Window* window=NULL;
SDL_Texture* background=NULL;
SDL_Texture* loadTexture=NULL;
SDL_Renderer* gRenderer=NULL;


enum KeyPressSurfaces
{
    KEY_DEFAULT,
    KEY_UP,
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_TOTAL
};

SDL_Texture* gKeyPressSurfaces[ KEY_TOTAL ];

bool init()
{
    bool success = true;
    if(SDL_Init(SDL_INIT_VIDEO)<0)
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success=false;
    }else{
        window=SDL_CreateWindow(title_window,SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,screen_w,screen_h,SDL_WINDOW_SHOWN);
        if(window==NULL)
        {
            cout << "Window could not be created! SDL_Error:" << SDL_GetError();
            success=false;
        }else{
            gRenderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
            if(gRenderer==NULL)
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }else{
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
            }
        }
    }
    return success;
}

SDL_Texture* load_texture(string path)
{
    bool success= true;
    SDL_Texture* newtexture = NULL;
    SDL_Surface* loadmedia = IMG_Load(path.c_str());
    if( loadmedia == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n",path.c_str(), SDL_GetError() );
        success=false;
    }else{
        newtexture=SDL_CreateTextureFromSurface(gRenderer,loadmedia);
        if(newtexture==NULL)
        {
            printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        SDL_FreeSurface(loadmedia);
    }

    return newtexture;

}

bool load_media()
{
    bool success=true;

    background= load_texture("backgroundgame.jpg");
    if( background == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }

    gKeyPressSurfaces[KEY_DEFAULT]= load_texture("right.png");
    if( gKeyPressSurfaces[ KEY_DEFAULT ] == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }

    gKeyPressSurfaces[KEY_UP]= load_texture("up.png");
    if( gKeyPressSurfaces[ KEY_UP ] == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }

    gKeyPressSurfaces[KEY_DOWN]= load_texture("down.png");
    if( gKeyPressSurfaces[ KEY_DOWN ] == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }

    gKeyPressSurfaces[KEY_LEFT]= load_texture("left.png");
    if( gKeyPressSurfaces[ KEY_LEFT ] == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }

    gKeyPressSurfaces[KEY_RIGHT]= load_texture("right.png");
    if( gKeyPressSurfaces[ KEY_RIGHT ] == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }

    return success;
}

void close()
{
    SDL_DestroyTexture( background );
    background = NULL;
    SDL_DestroyRenderer( gRenderer );
    gRenderer=NULL;
    SDL_DestroyWindow(window);
    window=NULL;
    SDL_Quit();
    IMG_Quit();
}


int main(int arc, char* argv[])
{
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {

        if( !load_media() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            loadTexture=gKeyPressSurfaces[KEY_DEFAULT];
            bool quit = false;
            SDL_Event e;
            SDL_Rect rect;
                    rect.x=screen_w/2;
                    rect.y=screen_h/2;
                    rect.w=100;
                    rect.h=100;

            while(!quit)
            {
                SDL_RenderClear(gRenderer);
                SDL_RenderCopy(gRenderer,background,NULL,NULL);
                SDL_RenderCopy(gRenderer,loadTexture,NULL,&rect);
                SDL_RenderPresent(gRenderer);
                SDL_Delay(10);

                while(SDL_PollEvent(&e)!=0)
                {
                    if(e.type==SDL_QUIT)
                        quit = true;
                    if(e.type==SDL_KEYDOWN)
                    {
                        switch(e.key.keysym.sym )
                        {
                        case SDLK_UP:
                            loadTexture= gKeyPressSurfaces[KEY_UP];
                            rect.y-=30;
                            break;

                        case SDLK_DOWN:
                            loadTexture= gKeyPressSurfaces[KEY_DOWN];
                            rect.y+=30;
                            break;

                        case SDLK_LEFT:
                            loadTexture= gKeyPressSurfaces[KEY_LEFT];
                            rect.x-=30;
                            break;

                        case SDLK_RIGHT:
                            loadTexture= gKeyPressSurfaces[KEY_RIGHT];
                            rect.x+=30;
                            break;
                        }
                    }

                }
            }

        }
    }
    close();

    return 0;
}

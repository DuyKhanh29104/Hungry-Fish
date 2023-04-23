#include"Function.h"

bool SDLCommonFunc::init(SDL_Window* &window, SDL_Renderer* &gRenderer)
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

SDL_Texture* SDLCommonFunc:: load_texture(std::string path,SDL_Renderer* gRender)
{
    SDL_Texture* newtexture = NULL;
    SDL_Surface* loadmedia = IMG_Load(path.c_str());
    SDL_SetColorKey(loadmedia,SDL_TRUE,SDL_MapRGB(loadmedia->format,0xFF, 0xFF, 0xFF));
    newtexture=SDL_CreateTextureFromSurface(gRender,loadmedia);
    SDL_FreeSurface(loadmedia);

    return newtexture;

}

void SDLCommonFunc:: close()
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

bool SDLCommonFunc::checkvacham(SDL_Rect smalFish, SDL_Rect bigFish, bool direc)
{
    if(direc && smalFish.x < bigFish.x && smalFish.x + smalFish.h > bigFish.x
       && smalFish.y <bigFish.y+bigFish.w / 2 && smalFish.y + smalFish.w > bigFish.y + bigFish.w /2)
    {
        return true;
    }

    if(!direc && smalFish.x < bigFish.x + bigFish.h && smalFish.x + smalFish.h > bigFish.x + bigFish.h
       && smalFish.y <bigFish.y+bigFish.w / 2 && smalFish.y + smalFish.w > bigFish.y + bigFish.w /2)
    {
        return true;
    }
    return false;
}



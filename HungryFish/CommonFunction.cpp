#include"CommonFunction.h"

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


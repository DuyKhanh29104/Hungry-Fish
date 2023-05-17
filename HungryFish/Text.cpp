#include"Text.h"

Text::Text()
{
    text_color.r = 255;
    text_color.g = 255;
    text_color.b = 255;
    text_color.a = 255;
    texture = NULL;
}

Text::~Text()
{

}

bool Text::LoadFromRenderText(TTF_Font* font,SDL_Renderer* gRenderer)
{
    SDL_Surface* textSurf = TTF_RenderText_Solid(font, str_val.c_str(), text_color);
    if(textSurf != NULL)
    {
        SDL_DestroyTexture(texture);
        texture = SDL_CreateTextureFromSurface(gRenderer,textSurf);
        width = textSurf->w;
        height = textSurf->h;
        SDL_FreeSurface(textSurf);
    }
    return texture != NULL;

}

void Text::Free()
{
    if(texture != NULL)
    {
        SDL_DestroyTexture(texture);
        texture = NULL;
    }
}

void Text::SetColor(Uint8 red, Uint8 green, Uint8 blue)
{
    text_color.r = red;
    text_color.g = green;
    text_color.b = blue;
}


void Text::RenderText(SDL_Renderer* gRenderer, int xp, int yp)
{
    SDL_Rect renderQuad = {xp, yp, width, height};
    SDL_RenderCopy(gRenderer, texture, NULL, &renderQuad);
}

#ifndef TEXT_H
#define TEXT_H

#include"Function.h"

class Text
{
public:
    Text();
    ~Text();


    bool LoadFromRenderText(TTF_Font* font, SDL_Renderer* gRenderer);
    void Free();

    void SetColor(Uint8 red, Uint8 green, Uint8 blue);

    void RenderText(SDL_Renderer* gRenderer, int xp, int yp);
    void SetText(const std::string& text) {str_val = text;}

    int GetW(){return width;};
    int GetH(){return height;};

private:
    std::string str_val;
    SDL_Color text_color;
    SDL_Texture* texture;
    int width;
    int height;
};

#endif // TEXT_H

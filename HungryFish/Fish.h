#ifndef FISH_H
#define FISH_H

#include "CommonFunction.h"

class Fish
{

public:
    Fish();
    ~Fish();
    void free();
    bool loadImage(std::string path,std::string path2,SDL_Renderer* gRender);
    void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
    void Move();
    void random();
    void SetBig();

protected:
    SDL_Texture* p_object;
    SDL_Texture* p_object2;
    SDL_Rect rect_;
    bool left = true;
    bool big = true;
    int x_;

};

#endif // FISH_H

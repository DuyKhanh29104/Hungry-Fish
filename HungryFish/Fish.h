#ifndef FISH_H
#define FISH_H

#include "Function.h"

class Fish
{

public:
    Fish();
    ~Fish();
    void free();
    bool loadImage(std::string path,std::string path2,SDL_Renderer* gRender);
    void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
    void Move();
    void NewFish();
    void Big();
    SDL_Rect GetRect()const {return rect_;}
    bool GetSize()const {return big;}
    bool GetDirec()const {return left;}
    void updatespeed(int i) {speed = i;}

protected:
    SDL_Texture* p_object;
    SDL_Texture* p_object2;
    SDL_Rect rect_;
    bool left = true;
    bool big = false;
    int x_;
    int speed = 3;

};

#endif // FISH_H

#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H

#include"Function.h"

class BaseObject
{
public:
    BaseObject();
    ~BaseObject();
    void SetRect(const int& x, const int& y ){rect_.x = x, rect_.y = y;}
    SDL_Rect GetRect()const {return rect_;}

    bool loadImage(std::string path,std::string path2,SDL_Renderer* gRender);
    void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
    void Free();
    void Control(SDL_Event &e);
    bool GetDirec() const {return left;}



protected:
    SDL_Texture* p_object;
    SDL_Texture* p_object2;
    SDL_Rect rect_;
    bool left = true;
    int x_;
    int y_;


};


#endif // BASE_OBJECT_H

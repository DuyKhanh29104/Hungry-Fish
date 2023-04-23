#include"Fish.h"

Fish::Fish()
{
    p_object = NULL;
    p_object2 = NULL;
    rect_.x = rand() % 2 * screen_w;
    rect_.y = rand() % 5 * screen_h/6 + 30;
    rect_.h = 0;
    rect_.w = 0;
    if(rect_.x == screen_w)
    {
        rect_.x += rand()% (screen_w / 2);
        left = true;
        x_ = -speed;
    }else
    {
        rect_.x = - rect_.h - (rand()% screen_w);
        left = false;
        x_ = speed;
    }
}

Fish::~Fish()
{
    free();
}

void Fish ::free()
{
    if(p_object != NULL)
    {
        SDL_DestroyTexture(p_object);
        p_object = NULL;
        rect_.w = 0;
        rect_.h = 0;

    }

    if(p_object2 != NULL)
    {
        SDL_DestroyTexture(p_object2);
        p_object2 = NULL;
        rect_.w = 0;
        rect_.h = 0;

    }
}

bool Fish::loadImage(std::string path,std::string path2,SDL_Renderer* gRender)
{
    SDL_Texture* newtexture = NULL;
    SDL_Texture* newtexture2 = NULL;
    SDL_Surface* loadmedia = IMG_Load(path.c_str());
    SDL_Surface* loadmedia2 = IMG_Load(path2.c_str());
    if(loadmedia != NULL && loadmedia2 != NULL)
    {
        newtexture=SDL_CreateTextureFromSurface(gRender, loadmedia);
        newtexture2=SDL_CreateTextureFromSurface(gRender, loadmedia2);
        if(newtexture != NULL && newtexture2 != NULL)
        {
            rect_.h = 0.8 * h_object;
            rect_.w = 0.8 * w_object;
        }
    }
    SDL_FreeSurface(loadmedia);
    p_object = newtexture;
    p_object2 = newtexture2;
    return (p_object != NULL && p_object2 != NULL);

}


void Fish::Render(SDL_Renderer* des, const SDL_Rect* clip)
{
    SDL_Rect renderquad{rect_.x, rect_.y, rect_.h, rect_.w};
    if(left) SDL_RenderCopy(des,p_object,clip,&renderquad);
    else SDL_RenderCopy(des, p_object2, clip, &renderquad);


}

void Fish::Big()
{
    rect_.h = 1.6 * h_object;
    rect_.w = 1.3 * w_object;
    big = true;
}

void Fish::NewFish()
{
    rect_.x = rand() % 2 * screen_w;
    rect_.y = rand() % 5 * screen_h/6 + 30;
    if(rect_.x == screen_w)
    {
        rect_.x += rand()% (screen_w / 2);
        left = true;
        x_ = -speed;
    }else
    {
        rect_.x = - rect_.h - (rand()% screen_w);
        left = false;
        x_ = speed;
    }
}
void Fish::Move()
{
    rect_.x += x_;
    if(rect_.x > 2 * screen_w || rect_.x < - screen_w)
    {
        NewFish();
    }

}

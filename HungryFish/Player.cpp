#include"Player.h"

Player::Player()
{
    p_object = NULL;
    p_object2 = NULL;
    rect_.x = 0;
    rect_.y = 0;
    rect_.h = 0;
    rect_.w = 0;
    x_=0;
    y_=0;
}

Player::~Player()
{
    Free();

}

bool Player::loadImage(std::string path,std::string path2,SDL_Renderer* gRender)
{
    SDL_Texture* newtexture = NULL;
    SDL_Texture* newtexture2 = NULL;
    SDL_Surface* loadmedia = IMG_Load(path.c_str());
    SDL_Surface* loadmedia2 = IMG_Load(path2.c_str());
    if(loadmedia != NULL && loadmedia2 != NULL)
    {
        newtexture=SDL_CreateTextureFromSurface(gRender,loadmedia);
        newtexture2=SDL_CreateTextureFromSurface(gRender,loadmedia2);
        if(newtexture != NULL && newtexture2 != NULL)
        {
            rect_.h = h_object;
            rect_.w = w_object;
        }
    }
    SDL_FreeSurface(loadmedia);
    p_object = newtexture;
    p_object2 = newtexture2;
    return (p_object != NULL && p_object2 != NULL);

}

void Player::Render(SDL_Renderer* des, const SDL_Rect* clip)
{
    SDL_Rect renderquad{rect_.x, rect_.y, rect_.h, rect_.w};
    if(left) SDL_RenderCopy(des,p_object,clip,&renderquad);
    else SDL_RenderCopy(des,p_object2,clip,&renderquad);


}

void Player::Control(SDL_Event &e)
{
    SDL_Delay(10);
    rect_.x+=x_;
    rect_.y+=y_;
    if(rect_.y >= screen_h-rect_.h || rect_.y <=0 ) rect_.y-=y_;
    if(rect_.x >= screen_w-(3.0/2*rect_.w) || rect_.x <=0 ) rect_.x-=x_;
    if(e.type==SDL_KEYDOWN)
    {
        switch(e.key.keysym.sym )
                {
                    case SDLK_UP:
                        y_ = -6;
                        break;

                    case SDLK_DOWN:
                        y_ = 6;
                        break;

                    case SDLK_LEFT:
                        x_ = -6;
                        left=true;
                        break;

                    case SDLK_RIGHT:
                        x_ = 6;
                        left=false;
                        break;
                }
    }

    if(e.type==SDL_KEYUP)
    {
        switch(e.key.keysym.sym )
                {
                    case SDLK_UP:
                        y_=0;
                        break;

                    case SDLK_DOWN:
                        y_=0;
                        break;

                    case SDLK_LEFT:
                        x_=0;
                        break;

                    case SDLK_RIGHT:
                        x_=0;
                        break;
                }
    }
}


void Player:: Free()
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
    x_ = 0;
    y_ = 0;
}


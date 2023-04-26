#include"Function.h"
#include"Text.h"

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
                    success = false;
            }
            if(TTF_Init() == -1) success = false;
            font = TTF_OpenFont("Font.ttf",20);
            if(font == NULL) success = false;
        }
    }
    return success;
}

SDL_Texture* SDLCommonFunc:: load_texture(std::string path,SDL_Renderer* gRender)
{
    SDL_Texture* newtexture = NULL;
    SDL_Surface* loadmedia = IMG_Load(path.c_str());
    //SDL_SetColorKey(loadmedia,SDL_TRUE,SDL_MapRGB(loadmedia->format,0xFF, 0xFF, 0xFF));
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

bool MenuGame(SDL_Renderer* gRenderer, TTF_Font* font)
{
    SDL_Texture* Menu = SDLCommonFunc::load_texture("img/MenuGame.jpg",gRenderer);
    SDL_Rect Rect;
    Rect.h = screen_h;
    Rect.w = screen_w;
    Text kMenu1;
    Text kMenu2;
    font = TTF_OpenFont("Font.ttf",100);
    int x_ = screen_w / 2 -100;
    kMenu1.SetText("Play");
    kMenu1.SetColor(100,100,100);
    kMenu1.LoadFromRenderText(font, gRenderer);

    kMenu2.SetText("Exit");
    kMenu2.SetColor(100,100,100);
    kMenu2.LoadFromRenderText(font, gRenderer);


    SDL_Event m_event;
    int xm;
    int ym;


    while(true)
    {
        SDL_RenderCopy(gRenderer, Menu, NULL, NULL);
        kMenu1.RenderText(gRenderer, x_, 400);
        kMenu2.RenderText(gRenderer, x_, 520);
        SDL_RenderPresent(gRenderer);
        while(SDL_PollEvent(&m_event))
        {
            switch (m_event.type)
            {
            case SDL_QUIT:
                return false;
            case SDL_MOUSEMOTION:
                xm = m_event.button.x;
                ym = m_event.button.y;
                if(xm > x_ && xm < x_ + kMenu1.GetW() && ym > 420 && ym < 420+kMenu1.GetH())
                {
                    kMenu1.SetColor(0,255,255);
                    kMenu1.LoadFromRenderText(font, gRenderer);
                }else
                {
                    kMenu1.SetColor(100,100,100);
                    kMenu1.LoadFromRenderText(font, gRenderer);
                }
                if(xm > x_ && xm < x_ + kMenu2.GetW() && ym > 550 && ym < 550+kMenu2.GetH())
                {
                    kMenu2.SetColor(0,255,255);
                    kMenu2.LoadFromRenderText(font, gRenderer);
                }else
                {
                    kMenu2.SetColor(100,100,100);
                    kMenu2.LoadFromRenderText(font, gRenderer);
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                xm = m_event.button.x;
                ym = m_event.button.y;
                if(xm > x_ && xm < x_ + kMenu1.GetW() && ym > 400 && ym < 400+kMenu1.GetH()) return true;
                if(xm > x_ && xm < x_ + kMenu2.GetW() && ym > 520 && ym < 520+kMenu2.GetH()) return false;
            }
        }
    }

}

bool GameOver(SDL_Renderer* gRenderer, TTF_Font* font)
{
    SDL_Texture* Menu = SDLCommonFunc::load_texture("img/GameOver.png",gRenderer);
    SDL_Rect Rect;
    Rect.h = screen_h;
    Rect.w = screen_w;
    Text kMenu1;
    Text kMenu2;
    font = TTF_OpenFont("Font.ttf",100);
    int x_ = screen_w / 2 -200;
    kMenu1.SetText("Play again");
    kMenu1.SetColor(100,255,100);
    kMenu1.LoadFromRenderText(font, gRenderer);

    kMenu2.SetText("Exit");
    kMenu2.SetColor(100,255,100);
    kMenu2.LoadFromRenderText(font, gRenderer);

    SDL_Event m_event;
    int xm;
    int ym;
    bool selected[2] = {false,false};
    while(true)
    {
        SDL_RenderCopy(gRenderer, Menu, NULL, NULL);

        kMenu1.RenderText(gRenderer, x_, 330);
        kMenu2.RenderText(gRenderer, x_, 450);
        SDL_RenderPresent(gRenderer);


        while(SDL_PollEvent(&m_event))
        {
            switch (m_event.type)
            {
            case SDL_QUIT:
                return false;

            case SDL_MOUSEMOTION:
                xm = m_event.button.x;
                ym = m_event.button.y;
                if(xm > x_ && xm < x_ + kMenu1.GetW() && ym > 330 && ym < 330+kMenu1.GetH())
                {
                    kMenu1.SetColor(0,255,255);
                    kMenu1.LoadFromRenderText(font, gRenderer);
                }else
                {
                    kMenu1.SetColor(100,255,100);
                    kMenu1.LoadFromRenderText(font, gRenderer);
                }
                if(xm > x_ && xm < x_ + kMenu2.GetW() && ym > 450 && ym < 450+kMenu2.GetH())
                {
                    kMenu2.SetColor(0,255,255);
                    kMenu2.LoadFromRenderText(font, gRenderer);
                }else
                {
                    kMenu2.SetColor(100,255,100);
                    kMenu2.LoadFromRenderText(font, gRenderer);
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                xm = m_event.button.x;
                ym = m_event.button.y;
                if(xm > x_ && xm < x_ + kMenu1.GetW() && ym > 330 && ym < 330+kMenu1.GetH()) return true;
                if(xm > x_ && xm < x_ + kMenu2.GetW() && ym > 450 && ym < 450+kMenu2.GetH()) return false;
            }
        }
    }

}




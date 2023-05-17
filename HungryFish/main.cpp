
#include "GameLoop.h"

using namespace std;


int main(int arc, char* argv[])
{
    if( SDLCommonFunc::init(window, gRenderer) == false )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        if(MenuGame(gRenderer, font))
        while(true)
        {
            NewGame(gRenderer);
            if(GameOver(gRenderer, font) == false) break;
        }
    }
    SDLCommonFunc:: close();

    return 0;
}

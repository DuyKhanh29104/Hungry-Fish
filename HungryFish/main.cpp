
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
        NewGame(gRenderer);
    }
    SDLCommonFunc:: close();

    return 0;
}

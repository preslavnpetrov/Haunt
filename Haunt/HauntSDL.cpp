#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN

// SDL2 Headers
#include <SDL.h>

#include "WindowManager.h"
#include "Game.h"

using namespace std;

//This is the SDL window
static WindowManager* windowManager = WindowManager::GetInstance();

//This is the our Game
static Game* game = Game::GetInstance();

int main(int argc, char* argv[])
{
	if (!windowManager->InitializeWindow(_WINDOW_TITLE, _WINDOW_WIDTH, _WINDOW_HEIGHT))
		return -1;

	game->Initialise(windowManager->GetWindow(), windowManager->GetSdlRenderer());

	game->Run(windowManager->GetWindow(), windowManager->GetSdlRenderer());

	game->CleanUp(windowManager->GetWindow());

	return 0;
}
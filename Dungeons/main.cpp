#include "olcConsoleGameEngine.h"

class Game : public olcConsoleGameEngine {
public:
	Game() {

	}

	// Inherited via olcConsoleGameEngine
	virtual bool OnUserCreate() override
	{
		return true;
	}

	virtual bool OnUserUpdate(float fElapsedTime) override
	{
		// Clear the screen
		Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, FG_BLACK);


		Draw(GetMouseX(), GetMouseY(), PIXEL_SOLID, FG_WHITE);

		return true;
	}
};

int main(int argc, char** argv) {
	Game game;

	auto a = game.ConstructConsole(60, 40, 10, 15);
	game.Start();

	return 0;
}
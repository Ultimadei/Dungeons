#include "olcConsoleGameEngine.h"

class Game : public olcConsoleGameEngine {
public:
	Game() {}

	// Inherited via olcConsoleGameEngine
	virtual bool OnUserCreate() override
	{
		ClearCanvas();

		return true;
	}

	virtual bool OnUserUpdate(float fElapsedTime) override
	{
		if (m_mouse[0].bPressed) { m_bPainting = true; }
		else if (m_mouse[0].bReleased) { m_bPainting = false; }

		if (m_bPainting) {
			m_paintCanvas.SetColour(m_mousePosX, m_mousePosY, FG_WHITE);
			m_paintCanvas.SetGlyph(m_mousePosX, m_mousePosY, PIXEL_SOLID);
		}

		// User requested to clear the canvas
		if (m_keys['C'].bPressed) {
			ClearCanvas();
		}

		// Clear the screen
		Fill(0, 0, m_nScreenWidth, m_nScreenHeight, PIXEL_SOLID, FG_BLACK);

		// Draw the canvas (excludes the empty space)
		DrawPartialSprite(0, 0, &m_paintCanvas, 0, 0, m_nScreenWidth, m_nScreenHeight);

		return true;
	}

private:

	void ClearCanvas() {
		m_paintCanvas = olcSprite(m_nScreenWidth, m_nScreenHeight);
	}

private:
	olcSprite m_paintCanvas;
	bool m_bPainting;
};

int main(int argc, char** argv) {
	Game game;

	auto a = game.ConstructConsole(60, 40, 10, 15);
	game.Start();

	return 0;
}
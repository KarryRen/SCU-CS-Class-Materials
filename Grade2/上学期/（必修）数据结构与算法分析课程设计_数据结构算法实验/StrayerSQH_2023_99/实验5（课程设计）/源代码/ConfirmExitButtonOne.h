#include "Button.h"

class ConfirmExitButtonOne : public Button {
public:
	static float ConfirmExitButtonOneWidth, ConfirmExitButtonOneHeight;
	bool isClicked;
	bool confirm;

	ConfirmExitButtonOne(float x, float y, std::string s);

	void DrawButton(sf::RenderWindow& window);

	void ExitProgram(sf::RenderWindow& window, bool& confirm);
};
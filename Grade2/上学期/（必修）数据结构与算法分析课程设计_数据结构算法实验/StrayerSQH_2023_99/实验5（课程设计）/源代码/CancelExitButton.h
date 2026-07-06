#ifndef CANCELEXITBUTTON_H
#define CANCELEXITBUTTON_H

#include "Button.h"

class CancelExitButton : public Button {
public:
	static float CancelExitButtonWidth, CancelExitButtonHeight;
	bool isClicked;
	bool cancel;

	CancelExitButton(float x, float y);

	void DrawButton(sf::RenderWindow& window);
};

#endif // !CANCELEXITBUTTON_H
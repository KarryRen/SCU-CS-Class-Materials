#ifndef EXITBUTTON_H
#define EXITBUTTON_H

#include "Button.h"

class ExitButton : public Button {
public:
    static float ExitButtonWidth, ExitButtonHeight;

    ExitButton(float x, float y);

    void DrawButton(sf::RenderWindow& window);

    int ExitProgram(sf::RenderWindow& window);

private:
    bool isClicked;  // °´Å¥ÊÇ·ñ±»µã»÷
};

#endif
#include <string>
#include "Button.h"
#include "CancelExitButton.h"

float CancelExitButton::CancelExitButtonWidth = 700;
float CancelExitButton::CancelExitButtonHeight = 300;

CancelExitButton::CancelExitButton(float x, float y) : Button(x, y, CancelExitButtonWidth, CancelExitButtonHeight, "Back to the Game", 128) {};

void CancelExitButton::DrawButton(sf::RenderWindow& window)
{
Button:DrawButton(window);
}
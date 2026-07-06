#include "Button.h"
#include "ChooseStateButton.h"

float ChooseStateButton::ChooseButtonWidth = 700;
float ChooseStateButton::ChooseButtonHeight = 300;

ChooseStateButton::ChooseStateButton(float x, float y, std::string s) : Button(x, y, ChooseButtonWidth, ChooseButtonHeight, s, 128) {};

void ChooseStateButton::SetButtonText(const std::string& text)
{
	label.setString(text);
}
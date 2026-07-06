#include <iostream>
#include "ConfirmExitButtonOne.h"

float ConfirmExitButtonOne::ConfirmExitButtonOneWidth = 700;
float ConfirmExitButtonOne::ConfirmExitButtonOneHeight = 300;

ConfirmExitButtonOne::ConfirmExitButtonOne(float x, float y, std::string s) : Button(x, y, ConfirmExitButtonOneWidth, ConfirmExitButtonOneHeight, s, 128) {};

void ConfirmExitButtonOne::DrawButton(sf::RenderWindow& window) {
    Button::DrawButton(window);
}

void ConfirmExitButtonOne::ExitProgram(sf::RenderWindow& window, bool& confirm) {
    if (confirm)
    {
        exit(0);
    }
}
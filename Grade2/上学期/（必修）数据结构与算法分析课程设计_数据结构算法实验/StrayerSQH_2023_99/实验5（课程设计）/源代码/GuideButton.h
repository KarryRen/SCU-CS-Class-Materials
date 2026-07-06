#ifndef GUIDEBUTTON_H
#define GUIDEBUTTON_H

#include "SFML/Graphics.hpp"

class GuideButton{
private:
    int characterIndex;
    float labelSpeed = 0.05f;
    sf::Clock clock;

public:
    float GuideButtonWidth;
    static float GuideButtonHeight;
    bool isHovered;             
    float characterSize = 50;
    float window_x, window_y;
    std::string guideButtonText;
    std::string currentLabel;
    sf::RectangleShape shape;   
    sf::Text label;             
    sf::Font font;              

	GuideButton(std::string text);

    bool DrawButton(sf::RenderWindow& window);

	void NextGuideButton();
};

#endif // !GUIDEBUTTON_H


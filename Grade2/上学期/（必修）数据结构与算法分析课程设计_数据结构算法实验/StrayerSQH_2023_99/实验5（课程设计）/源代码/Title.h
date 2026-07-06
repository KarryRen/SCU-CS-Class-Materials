#ifndef TITLE_H
#define TITLE_H

#include "SFML/Graphics.hpp"

class Title
{
private:
    int characterIndex;
    float labelSpeed = 0.05f;
    sf::Clock clock;

public:
    static float TitleHeight;
    float TitleWidth;
    float characterSize = 150;
    float window_x, window_y;
    std::string TitleText;
    std::string currentLabel;
    sf::RectangleShape shape;   
    sf::Text label;             
    sf::Font font;              

    Title(std::string text);

    bool DrawOnebyOne(sf::RenderWindow& window);

    void DrawOneTime(sf::RenderWindow& window);
};

#endif // !TITLE_H


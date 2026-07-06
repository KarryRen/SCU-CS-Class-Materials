#ifndef EXPLORE_H
#define EXPLORE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Explore {
private:
    int character_x, character_y;
    int Sex;
    sf::RectangleShape character;
    sf::Texture sexSetTexture;
    sf::Sprite sexSetSprite;
    static float PIXEL_SIZE;

    bool checkCollision(int x, int y) 
    {
        sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
        float Boundary_x = static_cast<float>(desktopMode.width);
        float Boundary_y = static_cast<float>(desktopMode.height);

        
        if (x <= 0 || y <= 0 || x >= Boundary_x || y >= Boundary_y)
        {
            return true;
        }

        return false;  // Ã»ÓÐÅö×²
    }

public:
    Explore(int sex);

    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();

    void Update();

    void Draw(sf::RenderWindow& window);

    int Program(sf::RenderWindow& window);
};

#endif // !EXPLORE_H

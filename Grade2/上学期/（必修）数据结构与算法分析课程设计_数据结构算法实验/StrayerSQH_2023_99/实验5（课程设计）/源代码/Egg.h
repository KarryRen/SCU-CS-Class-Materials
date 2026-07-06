#ifndef EGG_H
#define EGG_H

#include <iostream>
#include "SFML/Graphics.hpp"

class Egg {
private:
	static float EggWidth, EggHeight;
	float triggerArea_LU, triggerAreaWidth, triggerAreaHeigth;
	float egg_x, egg_y;
	float initialex, initialey;
	bool isClicked;

	std::string eggPath;

	sf::RectangleShape shape;   // бу???????б┴?

	void Update(sf::RenderWindow& window);

public:
	sf::Texture eggTexture;
	sf::Sprite eggSprite;

	Egg(float ex, float ey, float a, float b, float c, std::string s);

	int Trigger(float cx, float cy, sf::RenderWindow& window);

	int Draw(sf::RenderWindow& window);

	bool CheckHover(const sf::Vector2f& mousePos);
};

#endif // !EGG_H

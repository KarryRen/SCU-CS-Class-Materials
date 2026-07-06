#include "SFML/Graphics.hpp"
#include "Button.h"
#include "MusicClickDetail.h"
#include "Egg.h"

float Egg::EggWidth = 50;
float Egg::EggHeight = 50;

Egg::Egg(float ex, float ey, float a, float b, float c, std::string s)
{
	initialex = ex;
	initialey = ey;
	egg_x = ex;
	egg_y = ey;
	triggerArea_LU = a;
	triggerAreaWidth = b;
	triggerAreaHeigth = c;
	eggPath = s;

	shape.setPosition(sf::Vector2f(egg_x, egg_y));
	shape.setSize(sf::Vector2f(EggWidth, EggHeight));
	shape.setFillColor(sf::Color::Transparent);

	if (!eggTexture.loadFromFile(eggPath))
	{
		std::cout << "²Êµ°Í¼Ïñ¼ÓÔØÊ§°Ü£¬Çë¼ì²é¡£" << std::endl;
	}

	eggSprite.setTexture(eggTexture);
	eggSprite.setPosition(egg_x, egg_y);

	// ÉèÖÃ¼ýÍ·Í¼Æ¬µÄ´óÐ¡
	eggSprite.setScale(
		EggWidth / eggSprite.getLocalBounds().width,
		EggHeight / eggSprite.getLocalBounds().height
	);
}

int Egg::Trigger(float cx, float cy, sf::RenderWindow& window)
{
	if (cx >= triggerArea_LU && cx <= triggerArea_LU + triggerAreaWidth && cy >= triggerArea_LU && cy <= triggerArea_LU + triggerAreaHeigth)
	{
		Draw(window);
		return 1;
	}
	else
	{
		egg_x = initialex;
		egg_y = initialey;
	}
}

int Egg::Draw(sf::RenderWindow& window)
{
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		Update(window);

		return 0;
	}
}

void Egg::Update(sf::RenderWindow& window)
{
	for (float i = 0; i <= 10; i += 0.1)
	{
		egg_x += 0.05;

		shape.setPosition(egg_x, egg_y);
		eggSprite.setPosition(egg_x, egg_y);
		window.draw(shape);
		window.draw(eggSprite);
	}
}

bool Egg::CheckHover(const sf::Vector2f& mousePos)
{
	return shape.getGlobalBounds().contains(mousePos);
}
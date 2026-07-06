#include <iostream>
#include "SFML/Graphics.hpp"
#include "Title.h"

float Title::TitleHeight = 500;

Title::Title(std::string text) : characterIndex(0), TitleText(text)
{
	sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
	window_x = static_cast<float>(desktopMode.width);
	window_y = static_cast<float>(desktopMode.height);

	TitleWidth = window_x;

	shape.setPosition(0, 1 * window_y / 5);
	shape.setSize(sf::Vector2f(TitleWidth, TitleHeight));
	shape.setFillColor(sf::Color::Transparent);

	if (!font.loadFromFile("摄图摩登小方体(免费商用).ttf"))
	{
		std::cout << "程序加载默认字体失败，请检查字体是否存在！！！" << std::endl;
	}

	label.setFont(font);
	label.setCharacterSize(characterSize);
	label.setStyle(sf::Text::Bold);
	label.setFillColor(sf::Color::White);
}

bool Title::DrawOnebyOne(sf::RenderWindow& window)
{
	bool isPrint = false;

	window.draw(shape);
	sf::FloatRect labelBounds = label.getLocalBounds();
	sf::FloatRect shapeBounds = shape.getGlobalBounds();
	label.setOrigin(labelBounds.left + labelBounds.width / 2, labelBounds.top + labelBounds.height / 2);

	float centerX = shape.getPosition().x + 200;
	float centerY = shape.getPosition().y + 50;
	label.setPosition(centerX, centerY);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Time elapsed = clock.getElapsedTime();

		if (elapsed.asSeconds() > labelSpeed && currentLabel.length() < TitleText.length())
		{
			currentLabel += TitleText[currentLabel.length()];
			label.setString(currentLabel);

			clock.restart();
		}
		else if (currentLabel.length() == TitleText.length())
		{
			isPrint = true;
			return isPrint;
		}
		
		window.draw(label);
		window.display();
	}
}
void Title::DrawOneTime(sf::RenderWindow& window)
{
	Title("Welcome to Sichuan University!!!               ");

	window.draw(shape);
	
	label.setPosition(window_x / 2 + 328, 1 * window_y / 5 + 172);

	window.draw(label);
}



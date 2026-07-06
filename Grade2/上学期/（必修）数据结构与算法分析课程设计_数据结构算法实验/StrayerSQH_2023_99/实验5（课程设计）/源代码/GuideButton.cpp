#include "GuideButton.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

float GuideButton::GuideButtonHeight = 170;

GuideButton::GuideButton(std::string text) : isHovered(false), characterIndex(0), guideButtonText(text)
{
	sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
	window_x = static_cast<float>(desktopMode.width);
	window_y = static_cast<float>(desktopMode.height);

	GuideButtonWidth = window_x;

	shape.setPosition(0, 4 * window_y / 5);
	shape.setSize(sf::Vector2f(GuideButtonWidth, GuideButtonHeight));
	shape.setFillColor(sf::Color(128, 128, 128, 128));

	if (!font.loadFromFile("摄图摩登小方体(免费商用).ttf"))
	{
		cout << "程序加载默认字体失败，请检查字体是否存在！！！" << endl;
	}
	
	label.setFont(font);
	label.setCharacterSize(characterSize);
	label.setFillColor(sf::Color::White);

};

bool GuideButton::DrawButton(sf::RenderWindow& window)
{
	bool isPrint = false;

	window.draw(shape);
	sf::FloatRect labelBounds = label.getLocalBounds();
	sf::FloatRect shapeBounds = shape.getGlobalBounds();
	label.setOrigin(labelBounds.left + labelBounds.width / 2, labelBounds.top + labelBounds.height / 2);

	// 计算文本居中位置
	float centerX = shape.getPosition().x + 300;
	float centerY = shape.getPosition().y +50;
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

		// 逐个加载文字
		if (elapsed.asSeconds() > labelSpeed && currentLabel.length() < guideButtonText.length())
		{
			currentLabel += guideButtonText[currentLabel.length()];
			label.setString(currentLabel);

			// 重置时钟
			clock.restart();
		}
		else if (currentLabel.length() == guideButtonText.length())
		{
			// 文字已完全加载，设置标志为false，结束循环
			isPrint = true;
			return isPrint;
		}
		//window.clear();
		window.draw(label);
		window.display();
	}

	label.setString("");
}

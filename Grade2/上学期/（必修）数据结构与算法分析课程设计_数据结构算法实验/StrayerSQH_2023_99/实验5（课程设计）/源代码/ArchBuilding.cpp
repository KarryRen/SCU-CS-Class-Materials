#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "ArchBuilding.h"

float ArchBuilding::archIntroductionWidth = 614.4;
float ArchBuilding::archIntroductionHeight = 254.7;

ArchBuilding::ArchBuilding(float x, float y, float w, float h, std::string s) : Arch_x(x), Arch_y(y), ArchWidth(w), ArchHeight(h), ArchPicturePath(s)
{
	
	shape.setPosition(sf::Vector2f(Arch_x, Arch_y));
	shape.setSize(sf::Vector2f(ArchWidth, ArchHeight));
	shape.setFillColor(sf::Color::Transparent);

	if (!archTexture.loadFromFile(ArchPicturePath))
	{
		std::cout << "½¨ÖþÎïÍ¼Æ¬¼ÓÔØÊ§°Ü£¬Çë¼ì²é¡£" << std::endl;
	}

	archSprite.setTexture(archTexture);
	archSprite.setPosition(Arch_x, Arch_y);
	archSprite.setScale(
		ArchWidth / archSprite.getLocalBounds().width,
		ArchHeight / archSprite.getLocalBounds().height
	);
}

void ArchBuilding::DrawButton(sf::RenderWindow& window, std::string s)
{
	std::string tmp = s;
	if (isHovered && isClicked)
	{
		PictureChange(tmp);

		//window.draw(shape_);
		window.draw(archIntroductionSprite);
		//window.draw(shape);
		window.draw(archSprite);
	}
	else
	{
		//window.draw(shape);
		window.draw(archSprite);
	}
}

bool ArchBuilding::CheckHover(const sf::Vector2f& mousePos)
{
	return shape.getGlobalBounds().contains(mousePos);
}

void ArchBuilding::SetHovered(bool hovered)
{
	isHovered = hovered;
}

void ArchBuilding::PictureChange(std::string s)
{
	ArchIntroductionPath = s;

	shape_.setPosition(sf::Vector2f(Arch_x + ArchWidth, Arch_y));
	shape_.setSize(sf::Vector2f(700, 400));
	shape_.setFillColor(sf::Color::Red);

	if (!archIntroductionTexture.loadFromFile(ArchIntroductionPath))
	{
		std::cout << "½¨ÖþÎï½éÉÜ¼ÓÔØÊ§°Ü£¬Çë¼ì²é¡£" << std::endl;
	}

	archIntroductionSprite.setTexture(archIntroductionTexture);
	archIntroductionSprite.setPosition(Arch_x + ArchWidth, Arch_y);
	archIntroductionSprite.setScale(
		archIntroductionWidth / archIntroductionSprite.getLocalBounds().width,
		archIntroductionHeight / archIntroductionSprite.getLocalBounds().height
	);

}
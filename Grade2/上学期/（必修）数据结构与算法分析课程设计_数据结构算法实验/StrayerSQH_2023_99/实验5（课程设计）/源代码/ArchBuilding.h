#ifndef ARCH_H
#define ARCH_H

#include <iostream>
#include "SFML/Graphics.hpp"

class ArchBuilding
{
private:
	static float archIntroductionWidth, archIntroductionHeight;
	float ArchWidth, ArchHeight;
	float Arch_x, Arch_y;
	std::string ArchPicturePath; 
	std::string ArchIntroductionPath;
	bool isHovered;

	sf::RectangleShape shape;
	sf::Texture archTexture;
	sf::Sprite archSprite;
	sf::RectangleShape shape_;
	sf::Texture archIntroductionTexture;
	sf::Sprite archIntroductionSprite;


public:
	bool isClicked;

	ArchBuilding(float x, float y, float w, float h, std::string s);

	void DrawButton(sf::RenderWindow& window, std::string s);

	bool CheckHover(const sf::Vector2f& mousePos);

	void SetHovered(bool hovered);

	void PictureChange(std::string s);
};

#endif // !ARCH_H

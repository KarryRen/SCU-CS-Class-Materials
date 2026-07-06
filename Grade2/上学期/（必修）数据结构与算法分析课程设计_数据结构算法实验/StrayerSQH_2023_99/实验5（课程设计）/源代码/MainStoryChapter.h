#ifndef MAINSTORYCHAPTER_H
#define MAINSTORYCHAPTER_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "ReturnHomeButton.h"
#include "GlobalVar.h"
#include "MusicClickDetail.h"

using namespace std;

class MainStoryChapter{
public:
	sf::Texture chapterBackgroundImg;
	sf::Sprite chapterSprite;
	sf::Texture sexSetTexture;
	sf::Sprite sexSetSprite;
	sf::RectangleShape character;
	int character_x, character_y;
	float Boundary_x, Boundary_y;
	static float PIXEL_SIZE;
	int chapterNum;
	int Sex;
	std::string chapterImgPath;

	MainStoryChapter(int sex, int c, string s, sf::RenderWindow& window);
	
	bool checkBoundary(int x, int y)
	{
		sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
		float Boundary_x = static_cast<float>(desktopMode.width);
		float Boundary_y = static_cast<float>(desktopMode.height);
		if (x <= 0 || y <= 0 || x >= Boundary_x || y >= Boundary_y)
		{
			return true;
		}

		return false;  // 没有碰撞
	}

	bool checkCollision(int x, int y)
	{
		// 假设有一个墙壁在坐标 (400, 300) 处
		sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
		float window_x = static_cast<float>(desktopMode.width);
		float window_y = static_cast<float>(desktopMode.height);

		if (x > 2 * window_x / 8 && x < 2 * window_x / 8 + 4 * window_x / 8 &&
			y > 1 * window_y / 5 && y < 1 * window_y / 5 + 2.98 * window_y / 5)
		{
			x += PIXEL_SIZE / 2;
			y += PIXEL_SIZE / 2;

			if (
				(x >= 3 * window_x / 8 - PIXEL_SIZE / 2 && x <= 3 * window_x / 8 + 0.5 * window_x / 8 + PIXEL_SIZE / 2 && y >= 3 * window_y / 5 - PIXEL_SIZE / 2 && y <= 3 * window_y / 5 + 0.5 * window_y / 5 + PIXEL_SIZE / 2) ||
				(x >= 4 * window_x / 8 - PIXEL_SIZE / 2 && x <= 4 * window_x / 8 + 0.5 * window_x / 8 + PIXEL_SIZE / 2 && y >= 3 * window_y / 5 - PIXEL_SIZE / 2 && y <= 3 * window_y / 5 + 0.5 * window_y / 5 + PIXEL_SIZE / 2)
				)
			{
				return true;
			}
			return false;
		}
		
		return true;
	}

	void Move();
	void Update();
	void CharacterDraw(sf::RenderWindow& window);
};

class ChapterOne : public MainStoryChapter{
private:
	
public:
	
	ChapterOne(int sex, int c, std::string s, sf::RenderWindow & window);
	int Program(sf::RenderWindow& window);
};

#endif // !MAINSTORYCHAPTER_H
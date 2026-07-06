#include "MainStoryChapter.h"
#include "SFML/Graphics.hpp"
#include "GuideButton.h"
#include <iostream>
#include <chrono>
#include <thread>

float MainStoryChapter::PIXEL_SIZE = 100;

MainStoryChapter::MainStoryChapter(int sex, int c, std::string s, sf::RenderWindow & window)
{
	Sex = sex;
	chapterNum = c;
	chapterImgPath = s;
	character_x = 900;
	character_y = 900;

	//创建章节背景
	sf::VideoMode deskTop = sf::VideoMode::getDesktopMode();
	if (!chapterBackgroundImg.loadFromFile(chapterImgPath))
	{
		cout << "第" << chapterNum << "章节背景图片加载失败" << endl;
	}
	chapterSprite.setTexture(chapterBackgroundImg);
	chapterSprite.setScale(
		window.getSize().x / chapterSprite.getLocalBounds().width,
		window.getSize().y / chapterSprite.getLocalBounds().height
	);

	//创建人物形象
	character.setSize(sf::Vector2f(PIXEL_SIZE, PIXEL_SIZE));
	character.setFillColor(sf::Color::Red);
	if (Sex == 1)
	{
		if (!sexSetTexture.loadFromFile("Picture/Boy.jpg"))
		{
			std::cout << "Fail to open Boy.jpg" << std::endl;
		}

		sexSetSprite.setTexture(sexSetTexture);
		sexSetSprite.setPosition(character_x, character_y);
		sexSetSprite.setScale(
			PIXEL_SIZE / sexSetSprite.getLocalBounds().width,
			PIXEL_SIZE / sexSetSprite.getLocalBounds().height
		);
	}
	else
	{
		if (!sexSetTexture.loadFromFile("Picture/Girl.jpg"))
		{
			std::cout << "Fail to open Girl.jpg" << std::endl;
		}

		sexSetSprite.setTexture(sexSetTexture);
		sexSetSprite.setPosition(character_x, character_y);
		sexSetSprite.setScale(
			PIXEL_SIZE / sexSetSprite.getLocalBounds().width,
			PIXEL_SIZE / sexSetSprite.getLocalBounds().height
		);
	}
}

void MainStoryChapter::Move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (!checkCollision(character_x + 1, character_y - 1))
		{
			character_y -= PIXEL_SIZE / 10;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (!checkCollision(character_x + 1, character_y + PIXEL_SIZE - 1))
		{
			character_y += PIXEL_SIZE / 10;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (!checkCollision(character_x - 1, character_y + 1))
		{
			character_x -= PIXEL_SIZE / 10;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (!checkCollision(character_x + PIXEL_SIZE + 1, character_y + 1))
		{
			character_x += PIXEL_SIZE / 10;
		}
	}
}

void MainStoryChapter::Update()
{
	character.setPosition(character_x, character_y);
	sexSetSprite.setPosition(character_x, character_y);
}

void MainStoryChapter::CharacterDraw(sf::RenderWindow& window)
{
	window.draw(sexSetSprite);
}

ChapterOne::ChapterOne(int sex, int c, std::string s, sf::RenderWindow& window) : MainStoryChapter(sex, c, s, window) {};

int ChapterOne::Program(sf::RenderWindow& window)
{
	bool guideButtonOneisPrint = false;
	bool guideButtonSecondisPrint = false;
	bool guideButtonThirdisPrint = false;
	bool guideButtonForthisPrint = false;

	window.setFramerateLimit(60);

	window.clear();
	//ChapterOne chapterOne(MainStoryChapter::Sex, MainStoryChapter::chapterNum, MainStoryChapter::chapterImgPath, window);

	while (window.isOpen())
	{
		int end = 1;
		int returnHome = 1;
		int judge = 0;

		sf::Event event;
		ReturnHomeButton returnHomeButton(ExitButton_x, ExitButton_y);
		GuideButton guideButtonOne("Welcome to Sichuan University!!!");
		GuideButton guideButtonSecond("Sichuan University is a national key university directly under the Ministry of Education.");
		GuideButton guideButtonThird("Sichuan University is a high-level research-oriented comprehensive university.");
		GuideButton guideButtonForth("(The game is constantly updated. Simple character movements are possible for the character.)");

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if ((event.type == sf::Event::MouseButtonPressed && end) && returnHome)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					// 检查鼠标点击位置是否在退出按钮范围内
					if (returnHomeButton.CheckHover(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
					{
						// 退出按钮被点击，结束程序,创建互动元素音乐播放
						Arch archMusic("Music/ArchClickMusic.mp3");
						if (archMusic.ArchLoadMusic())
						{
							archMusic.ArchPlay();
						}
						returnHome = returnHomeButton.ExitProgram(window);

						if (returnHome)
						{
							return 0;
						}
					}
				}
			}
		}
		// 检测角色移动
		Move();

		// 获取鼠标位置
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

		window.clear();
		Update();

		window.draw(MainStoryChapter::chapterSprite);
		window.draw(MainStoryChapter::sexSetSprite);
		CharacterDraw(window);
		// 检查鼠标是否在按钮范围内，并设置按钮状态
		returnHomeButton.SetHovered(returnHomeButton.CheckHover(mousePosF));
		returnHomeButton.DrawButton(window);
		if (!guideButtonOneisPrint && !guideButtonSecondisPrint && !guideButtonThirdisPrint && !guideButtonForthisPrint)
		{
			guideButtonOneisPrint = guideButtonOne.DrawButton(window);
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		}
		else if (guideButtonOneisPrint && !guideButtonSecondisPrint && !guideButtonThirdisPrint && !guideButtonForthisPrint)
		{
			guideButtonSecondisPrint = guideButtonSecond.DrawButton(window);
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		}
		else if (guideButtonOneisPrint && guideButtonSecondisPrint && !guideButtonThirdisPrint && !guideButtonForthisPrint)
		{
			guideButtonThirdisPrint = guideButtonThird.DrawButton(window);
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		}
		else if (guideButtonOneisPrint && guideButtonSecondisPrint && guideButtonThirdisPrint && !guideButtonForthisPrint)
		{
			guideButtonForthisPrint = guideButtonForth.DrawButton(window);
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		}

		window.display();
	}
}
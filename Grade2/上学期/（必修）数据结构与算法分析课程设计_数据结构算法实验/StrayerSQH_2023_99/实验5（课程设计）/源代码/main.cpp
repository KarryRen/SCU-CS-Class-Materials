#include <iostream>
#include <SFML/Graphics.hpp>
#include <conio.h>
#include "GlobalVar.h"
#include "WindowsShow.h"
#include "Button.h"
#include "ChooseStateButton.h"
#include "ExitButton.h"
#include "MusicBGM.h"
#include "MusicClick.h"
#include "MusicClickDetail.h"
#include "SexChooseSystem.h"
#include "Explore.h"
#include "MainStoryChapter.h"
#include "Title.h"

float numAdd(float n);

int main()
{
    MusicBGM music("Music/BGM.mp3");
    if (music.loadMusic())
    {
        music.play();
    }

    WindowsShow windowsShow;
    windowsShow.ShowWindow();

    sf::RenderWindow& window = windowsShow.getWindow();

    int Sex = 2;//Ä¬ÈÏÎªÄÐÐÔ
    SexChooseSystem sexChooseSystem;
    while (window.isOpen() && Sex == 2)
    {
        sf::Event event;
        while (window.pollEvent(event) && Sex == 2) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            Sex = sexChooseSystem.SexChooseProgram(window);
        }
    }

    float Num = 0;
    ChooseStateButton MainStoryButton(
        window.getSize().x / 2 - ChooseStateButton::ChooseButtonWidth / 2,
        (7 - NumChooseButton + Num) * window.getSize().y / 7 - ChooseStateButton::ChooseButtonHeight / 2,
        "Main Story"
    );
    Num = numAdd(Num);
    ChooseStateButton ExploreButton(
        window.getSize().x / 2 - ChooseStateButton::ChooseButtonWidth / 2,
        (7 - NumChooseButton + Num) * window.getSize().y / 7 - ChooseStateButton::ChooseButtonHeight / 2,
        "Explore"
    );
    ExitButton ExitButton_(ExitButton_x, ExitButton_y);

    Title title("Welcome to Sichuan University!!!               ");

    while (window.isOpen())
    {
        bool titleisPrint = false;
        int exitGame = 1;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed && exitGame)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (ExitButton_.CheckHover(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
                    {
                        Arch archMusic("Music/ArchClickMusic.mp3");
                        if (archMusic.ArchLoadMusic())
                        {
                            archMusic.ArchPlay();
                        }
                        exitGame = ExitButton_.ExitProgram(window);
                    }
                }
            }

            int mainStoryPlay = 1;
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed && mainStoryPlay)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (MainStoryButton.CheckHover(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
                    {
                        Arch archMusic("Music/ArchClickMusic.mp3");
                        if (archMusic.ArchLoadMusic())
                        {
                            archMusic.ArchPlay();
                        }

                        ChapterOne chapterOne(Sex, 1, "Picture/ChapterOneImg.jpg", window);
                        if (mainStoryPlay)
                        {
                            mainStoryPlay = chapterOne.Program(window);
                        }
                    }
                }
            }

            int explorePlay = 1;
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed && explorePlay)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (ExploreButton.CheckHover(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
                    {
                        Arch archMusic("Music/ArchClickMusic.mp3");
                        if (archMusic.ArchLoadMusic())
                        {
                            archMusic.ArchPlay();
                        }

                        Explore exploreMode(Sex);
                        if (explorePlay)
                        {
                            explorePlay = exploreMode.Program(window);
                        }
                    }
                }
            }
        }

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

        MainStoryButton.SetHovered(MainStoryButton.CheckHover(mousePosF));
        ExploreButton.SetHovered(ExploreButton.CheckHover(mousePosF));
        ExitButton_.SetHovered(ExitButton_.CheckHover(mousePosF));

        window.clear();

        windowsShow.DrawBackground(window);

        ExitButton_.Button::DrawButton(window);
        MainStoryButton.Button::DrawButton(window);
        ExploreButton.Button::DrawButton(window);

        while (!titleisPrint)
        {
            titleisPrint = title.DrawOnebyOne(window);
        }
        titleisPrint = false;

        title.DrawOneTime(window);

        window.display();
    }

    return 0;
}

float numAdd(float n)
{
    return n + 1.5;
}
#include "ExitButton.h"
#include <iostream>
#include "ConfirmExitButtonOne.h"
#include "CancelExitButton.h"
#include "WindowsShow.h"
#include "MusicClickDetail.h"

float ExitButton::ExitButtonWidth = 300;
float ExitButton::ExitButtonHeight = 150;

ExitButton::ExitButton(float x, float y) : Button(x, y, ExitButtonWidth, ExitButtonHeight, "Exit<<", 0), isClicked(false) {}

void ExitButton::DrawButton(sf::RenderWindow& window)
{
    Button::DrawButton(window);

    if (isClicked) {
        ExitProgram(window);
    }
}

int ExitButton::ExitProgram(sf::RenderWindow& window)
{
    sf::Texture ExitBackgroundImg;
    sf::Sprite exitSprite;

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    if (!ExitBackgroundImg.loadFromFile("Picture/ChooseSex.jpg"))
    {
        std::cout << "³ÌÐò¼ÓÔØÄ¬ÈÏÍ¼Æ¬Ê§°Ü£¬Çë¼ì²éÍ¼Æ¬ÊÇ·ñ´æÔÚ£¡£¡£¡" << std::endl;
    }
    // ½«Í¼Æ¬ÉèÖÃÎªÈ«ÆÁ
    exitSprite.setTexture(ExitBackgroundImg);
    exitSprite.setScale(
        window.getSize().x / exitSprite.getLocalBounds().width,
        window.getSize().y / exitSprite.getLocalBounds().height
    );

    float Num = 0;

    ConfirmExitButtonOne confirmExitButtonOne(
        window.getSize().x / 2 - ConfirmExitButtonOne::ConfirmExitButtonOneWidth / 2,
        (7 - 2 + Num) * window.getSize().y / 7 - ConfirmExitButtonOne::ConfirmExitButtonOneHeight,
        "Exit the Game");
    Num += 1.5;
    CancelExitButton cancelExitButton(
        window.getSize().x / 2 - ConfirmExitButtonOne::ConfirmExitButtonOneWidth / 2,
        (7 - 2 + Num) * window.getSize().y / 7 - ConfirmExitButtonOne::ConfirmExitButtonOneHeight
    );

    int end = 1;
    while (window.isOpen())
    {
        confirmExitButtonOne.confirm = false;
        cancelExitButton.cancel = false;
        sf::Event Event;
        while (window.pollEvent(Event) && end)
        {
            if (Event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (Event.type == sf::Event::MouseButtonPressed)
            {
                if (Event.mouseButton.button == sf::Mouse::Left)
                {
                    if (confirmExitButtonOne.CheckHover(window.mapPixelToCoords(sf::Vector2i(Event.mouseButton.x, Event.mouseButton.y))))
                    {
                        Arch archMusic("Music/ArchClickMusic.mp3");
                        if (archMusic.ArchLoadMusic())
                        {
                            archMusic.ArchPlay();
                        }

                        confirmExitButtonOne.confirm = true;
                        confirmExitButtonOne.ExitProgram(window, confirmExitButtonOne.confirm);
                    }
                    else
                    {
                        confirmExitButtonOne.ExitProgram(window, confirmExitButtonOne.confirm);
                    }
                }
            }

            if (Event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (Event.type == sf::Event::MouseButtonPressed)
            {
                if (Event.mouseButton.button == sf::Mouse::Left)
                {
                    if (cancelExitButton.CheckHover(window.mapPixelToCoords(sf::Vector2i(Event.mouseButton.x, Event.mouseButton.y))))
                    {
                        Arch archMusic("Music/ArchClickMusic.mp3");
                        if (archMusic.ArchLoadMusic())
                        {
                            archMusic.ArchPlay();
                        }
                        return 0;
                    }
                }
            }

            window.clear();
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
            confirmExitButtonOne.SetHovered(confirmExitButtonOne.CheckHover(mousePosF));
            cancelExitButton.SetHovered(cancelExitButton.CheckHover(mousePosF));

            window.draw(exitSprite);

            confirmExitButtonOne.Button::DrawButton(window);
            cancelExitButton.Button::DrawButton(window);

            window.display();
        }

        std::cout << " " << std::endl;//ÒªÉ¾
    }

    return 0;
}
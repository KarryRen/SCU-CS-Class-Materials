#include "ExitButton.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "MusicClickDetail.h"

using namespace std;

// 构造函数（在窗口显示的x位置，在窗口显示的y位置，按钮高度，按钮宽度，按钮上显示的文字，按钮的默认透明度128）
Button::Button(float window_x, float window_y, float width, float height, const std::string& text, sf::Uint8 alpha)
    : isHovered(false)
{
    shape.setPosition(window_x, window_y);
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color(128, 128, 128, alpha));

    if (!font.loadFromFile("摄图摩登小方体(免费商用).ttf"))
    {
        cout << "程序加载默认字体失败，请检查字体是否存在！！！" << endl;
    }

    label.setFont(font);
    label.setString(text);
    label.setCharacterSize(characterSize);
    label.setFillColor(sf::Color::White);

    // 设置文本的原点位置为其宽度和高度的一半5
    sf::FloatRect labelBounds = label.getLocalBounds();
    label.setOrigin(labelBounds.left + labelBounds.width / 2, labelBounds.top + labelBounds.height / 2);

    // 将文本居中对齐
    float centerX = window_x + width / 2;
    float centerY = window_y + height / 2;
    label.setPosition(centerX, centerY);
}

void Button::DrawButton(sf::RenderWindow& window)
{
    label.setFillColor(sf::Color::White);
    shape.setFillColor(sf::Color(128, 128, 128, 0));

    if (isHovered)
    {
        characterSize = 120;
    }
    else
    {
        characterSize = 80;
    }

    // 设置按钮文本的字体大小
    label.setCharacterSize(characterSize);

    // 设置文本的原点位置为其宽度和高度的一半
    sf::FloatRect labelBounds = label.getLocalBounds();
    label.setOrigin(labelBounds.left + labelBounds.width / 2, labelBounds.top + labelBounds.height / 2);

    // 将文本居中对齐
    float centerX = shape.getPosition().x + shape.getSize().x / 2;
    float centerY = shape.getPosition().y + shape.getSize().y / 2;
    label.setPosition(centerX, centerY);

    window.draw(shape);
    window.draw(label);
}

bool Button::CheckHover(const sf::Vector2f& mousePos)
{

    return shape.getGlobalBounds().contains(mousePos);
}

void Button::SetHovered(bool hovered)
{
    isHovered = hovered;
}
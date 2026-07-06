#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <Windows.h>

using namespace std;

class Button
{
public:
    // 构造函数
    Button(float window_x, float window_y, float width, float height, const std::string& text, sf::Uint8 alpha = 128);

    // 绘制按钮
    void DrawButton(sf::RenderWindow& window);

    // 检查鼠标是否在按钮范围内
    bool CheckHover(const sf::Vector2f& mousePos);

    // 设置按钮的状态
    void SetHovered(bool hovered);

    sf::RectangleShape shape;   // 按钮的形状
    sf::Text label;             // 按钮上的文本
    sf::Font font;              // 按钮上文本的字体
    bool isHovered;             // 按钮是否被鼠标悬停
    float characterSize = 80;
};

#endif
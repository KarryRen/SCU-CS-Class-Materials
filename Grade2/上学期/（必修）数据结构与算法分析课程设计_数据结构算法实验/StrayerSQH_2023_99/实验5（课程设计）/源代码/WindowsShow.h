#ifndef WINDOWSSHOW_H
#define WINDOWSSHOW_H

#include <SFML/Graphics.hpp>

class WindowsShow {
private:
    sf::RenderWindow window;
    sf::Texture DefaultBackgroundImg;
    sf::Sprite background; // 添加背景精灵对象
public:
    void ShowWindow();
    void DrawBackground(sf::RenderWindow& window); // 添加绘制背景函数声明
    sf::RenderWindow& getWindow();
};

#endif // WINDOWSSHOW_H
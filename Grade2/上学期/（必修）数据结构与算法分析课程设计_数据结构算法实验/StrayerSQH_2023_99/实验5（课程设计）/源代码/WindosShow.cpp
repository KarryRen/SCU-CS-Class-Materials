#include "WindowsShow.h"
#include <iostream>

void WindowsShow::ShowWindow()
{
    // 获取桌面分辨率并创建一个全屏窗口
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    // 将窗口命名为“四川大学新生闯关模拟器”
    window.create(desktop, "四川大学新生闯关模拟器", sf::Style::Fullscreen);
    // 加载默认背景图片，创建一个精灵并将其设置为背景图片
    if (!DefaultBackgroundImg.loadFromFile("Picture/BGI.jpg"))
    {
        std::cout << "程序加载默认图片失败，请检查图片是否存在！！！" << std::endl;
        // sleep(3);
        // return -1;
    }
    // 将图片设置为全屏
    background.setTexture(DefaultBackgroundImg);
    background.setScale(
        window.getSize().x / background.getLocalBounds().width,
        window.getSize().y / background.getLocalBounds().height
    );

    // 获取窗口大小
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2f windowSizeFloat(windowSize.x, windowSize.y);
}

void WindowsShow::DrawBackground(sf::RenderWindow& window)
{
    window.draw(background);
}

sf::RenderWindow& WindowsShow::getWindow() {
    return window;
}
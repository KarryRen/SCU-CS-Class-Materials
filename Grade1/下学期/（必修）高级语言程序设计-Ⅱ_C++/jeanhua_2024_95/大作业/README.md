本人为四川大学2023级大一本科生，初学C++，项目代码质量不高，欢迎各路大佬给予指正  

<div align="center">

 **项目浏览量** ![counter](https://counter.seku.su/cmoe?name=JHMG-engine&theme=mbs)

</div>

# ✅JHMG 游戏引擎
![Language](https://img.shields.io/badge/language-c++-brightgreen) ![author](https://img.shields.io/badge/auther-jeanhua-blue)

JHMG 游戏引擎是我写的一个简单的2D游戏引擎，旨在帮助快速搭建和开发2D游戏。
 
[源仓库地址 https://github.com/jeanhua/JHMG-engine](https://github.com/jeanhua/JHMG-engine)

[gitee镜像地址 https://gitee.com/jeanhua/JHMG-engine](https://gitee.com/jeanhua/JHMG-engine)

[代码案例仓库](https://github.com/jeanhua/demo-codes-of-JHMG)

## 特点

- 提供了游戏场景管理、游戏对象管理、界面显示、音效播放、用户输入处理等核心功能。
- 包含了一系列基础的自定义类，如字符串处理、数学计算和图形操作等。
- 易于使用和扩展，适合开发小型的2D游戏或图形应用程序。

### 依赖

- [EasyX](https://easyx.cn/)：图形库，用于图形界面的绘制和处理。

### 下载

你可以从GitHub仓库下载源代码：

```bash
git clone https://github.com/jeanhua/JHMG-engine.git
```

或者[点此下载各版本](https://github.com/jeanhua/JHMG-engine/releases)

### 类图

![类图](./ClassDiagram.png)

# 详细信息
## 类介绍

### `GameObject` 类
- **描述：** 代表游戏中的各种对象，可以是圆形、矩形、菱形或三角形等形状。
- **功能：**
  - 管理对象的位置、大小、图像和可见性。
  - 处理对象之间的碰撞检测。
  - 允许设置游戏循环中对象的自定义行为。

### `GameUI` 类
- **描述：** 管理游戏中的用户界面元素，例如图片等。
- **功能：**
  - 控制界面元素的位置、大小、图像和可见性。
  - 处理用户界面元素的鼠标交互，如点击事件。

### `GameUIText` 类
- **描述：** 管理游戏用户界面中的文本元素。
- **功能：**
  - 设置文本的内容、位置和可见性。

### `GameSound` 类
- **描述：** 处理游戏音效的播放和控制。
- **功能：**
  - 播放、停止、暂停和恢复音效。
  - 设置音效的音量和播放位置。
  - 获取音效的长度和状态。

### `GameInput` 类
- **描述：** 处理游戏中的键盘输入。
- **功能：**
  - 捕获键盘按键事件。

### `GameScene` 类
- **描述：** 表示游戏中的一个场景，包含游戏对象、用户界面元素和文本元素。
- **功能：**
  - 管理场景中的游戏对象、用户界面元素和文本元素。
  - 处理游戏循环中的场景逻辑。

### `MouseAction` 类
- **描述：** 处理游戏对象和用户界面元素的鼠标交互。
- **功能：**
  - 处理鼠标点击事件，并触发相应的回调函数。

### `GameInputBox` 类
- **描述：** 处理游戏中的输入框，允许用户输入文本。
- **功能：**
  - 显示输入框，并允许用户输入文本内容。

### `GameMessageBox` 类
- **描述：** 管理游戏中的消息框，用于向用户显示消息。
- **功能：**
  - 显示消息框，并显示指定的消息内容。

### `Game` 类
- **描述：** 表示游戏本身，管理游戏窗口、场景、帧率和声音等。
- **功能：**
  - 初始化游戏窗口并启动游戏循环。
  - 设置游戏窗口的大小和标题。
  - 控制游戏的帧率。
  - 管理游戏中的场景和声音。
  - 处理游戏中的输入事件。

### `String` 类
- **描述：** 字符串类型，提供字符串操作的功能。
- **功能：**
  - 构造函数：可以从字符串、字符数组或另一个 `String` 对象构造。
  - 运算符重载：支持字符串的拼接、赋值、比较等操作。
  - 类型转换：可以将字符串转换为整型、浮点型等数据类型。
  - 字符串操作：包括索引、截取、查找等操作。

### `Fraction` 类
- **描述：** 分数类型，用于处理分数的计算。
- **功能：**
  - 构造函数：可以从整型、浮点型或分子分母构造分数。
  - 运算符重载：支持分数的加减乘除等运算。
  - 分数化简：将分数进行化简操作。
  - 类型转换：可以将分数转换为浮点型。

### `Vector2` 类
- **描述：** 二维向量，表示坐标或方向。
- **功能：**
  - 构造函数：可以从两个浮点数构造二维向量。
  - 运算符重载：支持向量的加减乘除等运算。
  - 向量操作：包括距离计算、叉乘、点乘等操作。

### `List` 类模板
- **描述：** 链表模板类，用于管理元素的链表结构。
- **功能：**
  - 添加元素：在链表末尾添加元素。
  - 删除元素：删除链表中的节点。
  - 构造函数：初始化链表。
  - 析构函数：释放链表内存。

### `Matrix` 类
- **描述：** 矩阵类，用于矩阵的运算和处理。
- **功能：**
  - 构造函数：可以从二维数组、其他矩阵对象或行列数构造矩阵。
  - 矩阵运算：支持矩阵的加减乘、转置、逆等运算。
  - 求解行列式：计算矩阵的行列式值。
  - 判断相等：判断两个矩阵是否相等。

### `Transform` 基类(包含子类 Circle，Rectangle，Triangle，Diamond，Trapezium)
- **描述：** 二维物体类，包括圆形、矩形、三角形、菱形等。
- **功能：**
  - 各种形状的构造：可以构造圆形、矩形、三角形、菱形等物体。
  - 移动：可以移动物体的位置。
  - 面积计算：可以计算物体的面积。
  - 碰撞检测：可以检测物体之间的碰撞。
  
# 💡基础教程
  ·基本思路：模块化开发，创建对象，绑定事件，加入游戏  
1.创建游戏对象
```cpp
  //声明全局游戏对象
Game* mainGame;
int main()
{
//创建游戏对象
mainGame = new Game;
      ······
```
2.设置窗口大小和标题
```cpp
mainGame->setWindowSize(Vector2(800, 600));
mainGame->setWindowTitle("Game demo");
```
3.设置游戏帧率
```cpp
mainGame->setTargetFrame(165);
```
4.创建游戏场景
```cpp
GameScene* scene = new GameScene;
```
5.添加场景到游戏中
```cpp
mainGame->setScene(scene);
```
6.创建游戏对象
```cpp
GameObject* player = new GameObject(new circle(25, Vector2(170, 70)), ".\\pkq.png", 50, 50, true);
```
7.添加游戏对象到场景中
```cpp
scene->addGameObject("player", player);
```
8.创建游戏UI对象
```cpp
GameUI* xiaoxin = new GameUI(Vector2(0, 0), Vector2(50, 50), ".\\xiaoxin.png", true);
```
9.添加UI对象到场景中
```cpp
scene->addGameUI("xiaoxin", xiaoxin);
```
10.创建文本UI对象
```cpp
GameUIText* text = new GameUIText(String("fps"), Vector2(100, 100));
```
11.添加文本UI到场景中
```cpp
scene->addGameUIText("text", text);
```
12.初始化窗口开始游戏
```cpp
mainGame->initWindow();
```

# 其他常用代码
1.获取游戏场景
```cpp
auto scene = mainGame->getScene();
```
2.获取游戏对象
```cpp
auto player = scene->getGameObject("player");
```
3.获取UI对象
```cpp
auto xiaoxin = scene->getGameUI("xiaoxin");
```
4.获取UI文本对象
```cpp
auto text = scene->getGameUIText("text");
```
5.从场景删除物体
```cpp
scene->removeGameObject("player");
```
6.从场景删除UI对象
```cpp
scene->removeGameUI("xiaoxin");
```
7.从场景删除UI文本对象
```cpp
scene->removeGameUIText("text")
```
8.获取键盘输入
```cpp
auto key = mainGame->Input.getKey();
//判断键盘输入
if (key == KeyMessage::a)
{
	//键盘按下 a 的操作
}
if (key == KeyMessage::d)
{
	//键盘按下 b 的操作
}
if (key == KeyMessage::w)
{
	//键盘按下 c 的操作
}
if (key == KeyMessage::s)
{
	//键盘按下 d 的操作
}
if (key == KeyMessage::space)
{
	//键盘按下 空格 的操作
}
if (key == KeyMessage::esc)
{
	//键盘按下 Esc退出键 的操作
}
```

# 进阶教程
1.绑定游戏对象碰撞事件(物体碰撞调用)
```cpp
//声明碰撞事件函数
void trigger(GameObject* other)
{
  //other是与 绑定的的游戏对象 相碰撞的 ·游戏对象· 的指针
  //碰撞输出名字
  cout << mainGame->getScene()->getName(other) << endl;
}
//绑定碰撞事件
int main()
{
  ···
  player->setOnCollision(trigger);
}
```
2.绑定游戏对象循环事件(每帧调用一次)
```cpp
//声明循环函数
void loop()
{
  //循环事件
}
//绑定循环函数
int main()
{
  ···
  player->setGameLoopFunc(loop);
}
```
3.绑定游戏对象点击事件(点击调用)
```cpp
//声明点击事件
void onClick(int messageType, Vector2 position,GameObject* self)
{
  //输出被点击对象id名
  cout<<mainGame->getScene()->getName(self)<<endl;
  //点击输出
  if (messageType == MouseMessage::leftDown)
	cout << "左键按下" << endl;
  if (messageType == MouseMessage::leftUp)
	cout << "左键放开" << endl;
  if (messageType == MouseMessage::rightDown)
	cout << "右键按下" << endl;
  if (messageType == MouseMessage::rightUp)
	cout << "右键放开" << endl;
}
//绑定点击事件
int main()
{
  ···
  player->mouseAction->setClickFunc(onClick);
}
```

## 完整示例
```cpp
#include "JHMG engine.h"
using namespace JHMG_ENGINE;

//声明全局游戏对象
Game* mainGame;

//声明函数
void loop(GameObject* self);
void trigger(GameObject* self, GameObject* other);
void onClick(int messageType, Vector2 position,GameObject* self);

int main()
{
	//创建游戏对象
	mainGame = new Game;
	//设置窗口大小和标题
	mainGame->setWindowSize(Vector2(800, 600));
	mainGame->setWindowTitle("Game demo");
	//设置游戏帧率
	mainGame->setTargetFrame(165);
	//创建游戏场景
	GameScene* scene = new GameScene;
	//添加场景到游戏中
	mainGame->setScene(scene);
	//创建UI对象
	GameUI* xiaoxin = new GameUI(Vector2(0, 0), Vector2(800, 600), ".\\background.jpg", true);
	//添加UI对象到场景中
	scene->addGameUI("xiaoxin", xiaoxin);
	//创建文本UI
	GameUIText* text = new GameUIText(String("fps"), Vector2(100, 100));
	//添加文本UI到场景中
	scene->addGameUIText("text", text);
	//创建游戏对象
	GameObject* player = new GameObject(new Circle(25, Vector2(170, 70)), ".\\pkq.png", 50, 50, true);
	//绑定游戏对象碰撞事件(物体碰撞调用)
	player->setOnCollision(trigger);
	//绑定游戏对象循环事件(每帧调用一次)
	player->setGameLoopFunc(loop);
	//添加游戏对象到场景中
	scene->addGameObject("player", player);
	//创建游戏对象
	GameObject* pikaqiu = new GameObject(new Circle(25, Vector2(270, 70)), ".\\pkq.png", 50, 50, true);
	//绑定游戏对象点击事件(点击调用)
	pikaqiu->mouseAction->setClickFunc(onClick);
	//添加游戏对象到场景中
	scene->addGameObject("pikaqiu", pikaqiu);
	//初始化窗口开始游戏
	mainGame->initWindow();
}

void loop(GameObject* self)
{
	//获取游戏场景
	auto scene = mainGame->getScene();
	//获取游戏对象
	auto player = scene->getGameObject("player");
	//获取UI文本对象
	auto text = scene->getGameUIText("text");
	//拼接显示fps
	text->text = "fps:" + std::to_string(int(1000 / mainGame->deltaTime));
	//获取键盘输入
	auto key = mainGame->input.getKey();
	//判断键盘输入
	if (key == KeyMessage::a)
	{
		Vector2 currentPosition = player->Transform.Circle->getPosition();
		//x = deltaX + X0 = V*t + X0
		currentPosition += Vector2(-250, 0) * ((float)mainGame->deltaTime / 1000);
		player->Transform.Circle->move(currentPosition);
	}
	if (key == KeyMessage::d)
	{
		Vector2 currentPosition = player->Transform.Circle->getPosition();
		currentPosition += Vector2(250, 0) * ((float)mainGame->deltaTime / 1000);
		player->Transform.Circle->move(currentPosition);
	}
	if (key == KeyMessage::w)
	{
		Vector2 currentPosition = player->Transform.Circle->getPosition();
		currentPosition += Vector2(0, -250) * ((float)mainGame->deltaTime / 1000);
		player->Transform.Circle->move(currentPosition);
	}
	if (key == KeyMessage::s)
	{
		Vector2 currentPosition = player->Transform.Circle->getPosition();
		currentPosition += Vector2(0, 250) * ((float)mainGame->deltaTime / 1000);
		player->Transform.Circle->move(currentPosition);
	}
	if (key == KeyMessage::space)
	{
		//删除物体
		std::cout << "delete pikaqiu" << std::endl;
		scene->removeGameObject("pikaqiu");
	}
	if (key == KeyMessage::esc)
	{
		//退出游戏
		exit(0);
	}
}

void trigger(GameObject* self,GameObject* other)
{
	//碰撞输出名字
	std::cout << mainGame->getScene()->getName(other) << std::endl;
}

void onClick(int messageType, Vector2 position,GameObject* self)
{
	std::cout<<mainGame->getScene()->getName(self)<< std::endl;
	//点击输出
	if (messageType == MouseMessage::leftDown)
		std::cout << "左键按下" << std::endl;
	if (messageType == MouseMessage::leftUp)
		std::cout << "左键放开" << std::endl;
	if (messageType == MouseMessage::rightDown)
		std::cout << "右键按下" << std::endl;
	if (messageType == MouseMessage::rightUp)
		std::cout << "右键放开" << std::endl;
}
```

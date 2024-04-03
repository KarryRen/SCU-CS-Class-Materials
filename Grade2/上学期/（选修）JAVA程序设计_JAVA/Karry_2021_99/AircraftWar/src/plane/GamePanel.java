package plane;

import java.awt.Canvas;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Point;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 * @author 任凯
 * @StudentID 2020141460080
 * @Utility 最重要的 进行游戏的界面 其包括两个部分
 * - 一方面实现游戏各种环境的配置
 * - 另一方面包含游戏对象 MapPanel (控制游戏进程的类)
 */

/**
 * GamePanel 是从 JPanel 继承出来的屏幕 Panel 对象
 * 属性：
 * -1. 两张背景图片 实现背景的滚动
 * -2. 一些基本的界面信息 几个内容的宽高等
 * -3. 总分数 计时器 生命量 等游戏辅助属性
 * <p>
 * 方法
 * -1. 游戏界面的构造方法
 * -2. 展现游戏界面的方法
 * -3. 开始和结束游戏的方法
 * <p>
 * 一个最重要的类
 * 游戏进程类 MapPanel
 */
public class GamePanel extends JPanel {
    private Image bg1, bg2; // 背景图片
    private GamePanel gp;
    private final int SCREEN_WIDTH = 800;   // 屏幕宽度
    private final int SCREEN_HEIGHT = 600;  // 屏幕高度
    static final int MAP_WIDTH = 600;       // 地图面板宽度
    static final int MAP_HEIGHT = 600;      // 地图面板高度
    static final int BULLET_WIDTH = 15;     // 子弹宽度
    static final int BULLET_HEIGHT = 30;    // 子弹高度
    static final int PLANE_SIZE = 100;      // 玩家飞机框边长
    static final int ENEMY_SIZE = 80;       // 敌机框边长
    static final int BOSS_WIDTH = 250;      // boss机的框的宽度
    static final int BOSS_HEIGHT = 180;     // boss机的高度
    private int bg1_y; // bg1图片的y坐标
    private int bg2_y; // bg2图片的y坐标
    private boolean isRunning = false; // 线程是否进行的标志
    private Canvas jp; // 地图面板
    private JButton startStopJB, restartJB, returnJB; // 三个按钮控制不同的功能
    private JLabel scoreLabel; // 总分数标签
    private MainPanel m; // 主面板对象
    static long score; // 总分数
    static int myPlaneLive; // 玩家飞机生命
    static int BossLive; // boss飞机生命

    static int time;//计时
    static long before_time2 = System.currentTimeMillis(); // 过去绘制boss子弹时间

    private Image iBuffer;
    private Graphics gBuffer;

    public GamePanel(MainPanel m) {
        // 设置两个图片的初始坐标
        bg1_y = 0;// bg1图片的y坐标
        bg2_y = -SCREEN_HEIGHT;// bg2图片的y坐标

        setLayout(null);// 清除布局管理
        setBackground(new Color(83, 163, 238));

        showPanel();//设置界面

        this.m = m;

        myPlaneLive = 100;// 玩家飞机的初始血量
        BossLive = 200;// boss飞机的初始血量
    }

    /**
     * 此方法作用是显示界面
     */
    private void showPanel() {
        score = 0; // 设置起始分数为0

        // 设置地图面板 也是最关键的部分
        jp = new MapPanel();
        jp.setBounds(200, 0, 600, 600);
        add(jp);

        // 设置按钮组
        startStopJB = new JButton("开始游戏(P)");
        startStopJB.setBounds(50, 60, 100, 50);
        add(startStopJB);
        startStopJB.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                stop_start();//暂停和开始监听
            }
        });

        restartJB = new JButton("重新开始");
        restartJB.setBounds(50, 140, 100, 50);
        add(restartJB);
        restartJB.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                //刷新游戏界面
                remove(jp);
                jp = new MapPanel();
                jp.setBounds(200, 0, 600, 600);
                add(jp);
                //让游戏暂停
                isRunning = false;
                startStopJB.setText("开始游戏(P)");//改变按钮文字
                Bullet.lastMPbTime = System.currentTimeMillis();

                startStopJB.setEnabled(true);//设置暂停
                score = 0;// 设置分数显示

                myPlaneLive = 100;// 设置自己飞机的生命 100
                BossLive = 200;// 设置boss生命 2000

                time = 0; //初始时间
            }
        });

        returnJB = new JButton("返回主菜单");
        returnJB.setBounds(50, 220, 100, 50);
        add(returnJB);
        returnJB.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                //返回主菜单的设置
                Point p = PanelFrame.mainWindow.getLocation();
                PanelFrame.mainWindow.dispose();
                isRunning = false;
                PanelFrame.main(null);
                PanelFrame.mainWindow.setLocation(p);
            }
        });

        //设置标签，用于存放分数
        scoreLabel = new JLabel("0", JLabel.CENTER);
        scoreLabel.setBounds(40, 300, 120, 50);
        scoreLabel.setFont(new Font("acefont-family", Font.BOLD, 30));
        scoreLabel.setForeground(Color.red);
        add(scoreLabel);
    }

    /**
     * @author 任凯
     * @StudentID 2020141460080
     * @Utility 游戏界面里控制游戏进程的类
     */
    private class MapPanel extends Canvas implements Runnable {
        private MyPlane myPlane;// 玩家飞机对象
        private BossPlane bossPlane; // boss飞机对象
        private Bullet bullet; // 子弹对象
        private Thread th; // 线程对象
        private ArrayList<Bullet> myPlaneBulletArr;//玩家飞机子弹数组
        private ArrayList<Bullet> enemyPlaneBulletArr;//敌机子弹数组
        private Enemy[] enemyArr;// 敌机数组
        private Collide collide;//碰撞是否碰撞的对象
        private Image x;//
        private ArrayList<Bullet[]> bossPlaneBulletArr; // boss子子弹数
        private ArrayList<Bullet> bossPlaneBossBulletArr;


        /**
         * MapPanel 构造函数
         */
        MapPanel() {
            requestFocusInWindow();// 设置请求焦点
            bg1 = bg2 = Toolkit.getDefaultToolkit().getImage(getClass().getResource("/images/mapback.png"));

            //创建玩家飞机对象
            myPlane = new MyPlane();
            myPlane.adapter(this); // 监听 GamePanel 的按键

            // 初始化敌机数组
            enemyArr = new Enemy[8]; // 创建敌机数组 最多有8个敌机
            for (int i = 0; i < enemyArr.length; i++)
                enemyArr[i] = new Enemy((-i - 1) * ENEMY_SIZE - BULLET_HEIGHT); // 敌机出现的位置

            //创建boss飞机对象
            bossPlane = new BossPlane();

            myPlaneBulletArr = new ArrayList<Bullet>();//初始化玩家飞机子弹数组
            enemyPlaneBulletArr = new ArrayList<Bullet>();//初始化敌机子弹数组
            bossPlaneBulletArr = new ArrayList<Bullet[]>();//初始化boss普通子弹数组
            bossPlaneBossBulletArr = new ArrayList<Bullet>(); // 初始化 boss 的大子弹数组

            collide = new Collide();  // 初始化碰撞对象

            adapter(); // 监听键盘

            th = new Thread(this);//创建线程
            th.start(); // 开启线程
        }

        /**
         * 此方法是线程run方法 不断地 draw + update
         */
        @Override
        public void run() {
            while (isRunning) {
                draw();//刷新界面
                // 方便我们控制游戏刷新地速率
                try {
                    Thread.sleep(20);//延时0.02s
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                time += 1;
            }
        }

        /**
         * 此方法用于线程中对所绘制对象的位置与存在与否的判断和绘制
         * 这里面实现以下逻辑移动 —— 只是坐标的移动 并没有实现真正的画面移动
         * 1. 背景地图的移动
         * 2. 玩家飞机的移动
         * 3. 敌机的移动
         */
        private void draw() {
            mapMove();  // 背景移动

            myPlane.planeMove(); // 控制玩家飞机移动

            // 所有的敌机移动 并检测玩家飞机和敌机是否碰撞
            for (int i = 0; i < enemyArr.length; i++) {
                collide.myPlaneCoEnemy(myPlane, enemyArr[i]);
                enemyArr[i].enemyMove();
            }

            // 玩家飞机子弹移动
            for (int i = 0; i < myPlaneBulletArr.size(); i++)
                myPlaneBulletArr.get(i).bulletMove_1(myPlaneBulletArr, i);

            // 玩家飞机子弹和敌机或者boss碰撞判断
            for (int i = 0; i < myPlaneBulletArr.size(); i++)
                for (int j = 0; j < enemyArr.length; j++) {
                    collide.bulletCoEnemy(myPlaneBulletArr.get(i), enemyArr[j]);
                    collide.bulletCoBoss(myPlaneBulletArr.get(i), bossPlane);
                }

            // 敌机子弹移动与碰撞判定
            for (int i = 0; i < enemyPlaneBulletArr.size(); i++) {
                collide.bulletCoMyPlane(enemyPlaneBulletArr.get(i), myPlane);//玩家飞机和敌机子弹碰撞
                enemyPlaneBulletArr.get(i).bulletMove_2(enemyPlaneBulletArr, i);
            }

            // 如果时间大于 2500 那么boss出现
            if (time >= 200) {
                collide.bossCoMyPlane(bossPlane, myPlane);
                bossPlane.bossMove();
            }

            // boss普通子弹移动和子弹与玩家飞机碰撞判断
            for (int i = 0; i < bossPlaneBulletArr.size(); i++)
                for (int j = 0; j < 5; j++) {
                    if (bossPlaneBulletArr.get(i)[j] != null) {
                        collide.bulletCoMyPlane(bossPlaneBulletArr.get(i)[j], myPlane);
                        bossPlaneBulletArr.get(i)[j].bulletMove_3(bossPlaneBulletArr, i, j);
                    }
                }

            // boss 特殊子弹移动和子弹与玩家飞机碰撞判断
            for (int i = 0; i < bossPlaneBossBulletArr.size(); i++) {
                collide.bossBulletCoMyPlane(bossPlaneBossBulletArr.get(i), myPlane);//玩家飞机和敌机子弹碰撞
                bossPlaneBossBulletArr.get(i).bulletMove_boss(bossPlaneBossBulletArr, i);
            }

            repaint(); // 调用 repaint 实现 paint
        }

        /**
         * 此方法是绘图 paint 主要绘制
         * 1. 分数
         * 2. 地图的移动
         * 3. 玩家飞机
         * 4. Boss 的 绘制
         */
        public void paint(Graphics g) {
            scoreLabel.setText("" + score);// 显示分数

            // 绘制背景地图进缓冲的画笔 -> 实现背景的绘制
            if (iBuffer == null) {
                iBuffer = createImage(MAP_WIDTH, MAP_HEIGHT);
                gBuffer = iBuffer.getGraphics();
            }
            gBuffer.fillRect(0, 0, MAP_WIDTH, MAP_HEIGHT);
            gBuffer.drawImage(bg1, 0, bg1_y, 600, 600, this);
            gBuffer.drawImage(bg2, 0, bg2_y, 600, 600, this);

            // 绘制玩家飞机
            myPlane.drawMyPlane(gBuffer, this);
            if (myPlane.stayed) {
                // 如果玩家飞机在活着 就绘制他的子弹
                bullet = new Bullet((int) (myPlane.getX_Y().getX()) + PLANE_SIZE / 2 - BULLET_WIDTH / 2,
                        (int) (myPlane.getX_Y().getY()) - BULLET_HEIGHT);
                // 子弹装载
                bullet.drawBullet_1(myPlaneBulletArr, gBuffer, this);
                for (int i = 0; i < myPlaneBulletArr.size() && myPlaneBulletArr.size() > 1; i++) {
                    myPlaneBulletArr.get(i).drawBullet(gBuffer, this, 1);//子弹绘制
                }
            } else if (myPlane.breakID == 30) {
                startStopJB.setEnabled(false);
                isRunning = false;
                new Dialog(m, 1);
            }

            if (myPlaneLive >= 0) {
                // 绘制玩家飞机血条
                x = Toolkit.getDefaultToolkit().getImage(getClass().getResource("/images/xue_" + ((100 - myPlaneLive) / 5 + 1) + ".png"));
                gBuffer.drawImage(x, 7, 7, 200, 20, this);
            }

            // 绘制敌机、敌机子弹
            for (int i = 0; i < enemyArr.length; i++) {
                // 绘制敌机
                enemyArr[i].drawEnemy(gBuffer, this, i % 5);
                // 装弹
                if (enemyArr[i].stayed && enemyArr[i].getX_Y().getY() > 0 && i % 2 == 0) {
                    int t = (int) (enemyArr[i].getX_Y().getY()) + ENEMY_SIZE;
                    if (t < MAP_HEIGHT) {
                        bullet = new Bullet((int) (enemyArr[i].getX_Y().getX()) + ENEMY_SIZE / 2 - BULLET_WIDTH / 2, t);
                        bullet.drawBullet_2(enemyPlaneBulletArr, gBuffer, this, i);// 子弹装载
                    }
                }
                // 绘制子弹
                for (int j = 0; j < enemyPlaneBulletArr.size(); j++) {
                    enemyPlaneBulletArr.get(j).drawBullet(gBuffer, this, 2); // 子弹绘制
                }
            }

            // 绘制Boss子弹
            if (time >= 200) {//10秒后出现boss
                if (bossPlane.getX_Y().getY() >= 80 && System.currentTimeMillis() - before_time2 >= 2500 && bossPlane.stayed) {//boss发射子弹时间限制

                    //装载boss普通子弹
                    Bullet[] bt = new Bullet[5];
                    for (int i = 0; i < 5; i++) {
                        bt[i] = new Bullet((int) (bossPlane.getX_Y().getX()) + BOSS_WIDTH / 2 - 5, (int) (bossPlane.getX_Y().getY()) + BOSS_HEIGHT - 30);
                        bt[i].drawBullet_3(gBuffer, this);
                    }
                    bossPlaneBulletArr.add(bt);

                    // 装载 boss 特殊子弹
                    int t = (int) (bossPlane.getX_Y().getY()) + ENEMY_SIZE;
                    if (t < MAP_HEIGHT) {
                        bullet = new Bullet((int) (bossPlane.getX_Y().getX()) + BOSS_WIDTH / 2 - 5, (int) (bossPlane.getX_Y().getY()) + BOSS_HEIGHT - 30);
                        bullet.drawBullet_boss(bossPlaneBossBulletArr, gBuffer, this);// 子弹装载
                    }

                    before_time2 = System.currentTimeMillis();
                }

                if (!bossPlane.stayed && bossPlane.breakID == 30) {
                    startStopJB.setEnabled(false);
                    isRunning = false;// 设置线程不循环了
                    new Dialog(m, 2);// 挑战成功对话显示
                }

                bossPlane.drawBoss(gBuffer, this);//绘制boss飞机
            }

            // 绘制BOSS的普通子弹
            for (int i = 0; i < bossPlaneBulletArr.size() && bossPlaneBulletArr.size() > 0; i++) {
                for (int j = 0; j < 5; j++)
                    if (bossPlaneBulletArr.get(i)[j] != null)
                        bossPlaneBulletArr.get(i)[j].drawBullet(gBuffer, this, 2);
            }

            // 绘制BOSS的特殊子弹
            for (int i = 0; i < bossPlaneBossBulletArr.size(); i++) {
                bossPlaneBossBulletArr.get(i).drawBullet(gBuffer, this, 3); // 子弹绘制
            }

            if (BossLive >= 0 && bossPlane.stayed) {
                //绘制boss飞机血条
                x = Toolkit.getDefaultToolkit().getImage(getClass().getResource("/images/xue_" + ((200 - BossLive) / 100 + 1) + ".png"));
                gBuffer.drawImage(x, (int) (bossPlane.getX_Y().getX()), (int) (bossPlane.getX_Y().getY() - 10), 250, 10, this);
            }

            g.drawImage(iBuffer, 0, 0, null);//把缓冲图像载入屏幕
        }

        /**
         * 此方法在调用paint前调用
         */
        public void update(Graphics g) {
            paint(g);
        }

        /**
         * 地图位置的滚动
         */
        private void mapMove() {
            // 背景地图移动 实现方法无非就是两张图片不断换动就OK了
            bg1_y += 1;
            bg2_y += 1;
            if (bg1_y == SCREEN_HEIGHT)
                bg1_y = -SCREEN_HEIGHT;
            if (bg2_y == SCREEN_HEIGHT)
                bg2_y = -SCREEN_HEIGHT;
        }

        /**
         * 此方法是对暂停键 pause 的监听
         * 监听 mapPannel 里的按键变化
         */
        private void adapter() {
            addKeyListener(new KeyAdapter() {
                @Override
                public void keyPressed(KeyEvent e) {
                    if (e.getKeyCode() == KeyEvent.VK_P) {
                        stop_start();
                    }
                }
            });
        }
    }

    /**
     * 此方法用于执行暂停与开始
     */
    private void stop_start() {
        if (isRunning == true) {
            isRunning = false; // 设置线程暂停
            startStopJB.setText("开始(P)"); // 改变按钮文字
        } else {
            isRunning = true; // 设置线程循环
            Thread d = new Thread((Runnable) jp); // 创建线程
            d.start(); // 启动线程
            startStopJB.setText("暂停(P)"); // 改变按钮文字
        }
    }
}

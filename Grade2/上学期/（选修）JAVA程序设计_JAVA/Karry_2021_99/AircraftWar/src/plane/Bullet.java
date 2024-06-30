package plane;

import java.awt.Canvas;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Point;
import java.awt.Toolkit;
import java.util.ArrayList;

/**
 * @author 任凯
 * @StudentID 2020141460080
 * @Utility 本类描述子弹
 */

/**
 * 方法
 * -1. 绘制各种飞机子弹
 * -2. 逻辑上控制子弹的移动方法
 */
public class Bullet {
    private int bulletX, bulletY; // 子弹坐标
    private final int STEPMP = 5; // 玩家飞机子弹速度
    private final int STEPEP = 5; //敌机子弹速度
    private Image bulletMP, bulletEP, bulletBoss; // 自己和敌机的子弹图片对象
    private final int MPBTIME = 200; // 玩家飞机子弹发射间隔时间
    private final int EPBTIME = 2000; // 敌机子弹发射间隔时间
    private final int BoBTIME = 300;
    static long lastMPbTime; // 过去绘制玩家飞机子弹时间
    static long lastBobTime;
    static long[] lastEPbTime = new long[10]; // 过去绘制敌机子弹时间
    boolean stayed = true; // 子弹存在标识

    public Bullet(int x, int y) {
        //初始化子弹坐标
        bulletX = x;
        bulletY = y;

        // 加载图片
        bulletMP = Toolkit.getDefaultToolkit().getImage(getClass().getResource("/images/bullet_01.png"));//设置玩家子弹图片
        bulletEP = Toolkit.getDefaultToolkit().getImage(getClass().getResource("/images/bullet_02.png"));//设置敌机子弹图片
        bulletBoss = Toolkit.getDefaultToolkit().getImage(getClass().getResource("/images/bullet_03.png"));// 设置boss超强子弹
    }

    /**
     * 子弹绘制方法
     */
    void drawBullet(Graphics g, Canvas c, int i) {
        if (i == 1)
            g.drawImage(bulletMP, bulletX, bulletY, GamePanel.BULLET_WIDTH, GamePanel.BULLET_HEIGHT, c);//绘制自己的子弹
        else if (i == 2)
            g.drawImage(bulletEP, bulletX, bulletY, GamePanel.BULLET_WIDTH, GamePanel.BULLET_WIDTH, c);//绘制敌机的子弹
        else
            g.drawImage(bulletBoss, bulletX, bulletY, GamePanel.BULLET_WIDTH, GamePanel.BULLET_WIDTH, c);
    }

    /**
     * 控制玩家飞机子弹移动方法
     */
    void bulletMove_1(ArrayList<Bullet> array, int i) {
        // 如果子弹已经飞出去 或者子弹碰撞
        if (bulletY < -GamePanel.BULLET_HEIGHT || stayed == false)
            array.remove(i); // 从数组中移除子弹对象
        else
            bulletY -= STEPMP;
    }

    /**
     * 控制敌机子弹移动方法
     */
    void bulletMove_2(ArrayList<Bullet> array, int i) {
        if (bulletY > GamePanel.MAP_HEIGHT || stayed == false)
            array.remove(i);//从数组中移除子弹对象
        else
            bulletY += STEPEP;
    }

    /**
     * boss 普通子弹移动方法
     * boss 特殊子弹移动方法
     */
    void bulletMove_3(ArrayList<Bullet[]> arr, int i, int j) {
        if (stayed)
            switch (j) {
                case 0:
                    bulletX -= 2;
                    bulletY += 2;
                    break;
                case 1:
                    bulletX -= 1;
                    bulletY += 2;
                    break;
                case 2:
                    bulletY += 2;
                    break;
                case 3:
                    bulletX += 1;
                    bulletY += 2;
                    break;
                case 4:
                    bulletX += 2;
                    bulletY += 2;
                    break;
                default:
                    break;
            }
        else
            arr.get(i)[j] = null;
    }

    void bulletMove_boss(ArrayList<Bullet> array, int i) {
        if (bulletY > GamePanel.MAP_HEIGHT || stayed == false)
            array.remove(i);//从数组中移除子弹对象
        else
            bulletY += STEPEP;
    }

    /**
     * 玩家飞机子弹绘制方法
     */
    void drawBullet_1(ArrayList<Bullet> array, Graphics g, Canvas c) {
        long nowTime = System.currentTimeMillis();
        if (nowTime - lastMPbTime >= MPBTIME)//判断是否发射子弹
        {
            drawBullet(g, c, 1);
            array.add(this);//子弹对象加进数组
            lastMPbTime = nowTime;//将现在时间作为过去时间
        }
    }

    /**
     * 敌机子弹绘制方法
     */
    void drawBullet_2(ArrayList<Bullet> array, Graphics g, Canvas c, int i) {
        long now_time = System.currentTimeMillis();
        if (now_time - lastEPbTime[i] >= EPBTIME)//判断是否发射子弹
        {
            drawBullet(g, c, 2);
            array.add(this); // 子弹对象加进数组
            lastEPbTime[i] = now_time;//将现在时间作为过去时间
        }
    }

    /**
     * boss普通子弹绘制方法
     */
    void drawBullet_3(Graphics g, Canvas c) {
        drawBullet(g, c, 2);
    }

    void drawBullet_boss(ArrayList<Bullet> array, Graphics g, Canvas c) {
        long now_time = System.currentTimeMillis();
        if (now_time - lastBobTime >= BoBTIME)//判断是否发射子弹
        {
            drawBullet(g, c, 3);
            array.add(this); // 子弹对象加进数组
            lastBobTime = now_time;//将现在时间作为过去时间
        }
    }

    /**
     * 获取子弹坐标方法
     */
    Point getX_Y() {
        return new Point(bulletX, bulletY);
    }
}

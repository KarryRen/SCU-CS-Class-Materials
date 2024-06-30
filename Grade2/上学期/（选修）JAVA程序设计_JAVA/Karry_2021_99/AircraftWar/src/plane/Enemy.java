package plane;

import java.awt.Canvas;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Point;
import java.awt.Toolkit;

/**
 * @author 任凯
 * @StudentID 2020141460080
 * @@utility 敌机类 包括敌机的所有内容
 */

public class Enemy {
    private int enemyX, enemyY;// 敌机坐标
    private int enemyOriginalY;// 敌机初始y坐标
    private Image enemyImage[];// 敌机图片数组
    private final int STEP = 2;// 敌机移动速度
    boolean stayed = true;// 敌机生存标识
    private Break b;// 爆炸图片对象
    private int breakID;// 爆炸图片ID

    /**
     * 敌机初始化
     */
    public Enemy(int y) {
        // 敌机坐标初始化
        enemyX = (int) (Math.random() * 500); // 横坐标随机初始化 这个地方可以做一点优化 就是说飞机始终产生在自己飞机的上方
        enemyOriginalY = enemyY = y; // 纵坐标是参数

        // 初始化敌机图片数组
        enemyImage = new Image[5];
        for (int i = 1; i <= enemyImage.length; i++) {
            enemyImage[i - 1] = Toolkit.getDefaultToolkit().getImage(getClass().getResource("/images/enemy" + i%2 + ".png"));
        }
    }

    /**
     * 敌机移动控制方法
     */
    void enemyMove() {
        if (enemyY > GamePanel.MAP_HEIGHT || stayed == false) {
            // 如果敌机已经飞出去了 或者已经死了
            if (GamePanel.time >= 200) { // 10秒过后敌机不在出现 只有 boss 出现
                enemyX = 0;
                enemyY = GamePanel.MAP_HEIGHT + GamePanel.PLANE_SIZE; // 敌机就算生成 也是生成在界面外面
            } else {
                enemyX = (int) (Math.random() * 500);
                enemyY = enemyOriginalY;
                stayed = true; // 敌机设置为生存状态为 true
            }
        } else
            enemyY += STEP;
    }

    /**
     * 绘制敌机以及爆炸的方法
     */
    void drawEnemy(Graphics g, Canvas c, int i) {
        if (stayed)
            g.drawImage(enemyImage[i], enemyX, enemyY, GamePanel.ENEMY_SIZE, GamePanel.ENEMY_SIZE, c); // 在某个界面上绘制敌机
        else if (breakID == 0) {
            b = new Break(enemyX, enemyY);
            b.enemyBreak(g, c, breakID);
            breakID++;
        }

        // 爆炸图像的绘制
        if (b != null && breakID != 0)
            if (breakID == 29) {
                b.enemyBreak(g, c, breakID);
                breakID = 0;
            } else {
                b.enemyBreak(g, c, breakID);
                breakID++;
            }
    }

    /**
     * 获取敌机坐标方法
     *
     * @return Point
     */
    Point getX_Y() {
        return new Point(enemyX, enemyY);
    }

}

package plane;

import java.awt.Canvas;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Point;
import java.awt.Toolkit;

/**
 * @author 任凯
 * @StudentID 20201414600080
 * @Utility 本类描述 boss飞机
 */
public class BossPlane {
    private int bossPlaneX, bossPlaneY;//boss飞机坐标
    private Image BossImage;//boss飞机图片
    private final int step = 1;//boss移动速度
    boolean stayed;//飞机存在标识
    private int position = -1, point;//飞机位置标记
    private Break b;//爆炸图片对象
    int breakID;//爆炸图片ID

    BossPlane() {
        // 飞机的初始坐标
        bossPlaneX = 175;
        bossPlaneY = -500;
        // 飞机图片的初始化
        BossImage = Toolkit.getDefaultToolkit().getImage(getClass().getResource("/images/boss.png"));

        stayed = true;
    }

    /**
     * 控制boss移动
     */
    void bossMove() {
        if (bossPlaneY < 80)
            bossPlaneY += step;
        else
            switch (position) {//让飞机曲线运动
                case 0: // 向右下移动
                    bossPlaneY += step;
                    bossPlaneX += step;
                    if (bossPlaneX == GamePanel.MAP_WIDTH - GamePanel.BOSS_WIDTH)
                        position++;
                    break;
                case 1: // 向左下移动
                    if ((point / 700) % 2 == 0) {
                        bossPlaneY += 3;
                        bossPlaneX -= step;
                    } else {
                        bossPlaneY += 2;
                        bossPlaneX -= 3;
                    }
                    if (bossPlaneY >= GamePanel.MAP_HEIGHT - GamePanel.BOSS_HEIGHT)
                        position++;
                    break;
                case 2:// 向左上移动
                    if ((point / 700) % 2 == 0) {
                        bossPlaneY -= step;
                        bossPlaneX -= step;
                    } else {
                        bossPlaneY -= 3;
                        bossPlaneX -= step;
                    }
                    if (bossPlaneX <= 0)
                        position++;
                    break;
                case 3: // 向右上移动
                    bossPlaneX += step;
                    if (bossPlaneX == 175)
                        position = -1;
                    break;
                default:// 向右移动
                    point++;
                    if (point % 300 == 0)
                        position = 0;
                    break;
            }
    }

    /**
     * 绘制boss
     */
    void drawBoss(Graphics g, Canvas c) {
        if (stayed)
            g.drawImage(BossImage, bossPlaneX, bossPlaneY, GamePanel.BOSS_WIDTH, GamePanel.BOSS_HEIGHT, c);
        else if (breakID == 0) {
            b = new Break(bossPlaneX, bossPlaneY);
            b.BossBreak(g, c, breakID);
            breakID++;
        } else {
            b.BossBreak(g, c, breakID);
            breakID++;
        }
    }

    /**
     * 获取 boss飞机坐标方法
     */
    Point getX_Y() {
        return new Point(bossPlaneX, bossPlaneY);
    }

}

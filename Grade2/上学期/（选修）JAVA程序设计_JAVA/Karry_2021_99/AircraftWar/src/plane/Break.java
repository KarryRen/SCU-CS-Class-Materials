package plane;

import java.awt.Canvas;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Toolkit;

import javax.swing.JDialog;

/**
 * @author 任凯
 * 本类描述飞机爆炸
 */

public class Break {
    private Image planeBreakImgArr[];//敌机爆炸图片数组
    private int x, y;//坐标
    JDialog f;

    public Break(int x, int y) {
        // 实例化敌机爆炸图片数
        planeBreakImgArr = new Image[6];
        for (int i = 0; i < planeBreakImgArr.length; i++) {
            planeBreakImgArr[i] = Toolkit.getDefaultToolkit().getImage(getClass()
                    .getResource("/images/bomb_enemy_" + i + ".png"));
        }
        // 初始化爆炸坐标
        this.x = x;
        this.y = y;
    }

    /**
     * 敌机爆炸图片绘制方法
     */
    void enemyBreak(Graphics g, Canvas c, int i) {
        g.drawImage(planeBreakImgArr[i / 5], x, y, GamePanel.ENEMY_SIZE, GamePanel.ENEMY_SIZE, c);
    }

    /**
     * 飞机爆炸图片绘制方法
     */
    void myPlaneBreak(Graphics g, Canvas c, int i) {
        if (i < 30)
            g.drawImage(planeBreakImgArr[i / 5], x, y, GamePanel.PLANE_SIZE, GamePanel.PLANE_SIZE, c);
    }

    /**
     * boss爆炸
     */
    void BossBreak(Graphics g, Canvas c, int i) {
        if (i < 30)
            g.drawImage(planeBreakImgArr[i / 5], x, y, GamePanel.BOSS_WIDTH, GamePanel.BOSS_HEIGHT, c);
    }

}

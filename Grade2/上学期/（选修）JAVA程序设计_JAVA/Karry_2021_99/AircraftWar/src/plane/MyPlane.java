package plane;

import java.awt.Canvas;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Point;
import java.awt.Toolkit;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;


/**
 * @author 任凯
 * @StudentID 2020141460080
 * @Utility 玩家飞机的类
 */


public class MyPlane {
    private int myPlaneX = 230, myPlaneY = 450; // 玩家飞机坐标
    private Image myPlaneImage[]; // 存储飞机图片的数组
    private final int STEP = 7; // 飞机速度
    private boolean pressUp, pressDown, pressLeft, pressRight; //记录按键状态
    boolean stayed = true; // 玩家飞机生存标识
    private Break b; // 爆炸图片对象
    int breakID; // 爆炸图片ID 实现图片的变动 展示连续的爆炸效果
    static int planeID; //玩家飞机编号

    public MyPlane() {
        // 初始化飞机图像数组
        myPlaneImage = new Image[5];
        for (int i = 1; i <= myPlaneImage.length; i++) {
            myPlaneImage[i - 1] = Toolkit.getDefaultToolkit().getImage(getClass().getResource("/images/Plane0" + i + ".png"));
        }
    }

    /**
     * 控制飞机移动方法 √
     * 一定要避免飞机飞出去
     */
    void planeMove() {
        if (pressUp)
            if (myPlaneY > 0) {
                myPlaneY -= STEP;
            }
        if (pressDown)
            if (myPlaneY < GamePanel.MAP_HEIGHT - GamePanel.PLANE_SIZE)
                myPlaneY += STEP;
        if (pressLeft)
            if (myPlaneX > 0)
                myPlaneX -= STEP;
        if (pressRight)
            if (myPlaneX < GamePanel.MAP_HEIGHT - GamePanel.PLANE_SIZE)
                myPlaneX += STEP;
    }

    /**
     * 绘制玩家飞机方法
     */
    void drawMyPlane(Graphics g, Canvas c) {
        if (stayed)
            g.drawImage(myPlaneImage[planeID], myPlaneX, myPlaneY, GamePanel.PLANE_SIZE, GamePanel.PLANE_SIZE, c);//绘制玩家飞机
        else if (breakID == 0) {
            b = new Break(myPlaneX, myPlaneY);
            b.myPlaneBreak(g, c, breakID);
            breakID++;
        } else {
            b.myPlaneBreak(g, c, breakID);
            breakID++;
        }
    }

    /**
     * 玩家飞机移动键盘监听方法
     * 和上面的 planeMove 息息相关
     */
    void adapter(Canvas c) {
        c.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                int key = e.getKeyCode();
                if (key == KeyEvent.VK_UP) pressUp = true;
                if (key == KeyEvent.VK_DOWN) pressDown = true;
                if (key == KeyEvent.VK_LEFT) pressLeft = true;
                if (key == KeyEvent.VK_RIGHT) pressRight = true;
            }

            @Override
            public void keyReleased(KeyEvent e) {
                int key = e.getKeyCode();
                if (key == KeyEvent.VK_UP) pressUp = false;
                if (key == KeyEvent.VK_DOWN) pressDown = false;
                if (key == KeyEvent.VK_LEFT) pressLeft = false;
                if (key == KeyEvent.VK_RIGHT) pressRight = false;
            }
        });

    }

    /**
     * 获取玩家飞机坐标方法
     */
    Point getX_Y() {
        return new Point(myPlaneX, myPlaneY);
    }
}

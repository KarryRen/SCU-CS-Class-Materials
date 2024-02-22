package plane;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.net.URISyntaxException;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 * @author 任凯
 * @StudentID 2020141460080
 * @utility 主界面类 实现游戏的最开始界面 可以选择飞机形状和进入游戏
 */

/**
 * MainPanel 是从 JFrame 继承出来的屏幕window对象
 * 属性：
 * -1. 四个 Label
 *      - 背景图像 bgLabel
 *      - 开始游戏 startLabel
 *      - 设置    settingLabel
 *      - 标识 1 flagLabel1 表示选择开始游戏
 *      - 标识 2 flagLabel2 表示选择设置
 *
 * -2. 背景音乐
 * -3. 表示自身的 MainPanel
 * <p>
 * 方法
 * -1. 主界面的构造方法
 * -2. 展现背景图片的方法
 * -3. 展现标签的方法
 * -4. 键盘事件监听器 最重要的一个
 */

public class MainPanel extends JFrame {
    // 四个label: back->背景label
    private JLabel bgLabel, startLabel, settingLabel, flagLabel1, flagLabel2;
    private PlaySound p; // 音频
    private MainPanel m; // 本类对象

    // 主界面的构造方法
    public MainPanel() {

        super("✈ 飞机大战 ✈"); // 设置窗口的 Title

        setSize(800, 600); // 设置窗体大小

        setLayout(null); // 清除布局管理(每一次创立新的游戏都要清空界面)

        showBackground(); // 设置并显示背景

        showLabel(); // 显示界面

        adapter(); // 监听键盘

        m = this;
    }

    /**
     * 键盘监听方法 也是本界面的关键部分
     * 建立起键盘适配器
     */
    public void adapter() {

        addKeyListener(new KeyAdapter() {

            @Override // 重写 keyPressed 方法
            public void keyPressed(KeyEvent e) {
                if (PlaySound.bgmArr[1]) {
                    //声音设置
                    p = new PlaySound();
                    p.open("sounds/ClickSound.wav");
                    p.init();
                    p.start();
                }

                int key = e.getKeyCode();

                // 监听敲击向上按钮或向下按钮
                if (key == KeyEvent.VK_DOWN || key == KeyEvent.VK_UP) {
                    // 实现两个 label 的可视转化
                    flagLabel1.setVisible(!flagLabel1.isVisible());
                    flagLabel2.setVisible(!flagLabel2.isVisible());

                    if (flagLabel1.isVisible()) {
                        startLabel.setForeground(Color.blue);
                        settingLabel.setForeground(Color.black);
                    } else {
                        startLabel.setForeground(Color.black);
                        settingLabel.setForeground(Color.blue);
                    }
                }

                // 监听回车按键 如果选择在 label3上 就进入游戏
                if (key == KeyEvent.VK_ENTER && flagLabel1.isVisible()) {
                    GamePanel game = new GamePanel(m);
                    add(game);
                    game.setSize(800, 600); // 设置游戏面板界面大小
                    //移除组件
                    remove(startLabel);
                    remove(settingLabel);
                    remove(flagLabel1);
                    remove(flagLabel2);
                    Bullet.lastMPbTime = System.currentTimeMillis();
                }

                // 监听回车按键 如果选择在 label4上 就进入设置对话框
                if (key == KeyEvent.VK_ENTER && flagLabel2.isVisible()) {
                    new Dialog(m, 0);
                }
            }

        });

    }

    /**
     * 设置背景图片 方法
     */
    private void showBackground() {

        // 通过文件路径 载入背景图像 创建ImageIcon对象background
        ImageIcon background = new ImageIcon(getClass().getResource("/images/mainback.png"));
        // 设置背景标签
        bgLabel = new JLabel(background);
        // 设置背景图片位置大小
        bgLabel.setBounds(0, 0, getWidth(), getHeight());
        // 设置面板透明
        JPanel j = (JPanel) getContentPane();
        j.setOpaque(false);
        // 显示设置好的背景
        getLayeredPane().add(bgLabel, new Integer(Integer.MIN_VALUE));
    }

    /**
     * 设置四个标签 方法
     */
    private void showLabel() {

        // 通过文件路径载入标签图像 创建 ImageIcon 对象 icon
        ImageIcon icon = new ImageIcon(getClass().getResource("/images/point.png"));

        // 设置标签
        // 开始标签
        startLabel = new JLabel("开始游戏"); // 创建标签 label01
        startLabel.setFont(new Font("acefont-family", Font.BOLD, 50)); // 设置字体格式
        startLabel.setForeground(Color.blue); // 设置前景颜色
        startLabel.setBounds(270, 340, 400, 120); // 设置位置和大小

        // 设置标签
        settingLabel = new JLabel("设置");
        settingLabel.setFont(new Font("acefont-family", Font.BOLD, 50));
        settingLabel.setBounds(320, 430, 200, 120);

        // 选择开始游戏的 label
        flagLabel1 = new JLabel(icon);
        flagLabel1.setBounds(40, 340, 250, 120);

        flagLabel2 = new JLabel(icon);
        flagLabel2.setBounds(130, 435, 250, 120);
        flagLabel2.setVisible(false);

        add(startLabel);
        add(settingLabel);
        add(flagLabel1);
        add(flagLabel2);
    }

}

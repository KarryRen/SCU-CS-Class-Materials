package plane;

import java.net.URISyntaxException;

import javax.swing.JFrame;


/**
 * @author 任凯
 * @StudentID 2020141460080
 * @utilyti 本类是主类 里面有 main 方法 是游戏的启动端
 */

public class PanelFrame {

    /**
     * 静态设置两个变量
     * 主页面对象 && 游戏声音对象
     * 均设置成静态变量是像让后续的对象可以对这两个属性进行调用
     */
    static MainPanel mainWindow;    // 主页面对象
    static PlaySound playSound;     // 游戏声音对象

    // main方法
    public static void main(String[] args) {

        // part 1. 实例化主页面对象的设置 √
        mainWindow = new MainPanel();
        // 监听关闭窗口按钮 实现点击 ❌ 关闭窗口
        mainWindow.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // 设置窗口可视
        mainWindow.setVisible(true);
        // 设置窗口不可拉伸
        mainWindow.setResizable(false);

        /**
         * part 2. 设置背景音乐 √
         **/
        if (playSound == null) {
            playSound = new PlaySound();
            playSound.open("sounds/OPSound.mid");
            playSound.init();
            playSound.loop();
            playSound.start();
        }
    }
}

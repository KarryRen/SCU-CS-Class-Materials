package plane;

import java.io.File;
import java.io.IOException;

import javax.sound.sampled.AudioFormat;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.sound.sampled.DataLine;
import javax.sound.sampled.LineUnavailableException;
import javax.sound.sampled.UnsupportedAudioFileException;

/**
 * @author 任凯
 * @StudentID 2020141460080
 * @utility 实现游戏种各种音频的播放 每一段音频的播放都要经过相关部分
 */

public class PlaySound {

    private File file;                  // 文件
    private AudioInputStream stream;    // 音频输入流
    private AudioFormat format;         // 音频格式
    private DataLine.Info info;         // 音频信息
    private Clip clip;                  // 音频clip
    static boolean[] bgmArr = new boolean[]{true, true, true, true}; //控制四种背景声音是否存在

    /**
     * 打开音频文件方法
     * 将文件转化为 AudioInputStream 以便于后续的操作
     * 获取文件流的格式
     */
    void open(String s) {
        file = new File(s); // 音频文件对象
        // 使用 try 和 catch 格式检测错误的发生
        try {
            stream = AudioSystem.getAudioInputStream(file); // 音频输入流对象
            format = stream.getFormat(); // 音频格式对象
        } catch (UnsupportedAudioFileException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * 初始化 clip
     */
    void init() {
        info = new DataLine.Info(Clip.class, format);// 音频信息对象实例化
        try {
            clip = (Clip) AudioSystem.getLine(info); // 创建音频行
            clip.open(stream); // 将音频数据读入音频行
        } catch (LineUnavailableException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * 循环播放音频的方法
     * 设置音乐的循环播放
     */
    void loop() {
        clip.loop(20);//回放
    }

    /**
     * 停止播放音频的方法
     */
    void stop() {
        clip.stop();//暂停音频播放
    }

    /**
     * 开始播放音频的方法
     */
    void start() {
        clip.start();//播放音频
    }
}

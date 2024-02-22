package plane;

import java.net.URISyntaxException;

/**
 * @author 任凯
 * @StudentID 2020141460080
 * @Utility 本类描述碰撞
 */

public class Collide {
    private PlaySound p;

    /**
     * 玩家飞机子弹与敌机碰撞方法
     */
    void bulletCoEnemy(Bullet b, Enemy e) {
        // 判断是否产生碰撞
        if (b.getX_Y().getX() >= e.getX_Y().getX() - GamePanel.BULLET_WIDTH
                && b.getX_Y().getX() <= e.getX_Y().getX() + GamePanel.ENEMY_SIZE
                && b.getX_Y().getY() >= e.getX_Y().getY() - GamePanel.BULLET_HEIGHT
                && b.getX_Y().getY() <= e.getX_Y().getY() + GamePanel.ENEMY_SIZE) {
            b.stayed = false;
            e.stayed = false;
            if (PlaySound.bgmArr[2]) {
                //敌机爆炸声音
                p = new PlaySound();
                p.open("sounds/Break.wav");
                p.init();
                p.start();
            }
            GamePanel.score += 100;//增加分数，每架飞机增加100
        }
    }

    /**
     * 玩家飞机与敌机碰撞方法
     */
    void myPlaneCoEnemy(MyPlane m, Enemy e) {
        if (m.getX_Y().getX() >= e.getX_Y().getX() - GamePanel.PLANE_SIZE
                && m.getX_Y().getX() <= e.getX_Y().getX() + GamePanel.ENEMY_SIZE
                && m.getX_Y().getY() >= e.getX_Y().getY() - GamePanel.PLANE_SIZE
                && m.getX_Y().getY() <= e.getX_Y().getY() + GamePanel.ENEMY_SIZE) {
            e.stayed = false;
            if (GamePanel.myPlaneLive <= 50) {
                m.stayed = false;
                if (PlaySound.bgmArr[3]) {
                    //玩家飞机爆炸声音
                    p = new PlaySound();
                    p.open("sounds/HeroBrustSound.wav");
                    p.init();
                    p.start();
                }
                GamePanel.myPlaneLive = 0;
            } else
                GamePanel.myPlaneLive -= 50;
        }
    }

    /**
     * 玩家飞机和敌机子弹碰撞方法
     */
    void bulletCoMyPlane(Bullet b, MyPlane m) {
        if (b.getX_Y().getX() >= m.getX_Y().getX()
                && b.getX_Y().getX() <= m.getX_Y().getX() + GamePanel.PLANE_SIZE - GamePanel.BULLET_WIDTH
                && b.getX_Y().getY() >= m.getX_Y().getY()
                && b.getX_Y().getY() <= m.getX_Y().getY() + GamePanel.PLANE_SIZE) {
            b.stayed = false;
            if (GamePanel.myPlaneLive <= 5) {
                m.stayed = false;
                if (PlaySound.bgmArr[3]) {
                    //玩家飞机爆炸声音
                    p = new PlaySound();
                    p.open("sounds/HeroBrustSound.wav");
                    p.init();
                    p.start();
                }
                GamePanel.myPlaneLive = 0;//飞机丧失生命
            } else
                GamePanel.myPlaneLive -= 5;//飞机生命减少
        }
    }

    void bossBulletCoMyPlane(Bullet b, MyPlane m) {
        if (b.getX_Y().getX() >= m.getX_Y().getX()
                && b.getX_Y().getX() <= m.getX_Y().getX() + GamePanel.PLANE_SIZE - GamePanel.BULLET_WIDTH
                && b.getX_Y().getY() >= m.getX_Y().getY()
                && b.getX_Y().getY() <= m.getX_Y().getY() + GamePanel.PLANE_SIZE) {
            m.stayed = false;
            if (PlaySound.bgmArr[3]) {
                //玩家飞机爆炸声音
                p = new PlaySound();
                p.open("sounds/HeroBrustSound.wav");
                p.init();
                p.start();
            }
            GamePanel.myPlaneLive = 0;
        }
    }

    /**
     * boss与玩家飞机碰撞
     */
    void bossCoMyPlane(BossPlane b, MyPlane m) {
        if (b.getX_Y().getX() >= m.getX_Y().getX() - GamePanel.BOSS_WIDTH
                && b.getX_Y().getX() <= m.getX_Y().getX() + GamePanel.PLANE_SIZE
                && b.getX_Y().getY() >= m.getX_Y().getY() - GamePanel.BOSS_HEIGHT
                && b.getX_Y().getY() <= m.getX_Y().getY() + GamePanel.PLANE_SIZE) {
            m.stayed = false;
            if (PlaySound.bgmArr[3]) {
                //玩家飞机爆炸声音
                p = new PlaySound();
                p.open("sounds/HeroBrustSound.wav");
                p.init();
                p.start();
            }
            GamePanel.myPlaneLive = 0;
        }
    }

    /**
     * 玩家飞机子弹与boss飞机碰撞
     */
    void bulletCoBoss(Bullet b, BossPlane m) {
        if (b.getX_Y().getX() >= m.getX_Y().getX()
                && b.getX_Y().getX() <= m.getX_Y().getX() + GamePanel.BOSS_WIDTH - GamePanel.BULLET_WIDTH
                && b.getX_Y().getY() >= m.getX_Y().getY()
                && b.getX_Y().getY() <= m.getX_Y().getY() + GamePanel.BOSS_HEIGHT
                && m.getX_Y().getY() >= 0) {
            b.stayed = false;
            if (GamePanel.BossLive <= 1) {
                m.stayed = false;
                if (PlaySound.bgmArr[3]) {
                    //玩家飞机爆炸声音
                    p = new PlaySound();
                    p.open("sounds/HeroBrustSound.wav");
                    p.init();
                    p.start();
                }
                GamePanel.BossLive = 0;//boss飞机生命减少
                GamePanel.score += 500;//分数 + 500
            } else
                GamePanel.BossLive -= 1; // boss飞机生命减少
        }
    }
}

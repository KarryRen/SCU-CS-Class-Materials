package com.example.software.service;

import java.util.List;

import com.example.software.pojo.User;

/**
 * 用户管理
 */
public interface UserService {

    /**
     * 根据ID查询自己
     * 
     * @param List<User>
     * @return
     */
    List<User> getUser();


    /**
     * 用户注册
     * 
     * @param user
     * @return
     */
    void register(User user);

    /**
     * 用户登录
     * 
     * @param user
     * @return
     */
    User login(User user);

    /**
     * 更新个人信息
     * 
     * @param user
     * @return
     */
    void updateInformation(User user);

    /**
     * 修改用户密码
     * 
     * @param user
     * @return
     */
    void updateUserPasswd(User user);

    /**
     * 管理员查询用户信息
     * 
     * @param user
     * @return
     */
    List<User> selectUser(User user);
}

package com.example.software.service.impl;

import com.example.software.mapper.UserMapper;
import com.example.software.pojo.User;
import com.example.software.service.UserService;

import lombok.RequiredArgsConstructor;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
@RequiredArgsConstructor
public class UserServiceImpl implements UserService {

    @Autowired
    private UserMapper userMapper;

    @Override
    public List<User> getUser() {
        return userMapper.getUser();
    }

    // 用户注册
    @Override
    public void register(User user) {
        userMapper.register(user.getUserName(), user.getUserLicense(), user.getUserPhone(), user.getUserEmail(),
                user.getUserSalt(), user.getUserPasswd());
    }

    // 用户登录
    @Override
    public User login(User user) {
        return userMapper.userLogin(user.getUserEmail());
    }

    // 更新个人信息
    @Override
    public void updateInformation(User user) {
        userMapper.updateInformation(user.getUserId(), user.getUserName(), user.getUserLicense(), user.getUserPhone(), user.getUserEmail());
    }

    // 修改用户密码
    @Override
    public void updateUserPasswd(User user) {
        userMapper.updateUserPasswd(user.getUserId(), user.getUserSalt(), user.getUserPasswd());
    }

    // 管理员查询用户信息
    @Override
    public List<User> selectUser(User user) {
        return userMapper.selectUser(user.getUserName(), user.getUserLicense(), user.getUserPhone(), user.getUserEmail());
    }
}

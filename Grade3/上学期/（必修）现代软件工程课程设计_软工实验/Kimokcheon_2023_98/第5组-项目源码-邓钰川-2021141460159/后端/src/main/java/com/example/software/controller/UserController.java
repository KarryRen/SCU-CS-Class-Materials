package com.example.software.controller;

import com.example.software.pojo.User;
import com.example.software.pojo.Result;
import com.example.software.service.UserService;
import com.example.software.utils.EncryptionUtils;
import com.example.software.utils.JwtUtils;

import java.util.List;
import java.util.Objects;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RequestMapping("/user")
@RestController
public class UserController {

    @Autowired
    private UserService userService;

    // 测试用户类
    @GetMapping("/GetUser")
    public Result GetUser(@RequestBody User user) {
        List<User> users = userService.getUser();
        return Result.success(users);
    }

    // 更新用户信息
    @PostMapping("/UpdateInformation")
    public Result UpdateInformation(@RequestHeader("Authorization") String userJWT, @RequestBody User user) {
        Integer userId = JwtUtils.getUserIdByJWT(userJWT);
        user.setUserId(userId);
        try {
            userService.updateInformation(user);
        } catch (Exception e) {
            return Result.error("信息更新失败" + e.getMessage());
        }
        return Result.success("信息更新成功");
    }

    // 修改密码
    @PostMapping("/UpdateUserPasswd")
    public Result updateUserPasswd(@RequestHeader("Authorization") String userJWT, @RequestBody User user) {
        Integer userId = JwtUtils.getUserIdByJWT(userJWT);
        user.setUserId(userId);
        User u = userService.login(user);
        if (u == null)
            return Result.error("账户或密码错误");// 账户错误

        String passwd = EncryptionUtils.sha256(user.getUserPasswd() + u.getUserSalt());
        if (!Objects.equals(passwd, u.getUserPasswd())) {
            return Result.error("原始密码错误");// 密码错误
        }

        user.setUserPasswd(user.getUserPhone());
        user.setUserSalt(EncryptionUtils.generateRandomString(64));
        passwd = EncryptionUtils.sha256(user.getUserPasswd() + user.getUserSalt());
        user.setUserPasswd(passwd);
        try {
            userService.updateUserPasswd(user);
        } catch (Exception e) {
            return Result.error("密码更改失败" + e.getMessage());
        }
        return Result.success("密码更改成功");
    }

    // 管理员查询用户信息
    @PostMapping("/SelectUser")
    public Result SelectUser(@RequestHeader("Authorization") String userJWT, @RequestBody User user) {
        List<User> users;
        try {
            users = userService.selectUser(user);
        } catch (Exception e) {
            return Result.error("查询失败" + e.getMessage());
        }
        return Result.success(users);
    }
}

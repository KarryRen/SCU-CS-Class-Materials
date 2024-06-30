package com.example.software.controller;

import com.example.software.pojo.Result;
import com.example.software.pojo.User;
import com.example.software.pojo.LoginResult;
import com.example.software.service.UserService;
import com.example.software.utils.JwtUtils;
import com.example.software.utils.EncryptionUtils;

import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import org.springframework.http.ResponseEntity;
import org.springframework.util.ResourceUtils;
import org.springframework.http.MediaType;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

@Slf4j
@RequestMapping("/login")
@RestController
public class LoginController {

    @Autowired
    private UserService userService;

    @PostMapping("/Login")
    public Result Login(@RequestBody User user) {
        User u = userService.login(user);
        if (u == null)
            return Result.error("账户或密码错误");// 账户错误

        String passwd = EncryptionUtils.sha256(user.getUserPasswd() + u.getUserSalt());
        System.out.println("加盐加密后的密码是: " + passwd);
        if (!Objects.equals(passwd, u.getUserPasswd())) {
            return Result.error("账户或密码错误");// 密码错误
        }

        log.info("用户登录: ", u.getUserId());

        Map<String, Object> claims = new HashMap<>();
        claims.put("userId", u.getUserId());
        claims.put("userPermissions", u.getUserPermissions());
        String jwt = JwtUtils.generateJwt(claims);

        LoginResult loginResult = new LoginResult(jwt, u.getUserName(), u.getUserEmail(), u.getUserId(), u.getUserPermissions());

        return Result.success(loginResult);
    }

    @PostMapping("/Register")
    public Result Register(@RequestBody User user) {
        String salt = EncryptionUtils.generateRandomString(64);
        user.setUserSalt(salt);
        String passwd = EncryptionUtils.sha256(user.getUserPasswd() + user.getUserSalt());
        user.setUserPasswd(passwd);
        try {
            userService.register(user);
        } catch (Exception e) {
            return Result.error("注册失败" + e.getMessage());
        }
        return Result.success("注册成功");
    }

    @GetMapping("/image")
    public ResponseEntity<byte[]> getImage(@RequestParam String imageName) throws IOException {
        File file = ResourceUtils.getFile("./img/" + imageName + ".png");
        byte[] imageBytes = Files.readAllBytes(file.toPath());

        return ResponseEntity.ok()
                .contentType(MediaType.IMAGE_PNG)
                .body(imageBytes);
    }

}

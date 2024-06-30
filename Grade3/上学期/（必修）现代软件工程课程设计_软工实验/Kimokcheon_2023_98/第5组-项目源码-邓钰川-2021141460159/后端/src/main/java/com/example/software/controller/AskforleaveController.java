package com.example.software.controller;

import com.example.software.pojo.User;
import com.example.software.pojo.Askforleave;
import com.example.software.pojo.Result;
import com.example.software.service.AskforleaveService;
import com.example.software.utils.JwtUtils;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RequestMapping("/askforleave")
@RestController
public class AskforleaveController {

    @Autowired
    private AskforleaveService askforleaveService;

    // 测试用户类
    @GetMapping("/GetAskforleave")
    public Result GetAskforleave(@RequestBody User user) {
        List<Askforleave> Askforleaves = askforleaveService.getAskforleave();
        return Result.success(Askforleaves);
    }

    @PostMapping("/UserAskforleave")
    public Result UserAskforleave(@RequestHeader("Authorization") String userJWT,
            @RequestBody Askforleave askforleave) {
        Integer userId = JwtUtils.getUserIdByJWT(userJWT);
        askforleave.setUserId(userId);
        try {
            askforleaveService.userAskforleave(askforleave);
        } catch (Exception e) {
            return Result.error("请假申请失败" + e.getMessage());
        }
        return Result.success("请假申请成功");
    }

    @PostMapping("/AdministratorAudit")
    public Result AdministratorAudit(@RequestHeader("Authorization") String userJWT,
            @RequestBody Askforleave askforleave) {
        try {
            askforleaveService.administratorAudit(askforleave);
        } catch (Exception e) {
            return Result.error("请假申请审核失败" + e.getMessage());
        }
        return Result.success("请假申请审核成功");
    }

    @PostMapping("/UserGetAskforleave")
    public Result UserGetAskforleave(@RequestHeader("Authorization") String userJWT,
            @RequestBody Askforleave askforleave) {
        Integer userId = JwtUtils.getUserIdByJWT(userJWT);
        askforleave.setUserId(userId);
        List<Askforleave> askforleaves;
        try {
            askforleaves = askforleaveService.userGetAskforleave(askforleave);
        } catch (Exception e) {
            return Result.error("用户请假信息查询失败" + e.getMessage());
        }
        return Result.success(askforleaves);
    }

    @PostMapping("/AdministratorGetAskforleave")
    public Result AdministratorGetAskforleave(@RequestHeader("Authorization") String userJWT,
            @RequestBody Askforleave askforleave) {
        List<Askforleave> askforleaves;
        try {
            askforleaves = askforleaveService.administratorGetAskforleave(askforleave);
        } catch (Exception e) {
            return Result.error("请假信息查询失败" + e.getMessage());
        }
        return Result.success(askforleaves);
    }
}

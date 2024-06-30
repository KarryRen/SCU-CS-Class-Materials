package com.example.software.controller;

import com.example.software.pojo.User;
import com.example.software.pojo.Leaveschool;
import com.example.software.pojo.Result;
import com.example.software.service.LeaveschoolService;
import com.example.software.utils.JwtUtils;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RequestMapping("/leaveschool")
@RestController
public class LeaveschoolController {

    @Autowired
    private LeaveschoolService leaveschoolService;

    // 测试用户类
    @GetMapping("/GetLeaveschool")
    public Result GetLeaveschool(@RequestBody User user) {
        List<Leaveschool> Leaveschools = leaveschoolService.getLeaveschool();
        return Result.success(Leaveschools);
    }

    @PostMapping("/UserLeaveschool")
    public Result UserLeaveschool(@RequestHeader("Authorization") String userJWT,
            @RequestBody Leaveschool leaveschool) {
        Integer userId = JwtUtils.getUserIdByJWT(userJWT);
        leaveschool.setUserId(userId);
        try {
            leaveschoolService.userLeaveschool(leaveschool);
        } catch (Exception e) {
            return Result.error("离校申请失败" + e.getMessage());
        }
        return Result.success("离校申请成功");
    }

    @PostMapping("/AdministratorAudit")
    public Result AdministratorAudit(@RequestHeader("Authorization") String userJWT,
            @RequestBody Leaveschool leaveschool) {
        try {
            leaveschoolService.administratorAudit(leaveschool);
        } catch (Exception e) {
            return Result.error("离校申请审核失败" + e.getMessage());
        }
        return Result.success("离校申请审核成功");
    }

    @PostMapping("/UserGetLeaveschool")
    public Result UserGetLeaveschool(@RequestHeader("Authorization") String userJWT,
            @RequestBody Leaveschool leaveschool) {
        Integer userId = JwtUtils.getUserIdByJWT(userJWT);
        leaveschool.setUserId(userId);
        List<Leaveschool> leaveschools;
        try {
            leaveschools = leaveschoolService.userGetLeaveschool(leaveschool);
        } catch (Exception e) {
            return Result.error("用户离校信息查询失败" + e.getMessage());
        }
        return Result.success(leaveschools);
    }

    @PostMapping("/AdministratorGetLeaveschool")
    public Result AdministratorGetLeaveschool(@RequestHeader("Authorization") String userJWT,
            @RequestBody Leaveschool leaveschool) {
        List<Leaveschool> leaveschools;
        try {
            leaveschools = leaveschoolService.administratorGetLeaveschool(leaveschool);
        } catch (Exception e) {
            return Result.error("离校信息查询失败" + e.getMessage());
        }
        return Result.success(leaveschools);
    }
}

package com.example.software.controller;

import com.example.software.pojo.User;
import com.example.software.pojo.Repair;
import com.example.software.pojo.Result;
import com.example.software.service.RepairService;
import com.example.software.utils.JwtUtils;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RequestMapping("/repair")
@RestController
public class RepairController {

    @Autowired
    private RepairService repairService;

    // 测试用户类
    @GetMapping("/GetRepair")
    public Result GetRepair(@RequestBody User user) {
        List<Repair> Repairs = repairService.getRepair();
        return Result.success(Repairs);
    }

    @PostMapping("/AddRepair")
    public Result AddRepair(@RequestHeader("Authorization") String userJWT, @RequestBody Repair repair) {
        Integer userId = JwtUtils.getUserIdByJWT(userJWT);
        repair.setUserId(userId);
        try {
            repairService.addRepair(repair);
        } catch (Exception e) {
            return Result.error("维修信息添加失败" + e.getMessage());
        }
        return Result.success("维修新添加成功");
    }

    @PostMapping("/getSelfRepairs")
    public Result getSelfRepairs(@RequestHeader("Authorization") String userJWT, @RequestBody Repair repair) {
        Integer userId = JwtUtils.getUserIdByJWT(userJWT);
        repair.setUserId(userId);
        List<Repair> repairs;
        try {
            repairs = repairService.getSelfRepairs(repair);
        } catch (Exception e) {
            return Result.error("历史报修信息查询失败" + e.getMessage());
        }
        return Result.success(repairs);
    }

    @PostMapping("/UpdateRepair")
    public Result UpdateRepair(@RequestHeader("Authorization") String userJWT, @RequestBody Repair repair) {
        try {
            repairService.updateRepair(repair);
        } catch (Exception e) {
            return Result.error("维修信息审批失败" + e.getMessage());
        }
        return Result.success("维修信息审批成功");
    }

    @PostMapping("/getRepairs")
    public Result getRepairs(@RequestHeader("Authorization") String userJWT, @RequestBody Repair repair) {
        Integer userId = JwtUtils.getUserIdByJWT(userJWT);
        repair.setUserId(userId);
        List<Repair> repairs;
        try {
            repairs = repairService.getRepairs(repair);
        } catch (Exception e) {
            return Result.error("用户报修信息查询失败" + e.getMessage());
        }
        return Result.success(repairs);
    }
}

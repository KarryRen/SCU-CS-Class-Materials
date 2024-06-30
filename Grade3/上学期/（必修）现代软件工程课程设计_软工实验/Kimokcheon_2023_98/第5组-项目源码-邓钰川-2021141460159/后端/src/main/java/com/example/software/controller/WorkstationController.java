package com.example.software.controller;

import com.example.software.pojo.Workstation;
import com.example.software.pojo.Result;
import com.example.software.service.WorkstationService;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;


@RequestMapping("/workstation")
@RestController
public class WorkstationController {

    @Autowired
    private WorkstationService workstationService;

    // 测试用户类
    @PostMapping("/GetWorkstation")
    public Result GetWorkstation() {
        List<Workstation> Workstations =  workstationService.getWorkstation();
        return Result.success(Workstations);
    }

    // 管理员添加工位
    @PostMapping("/AddWorkstation")
    public Result AddWorkstation(@RequestHeader("Authorization") String userJWT, @RequestBody Workstation workstation) {
        try {
            workstationService.addWorkstation(workstation);
        } catch (Exception e) {
            return Result.error("工位添加失败" + e.getMessage());
        }
        return Result.success("工位添加成功");
    }

    @PostMapping("/UpdateWorkstation")
    public Result UpdateWorkstation(@RequestHeader("Authorization") String userJWT, @RequestBody Workstation workstation) {
        try {
            workstationService.updateWorkstation(workstation);
        } catch (Exception e) {
            return Result.error("工位信息更新失败" + e.getMessage());
        }
        return Result.success("工位信息更新成功");
    }

    // 管理员绑定工位给指定的用户
    @PutMapping("/BindWorkstation")
    public Result BindWorkstation(@RequestHeader("Authorization") String userJWT, @RequestBody Workstation workstation) {
        try {
            workstationService.bindWorkstation(workstation);
        } catch (Exception e) {
            return Result.error("工位绑定成功" + e.getMessage());
        }
        return Result.success("工位绑定失败");
    }

    // 管理员删除工位
    @PostMapping("/DeleteWorkstation")
    public Result DeleteWorkstation(@RequestHeader("Authorization") String userJWT, @RequestBody Workstation workstation) {
        try {
            workstationService.deleteWorkstation(workstation);
        } catch (Exception e) {
            return Result.error("工位删除失败" + e.getMessage());
        }
        return Result.success("工位删除成功");
    }
}

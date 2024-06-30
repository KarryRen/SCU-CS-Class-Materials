package com.example.software.controller;

import com.example.software.pojo.User;
import com.example.software.pojo.Equipment;
import com.example.software.pojo.Result;
import com.example.software.service.EquipmentService;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RequestMapping("/equipment")
@RestController
public class EquipmentController {

    @Autowired
    private EquipmentService equipmentService;

    // 测试用户类
    @GetMapping("/GetEquipment")
    public Result GetEquipment(@RequestBody User user) {
        List<Equipment> Equipments = equipmentService.getEquipment();
        return Result.success(Equipments);
    }

    @PostMapping("/AddEquipment")
    public Result AddEquipment(@RequestHeader("Authorization") String userJWT,
            @RequestBody Equipment equipment) {
        try {
            equipmentService.addEquipment(equipment);
        } catch (Exception e) {
            return Result.error("设备添加失败" + e.getMessage());
        }
        return Result.success("设备添加成功");
    }

    @PostMapping("/SearchEquipment")
    public Result SearchEquipment(@RequestHeader("Authorization") String userJWT,
            @RequestBody Equipment equipment) {
        List<Equipment> equipments;
        try {
            equipments = equipmentService.searchEquipment(equipment);
        } catch (Exception e) {
            return Result.error("设备搜索失败" + e.getMessage());
        }
        return Result.success(equipments);
    }
}

package com.example.software.service;

import java.util.List;

import com.example.software.pojo.Equipment;

/**
 * 用户管理
 */
public interface EquipmentService {


    /**
     * 根据ID查询自己
     * 
     * @param List<Equipment>
     * @return
     */
    List<Equipment> getEquipment();

    // 管理员添加设备
    void addEquipment(Equipment equipment);

    // 搜索设备
    List<Equipment> searchEquipment(Equipment equipment);
}

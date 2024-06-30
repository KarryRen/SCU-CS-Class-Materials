package com.example.software.service.impl;

import com.example.software.mapper.EquipmentMapper;
import com.example.software.pojo.Equipment;
import com.example.software.service.EquipmentService;

import lombok.RequiredArgsConstructor;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.*;

@Service
@RequiredArgsConstructor
public class EquipmentServiceImpl implements EquipmentService {

    @Autowired
    private EquipmentMapper equipmentMapper;

    @Override
    public List<Equipment> getEquipment() {
        return equipmentMapper.getEquipment();
    }

    // 管理员添加设备
    @Override
    public void addEquipment(Equipment equipment) {
        equipmentMapper.addEquipment(equipment.getEquipmentName(), equipment.getEquipmentIntroduction(),
                equipment.getEquipmentBuilding(), equipment.getEquipmentClassroom(), equipment.getEquipmentState());
    }

    // 搜索设备
    @Override
    public List<Equipment> searchEquipment(Equipment equipment) {
        return equipmentMapper.searchEquipment(equipment.getEquipmentName());
    }
}

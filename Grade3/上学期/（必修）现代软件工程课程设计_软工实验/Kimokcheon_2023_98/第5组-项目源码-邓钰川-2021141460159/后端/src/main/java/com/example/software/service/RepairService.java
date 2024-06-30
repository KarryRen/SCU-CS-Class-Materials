package com.example.software.service;

import java.util.List;

import com.example.software.pojo.Repair;

/**
 * 用户管理
 */
public interface RepairService {

    /**
     * 根据ID查询自己
     * 
     * @param List<Repair>
     * @return
     */
    List<Repair> getRepair();

    // 用户查询自己的报修记录
    List<Repair> getSelfRepairs(Repair repair);

    // * 用户添加报修信息
    void addRepair(Repair repair);

    // 管理员查询报修记录
    List<Repair> getRepairs(Repair repair);

    // * 管理员审批修改报修信息
    void updateRepair(Repair repair);
}

package com.example.software.service.impl;

import com.example.software.mapper.RepairMapper;
import com.example.software.pojo.Repair;
import com.example.software.service.RepairService;

import lombok.RequiredArgsConstructor;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.*;

@Service
@RequiredArgsConstructor
public class RepairServiceImpl implements RepairService {

    @Autowired
    private RepairMapper repairMapper;

    @Override
    public List<Repair> getRepair() {
        return repairMapper.getRepair();
    }

    @Override
    public List<Repair> getSelfRepairs(Repair repair) {
        return repairMapper.getSelfRepairs(repair.getUserId());
    }

    @Override
    public void addRepair(Repair repair) {
        repairMapper.addRepair(repair.getUserId(), repair.getRepairReason());
    }

    @Override
    public List<Repair> getRepairs(Repair repair) {
        return repairMapper.getRepairs();
    }

    @Override
    public void updateRepair(Repair repair) {
        repairMapper.updateRepair(repair.getRepairId(), repair.getRepairReply(), repair.getRepairState());
    }
}

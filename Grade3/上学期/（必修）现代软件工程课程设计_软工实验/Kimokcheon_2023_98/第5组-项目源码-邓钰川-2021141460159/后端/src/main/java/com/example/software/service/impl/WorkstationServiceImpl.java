package com.example.software.service.impl;

import com.example.software.mapper.WorkstationMapper;
import com.example.software.pojo.Workstation;
import com.example.software.service.WorkstationService;

import lombok.RequiredArgsConstructor;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
@RequiredArgsConstructor
public class WorkstationServiceImpl implements WorkstationService {

    @Autowired
    private WorkstationMapper workstationMapper;

    @Override
    public List<Workstation> getWorkstation() {
        return workstationMapper.getWorkstation();
    }

    // 管理员添加工位
    @Override
    public void addWorkstation(Workstation workstation) {
        workstationMapper.addWorkstation(workstation.getUserId(), workstation.getWorkstationBuilding(),
                workstation.getWorkstationClassroom(),
                workstation.getWorkstationSeat(), workstation.getWorkstationTime());
    }

    // 管理员绑定工位给指定的用户,也可以取消绑定吧,比如说设置成null,既工位登记/释放
    @Override
    public void bindWorkstation(Workstation workstation) {
        workstationMapper.bindWorkstation(workstation.getWorkstationId(), workstation.getUserId(),
                workstation.getWorkstationState());
    }

    // 管理员更新工位信息
    @Override
    public void updateWorkstation(Workstation workstation) {
        workstationMapper.updateWorkstation(workstation.getWorkstationId(), workstation.getWorkstationBuilding(),
                workstation.getWorkstationClassroom(), workstation.getWorkstationSeat());
    }

    // 管理员删除工位
    @Override
    public void deleteWorkstation(Workstation workstation) {
        workstationMapper.deleteWorkstation(workstation.getWorkstationId());
    }
}

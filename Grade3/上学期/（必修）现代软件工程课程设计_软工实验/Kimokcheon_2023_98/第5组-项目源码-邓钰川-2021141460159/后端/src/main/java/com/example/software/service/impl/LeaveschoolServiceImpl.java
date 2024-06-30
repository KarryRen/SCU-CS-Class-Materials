package com.example.software.service.impl;

import com.example.software.mapper.LeaveschoolMapper;
import com.example.software.pojo.Leaveschool;
import com.example.software.service.LeaveschoolService;

import lombok.RequiredArgsConstructor;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.*;

@Service
@RequiredArgsConstructor
public class LeaveschoolServiceImpl implements LeaveschoolService {

    @Autowired
    private LeaveschoolMapper leaveschoolMapper;

    @Override
    public List<Leaveschool> getLeaveschool() {
        return leaveschoolMapper.getLeaveschool();
    }

    // 用户离校
    @Override
    public void userLeaveschool(Leaveschool leaveschool) {
        leaveschoolMapper.userLeaveschool(leaveschool.getUserId(), leaveschool.getLeaveschoolReason(),
                leaveschool.getLeaveschoolTime(), leaveschool.getLeaveschoolBack());
    }

    // 管理员审核
    @Override
    public void administratorAudit(Leaveschool leaveschool) {
        leaveschoolMapper.administratorAudit(leaveschool.getLeaveschoolId(), leaveschool.getAdminId(),
                leaveschool.getLeaveschoolReply(), leaveschool.getLeaveschoolState());
    }

    // 用户查询离校信息
    @Override
    public List<Leaveschool> userGetLeaveschool(Leaveschool leaveschool) {
        return leaveschoolMapper.userGetLeaveschool(leaveschool.getUserId());
    }

    // 管理员查询离校信息
    @Override
    public List<Leaveschool> administratorGetLeaveschool(Leaveschool leaveschool) {
        return leaveschoolMapper.administratorGetLeaveschool(leaveschool.getLeaveschoolState());
    }
}

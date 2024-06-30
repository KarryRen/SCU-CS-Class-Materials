package com.example.software.service.impl;

import com.example.software.mapper.AskforleaveMapper;
import com.example.software.pojo.Askforleave;
import com.example.software.service.AskforleaveService;

import lombok.RequiredArgsConstructor;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.*;

@Service
@RequiredArgsConstructor
public class AskforleaveServiceImpl implements AskforleaveService {

    @Autowired
    private AskforleaveMapper askforleaveMapper;

    @Override
    public List<Askforleave> getAskforleave(){
        return askforleaveMapper.getAskforleave();
    }

    // 用户请假
    @Override
    public void userAskforleave(Askforleave askforleave){
        askforleaveMapper.userAskforleave(askforleave.getUserId(), askforleave.getAskforleaveReason(), askforleave.getAskforleaveTime(), askforleave.getAskforleaveBack());
    }

    // 管理员审核
    @Override
    public void administratorAudit(Askforleave askforleave){
        askforleaveMapper.administratorAudit(askforleave.getAskforleaveId(), askforleave.getAdminId(), askforleave.getAskforleaveReply(), askforleave.getAskforleaveState());
    }

    // 用户查询请假信息
    @Override
    public List<Askforleave> userGetAskforleave(Askforleave askforleave){
        return askforleaveMapper.userGetAskforleave(askforleave.getUserId());
    }

    // 管理员查询请假信息
    @Override
    public List<Askforleave> administratorGetAskforleave(Askforleave askforleave){
        return askforleaveMapper.administratorGetAskforleave(askforleave.getAskforleaveState());
    }
}

package com.example.software.service;

import java.util.List;

import com.example.software.pojo.Askforleave;

/**
 * 用户管理
 */
public interface AskforleaveService {


    /**
     * 根据ID查询自己
     * 
     * @param List<Askforleave>
     * @return
     */
    List<Askforleave> getAskforleave();

    // 用户请假
    void userAskforleave(Askforleave askforleave);

    // 管理员审核
    void administratorAudit(Askforleave askforleave);

    // 用户查询请假信息
    List<Askforleave> userGetAskforleave(Askforleave askforleave);

    // 管理员查询请假信息
    List<Askforleave> administratorGetAskforleave(Askforleave askforleave);
}

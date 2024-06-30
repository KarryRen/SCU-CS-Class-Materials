package com.example.software.service;

import java.util.List;

import com.example.software.pojo.Leaveschool;

/**
 * 用户管理
 */
public interface LeaveschoolService {

    /**
     * 根据ID查询自己
     * 
     * @param List<Leaveschool>
     * @return
     */
    List<Leaveschool> getLeaveschool();

    // 用户离校
    void userLeaveschool(Leaveschool leaveschool);

    // 管理员审核
    void administratorAudit(Leaveschool leaveschool);

    // 用户查询离校信息
    List<Leaveschool> userGetLeaveschool(Leaveschool leaveschool);

    // 管理员查询离校信息
    List<Leaveschool> administratorGetLeaveschool(Leaveschool leaveschool);

}

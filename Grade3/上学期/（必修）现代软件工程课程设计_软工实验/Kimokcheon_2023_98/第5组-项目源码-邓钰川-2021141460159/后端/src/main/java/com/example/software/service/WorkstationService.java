package com.example.software.service;

import java.util.List;

import com.example.software.pojo.Workstation;

/**
 * 用户管理
 */
public interface WorkstationService {

    /**
     * 根据ID查询自己
     * 
     * @param List<Workstation>
     * @return
     */
    List<Workstation> getWorkstation();

    /**
     * 管理员添加工位
     * 
     * @param workstation
     * @return
     */
    void addWorkstation(Workstation workstation);

    /**
     * 管理员绑定工位给指定的用户,也可以取消绑定吧,比如说设置成null,既工位登记/释放
     * 
     * @param workstation
     * @return
     */
    void bindWorkstation(Workstation workstation);

    /**
     * 管理员更新工位信息
     * 
     * @param workstation
     * @return
     */
    void updateWorkstation(Workstation workstation);

    /**
     * 管理员删除工位
     * 
     * @param workstation
     * @return
     */
    void deleteWorkstation(Workstation workstation);
}

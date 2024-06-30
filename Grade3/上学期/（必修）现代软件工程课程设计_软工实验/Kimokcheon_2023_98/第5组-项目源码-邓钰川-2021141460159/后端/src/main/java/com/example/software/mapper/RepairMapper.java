package com.example.software.mapper;

import com.example.software.pojo.Repair;

import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;

import java.util.List;

/**
 * 员工管理
 */
@Mapper
public interface RepairMapper {
        /**
         * 
         *
         * @return
         */
        @Select("select *from repair")
        List<Repair> getRepair();

        /**
         * 用户查询自己的报修记录
         * @param userId
        */
        @Select("select * from repair where user_id = #{userId}")
        List<Repair> getSelfRepairs(Integer userId);

        /**
         * 用户添加报修信息
         *
         * @return
         */
        @Insert("INSERT INTO repair " +
                        "(user_id, repair_reason) " +
                        "VALUES " +
                        "(#{userId}, #{repairReason})")
        void addRepair(Integer userId, String repairReason);

        /**
         * 管理员查询报修记录
         * @param userId
        */
        @Select("select * from repair where repair_state != 2 and repair_state != -1")
        List<Repair> getRepairs();


        /**
         * 管理员审批修改报修信息
         *
         * @return
         */
        @Update("UPDATE repair SET " +
                        "repair_reply = #{repairReply}, repair_state = #{repairState} " +
                        "WHERE repair_id = #{repairId}")
        void updateRepair(Integer repairId, String repairReply, Integer repairState);

}

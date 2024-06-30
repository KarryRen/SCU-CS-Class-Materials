package com.example.software.mapper;

import com.example.software.pojo.Leaveschool;

import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;

import java.sql.Timestamp;
import java.util.List;

/**
 * 员工管理
 */
@Mapper
public interface LeaveschoolMapper {
        /**
         * 
         *
         * @return
         */
        @Select("select *from leaveschool")
        List<Leaveschool> getLeaveschool();

        /**
         * 用户离校
         *
         * @return
         */
        @Insert("INSERT INTO leaveschool " +
                        "(user_id, leaveschool_reason, leaveschool_time, leaveschool_back) " +
                        "VALUES " +
                        "(#{userId}, #{leaveschoolReason}, #{leaveschoolTime}, #{leaveschoolBack})")
        void userLeaveschool(Integer userId, String leaveschoolReason, Timestamp leaveschoolTime,
                        Timestamp leaveschoolBack);

        /**
         * 管理员审核
         *
         * @return
         */
        @Update("UPDATE leaveschool SET " +
                        "admin_id = #{adminId}, leaveschool_reply = #{leaveschoolReply}, leaveschool_state = #{leaveschoolState} "
                        +
                        "WHERE leaveschool_id = #{leaveschoolId}")
        void administratorAudit(Integer leaveschoolId, Integer adminId, String leaveschoolReply,
                        Integer leaveschoolState);

        /**
         * 用户查询离校信息
         *
         * @return
         */
        @Select("select * from leaveschool where user_id = #{userId}")
        List<Leaveschool> userGetLeaveschool(Integer userId);

        /**
         * 管理员查询离校信息
         *
         * @return
         */
        @Select("select * from leaveschool where leaveschool_state = #{leaveschoolState}")
        List<Leaveschool> administratorGetLeaveschool(Integer leaveschoolState);

}

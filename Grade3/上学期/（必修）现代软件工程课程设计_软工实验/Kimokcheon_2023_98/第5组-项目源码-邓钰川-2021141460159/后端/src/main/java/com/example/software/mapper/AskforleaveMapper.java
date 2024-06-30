package com.example.software.mapper;

import com.example.software.pojo.Askforleave;

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
public interface AskforleaveMapper {
        /**
         * 
         *
         * @return
         */
        @Select("select * from askforleave")
        List<Askforleave> getAskforleave();

        /**
         * 用户请假
         *
         * @return
         */
        @Insert("INSERT INTO askforleave " +
                        "(user_id, askforleave_reason, askforleave_time, askforleave_back) " +
                        "VALUES " +
                        "(#{userId}, #{askforleaveReason}, #{askforleaveTime}, #{askforleaveBack})")
        void userAskforleave(Integer userId, String askforleaveReason, Timestamp askforleaveTime,
                        Timestamp askforleaveBack);

        /**
         * 管理员审核
         *
         * @return
         */
        @Update("UPDATE askforleave SET " +
                        "admin_id = #{adminId}, askforleave_reply = #{askforleaveReply}, askforleave_state = #{askforleaveState} "
                        +
                        "WHERE askforleave_id = #{askforleaveId}")
        void administratorAudit(Integer askforleaveId, Integer adminId, String askforleaveReply,
                        Integer askforleaveState);

        /**
         * 用户查询请假信息
         *
         * @return
         */
        @Select("select * from askforleave where user_id = #{userId}")
        List<Askforleave> userGetAskforleave(Integer userId);

        /**
         * 管理员查询请假信息
         *
         * @return
         */
        @Select("select * from askforleave where askforleave_state = #{askforleaveState}")
        List<Askforleave> administratorGetAskforleave(Integer askforleaveState);

}

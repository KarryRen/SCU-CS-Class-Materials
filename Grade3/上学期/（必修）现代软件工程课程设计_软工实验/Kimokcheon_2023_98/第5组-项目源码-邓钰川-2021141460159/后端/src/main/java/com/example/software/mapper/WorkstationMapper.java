package com.example.software.mapper;

import com.example.software.pojo.Workstation;
import com.example.software.mapper.SQLConstructor.WorkstationSQLConstructor;

import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;
import org.apache.ibatis.annotations.UpdateProvider;
import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Insert;

import java.sql.Timestamp;
import java.util.List;

/**
 * 员工管理
 */
@Mapper
public interface WorkstationMapper {
        /**
         * 
         *
         * @return
         */
        @Select("select *from workstation")
        List<Workstation> getWorkstation();

        /**
         * 管理员添加工位
         *
         * @return
         */
        @Insert("INSERT INTO workstation " +
                        "(user_id, workstation_building, workstation_classroom, workstation_seat, workstation_time) "
                        +
                        "VALUES (#{userId}, #{workstationBuilding}, #{workstationClassroom}, #{workstationSeat}, NOW() )")
        void addWorkstation(Integer userId, String workstationBuilding, String workstationClassroom,
                        Integer workstationSeat, Timestamp workstationTime);

        /**
         * 管理员绑定工位给指定的用户,也可以取消绑定吧,比如说设置成null,既工位登记/释放
         *
         * @return
         */
        @Update("UPDATE workstation" +
                        "SET user_id = #{userId}, workstation_state = #{workstationState}" +
                        "WHERE workstation_id = #{workstationId};")
        void bindWorkstation(Integer workstationId, Integer userId, Integer workstationState);

        /**
         * 管理员更新工位信息
         *
         * @return
         */
        @UpdateProvider(type = WorkstationSQLConstructor.class, method = "updateWorkstation")
        void updateWorkstation(Integer workstationId, String workstationBuilding,
                        String workstationClassroom, Integer workstationSeat);

        /**
         * 管理员删除工位
         *
         * @return
         */
        @Delete("DELETE FROM workstation " +
                        "WHERE workstation_id = #{workstationId}")
        void deleteWorkstation(Integer workstationId);
}

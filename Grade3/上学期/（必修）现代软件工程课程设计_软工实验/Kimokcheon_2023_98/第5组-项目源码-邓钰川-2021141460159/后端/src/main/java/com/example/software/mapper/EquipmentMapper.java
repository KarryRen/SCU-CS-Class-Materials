package com.example.software.mapper;

import com.example.software.pojo.Equipment;

import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * 员工管理
 */
@Mapper
public interface EquipmentMapper {
        /**
         * 
         *
         * @return
         */
        @Select("select *from equipment")
        List<Equipment> getEquipment();

        /**
         * 管理员添加设备
         *
         * @return
         */
        @Insert("INSERT INTO equipment " +
                        "(equipment_name, equipment_introduction, equipment_building, equipment_classroom, equipment_state)"
                        +
                        "VALUES " +
                        "(#{equipmentName}, #{equipmentIntroduction}, #{equipmentBuilding}, #{equipmentClassroom}, #{equipmentState})")
        void addEquipment(String equipmentName, String equipmentIntroduction, String equipmentBuilding,
                        String equipmentClassroom, Integer equipmentState);

        /**
         * 搜索查找设备
         *
         * @return
         */
        @Select("select * from equipment where equipment_name like #{equipmentName}")
        List<Equipment> searchEquipment(@Param("equipmentName") String equipmentName);

}

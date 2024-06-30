package com.example.software.mapper.SQLConstructor;

import org.apache.ibatis.jdbc.SQL;

public class WorkstationSQLConstructor {
    public String updateWorkstation(Integer workstationId, String workstationBuilding,
            String workstationClassroom, Integer workstationSeat) {
        SQL sql = new SQL().UPDATE("workstation");
        if (workstationBuilding != null && !workstationBuilding.isEmpty()) {
            sql.SET("workstation_building = #{workstationBuilding}");
        }
        if (workstationClassroom != null && !workstationClassroom.isEmpty()) {
            sql.SET("workstation_classroom = #{workstationClassroom}");
        }
        if (workstationSeat != null) {
            sql.SET("workstation_seat = #{workstationSeat}");
        }
        sql.WHERE("workstation_id = #{workstationId}");
        return sql.toString();
    }
}

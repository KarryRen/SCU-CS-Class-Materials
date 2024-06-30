package com.example.software.pojo;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;
import java.sql.Timestamp;

/**
 * 用户实体类
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
@Builder
public class Workstation {
    private Integer workstationId;
    private Integer userId;
    private String workstationBuilding;
    private String workstationClassroom;
    private Integer workstationSeat;
    private Timestamp workstationTime;
    private Integer workstationState;
}

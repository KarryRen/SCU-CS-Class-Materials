package com.example.software.pojo;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * 用户实体类
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
@Builder
public class Equipment {
    private Integer equipmentId;
    private String equipmentName;
    private String equipmentIntroduction;
    private String equipmentBuilding;
    private String equipmentClassroom;
    private Integer equipmentState;
}

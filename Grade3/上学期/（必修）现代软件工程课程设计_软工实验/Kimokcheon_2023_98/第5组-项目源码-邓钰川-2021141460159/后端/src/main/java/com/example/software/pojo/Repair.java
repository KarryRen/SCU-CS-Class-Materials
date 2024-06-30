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
public class Repair {
    private Integer repairId;
    private Integer userId;
    private Integer adminId;
    private Integer equipmentId;
    private String repairReason;
    private String repairReply;
    private Integer repairState;
}

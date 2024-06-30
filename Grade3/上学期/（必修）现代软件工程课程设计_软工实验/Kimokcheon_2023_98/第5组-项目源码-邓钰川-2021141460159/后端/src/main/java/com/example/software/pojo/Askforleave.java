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
public class Askforleave {
    private Integer askforleaveId;
    private Integer userId;
    private Integer adminId;
    private String askforleaveReason;
    private Timestamp askforleaveTime;
    private Timestamp askforleaveBack;
    private String askforleaveReply;
    private Integer askforleaveState;
}

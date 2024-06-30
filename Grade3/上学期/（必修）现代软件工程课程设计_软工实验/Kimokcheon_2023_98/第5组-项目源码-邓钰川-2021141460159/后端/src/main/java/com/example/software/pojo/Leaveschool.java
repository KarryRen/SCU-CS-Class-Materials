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
public class Leaveschool {
    private Integer leaveschoolId;
    private Integer userId;
    private Integer adminId;
    private String leaveschoolReason;
    private Timestamp leaveschoolTime;
    private Timestamp leaveschoolBack;
    private String leaveschoolReply;
    private Integer leaveschoolState;
}

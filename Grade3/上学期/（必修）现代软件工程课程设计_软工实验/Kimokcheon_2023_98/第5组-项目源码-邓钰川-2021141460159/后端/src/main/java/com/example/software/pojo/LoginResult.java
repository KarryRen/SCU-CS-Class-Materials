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
public class LoginResult {
    private String jwt;
    private String userName;
    private String userEmail;
    private Integer userId;
    private Integer userPermissions;
}

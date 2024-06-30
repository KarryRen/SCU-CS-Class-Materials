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
public class User {
    private Integer userId;
    private String userName;
    private String userImg;
    private String userLicense;
    private String userPhone;
    private String userEmail;
    private String userSalt;
    private String userPasswd;
    private Integer userPermissions;
}

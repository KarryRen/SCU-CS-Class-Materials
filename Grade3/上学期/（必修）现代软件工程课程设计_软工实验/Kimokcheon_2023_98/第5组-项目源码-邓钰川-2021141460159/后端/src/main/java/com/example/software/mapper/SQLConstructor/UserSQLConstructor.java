package com.example.software.mapper.SQLConstructor;

import org.apache.ibatis.jdbc.SQL;

public class UserSQLConstructor {
    public String updateInformation(Integer userId, String userName, String userLicense,
            String userPhone, String userEmail) {
        SQL sql = new SQL().UPDATE("user");
        if (userName != null && !userName.isEmpty()) {
            sql.SET("user_name = #{userName}");
        }
        if (userLicense != null && !userLicense.isEmpty()) {
            sql.SET("user_license = #{userLicense}");
        }
        if (userPhone != null && !userPhone.isEmpty()) {
            sql.SET("user_phone = #{userPhone}");
        }
        if (userEmail != null && !userEmail.isEmpty()) {
            sql.SET("user_email = #{userEmail}");
        }
        sql.WHERE("user_id = #{userId}");
        return sql.toString();
    }

    public String selectUser(String userName, String userLicense, String userPhone, String userEmail) {
        SQL sql = new SQL().SELECT("*");
        sql.FROM("user");
        userEmail = userPhone = userLicense = userName;
        if (userName != null && !userName.isEmpty()) {
            // sql.WHERE("user_name = #{userName}");
            sql.OR();
            sql.WHERE("user_name like \"%" + userName + "%\"");
        }
        if (userLicense != null && !userLicense.isEmpty()) {
            // sql.WHERE("user_license = #{userLicense}");
            sql.OR();
            sql.WHERE("user_license like \"%" + userLicense + "%\"");
        }
        if (userPhone != null && !userPhone.isEmpty()) {
            // sql.WHERE("user_phone = #{userPhone}");
            sql.OR();
            sql.WHERE("user_phone like \"%" + userPhone + "%\"");
        }
        if (userEmail != null && !userEmail.isEmpty()) {
            // sql.WHERE("user_email = #{userEmail}");
            sql.OR();
            sql.WHERE("user_email like \"%" + userEmail + "%\"");
        }
        return sql.toString();
    }
}

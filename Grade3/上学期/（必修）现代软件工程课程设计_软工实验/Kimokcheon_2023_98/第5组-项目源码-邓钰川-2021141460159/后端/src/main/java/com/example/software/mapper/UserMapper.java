package com.example.software.mapper;

import com.example.software.mapper.SQLConstructor.UserSQLConstructor;
import com.example.software.pojo.User;

import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.SelectProvider;
import org.apache.ibatis.annotations.Update;
import org.apache.ibatis.annotations.UpdateProvider;

import java.util.List;

/**
 * 员工管理
 */
@Mapper
public interface UserMapper {
        /**
         * 测试接口
         *
         * @return
         */
        @Select("select *from user")
        List<User> getUser();

        /**
         * 用户注册
         *
         * @return
         */
        @Insert("INSERT INTO user " +
                        "(user_name, user_license, user_phone, user_email, user_salt, user_passwd) " +
                        "VALUES " +
                        "(#{userName}, #{userLicense}, #{userPhone}, #{userEmail}, #{userSalt}, #{userPasswd})")
        void register(String userName, String userLicense, String userPhone,
                        String userEmail, String userSalt, String userPasswd);

        /**
         * 用户登录
         *
         * @return
         */
        @Select("select * from user where user_email = #{userEmail}")
        User userLogin(String userEmail);

        /**
         * 更新个人信息
         *
         * @return
         */
        @UpdateProvider(type = UserSQLConstructor.class, method = "updateInformation")
        void updateInformation(Integer userId, String userName, String userLicense,
                        String userPhone, String userEmail);

        /**
         * 更新密码
         *
         * @return
         */
        @Update("UPDATE user SET " +
                        "user_salt = #{userSalt}, user_passwd = #{userPasswd}" +
                        "WHERE user_id = #{userId};")
        void updateUserPasswd(Integer userId, String userSalt, String userPasswd);

        /**
         * 管理员查询用户信息
         *
         * @return
         */
        @SelectProvider(type = UserSQLConstructor.class, method = "selectUser")
        List<User> selectUser(String userName, String userLicense, String userPhone, String userEmail);
}

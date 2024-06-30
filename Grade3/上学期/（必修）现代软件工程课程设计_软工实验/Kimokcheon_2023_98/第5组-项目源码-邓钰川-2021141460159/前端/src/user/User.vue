<template>
  <div class="dashboard-container">
    <h2>用户主界面</h2>
    <div class="user-info">
      <p>用户名: {{ userName }}</p>
      <p>邮箱: {{ userEmail }}</p>
      <!-- 更多用户信息 -->
    </div>
    <div class="buttons">
      <button @click="goTo('student/askForLeave')">请假申请</button>
      <button @click="goTo('student/leaveSchool')">离校申请</button>
      <button @click="goTo('student/repair')">设备报修</button>
      <button @click="goTo('student/update')">个人信息修改</button>
      <button @click="goTo('student/updatePasswd')">修改密码</button>
    </div>
  </div>
</template>

<script>
import axios from 'axios';

export default {
  data() {
    return {
      userName : "",
      userEmail : ""
    };
  },
  mounted() {
    this.fetchUserInfo();
  },
  methods: {
    async fetchUserInfo() {
      this.userName = localStorage.getItem("userName")
      this.userEmail = localStorage.getItem("userEmail")
    },
    goTo(routeName) {
      this.$router.push("/" + routeName);
    }
  }
};
</script>

<style>
.dashboard-container {
  max-width: 600px;
  margin: 50px auto;
  padding: 20px;
  box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
  border-radius: 10px;
  text-align: center;
}

.user-info {
  margin-bottom: 20px;
}

.buttons button {
  margin: 10px;
  padding: 10px 20px;
  border: none;
  border-radius: 5px;
  background-color: #007bff;
  color: white;
  cursor: pointer;
}

.buttons button:hover {
  background-color: #0056b3;
}
</style>

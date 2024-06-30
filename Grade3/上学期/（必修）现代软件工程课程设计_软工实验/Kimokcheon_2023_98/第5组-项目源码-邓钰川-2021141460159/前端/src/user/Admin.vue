<template>
  <div class="admin-dashboard-container">
    <h2>管理员主界面</h2>
    <div class="admin-info">
      <p>用户名: {{ userName }}</p>
      <p>邮箱: {{ userEmail }}</p>
      <!-- 更多管理员信息 -->
    </div>
    <div class="buttons">
      <button @click="goTo('admin/askForLeaveAuditAudit')">请假审批界面</button>
      <button @click="goTo('admin/leaveSchoolAudit')">离校审批界面</button>
      <button @click="goTo('admin/repairAudit')">报修审批界面</button>
      <button @click="goTo('admin/userMessage')">用户信息查看搜索</button>
      <button @click="goTo('admin/workStation')">工位管理</button>
    </div>
  </div>
</template>
  
<script>
import axios from 'axios';

export default {
  data() {
    return {
      adminInfo: {},
      userName: "",
      userEmail: ""
    };
  },
  mounted() {
    this.fetchAdminInfo();
  },
  methods: {
    async fetchAdminInfo() {
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
.admin-dashboard-container {
  max-width: 600px;
  margin: 50px auto;
  padding: 20px;
  box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
  border-radius: 10px;
  text-align: center;
}

.admin-info p {
  margin-bottom: 10px;
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
  
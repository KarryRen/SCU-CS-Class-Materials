<template>
  <div class="register-container">
    <h2>注册</h2>
    <form @submit.prevent="register">
      <div class="form-group">
        <label for="userName">用户名:</label>
        <input type="text" id="userName" v-model="user.userName" required>
      </div>
      <div class="form-group">
        <label for="userLicense">证件号:</label>
        <input type="userLicense" id="userLicense" v-model="user.userLicense" required>
      </div>
      <div class="form-group">
        <label for="userPhone">手机号:</label>
        <input type="userPhone" id="userPhone" v-model="user.userPhone" required>
      </div>
      <div class="form-group">
        <label for="userEmail">邮箱:</label>
        <input type="userEmail" id="userEmail" v-model="user.userEmail" required>
      </div>
      <div class="form-group">
        <label for="userPasswd">密码:</label>
        <input type="userPasswd" id="userPasswd" v-model="user.userPasswd" required>
      </div>
      <button type="submit">注册</button>
    </form>
  </div>
</template>

<script>
import axios from 'axios';

export default {
  data() {
    return {
      user: {
        userName: '',
        userLicense : '',
        userPhone : '',
        userEmail: '',
        userPasswd: ''
      }
    };
  },
  methods: {
    async register() {
      try {
        const response = await axios.post('/api/login/Register', this.user);
        if (response.data.code === 1) {
          this.$router.push({ name: '/Login' });
        } else {
          // 处理注册失败逻辑
        }
      } catch (error) {
        console.error(error);
        // 显示错误信息
      }
    }
  }
};
</script>

<style>
.register-container {
  max-width: 400px;
  margin: 50px auto;
  padding: 20px;
  box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
  border-radius: 10px;
  text-align: left;
}

.form-group {
  display: flex;
  align-items: center;
  margin-bottom: 20px;
}

.form-group label {
  flex: 0 0 100px;
  /* 分配固定宽度 */
  margin-right: 10px;
}

input[type="text"],
input[type="userEmail"],
input[type="userPasswd"] {
  flex: 1;
  /* 占用剩余空间 */
  padding: 10px;
  border: 1px solid #ddd;
  border-radius: 5px;
}

button {
  width: 100%;
  padding: 10px;
  margin-top: 10px;
  border: none;
  border-radius: 5px;
  background-color: #007bff;
  color: white;
  cursor: pointer;
}

button:hover {
  background-color: #0056b3;
}

.register-container {
  max-width: 400px;
  margin: 50px auto;
  padding: 20px;
  box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
  border-radius: 10px;
  text-align: center;
}

.form-group {
  margin-bottom: 20px;
}

input[type="text"],
input[type="userEmail"],
input[type="userPasswd"] {
  width: 100%;
  padding: 10px;
  border: 1px solid #ddd;
  border-radius: 5px;
  margin-top: 5px;
}

button {
  width: 100%;
  padding: 10px;
  margin-top: 10px;
  border: none;
  border-radius: 5px;
  background-color: #007bff;
  color: white;
  cursor: pointer;
}

button:hover {
  background-color: #0056b3;
}</style>

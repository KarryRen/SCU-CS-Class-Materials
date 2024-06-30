<template>
  <div class="img">
  <div class="login-container">
    <form @submit.prevent="login">
      <div class="form-group">
        <label for="userEmail">手机号/邮箱:</label>
        <input type="text" id="userEmail" v-model="credentials.userEmail" required>
      </div>
      <div class="form-group">
        <label for="userPasswd">密码:</label>
        <input type="password" id="userPasswd" v-model="credentials.userPasswd" required>
      </div>
      <div>{{ loginError }}</div>
      <button type="submit">登录</button>
      <button type="button" @click="goToRegister">注册</button>
    </form>
  </div>
</div>
</template>

<script>
import axios from 'axios';

export default {
  data() {
    return {
      credentials: {
        userEmail: '',
        userPasswd: ''
      }
    };
  },
  methods: {
    async login() {
      try {
        const response = await axios.post('/api/login/Login', this.credentials);
        if (response.data.code === 1) {
          localStorage.setItem('jwt', response.data.data.jwt);
          localStorage.setItem('userName', response.data.data.userName);
          localStorage.setItem('userEmail', response.data.data.userEmail);
          if (response.data.data.userPermissions === 0) {
            this.$router.push("/User")
          }
          else {
            this.$router.push("/admin")
          }
        } else {
          window.alert(response.data.msg)
          // 处理登录失败的情况
        }
      } catch (error) {
        console.error(error)
        // 处理错误
      }
    },
    goToRegister() {
      // this.$router.push("/User");
      this.$router.push("/register");
    }
  }
};
</script>

<style>
/*.img{
    background-image: url("https://t.mwm.moe/fj");
  background-size: cover;
  background-position: center;
  height: 100%;
}*/
.login-container {
  max-width: 400px;
  margin: 100px auto;
  padding: 20px;
  box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
  border-radius: 8px;
  background-color: #fff;
}

.form-group {
  margin-bottom: 15px;
}

.form-group label {
  display: block;
  margin-bottom: 5px;
}

.form-group input {
  width: 100%;
  padding: 10px;
  border: 1px solid #ddd;
  border-radius: 4px;
  box-sizing: border-box;
}

button {
  width: 100%;
  padding: 10px;
  border: none;
  border-radius: 4px;
  background-color: #007bff;
  color: white;
  cursor: pointer;
}

button:hover {
  background-color: #0056b3;
}
</style>

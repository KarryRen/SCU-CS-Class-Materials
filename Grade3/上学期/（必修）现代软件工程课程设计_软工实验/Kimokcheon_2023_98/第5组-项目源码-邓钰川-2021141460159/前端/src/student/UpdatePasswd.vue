<template>
    <div class="user-info-container">
        <h1>账户密码更新</h1>
        <form @submit.prevent="updateInformation">
            <div class="form-group">
                <label for="userPasswd">原始密码：</label>
                <input type="txt" id="userPasswd" v-model="userInfo.userPasswd" />
            </div>
            <div class="form-group">
                <label for="userPhone">新密码:</label>
                <input type="password" id="userPhone" v-model="userInfo.userPhone" />
            </div>
            <div class="form-group">
                <label for="userLicense">确认：</label>
                <input type="password" id="userLicense" v-model="userInfo.userLicense" />
            </div>
            <button type="submit">更新密码</button>
        </form>
    </div>
</template>
  
<script>
import axios from 'axios';

export default {
    data() {
        return {
            userInfo: {
                userEmail: '',
                userPhone: '',
                userLicense: '',
                userName: ''
            }
        };
    },
    methods: {
        updateInformation() {
            if (this.userInfo.userPhone === this.userInfo.userLicense) {
                this.userInfo.userEmail = localStorage.getItem("userEmail")
                axios.post('/api/user/UpdateUserPasswd', this.userInfo)
                    .then(response => {
                        if (response.data.code === 1){
                            window.alert("密码更新成功")
                            this.$router.push("/User")
                        }
                        else
                            window.alert(response.data.msg)
                        // 可以根据返回的数据做进一步的处理
                    })
                    .catch(error => {
                        window.alert("信息更新失败", error)
                    });
            }
            else {
                window.alert("两次密码不一致")
            }
            this.userInfo = {
                userEmail: '',
                userPhone: '',
                userLicense: '',
                userName: ''
            }
        }
    }
};
</script>
  
<style scoped>
.user-info-container {
    max-width: 400px;
    margin: 0 auto;
    font-family: Arial, sans-serif;
}

.form-group {
    margin-bottom: 20px;
}

label {
    display: block;
    margin-bottom: 5px;
}

input {
    width: 100%;
    padding: 10px;
    font-size: 16px;
    border: 1px solid #ccc;
    border-radius: 5px;
}

button {
    padding: 10px 20px;
    background-color: #4CAF50;
    color: white;
    border: none;
    border-radius: 5px;
    cursor: pointer;
}
</style>
  
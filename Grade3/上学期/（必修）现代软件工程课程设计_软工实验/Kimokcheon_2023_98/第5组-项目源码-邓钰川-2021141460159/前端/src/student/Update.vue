<template>
    <div class="user-info-container">
        <h1>个人信息更新</h1>
        <form @submit.prevent="updateInformation">
            <div class="form-group">
                <label for="userEmail">邮箱：</label>
                <input type="email" id="userEmail" v-model="userInfo.userEmail"  />
            </div>
            <div class="form-group">
                <label for="userPhone">电话：</label>
                <input type="tel" id="userPhone" v-model="userInfo.userPhone"  />
            </div>
            <div class="form-group">
                <label for="userLicense">证件号：</label>
                <input type="text" id="userLicense" v-model="userInfo.userLicense"  />
            </div>
            <div class="form-group">
                <label for="userName">姓名：</label>
                <input type="text" id="userName" v-model="userInfo.userName"  />
            </div>
            <button type="submit">更新信息</button>
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
            axios.post('/api/user/UpdateInformation', this.userInfo)
                .then(response => {
                    window.alert("信息更新成功")
                    // 可以根据返回的数据做进一步的处理
                })
                .catch(error => {
                    window.alert("信息更新失败", error)
                });
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
  
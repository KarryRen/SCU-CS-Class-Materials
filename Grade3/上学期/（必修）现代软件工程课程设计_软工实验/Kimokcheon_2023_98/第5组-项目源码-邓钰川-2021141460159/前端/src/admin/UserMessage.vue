<template>
    <div class="user-message">
        <h1>用户信息</h1>
        <input type="text" v-model="userName" @input="handleSearchInput" @keyup.enter="searchUsers"
            placeholder="请输入需要查询的用户姓名">
        <button @click="confirmSearch">搜索</button>
        <div v-if="users.length > 0">
            <div v-for="(user, index) in users" :key="index" class="user">
                <!-- <h3>{{ user.name }}</h3> -->
                <p>用户ID: {{ user.userId }}</p>
                <p>用户名: {{ user.userName }}</p>
                <p>用户邮箱: {{ user.userEmail }}</p>
                <p>证件号: {{ user.userLicense }}</p>
            </div>
        </div>
        <div v-else>
            <p>不存在该用户</p>
        </div>
    </div>
</template>
  
<script>
import axios from 'axios';

export default {
    data() {
        return {
            users: [],
            userName: ''
        };
    },
    mounted() {
        this.getUsers();
    },
    methods: {
        async getUsers() {
            try {
                const response = await axios.post('/api/user/SelectUser', {
                    userId : 0
                });
                this.users = response.data.data;
            } catch (error) {
                console.error('Failed to fetch user information:', error);
                // 可以在这里处理获取用户信息失败的情况，比如显示错误信息给用户
            }
        },
        handleSearchInput() {
            if (this.searchTimer) {
                clearTimeout(this.searchTimer);
            }
            this.searchTimer = setTimeout(this.searchUsers, 2000);
        },
        async searchUsers() {
            if (this.searchTimer) {
                clearTimeout(this.searchTimer);
            }
            try {
                const response = await axios.post('/api/user/SelectUser', {
                    userName: this.userName
                });
                this.users = response.data.data;
            } catch (error) {
                console.error('Failed to search for users:', error);
                // 可以在这里处理搜索用户信息失败的情况，比如显示错误信息给用户
            }
        },
        confirmSearch() {
            if (this.searchTimer) {
                clearTimeout(this.searchTimer);
            }
            this.searchUsers();
        }
    }
};
</script>
  
<style>
.user-message {
    max-width: 600px;
    margin: 0 auto;
    padding: 20px;
    border: 1px solid #ccc;
    border-radius: 5px;
}

.user {
    margin-bottom: 20px;
    padding: 10px;
    border: 1px solid #eee;
}
</style>
  
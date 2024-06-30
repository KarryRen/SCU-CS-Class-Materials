<template>
    <div class="img">
    <div class="leave-application-container">
        <h2>请假申请</h2>
        <div class="leave-records">
            <h3>我的请假记录</h3>
            <ul>
                <li v-for="record in leaveRecords" :key="record.id">
                    请假原因: {{ record.askforleaveReason }}
                    <br>
                    时间: {{ record.askforleaveTime }} 到 {{ record.askforleaveBack }}
                    <br>
                    管理员回复: {{ record.askforleaveReply }}
                    <br>
                    审批状态: {{ record.askforleaveState }}
                </li>
            </ul>
        </div>
        <form @submit.prevent="submitLeaveRequest">
            <div class="form-group">
                <label for="reason">请假原因:</label>
                <input type="text" id="reason" v-model="newLeaveRequest.askforleaveReason" required>
            </div>
            <div class="form-group">
                <label for="from">开始日期:</label>
                <input type="date" id="from" v-model="newLeaveRequest.askforleaveTime" required>
            </div>
            <div class="form-group">
                <label for="to">结束日期:</label>
                <input type="date" id="to" v-model="newLeaveRequest.askforleaveBack" required>
            </div>
            <button type="submit">提交申请</button>
        </form>
        <button @click="goToDashboard">返回主页面</button>
    </div>
    </div>
</template>

<script>
import axios from 'axios';
// 设置全局的jwt令牌携带
axios.defaults.headers.common['Authorization'] = localStorage.getItem("jwt")

export default {
    data() {
        return {
            leaveRecords: [],
            newLeaveRequest: {
                askforleaveReason: '',
                askforleaveTime: '',
                askforleaveBack: ''
            }
        };
    },
    mounted() {
        this.fetchLeaveRecords();
    },
    methods: {
        async fetchLeaveRecords() {
            try {
                const response = await axios.post('/api/askforleave/UserGetAskforleave', { withCredentials: true });
                if (response.data.code === 1) {
                    for (var i = 0; i < response.data.data.length; i++) {
                        var state = response.data.data[i].askforleaveState
                        if (state === 0){
                            response.data.data[i].askforleaveState = "待审核"
                            response.data.data[i].askforleaveReply = "待审核"
                        }
                        else if (state === -1)
                            response.data.data[i].askforleaveState = "不允许请假"
                        else if (state === 1)
                            response.data.data[i].askforleaveState = "允许请假"
                    }
                    this.leaveRecords = response.data.data;
                }
            } catch (error) {
                console.error(error);
                // 处理错误
            }
        },
        async submitLeaveRequest() {
            try {
                await axios.post('/api/askforleave/UserAskforleave', this.newLeaveRequest, { withCredentials: true });
                // window.alert(response.data.data)
                // 刷新当前界面以更新请假信息
                this.fetchLeaveRecords();
                this.resetForm();
            } catch (error) {
                console.error(error);
                // 显示错误信息
            }
        },
        resetForm() {
            this.newLeaveRequest = { reason: '', from: '', to: '' };
        },
        goToDashboard() {
            this.$router.push("/user");
        }
    }
};
</script>

<style>

.leave-application-container {
    max-width: 600px;
    margin: 50px auto;
    padding: 20px;
    box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
    border-radius: 10px;
    text-align: left;
}

.form-group {
    margin-bottom: 20px;
}

input[type="text"],
input[type="date"] {
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
}

.leave-records ul {
    list-style: none;
    padding: 0;
}

.leave-records li {
    background-color: #f8f8f8;
    padding: 10px;
    margin-bottom: 10px;
    border-radius: 5px;
}

/* 样式调整，使返回按钮与提交按钮视觉上有所区分 */
button[type="submit"] {
    background-color: #28a745;
}

button[type="submit"]:hover {
    background-color: #218838;
}

button:not([type="submit"]) {
    background-color: #6c757d;
    color: white;
}

button:not([type="submit"]):hover {
    background-color: #5a6268;
}
</style>
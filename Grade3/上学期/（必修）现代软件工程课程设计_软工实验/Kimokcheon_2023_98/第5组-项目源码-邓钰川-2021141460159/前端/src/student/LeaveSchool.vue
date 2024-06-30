<template>
    <div class="leave-application-container">
        <h2>离校申请</h2>
        <div class="leave-records">
            <h3>我的离校记录</h3>
            <ul>
                <li v-for="record in leaveRecords" :key="record.id">
                    离校原因: {{ record.leaveschoolReason }}
                    <br>
                    时间: {{ record.leaveschoolTime }} 到 {{ record.leaveschoolBack }}
                    <br>
                    管理员回复: {{ record.leaveschoolReply }}
                    <br>
                    审批状态: {{ record.leaveschoolState }}
                </li>
            </ul>
        </div>
        <form @submit.prevent="submitLeaveRequest">
            <div class="form-group">
                <label for="reason">离校原因:</label>
                <input type="text" id="reason" v-model="newLeaveRequest.leaveschoolReason" required>
            </div>
            <div class="form-group">
                <label for="from">开始日期:</label>
                <input type="date" id="from" v-model="newLeaveRequest.leaveschoolTime" required>
            </div>
            <div class="form-group">
                <label for="to">结束日期:</label>
                <input type="date" id="to" v-model="newLeaveRequest.leaveschoolBack" required>
            </div>
            <button type="submit">提交申请</button>
        </form>
        <button @click="goToDashboard">返回主页面</button>
    </div>
</template>

<script>
import axios from 'axios';
axios.defaults.headers.common['Authorization'] = localStorage.getItem("jwt")

export default {
    data() {
        return {
            leaveRecords: [],
            newLeaveRequest: {
                leaveschoolReason: '',
                leaveschoolTime: '',
                leaveschoolBack: ''
            }
        };
    },
    mounted() {
        this.fetchLeaveRecords();
    },
    methods: {
        async fetchLeaveRecords() {
            try {
                const response = await axios.post('/api/leaveschool/UserGetLeaveschool', { withCredentials: true });
                if (response.data.code === 1) {
                    for (var i = 0; i < response.data.data.length; i++) {
                        var state = response.data.data[i].leaveschoolState
                        if (state === 0) {
                            response.data.data[i].leaveschoolState = "待审核"
                            response.data.data[i].leaveschoolReply = "待审核"
                        }
                        else if (state === -1)
                            response.data.data[i].leaveschoolState = "不允许离校"
                        else if (state === 1)
                            response.data.data[i].leaveschoolState = "允许离校"
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
                await axios.post('/api/leaveschool/UserLeaveschool', this.newLeaveRequest, { withCredentials: true });
                // 刷新当前界面以更新离校信息
                this.fetchLeaveRecords();
                this.resetForm();
            } catch (error) {
                console.error(error);
                // 显示错误信息
            }
        },
        resetForm() {
            this.newLeaveRequest = {
                leaveschoolReason: '',
                leaveschoolTime: '',
                leaveschoolBack: ''
            }
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
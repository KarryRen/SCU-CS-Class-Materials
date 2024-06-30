<template>
    <div class="askforleave-approval-container">
        <h2>请假审批</h2>
        <div v-for="record in askforleaveRequests" :key="record.id" class="request-item">
            用户ID: {{ record.userId }}
            <br>
            请假原因: {{ record.askforleaveReason }}
            <br>
            时间: {{ record.askforleaveTime }} 到 {{ record.askforleaveBack }}
            <br>
            <!-- 审批状态: {{ record.askforleaveState }} -->
            <textarea v-model="record.askforleaveReply" placeholder="审核意见" required></textarea>
            <button @click="approveaskforleave(record, true)">批准请假</button>
            <button @click="approveaskforleave(record, false)">拒绝请假</button>
        </div>
    </div>
</template>
  
<script>
import axios from 'axios';
axios.defaults.headers.common['Authorization'] = localStorage.getItem("jwt")

export default {
    data() {
        return {
            askforleaveRequests: []
        };
    },
    mounted() {
        this.fetchaskforleaveRequests();
    },
    methods: {
        async fetchaskforleaveRequests() {
            try {
                const response = await axios.post('/api/askforleave/AdministratorGetAskforleave', { "askforleaveState": 0 });
                this.askforleaveRequests = response.data.data;
            } catch (error) {
                console.error(error);
                // 处理错误
            }
        },
        async approveaskforleave(request, approvalStatus) {
            if (!request.askforleaveReply) {
                alert('审核意见不能为空');
                return;
            }
            try {
                if (approvalStatus == true) {
                    request.askforleaveState = 1
                }
                else {
                    request.askforleaveState = -1
                }
                const response = await axios.post('/api/askforleave/AdministratorAudit', request);
                if (response.data.code === 1)
                    window.alert("审批成功")
                else
                    window.alert("审批失败")
                this.fetchaskforleaveRequests()
            } catch (error) {
                console.error(error);
            }
        }
    }
};
</script>
  
<style>
.askforleave-approval-container {
    max-width: 600px;
    margin: 50px auto;
    padding: 20px;
    box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
    border-radius: 10px;
    text-align: left;
}

.request-item {
    margin-bottom: 20px;
    padding: 15px;
    border: 1px solid #ddd;
    border-radius: 5px;
}

.request-item textarea {
    width: 100%;
    margin-top: 10px;
    margin-bottom: 10px;
    padding: 10px;
    border: 1px solid #ddd;
    border-radius: 5px;
}

button {
    margin-right: 10px;
    padding: 5px 15px;
    border: none;
    border-radius: 5px;
    cursor: pointer;
}

button:hover {
    opacity: 0.9;
}
</style>
  
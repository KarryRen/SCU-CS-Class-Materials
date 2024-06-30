<template>
    <div class="leaveschool-approval-container">
        <h2>离校审批</h2>
        <div v-for="record in leaveschoolRequests" :key="record.id" class="request-item">
            用户ID: {{ record.userId }}
            <br>
            离校原因: {{ record.leaveschoolReason }}
            <br>
            时间: {{ record.leaveschoolTime }} 到 {{ record.leaveschoolBack }}
            <br>
            <!-- 审批状态: {{ record.leaveschoolState }} -->
            <textarea v-model="record.leaveschoolReply" placeholder="审核意见" class="small-textarea" required></textarea>
            <button @click="approveleaveschool(record, true)">批准离校</button>
            <button @click="approveleaveschool(record, false)">拒绝离校</button>
        </div>
    </div>
</template>
  
<script>
import axios from 'axios';
axios.defaults.headers.common['Authorization'] = localStorage.getItem("jwt")

export default {
    data() {
        return {
            leaveschoolRequests: []
        };
    },
    mounted() {
        this.fetchleaveschoolRequests();
    },
    methods: {
        async fetchleaveschoolRequests() {
            try {
                const response = await axios.post('/api/leaveschool/AdministratorGetLeaveschool', { "leaveschoolState": 0 });
                this.leaveschoolRequests = response.data.data;
            } catch (error) {
                console.error(error);
                // 处理错误
            }
        },
        async approveleaveschool(request, approvalStatus) {
            if (!request.leaveschoolReply) {
                alert('审核意见不能为空');
                return;
            }
            try {
                if (approvalStatus == true) {
                    request.leaveschoolState = 1
                }
                else {
                    request.leaveschoolState = -1
                }
                const response = await axios.post('/api/leaveschool/AdministratorAudit', request);
                if (response.data.code === 1)
                    window.alert("审批成功")
                else
                    window.alert("审批失败")
                this.fetchleaveschoolRequests()
            } catch (error) {
                console.error(error);
            }
        }
    }
};
</script>
  
<style>
/* .small-textarea {
  width: 50px;
  height: 50px;
  resize: none;
} */
.leaveschool-approval-container {
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
  
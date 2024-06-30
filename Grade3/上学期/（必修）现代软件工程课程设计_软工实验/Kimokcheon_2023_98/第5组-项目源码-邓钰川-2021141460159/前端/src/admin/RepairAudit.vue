<template>
    <div class="repair-approval-container">
        <h2>报修审批</h2>
        <div v-for="record in repairRequests" :key="record.id" class="request-item">
            用户ID: {{ record.userId }}
            <br>
            故障现象: {{ record.repairReason }}
            <br>
            审批状态: {{ record.repairState }}
            <textarea v-model="record.repairReply" placeholder="审核意见"></textarea>
            <button @click="approverepair(record, 2)">维修完毕</button>
            <button @click="approverepair(record, 1)">正在维修</button>
            <button @click="approverepair(record, -1)">物品损坏</button>
        </div>
    </div>
</template>
  
<script>
import axios from 'axios';
axios.defaults.headers.common['Authorization'] = localStorage.getItem("jwt")

export default {
    data() {
        return {
            repairRequests: []
        };
    },
    mounted() {
        this.fetchrepairRequests();
    },
    methods: {
        async fetchrepairRequests() {
            try {
                const response = await axios.post('/api/repair/getRepairs', { "repairState": 0 });
                if (response.data.code === 1) {
                    this.repairRequests = response.data.data;
                    var length = this.repairRequests.length
                    for (var i = 0; i < length; i++) {
                        if (this.repairRequests[i].repairState === 0)
                            this.repairRequests[i].repairState = "待审核"
                        else
                            this.repairRequests[i].repairState = "维修中"
                    }
                }
            } catch (error) {
                console.error(error);
                // 处理错误
            }
        },
        async approverepair(request, approvalStatus) {
            if (!request.repairReply) {
                alert('审核意见不能为空');
                return;
            }
            try {
                request.repairState = approvalStatus
                await axios.post('/api/repair/UpdateRepair', request);
                fetchrepairRequests()
            } catch (error) {
                console.error(error);
            }
        }
    }
};
</script>
  
<style>
.repair-approval-container {
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
  
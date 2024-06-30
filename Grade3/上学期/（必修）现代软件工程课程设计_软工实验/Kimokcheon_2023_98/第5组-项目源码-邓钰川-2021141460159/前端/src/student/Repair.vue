<template>
    <div class="repair-application">
        <h1>Repair Service Application</h1>
        <div class="repair-infos">
            <div class="repair-info">
                <ul>
                    <li v-for="repairInfo in repairInfos" :key="repairInfo.id">
                        <!-- 报修id: {{ repairInfo.repairId }} -->
                        <!-- <br> -->
                        故障现象: {{ repairInfo.repairReason }}
                        <br>
                        管理员回复: {{ repairInfo.repairReply }}
                        <br>
                        设备状态: {{ repairInfo.repairState }}
                    </li>
                </ul>
            </div>
        </div>
        <div class="edit-repair">
            <h2>申请设备报修</h2>
            <form @submit.prevent="submitRepair">
            <div class="form-group">
                <label for="device">故障现象:</label>
                <input type="text" id="repairReason" v-model="newRepair.repairReason" required>
            </div>
            <button type="submit">提交申请</button>
        </form>
        </div>
    </div>
</template>
  
<script>
import axios from 'axios';
axios.defaults.headers.common['Authorization'] = localStorage.getItem("jwt")

export default {
    data() {
        return {
            repairInfos: [],
            newRepair: {
                repairReason: ''
            }
        };
    },
    mounted() {
        this.getRepairInfo();
    },
    methods: {
        async getRepairInfo() {
            try {
                const response = await axios.post('/api/repair/getSelfRepairs', { withCredentials: true });
                if (response.data.code === 1) {
                    for (var i = 0; i < response.data.data.length; i++) {
                        var state = response.data.data[i].repairState
                        if (state === 0){
                            response.data.data[i].repairState = "待审核"
                            response.data.data[i].repairReply = "待审核"
                        }
                        else if (state === -1)
                            response.data.data[i].repairState = "设备遭到不可逆转的损害， 停止使用"
                        else if (state === 1)
                            response.data.data[i].repairState = "维修中"
                        else if(state === 2)
                        response.data.data[i].repairState = "修理完成"
                    }
                    this.repairInfos = response.data.data;
                }
                // window.alert(response.data.data)
            } catch (error) {
                console.error('Failed to fetch repair information:', error);
                // 处理获取报修信息失败的情况，比如显示错误信息给用户
            }
        },
        async submitRepair() {
            try {
                await axios.post('/api/repair/AddRepair', this.newRepair);
                // 提交成功后刷新报修信息
                this.getRepairInfo();
                // 清空表单
                this.newRepair = {
                    repairReason: ''
                };
            } catch (error) {
                console.error('Failed to submit repair information:', error);
                // 处理提交报修信息失败的情况，比如显示错误信息给用户
            }
        }
    }
};
</script>
  
<style>
.repair-application {
    max-width: 600px;
    margin: 0 auto;
    padding: 20px;
    border: 1px solid #e0e0e0;
    border-radius: 8px;
    background-color: #f9f9f9;
    box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
    text-align: center;
}

.repair-application h1 {
    font-size: 24px;
    margin-bottom: 20px;
}

.repair-infos {
    max-width: 600px;
    margin: 50px auto;
    padding: 20px;
    box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
    border-radius: 10px;
    text-align: left;
}

.repair-info ul {
    list-style: none;
    padding: 0;
}

.repair-info li {
    background-color: #f8f8f8;
    padding: 10px;
    margin-bottom: 10px;
    border-radius: 5px;
}

.edit-repair {
    margin-bottom: 20px;
}

form {
    display: flex;
    flex-direction: column;
    gap: 10px;
}

label {
    font-weight: bold;
}

input,
textarea,
select {
    padding: 10px;
    border: 1px solid #ccc;
    border-radius: 5px;
}

button {
    padding: 10px 20px;
    background-color: #3498db;
    color: #ffffff;
    border: none;
    border-radius: 5px;
    cursor: pointer;
    transition: background-color 0.3s ease;
}

button:hover {
    background-color: #2980b9;
}
</style>
  
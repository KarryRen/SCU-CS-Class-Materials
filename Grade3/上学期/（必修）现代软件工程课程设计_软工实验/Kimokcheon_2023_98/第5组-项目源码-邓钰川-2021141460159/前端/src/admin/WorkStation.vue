<template>
  <div class="workstation-container">
    <h1>工位管理界面</h1>
    <div class="input-container">
      <input type="text" v-model="newWorkstation.userId" placeholder="用户ID">
      <input type="text" v-model="newWorkstation.workstationBuilding" placeholder="建筑名">
      <input type="text" v-model="newWorkstation.workstationClassroom" placeholder="教室号">
      <input type="text" v-model="newWorkstation.workstationSeat" placeholder="座位号">
      <button @click="addWorkstation">添加工位</button>
    </div>
    <div v-if="workstations.length > 0" class="workstation-list">
      <h2>工位列表</h2>
      <div v-for="workstation in workstations" :key="workstation.id" class="workstation-item">
        <div class="workstation-details">
          <div class="">
            <span class="workstation-id">工位ID: {{ workstation.workstationId }}</span>
            <br>
            用户ID: {{ workstation.userId }}
            <br>
            <span class="workstation-name">位置: {{ workstation.workstationBuilding }}</span>
          </div>
          <div class="workstation-actions">
            <button @click="deleteWorkstation(workstation.workstationId)" class="delete-button">删除</button>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
import axios from 'axios';
axios.defaults.headers.common['Authorization'] = localStorage.getItem("jwt")

export default {
  data() {
    return {
      workstations: [],
      newWorkstation: {
        userId: '',
        workstationBuilding: '',
        workstationClassroom: '',
        workstationSeat: ''
      },
      deleteRequest: {
        "workstationId": 0
      }
    };
  },
  mounted() {
    this.getAllWorkstations(); // 页面加载时自动获取工位信息
  },
  methods: {
    getAllWorkstations() {
      axios.post('/api/workstation/GetWorkstation')
        .then(response => {
          this.workstations = response.data.data;
          var length = response.data.data.length;
          for (var i = 0; i < length; i++) {
            response.data.data[i].workstationBuilding = response.data.data[i].workstationBuilding + " " + response.data.data[i].workstationClassroom + " " + response.data.data[i].workstationSeat + "号";
          }
        })
        .catch(error => {
          console.error('获取工位信息失败', error);
        });
    },
    selectWorkstation(workstationId, userId) {
      // 发送请求选择工位的逻辑
    },
    async deleteWorkstation(workstationId) {
      this.deleteRequest.workstationId = workstationId
      const response = await axios.post('/api/workstation/DeleteWorkstation', this.deleteRequest, { withCredentials: true });
      if (response.data.code === 1) {
        window.alert("删除成功")
      } else {
        window.alert("删除失败")
      }
      this.deleteRequest.workstationId = 0
      this.getAllWorkstations(); // 刷新工位列表
    },
    addWorkstation() {
      axios.post('/api/workstation/AddWorkstation', this.newWorkstation)
        .then(response => {
          if(response.data.code === 1)
            window.alert("添加工位成功")
          else
            window.alert("添加工位失败")
          this.newWorkstation.workstationBuilding = ''; // 清空输入框
          this.newWorkstation.userId = ''; // 清空输入框
          this.workstationClassroom = ''
          this.workstationSeat = ''
          this.getAllWorkstations(); // 刷新工位列表
        })
        .catch(error => {
          window.alert("添加工位失败")
          console.error('添加工位失败', error);
        });
    }
  }
};
</script>

<style scoped>
.workstation-container {
  max-width: 600px;
  margin: 0 auto;
  font-family: Arial, sans-serif;
}

.input-container input {
  margin-bottom: 10px;
  padding: 8px;
  border: 1px solid #ccc;
  border-radius: 5px;
}

.input-container button {
  padding: 10px;
  background-color: #4CAF50;
  color: white;
  border: none;
  border-radius: 5px;
  cursor: pointer;
  margin-bottom: 10px;
}

.workstation-list {
  margin-top: 20px;
}

.workstation-item {
  background-color: #f4f4f4;
  padding: 10px;
  margin-bottom: 10px;
  border-radius: 10px;
  box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
}

.workstation-details {
  display: flex;
  justify-content: space-between;
  align-items: center;
}

.workstation-info {
  display: flex;
  align-items: center;
}

.workstation-id {
  margin-right: 10px;
  font-weight: bold;
}

.workstation-actions button.delete-button {
  padding: 8px 16px;
  background-color: #ff6347;
  color: white;
  border: none;
  border-radius: 5px;
  cursor: pointer;
}
</style>

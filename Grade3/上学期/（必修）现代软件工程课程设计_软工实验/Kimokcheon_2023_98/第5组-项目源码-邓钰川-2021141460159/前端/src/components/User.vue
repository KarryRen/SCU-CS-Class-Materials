<template>
    <div>
        <h2>个人主页</h2>
        <p>欢迎，{{ username }}</p>
        <!-- 其他个人主页内容 -->
    </div>
</template>
  
<script>
export default {
    data() {
        return {
            username: '用户A' // 这里可以根据实际情况从后端获取用户名等信息
        }
    }
}
</script>
  
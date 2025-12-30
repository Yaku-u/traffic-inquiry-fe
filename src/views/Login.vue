<template>
    <div class="container">
        <div class="login-box">
            <div class="title">全国交通查询</div>
        
            <div class="input">
                <el-input v-model="username" style="width: 240px; height: 40px;" placeholder="username" />
            </div>
            <div class="input">
                <el-input v-model="password" style="width: 240px; height: 40px;" type="password" placeholder="password" show-password />
            </div>
            <div class="button">
                <router-link to="/home">
                    <el-button type="primary">Login</el-button>
                </router-link>
            </div>

        </div>
    </div>
</template>

<script lang="ts" setup>
    import { ref } from 'vue'
    const username = ref('')
    const password = ref('')
    

</script>

<style lang="less" scoped>
    @import url('../assets/login.less');
</style>
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
                <el-button type="primary" @click="login">Login</el-button>
            </div>

        </div>
    </div>
</template>

<script lang="ts" setup>
    import { ref } from 'vue'
    import { useRouter } from 'vue-router'
    import { ElMessage } from 'element-plus'
    const username = ref<string>('')
    const password = ref<string>('')
    const router = useRouter()
    
    const login = () => {
        if(!username.value || !password.value){
            ElMessage.error("账号密码不能为空")
            return 
        }

        if(username.value === 'admin' && password.value === '123456'){
            ElMessage.success("管理员登录成功")
            router.push('/admin')
            return 
        }

        if(username.value === 'user' && password.value === '123456'){
            ElMessage.success("用户登录成功")
            router.push('/home')
            return
        }

            ElMessage.error("账号或密码错误")
    }

    

</script>

<style lang="less" scoped>
    @import url('../assets/login.less');
</style>
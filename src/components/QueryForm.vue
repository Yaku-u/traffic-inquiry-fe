<template>
    <div class="main">
        <el-form :model="form" label-width="auto" style="max-width: 500px">
            <el-form-item label="起始城市">
                <el-select v-model="form.fromWhere" />
            </el-form-item>
            <el-form-item label="目的城市">
                <el-select v-model="form.toWhere" />
            </el-form-item>
            <el-form-item label="策略">
                <el-radio-group v-model="form.type">
                    <el-radio value="time">最少时间</el-radio>
                    <el-radio value="cost">最少花费</el-radio>
                    <el-radio value="hub">最少中转</el-radio>
                </el-radio-group>
            </el-form-item>
            <el-form-item>
                <el-button type="primary" @click="">Create</el-button>
                <el-button>Cancel</el-button>
            </el-form-item>
        </el-form>
    </div>

</template>

<script lang="ts" setup>
    import { reactive } from 'vue'

    const form = reactive({
        fromWhere: '',
        toWhere: '',
        type: '',
    })


</script>

<style lang="less" scoped>
    .main {
        width: 600px;
        height: 400px;
        border: 1px solid #d5d5d5;
        border-radius: 10px;
        background-color: #fff;
        display: flex;
        align-items: center;
        justify-content: center;


        & .el-form-item{
            padding: 10px;
        } 

    }
</style>
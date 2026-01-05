<template>
    <div class="main">
        <el-form label-width="auto" style="max-width: 500px">
            <el-form-item label="起始城市">
                <el-select v-model="from">
                    <el-option v-for="c in cities" :key="c.name" :label="c.name" :value="c.name" />
                </el-select>
            </el-form-item>

            <el-form-item label="目的城市">
                <el-select v-model="to">
                    <el-option v-for="c in cities" :key="c.name" :label="c.name" :value="c.name" />
                </el-select>
            </el-form-item>

            <el-form-item label="策略">
                <el-radio-group v-model="strategy">
                    <el-radio value="Fastest">最少时间</el-radio>
                    <el-radio value="Cheapest">最少花费</el-radio>
                    <el-radio value="LessTransfer">最少中转</el-radio>
                </el-radio-group>
            </el-form-item>

            <el-form-item>
                <el-button type="primary" @click="submit" class="create-button">
                    Create
                </el-button>
            </el-form-item>
        </el-form>
    </div>
</template>

<script lang="ts" setup>
    import { ref } from 'vue'
    import { ElMessage } from 'element-plus';

    defineProps<{
        cities: any[]
    }>()

    const emit = defineEmits<{
        (e: 'submit', payload: {
            from: string;
            to: string;
            strategy: 'Fastest' | 'Cheapest' | 'LessTransfer'
        }): void
    }>()

    const from = ref("")
    const to = ref("")
    const strategy = ref<"Fastest" | "Cheapest" | "LessTransfer">("Fastest")

    const submit = () => {
        if (!from.value || !to.value) {
            ElMessage.error("请填写完整信息")
            return
        }

        if(from.value === to.value){
            ElMessage.error("目的城市不能与起始城市相同")
        }

        emit('submit', {
            from: from.value,
            to: to.value,
            strategy: strategy.value,
        })
    }



</script>

<style lang="less" scoped>
    .main {
        width: 700px;
        height: 400px;
        border: 1px solid #d5d5d5;
        border-radius: 5px;
        // background-color: #f9f9f9;
        background-color: #fff;
        display: flex;
        align-items: center;
        justify-content: center;


        & .el-form-item {
            padding: 10px;

            :last-child {
                justify-content: center;
            }
        }


    }
</style>
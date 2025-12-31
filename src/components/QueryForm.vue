<template>
    <div class="main">
        <el-form :model="form" label-width="auto" style="max-width: 500px">
            <el-form-item label="起始城市">
                <el-select v-model="form.fromWhere">
                    <el-option v-for="city in cityList" :key="city" :label="city" :value="city" />
                </el-select>
            </el-form-item>
            <el-form-item label="目的城市">
                <el-select v-model="form.toWhere">
                    <el-option v-for="city in cityList" :key="city" :label="city" :value="city" />
                </el-select>
            </el-form-item>
            <el-form-item label="策略">
                <el-radio-group v-model="form.type">
                    <el-radio value="Fastest">最少时间</el-radio>
                    <el-radio value="Cheapest">最少花费</el-radio>
                    <el-radio value="LessTransfer">最少中转</el-radio>
                </el-radio-group>
            </el-form-item>
            <el-form-item>
                <el-button type="primary" @click="submitQuery" class="create-button">Create</el-button>
                <!-- <el-button>Cancel</el-button> -->
            </el-form-item>
        </el-form>
    </div>

</template>

<script lang="ts" setup>
    import { reactive, ref, onMounted } from 'vue'
    import { ElMessage } from 'element-plus';
    import axios from 'axios';
    import { useTrafficStore } from '../stores/TrafficStore'

    type QueryType = 'Fastest' | 'Cheapest' | 'LessTransfer'

    interface QueryFrom {
        fromWhere: string
        toWhere: string
        type: QueryType
    }

    // interface RouteResult {
    //     num: string,
    //     from: string,
    //     to: string,
    //     startTime: string,
    //     endTime: string,
    //     price: number
    // }

    const trafficStore = useTrafficStore()
    const cityList = ref<string[]>([
        // '北京',
        // '上海',
        // '广州',
        // '深圳',
        // '杭州',
        // '南京',
        // '武汉',
    ])
    // const TableData = ref<RouteResult[]>([])
    const form = reactive<QueryFrom>({
        fromWhere: '',
        toWhere: '',
        type: 'Fastest',
    })

    // 获取城市信息
    onMounted(async () => {
        try {
            const res = await axios.get<string[]>('/api/cities')
            cityList.value = res.data
        } catch (e) {
            console.error('获取城市列表失败')
        }
    })

    //数据模拟
    // function mockQueryRoute(from: string, to: string, type: QueryType): RouteResult[] {
    //     return [
    //         { num: '001', from, to, startTime: '08:00', endTime: '12:00', price: 300 },
    //         { num: '002', from, to, startTime: '09:00', endTime: '13:00', price: 250 },
    //         { num: '003', from, to, startTime: '10:00', endTime: '14:00', price: 200 },
    //     ]
    // }

    async function submitQuery() {
        if (!form.fromWhere || !form.toWhere || !form.type) {
            ElMessage.error("请填写完整信息")
            return
        }

        if (form.fromWhere === form.toWhere) {
            ElMessage.error("始发不能为同一地点")
            return
        }

        try {
            console.log({ ...form });
            await trafficStore.submitQuery({ ...form })

            // TableData.value = res.data // 储存后端返回信息
            // console.log('查询成功')
            // console.log(TableData.value)
        } catch (e) {
            console.error('error:', e)
        }

        // TableData.value = mockQueryRoute(form.fromWhere, form.toWhere, form.type)
        // console.log(TableData.value)
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
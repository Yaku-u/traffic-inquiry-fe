<template>
    <div class="main">
        <el-table :data="tableData" style="max-width: 650px">
            <el-table-column label="班次" prop="num" />
            <el-table-column label="起始城市" prop="from" />
            <el-table-column label="目的城市" prop="to" />
            <el-table-column label="出发时间" prop="startTime" />
            <el-table-column label="到达时间" prop="endTime" />
            <el-table-column label="费用" prop="price" />
            <el-table-column align="right">
                <template #default="scope">
                    <el-button size="small" type="danger" @click="handleDelete(scope.$index)">
                        Delete
                    </el-button>
                </template>
            </el-table-column>
        </el-table>
    </div>

</template>

<script lang="ts" setup>
    import { storeToRefs } from 'pinia'
    import { useTrafficStore } from '../stores/TrafficStore'

    const trafficStore = useTrafficStore()
    const { tableData } = storeToRefs(trafficStore)

    function handleDelete(index: number) {
        console.log('delete row:', index)
    }
</script>


<style lang="less" scoped>
    .main {
        width: 700px;
        height: 400px;
        border: 1px solid #d5d5d5;
        border-radius: 5px;
        background-color: #fff;
        // background-color: #f4f4f4;
        display: flex;
        align-items: center;
        justify-content: center;

        & .el-table {
            // --el-table-tr-bg-color: #f4f4f4;
            // --el-table-header-bg-color: #f4f4f4;
            --el-table-row-hover-bg-color: #e8e8e8;
        }
    }
</style>
<template>
    <div class="main">
        <el-table :data="tableData" style="max-width: 650px" height="260">
            <el-table-column label="班次" prop="num" />
            <el-table-column label="起始城市" prop="fromName" />
            <el-table-column label="目的城市" prop="toName" />
            <el-table-column label="出发时间" prop="startTime" />
            <el-table-column label="到达时间" prop="endTime" />
            <el-table-column label="费用" prop="price" />
        </el-table>
    </div>

</template>

<script lang="ts" setup>
    const props = defineProps<{
        tableData: any[]

    }>()
    
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
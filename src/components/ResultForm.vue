<template>
    <div class="main">
        <el-table :data="rows" style="max-width: 650px" height="260" show-summary :summary-method="summaryMethod">
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
    import { computed } from 'vue'
    const props = defineProps<{
        tableData: any[]
    }>()

    const rows = computed(() => {
        return props.tableData.filter(item => typeof item === 'object')
    })

    const summaryValue = computed(() => {
        return props.tableData.find(item => typeof item === 'number') ?? ''
    })

    const summaryType = computed(() => {
        return props.tableData.find(item => typeof item === 'string') ?? ''
    })

    const summaryMethod = ({ columns }: any) => {
        const sums: (string | number)[] = []

        columns.forEach((column: any, index: number) => {
            if (index === 0) {
                // sums[index] = '统计'
                return
            }

            if (column.property === 'endTime') {
                sums[index] = summaryType.value
            } else if (column.property === 'price') {
                sums[index] = summaryValue.value
            } else {
                sums[index] = ''
            }
        })

        return sums
    }

</script>


<style lang="less" scoped>
    .main {
        width: 700px;
        height: 400px;
        border: var(--border);
        border-radius: 5px;
        background-color: var(--bg-color);
        // background-color: #f4f4f4;
        display: flex;
        align-items: center;
        justify-content: center;

        & .el-table {
            // --el-table-tr-bg-color: #f4f4f4;
            --el-table-row-hover-bg-color: #e8e8e8;
            --el-table-tr-bg-color: none;
            --el-table-bg-color: none;
            --el-table-header-bg-color: none;
        }
    }

    :deep(.el-table__footer-wrapper){
        --el-table-row-hover-bg-color: var(--border);
    }
</style>
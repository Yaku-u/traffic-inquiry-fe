<template>
    <div class="main">
        <el-tabs class="tabs" tab-position="right">
            <el-tab-pane label="城市">
                <el-table :data="cities">
                    <el-table-column label="城市编码" prop="id" />
                    <el-table-column label="城市名称" prop="name" />
                    <el-table-column label="城市简称" prop="code" />
                    <el-table-column>
                        <template #default="scope">
                            <el-button size="small" type="danger" @click="$emit('delete-city', scope.row.name)">
                                Delete
                            </el-button>
                        </template>
                    </el-table-column>
                </el-table>
            </el-tab-pane>


            <el-tab-pane label="路线">
                <el-table :data="routes">
                    <el-table-column label="路线编码" prop="id" />
                    <el-table-column label="起始城市" prop="fromName" />
                    <el-table-column label="目的城市" prop="toName" />
                    <el-table-column label="出发时间" prop="startTime" />
                    <el-table-column label="到达时间" prop="endTime" />
                    <el-table-column label="班次" prop="num" />
                    <el-table-column label="费用" prop="price" />
                    <el-table-column align="right">
                        <template #default="scope">
                            <el-button size="small" type="danger" @click="$emit('delete-route', scope.row.id)">
                                Delete
                            </el-button>
                        </template>
                    </el-table-column>

                </el-table>
            </el-tab-pane>
        </el-tabs>
    </div>

</template>


<script setup lang="ts">
    const props = defineProps<{
        cities: any[],
        routes: any[]
    }>()

</script>


<style scoped lang="less">
    .main {
        border-radius: 5px;
        background-color: #fff;
        width: 100%;
        display: flex;
        align-items: center;
        justify-content: center;

        & .tabs {
            width: 90%;
            height: 95%;


            & .el-table{
                width: 95%;
            }
        }



    }
</style>
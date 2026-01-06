<template>
    <div class="main">
        <el-tabs type="card" class="tabs">
            <el-tab-pane label="add City">

            </el-tab-pane>
            <el-tab-pane label="update City"></el-tab-pane>
            <el-tab-pane label="add Route">
                <el-form label-width="auto" style="max-width: 500px">
                    <el-form-item label="起始城市">
                        <el-input></el-input>
                    </el-form-item>
                    <el-form-item label="目的城市">
                        <el-input></el-input>
                    </el-form-item>
                    <el-form-item label="出发时间">
                        <el-input></el-input>
                    </el-form-item>
                    <el-form-item label="到达时间">
                        <el-input></el-input>
                    </el-form-item>
                    <el-form-item label="班次">
                        <el-input></el-input>
                    </el-form-item>
                    <el-form-item label="费用">
                        <el-input></el-input>
                    </el-form-item>

                    <el-form-item>
                        <el-button type="primary" class="create-button">Add</el-button>
                        <el-button>Cancel</el-button>
                    </el-form-item>
                </el-form>
            </el-tab-pane>
            <el-tab-pane label="update Route"></el-tab-pane>

        </el-tabs>

    </div>
</template>

<script setup lang="ts">
    import { ref } from 'vue'

</script>

<style scoped lang="less">
    .main {
        // width: 600px;
        // height: 570px;
        border: 1px solid #d5d5d5;
        border-radius: 5px;
        background-color: #fff;
        // background-color: #f9f9f9;
        display: flex;
        align-items: center;
        justify-content: center;

        & .tabs {
            // margin: 10px;
            width: 600px;
            height: 650px;

            & .el-tab-pane {
                height: 100%;
                display: flex;
                align-items: center;
                justify-content: center;



                & .el-form-item {
                    padding: 10px;
                }
            }

        }




    }

</style>
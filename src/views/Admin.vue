<template>
    <div class="container">
        <Menu />
        <div class="main">
            <div class="left">
                <ManageForm />
            </div>
            <div class="right">
                <el-tabs v-model="activeName" type="card">
                    <el-tab-pane label="Cities" name="first">
                        <!-- <ResultForm /> -->
                    </el-tab-pane>
                    <el-tab-pane label="Routes" name="second">
                        <!-- <ResultForm /> -->
                    </el-tab-pane>
                </el-tabs>
            </div>
        </div>
    </div>

</template>

<script lang="ts" setup>
    import Menu from '../components/menu.vue'
    import ManageForm from '../components/ManageForm.vue'
    import ResultForm from '../components/ResultForm.vue'
    import { ref } from 'vue'


    const activeName = ref('first')


</script>

<style lang="less" scoped>
    @import url(../assets/admin.less);
</style>>

<template>
    <div class="container">
        <Menu />
        <div class="main">
            <div class="left">
                <ManageForm />
            </div>
            <div class="right">
                <ResultForm />
            </div>
        </div>
    </div>

</template>

<script lang="ts" setup>
    import Menu from '../components/menu.vue'
    import ManageForm from '../components/ManageForm.vue'
    import ResultForm from '../components/ResultForm.vue'
    

</script>

<style lang="less" scoped>
    @import url(../assets/admin.less);
</style>>

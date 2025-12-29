<template>
    <div class="container">
        <Menu/>
        <div class="main">
            <QueryForm/>
        </div>
        <div class="footer"></div>
    </div>
</template>

<script lang="ts" setup>
    import Menu from '../components/menu.vue'
    import QueryForm from '../components/QueryForm.vue'
</script>

<style lang="less" scoped>
    @import url(../assets/home.less);
</style>
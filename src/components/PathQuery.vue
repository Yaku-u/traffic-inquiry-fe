import PathQuery from '@vue/';
<template>
    <div class="container">
        <Menu/>
        <div class="main"></div>
        <div class="footer"></div>
    </div>
</template>

<script setup>
    import Menu from './menu.vue'
</script>

<style lang="less" scoped>
    @import url(../assets/PathQuery.less);
</style>
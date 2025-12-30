<template>
    <div class="container">
        <Menu />
        <div class="main">
            <div class="left">
                <QueryForm class="form"/>
                <ResultForm class="form"/>
            </div>
            <div class="right">
                <TrafficGraph />
            </div>
        </div>
        <div class="footer"></div>
    </div>
</template>

<script lang="ts" setup>
    import Menu from '../components/menu.vue'
    import QueryForm from '../components/QueryForm.vue'
    import ResultForm from '../components/ResultForm.vue'
    import TrafficGraph from '../components/TrafficGraph.vue'
</script>

<style lang="less" scoped>
    @import url(../assets/home.less);
</style>
<template>
    <div class="container">
        <Menu />
        <div class="main">
            <div class="left">
                <QueryForm class="form" :cities="cities" @submit="handleQuery" />
                <ResultForm class="form" :tableData="routes" :showDelete="false" />
            </div>
            <div class="right">
                <TrafficGraph :cities="cities" :routes="allRoutes" :highlightRoutes="routes" />
            </div>
        </div>
    </div>
</template>

<script lang="ts" setup>
    import Menu from '../components/menu.vue'
    import QueryForm from '../components/QueryForm.vue'
    import ResultForm from '../components/ResultForm.vue'
    import TrafficGraph from '../components/TrafficGraph.vue'
    import { ref, onMounted } from 'vue'
    import { getAllCities, getAllRoutes, getFastestPath, getCheapestPath, getLessTransferPath } from '../api/traffic';
    const cities = ref<any[]>([])
    const allRoutes = ref<any[]>([])
    const routes = ref<any[]>([])
    const cityMap = ref<Record<number, string>>({})

    onMounted(async () => {
        cities.value = (await getAllCities())
        // console.log(JSON.stringify(cities.value))

        const map: Record<number, string> = {}
        cities.value.forEach((c: any) => {
            map[c.id] = c.name
        })
        cityMap.value = map

        allRoutes.value = (await getAllRoutes())
        // console.log(JSON.stringify(allRoutes.value))

    })

    const handleQuery = async (payload: {
        from: string
        to: string
        strategy: "Fastest" | "Cheapest" | "LessTransfer"
    }) => {
        let res

        if (payload.strategy === "Fastest") {
            res = await getFastestPath(payload.from, payload.to)
        }
        else if (payload.strategy === "Cheapest") {
            res = await getCheapestPath(payload.from, payload.to)
        }
        else {
            res = await getLessTransferPath(payload.from, payload.to)
        }
        routes.value = res.path.map((item: any) => ({
            ...item,
            fromName: cityMap.value[item.from],
            toName: cityMap.value[item.to]
        }))
        console.log(JSON.stringify(routes.value))
    }



</script>

<style lang="less" scoped>
    @import url(../assets/home.less);
</style>
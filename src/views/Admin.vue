<template>
    <div class="container">
        <Menu />
        <div class="main">
            <div class="left">
                <ManageForm :cities="cities" :routes="routes" @add-city="AddCity" @update-city="UpdateCity"
                    @add-route="AddRoute" @updata-route="UpdateRoute" />
            </div>
            <div class="right">
                <DataTable :cities="cities" :routes="routes" @delete-city="DeleteCity" @delete-route="DeleteRoute" />
            </div>
        </div>
    </div>

</template>

<script lang="ts" setup>
    import { ref, onMounted } from 'vue'
    import Menu from '../components/menu.vue'
    import ManageForm from '../components/ManageForm.vue'
    import DataTable from '../components/DataTable.vue'
    import { getAllCities, getAllRoutes, addCity, updateCity, deleteCity, addRoute, updateRoute, deleteRoute } from '../api/traffic'

    const cities = ref<any[]>([])
    const routes = ref<any[]>([])

    onMounted(async () => {
        cities.value = (await getAllCities())
        console.log(JSON.stringify(cities.value))
        
        const routeRes = (await getAllRoutes())
        const cityMap = new Map<number, string>()
        cities.value.forEach(c => {
            cityMap.set(c.id, c.name)
        })

        routes.value = routeRes.map((item: any) => ({
            ...item,
            fromName: cityMap.get(item.from),
            toName: cityMap.get(item.to)
        }))
    })



    const AddCity = async (city: any) => {
        const res = await addCity(city)
        cities.value.push(res)
    }

    const UpdateCity = async (payload: any) => {
        await updateCity(payload)
        const c = cities.value.find(c => c.id === payload.id)
        if (c) Object.assign(c, payload)
    }

    const DeleteCity = async (index: number) => {
        const city = cities.value[index]
        await deleteCity(city.id)
        cities.value.splice(index, 1)
    }

    const AddRoute = async (route: any) => {
        const res = await addRoute(route)
        routes.value.push(res)
    }

    const UpdateRoute = async (payload: any) => {
        await updateRoute(payload)
        const r = routes.value.find(r => r.id === payload.id)
        if (r) Object.assign(r, payload)
    }

    const DeleteRoute = async (index: number) => {
        const route = routes.value[index]
        await deleteRoute(route.id)
        routes.value.splice(index, 1)
    }


</script>

<style lang="less" scoped>
    @import url(../assets/admin.less);
</style>>

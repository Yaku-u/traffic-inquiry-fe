<template>
    <div class="container">
        <Menu />
        <div class="main">
            <div class="left">
                <ManageForm :cities="cities" :routes="routes" @add-city="AddCity" @update-city="UpdateCity"
                    @add-route="AddRoute" @update-route="UpdateRoute" />
            </div>
            <div class="right">
                <DataTable :cities="cities" :routes="routes" @delete-city="DeleteCity" @delete-route="DeleteRoute" />
            </div>
        </div>
    </div>

</template>

<script lang="ts" setup>
    import { ref, onMounted, TrackOpTypes } from 'vue'
    import Menu from '../components/menu.vue'
    import ManageForm from '../components/ManageForm.vue'
    import DataTable from '../components/DataTable.vue'
    import { getAllCities, getAllRoutes, addCity, updateCity, deleteCity, addRoute, updateRoute, deleteRoute } from '../api/traffic'

    const cities = ref<any[]>([])
    const routes = ref<any[]>([])

    const getRoutes = async() => {
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
        console.log(JSON.stringify(routes.value))
    }


    const fetchAllData = async () => {
        cities.value = (await getAllCities())
        console.log(JSON.stringify(cities.value))
        getRoutes()
    }

    onMounted(fetchAllData)


    const AddCity = async (city: any) => {
        try{
            const req = await addCity(city)
            console.log(JSON.stringify(req))

        }catch(e){
            console.error(e)
        }
        getAllCities()

    }

    const UpdateCity = async (city: any) => {
        try{
            const req = await updateCity(city)
            console.log(JSON.stringify(req))
        }catch(e){
            console.error(e)
        }
        getAllCities()
    }

    const DeleteCity = async (name: string) => {
        cities.value = cities.value.filter(c => c.name !== name)
        try {
            await deleteCity(name)
        } catch (e) {
            console.error(e)
        }
        getAllCities()
    }

    const AddRoute = async (route: any) => {
        try{
            const req = await addRoute(route)
            console.log(JSON.stringify(req))
        }catch(e){
            console.error(e)
        }
        getRoutes()
    }

    const UpdateRoute = async (route: any) => {
        try{
            const req = await updateRoute(route)
            console.log(JSON.stringify(req))
        }catch(e){
            console.error(e)
        }
        getRoutes()
    }

    const DeleteRoute = async (id: number) => {
        routes.value = routes.value.filter(r => r.id !== id)
        try{
            await deleteRoute(id)
        }catch(e){
            console.error(e)
        }
        getRoutes()
    }


</script>

<style lang="less" scoped>
    @import url(../assets/admin.less);
</style>>

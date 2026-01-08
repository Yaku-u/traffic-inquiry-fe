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
    import { ref, onMounted } from 'vue'
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

    const getCities = async() => {
        cities.value = (await getAllCities())
        console.log(JSON.stringify(cities.value))
    }


    onMounted(async() => {
        getCities()
        getRoutes()
    })


    const AddCity = async (city: any) => {
        try{
            await addCity(city)
            getCities()
        }catch(e){
            console.error(e)
        }

    }

    const UpdateCity = async (city: any) => {
        try{
            await updateCity(city)
            getCities()
        }catch(e){
            console.error(e)
        }
    }

    const DeleteCity = async (id: number) => {
        cities.value = cities.value.filter(c => c.id !== id)
        try {
            await deleteCity(id)
            getCities()
        } catch (e) {
            console.error(e)
        }
    }

    const AddRoute = async (route: any) => {
        try{
            await addRoute(route)
            getRoutes()
        }catch(e){
            console.error(e)
        }
    }

    const UpdateRoute = async (route: any) => {
        try{
            await updateRoute(route)
            getRoutes()
        }catch(e){
            console.error(e)
        }
    }

    const DeleteRoute = async (id: number) => {
        routes.value = routes.value.filter(r => r.id !== id)
        try{
            await deleteRoute(id)
            getRoutes()
        }catch(e){
            console.error(e)
        }
    }


</script>

<style lang="less" scoped>
    @import url(../assets/admin.less);
</style>>

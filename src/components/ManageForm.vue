<template>
    <div class="main">
        <el-tabs class="tabs" tab-position="left">

            <el-tab-pane label="添加城市">
                <el-form ref="addCityRef" :model="addCityForm" label-width="auto" style="max-width: 500px">
                    <el-form-item label="城市名称" prop="name">
                        <el-input v-model="addCityForm.name" />
                    </el-form-item>
                    <el-form-item label="城市简称" prop="code">
                        <el-input v-model="addCityForm.code" />
                    </el-form-item>
                    <el-form-item>
                        <el-button type="primary" @click="emit('add-city', addCityForm)"> Add </el-button>
                        <el-button @click="cancelAddCity">Cancel</el-button>
                    </el-form-item>
                </el-form>
            </el-tab-pane>

            <el-tab-pane label="更改城市">
                <el-form ref="updateCityRef" :model="updateCityForm" label-width="auto" style="max-width: 500px">
                    <el-form-item label="原名称" prop="name">
                        <el-input v-model="updateCityForm.name" />
                    </el-form-item>
                    <el-form-item label="新名称" prop="newname">
                        <el-input v-model="updateCityForm.newname" />
                    </el-form-item>
                    <el-form-item label="新简称" prop="newcode">
                        <el-input v-model="updateCityForm.newcode" />
                    </el-form-item>
                    <el-form-item>
                        <el-button type="primary" @click="emit('update-city', updateCityForm)"> Update </el-button>
                        <el-button @click="cancelUpdateCity"> Cancel </el-button>
                    </el-form-item>
                </el-form>
            </el-tab-pane>

            <el-tab-pane label="添加路线">
                <el-form ref="addRouteRef" :model="addRouteForm" label-width="auto" style="max-width: 500px">
                    <el-form-item label="起始城市" prop="from">
                        <el-input v-model="addRouteForm.from" />
                    </el-form-item>
                    <el-form-item label="目的城市" prop="to">
                        <el-input v-model="addRouteForm.to" />
                    </el-form-item>
                    <el-form-item label="出发时间" prop="startTime">
                        <el-input-number v-model="addRouteForm.startTime" :controls="false" align="left" />
                    </el-form-item>
                    <el-form-item label="到达时间" prop="endTime">
                        <el-input-number v-model="addRouteForm.endTime" :controls="false" align="left" />
                    </el-form-item>
                    <el-form-item label="班次" prop="num">
                        <el-input-number v-model="addRouteForm.num" :controls="false" align="left" />
                    </el-form-item>
                    <el-form-item label="费用" prop="price">
                        <el-input-number v-model="addRouteForm.price" :controls="false" align="left" />
                    </el-form-item>
                    <el-form-item>
                        <el-button type="primary" @click="emit('add-route', addRouteForm)"> Add </el-button>
                        <el-button @click="cancelAddRoute"> Cancel </el-button>
                    </el-form-item>
                </el-form>
            </el-tab-pane>

            <el-tab-pane label="更改路线">
                <el-form ref="updateRouteRef" :model="updateRouteForm" label-width="auto" style="max-width: 500px">
                    <el-form-item label="路线编码" prop="id">
                        <el-input-number v-model="updateRouteForm.id" :controls="false" align="left"/>
                    </el-form-item>
                    <el-form-item label="起始城市" prop="from">
                        <el-input v-model="updateRouteForm.from" />
                    </el-form-item>
                    <el-form-item label="目的城市" prop="to">
                        <el-input v-model="updateRouteForm.to" />
                    </el-form-item>
                    <el-form-item label="出发时间" prop="startTime">
                        <el-input-number v-model="updateRouteForm.startTime" :controls="false" align="left"/>
                    </el-form-item>
                    <el-form-item label="到达时间" prop="endTime">
                        <el-input-number v-model="updateRouteForm.endTime" :controls="false" align="left"/>
                    </el-form-item>
                    <el-form-item label="班次" prop="num">
                        <el-input-number v-model="updateRouteForm.num" :controls="false" align="left"/>
                    </el-form-item>
                    <el-form-item label="费用" prop="price">
                        <el-input-number v-model="updateRouteForm.price" :controls="false" align="left"/>
                    </el-form-item>
                    <el-form-item>
                        <el-button type="primary" @click="emit('update-route', updateRouteForm)"> Update </el-button>
                        <el-button @click="cancelUpdateRoute"> Cancel </el-button>
                    </el-form-item>
                </el-form>
            </el-tab-pane>

        </el-tabs>

    </div>
</template>

<script setup lang="ts">

    import { ref, reactive } from 'vue'
    import type { FormInstance } from 'element-plus'

    const addCityRef = ref<FormInstance>()
    const updateCityRef = ref<FormInstance>()
    const addRouteRef = ref<FormInstance>()
    const updateRouteRef = ref<FormInstance>()
    const props = defineProps<{
        cities: any[]
        routes: any[]
    }>()

    const emit = defineEmits([
        'add-city',
        'update-city',
        'add-route',
        'update-route'
    ])

    const addCityForm = reactive({
        name: '',
        code: ''
    })

    const updateCityForm = reactive({
        name: '',
        newname: '',
        newcode: ''
    })

    const addRouteForm = reactive({
        from: '',
        to: '',
        startTime: null,
        endTime: null,
        num: null,
        price: null,
        type: 1
    })

    const updateRouteForm = reactive({
        id: null,
        from: '',
        to: '',
        startTime: null,
        endTime: null,
        num: null,
        price: null,
        type: 1
    })

    const cancelAddCity = () => {
        addCityRef.value?.resetFields()
    }

    const cancelUpdateCity = () => {
        updateCityRef.value?.resetFields()
    }

    const cancelAddRoute = () => {
        addRouteRef.value?.resetFields()
    }

    const cancelUpdateRoute = () => {
        updateRouteRef.value?.resetFields()
    }


</script>

<style scoped lang="less">
    .main {
        border-radius: 5px;
        background-color: var(--bg-color);
        width: 90%;
        display: flex;
        align-items: center;
        justify-content: center;
        // width: 600px;
        // height: 570px;
        // border: 1px solid #d5d5d5;
        // background-color: #f9f9f9;

        & .tabs {
            height: 90%;
            width: 90%;
            // margin: 10px;
            // border: 1px solid #d5d5d5;

            & .el-tab-pane {
                height: 100%;
                display: flex;
                align-items: center;
                justify-content: center;
                // border: 1px solid #d5d5d5;

                & .el-form-item {
                    padding: 10px;

                    & .el-input-number{
                        width: 200px;
                    }

                    :last-child {
                        justify-content: center;
                    }


                }

            }

        }




    }

</style>
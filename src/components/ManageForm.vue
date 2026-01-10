<template>
    <div class="main">
        <el-tabs class="tabs" tab-position="left">

            <el-tab-pane label="添加城市">
                <el-form ref="addCityRef" :model="addCityForm" label-width="auto" style="max-width: 500px"
                    :rules="cityRules">
                    <el-form-item label="城市名称" prop="name">
                        <el-input v-model="addCityForm.name" />
                    </el-form-item>
                    <el-form-item label="城市简称" prop="code">
                        <el-input v-model="addCityForm.code" />
                    </el-form-item>
                    <el-form-item class="btn">
                        <el-button type="primary" @click="submitAddCity"> Add </el-button>
                        <el-button @click="cancelAddCity">Cancel</el-button>
                    </el-form-item>
                </el-form>
            </el-tab-pane>

            <el-tab-pane label="更改城市">
                <el-form ref="updateCityRef" :model="updateCityForm" label-width="auto" style="max-width: 500px"
                    :rules="updateCityRules">
                    <el-form-item label="原名称" prop="name">
                        <el-input v-model="updateCityForm.name" />
                    </el-form-item>
                    <el-form-item label="新名称" prop="newname">
                        <el-input v-model="updateCityForm.newname" />
                    </el-form-item>
                    <el-form-item label="新简称" prop="newcode">
                        <el-input v-model="updateCityForm.newcode" />
                    </el-form-item>
                    <el-form-item class="btn">
                        <el-button type="primary" @click="submitUpdateCity"> Update </el-button>
                        <el-button @click="cancelUpdateCity"> Cancel </el-button>
                    </el-form-item>
                </el-form>
            </el-tab-pane>

            <el-tab-pane label="添加路线">
                <el-form ref="addRouteRef" :model="addRouteForm" label-width="auto" style="max-width: 500px"
                    :rules="routeRules">
                    <el-form-item label="起始城市" prop="from">
                        <el-input v-model="addRouteForm.from" />
                    </el-form-item>
                    <el-form-item label="目的城市" prop="to">
                        <el-input v-model="addRouteForm.to" />
                    </el-form-item>
                    <el-form-item label="出发时间" prop="startTime">
                        <el-time-picker v-model="addRouteForm.startTime" value-format="HH:mm" format="HH:mm" />
                    </el-form-item>
                    <el-form-item label="到达时间" prop="endTime">
                        <el-time-picker v-model="addRouteForm.endTime" value-format="HH:mm" format="HH:mm" />
                    </el-form-item>
                    <el-form-item label="班次" prop="num">
                        <el-input v-model="addRouteForm.num" />
                    </el-form-item>
                    <el-form-item label="费用" prop="price">
                        <el-input-number v-model="addRouteForm.price" :controls="false" align="left" />
                    </el-form-item>
                    <el-form-item class="btn">
                        <el-button type="primary" @click="submitAddRoute"> Add </el-button>
                        <el-button @click="cancelAddRoute"> Cancel </el-button>
                    </el-form-item>
                </el-form>
            </el-tab-pane>

            <el-tab-pane label="更改路线">
                <el-form ref="updateRouteRef" :model="updateRouteForm" label-width="auto" style="max-width: 500px"
                    :rules="updateRouteRules">
                    <el-form-item label="路线编码" prop="id">
                        <el-input-number v-model="updateRouteForm.id" :controls="false" align="left" />
                    </el-form-item>
                    <el-form-item label="起始城市" prop="from">
                        <el-input v-model="updateRouteForm.from" />
                    </el-form-item>
                    <el-form-item label="目的城市" prop="to">
                        <el-input v-model="updateRouteForm.to" />
                    </el-form-item>
                    <el-form-item label="出发时间" prop="startTime">
                        <el-time-picker v-model="updateRouteForm.startTime" value-format="HH:mm" format="HH:mm" />
                    </el-form-item>
                    <el-form-item label="到达时间" prop="endTime">
                        <el-time-picker v-model="updateRouteForm.endTime" value-format="HH:mm" format="HH:mm" />
                    </el-form-item>
                    <el-form-item label="班次" prop="num">
                        <el-input v-model="updateRouteForm.num" />
                    </el-form-item>
                    <el-form-item label="费用" prop="price">
                        <el-input-number v-model="updateRouteForm.price" :controls="false" align="left" />
                    </el-form-item>
                    <el-form-item class="btn">
                        <el-button type="primary" @click="submitUpdateRoute"> Update </el-button>
                        <el-button @click="cancelUpdateRoute"> Cancel </el-button>
                    </el-form-item>
                </el-form>
            </el-tab-pane>

        </el-tabs>

    </div>
</template>

<script setup lang="ts">
    import { ElMessage } from 'element-plus'
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
        startTime: '',
        endTime: '',
        num: '',
        price: null,
        type: 1
    })

    const updateRouteForm = reactive({
        id: null,
        from: '',
        to: '',
        startTime: '',
        endTime: '',
        num: '',
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

    const cityRules = {
        name: [{ required: true, message: '', trigger: 'change' }],
        code: [{ required: true, message: '', trigger: 'change' }]
    }

    const updateCityRules = {
        name: [{ required: true, message: '', trigger: 'change' }],
        newname: [{ required: true, message: '', trigger: 'change' }],
        newcode: [{ required: true, message: '', trigger: 'change' }]
    }

    const routeRules = {
        from: [{ required: true, message: '', trigger: 'change' }],
        to: [{ required: true, message: '', trigger: 'change' }],
        startTime: [{ required: true, message: '', trigger: 'change' }],
        endTime: [{ required: true, message: '', trigger: 'change' }],
        num: [{ required: true, message: '', trigger: 'change' }],
        price: [{ required: true, message: '', trigger: 'change' }]
    }

    const updateRouteRules = {
        id: [{ required: true, message: '', trigger: 'change' }],
        ...routeRules
    }

    const submitAddCity = () => {
        addCityRef.value?.validate((valid) => {
            if (!valid) {
                ElMessage.error('请填写完整信息')
                return
            }
            emit('add-city', addCityForm)
        })
    }

    const submitUpdateCity = () => {
        updateCityRef.value?.validate((valid) => {
            if (!valid) {
                ElMessage.error('请填写完整信息')
                return
            }
            emit('update-city', updateCityForm)
        })
    }

    const submitAddRoute = () => {
        addRouteRef.value?.validate((valid) => {
            if (!valid) {
                ElMessage.error('请填写完整信息')
                return
            }
            emit('add-route', addRouteForm)
        })
    }

    const submitUpdateRoute = () => {
        updateRouteRef.value?.validate((valid) => {
            if (!valid) {
                ElMessage.error('请填写完整信息')
                return
            }
            emit('update-route', updateRouteForm)
        })
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

        & .tabs {
            height: 90%;
            width: 90%;

            & .el-tab-pane {
                height: 100%;
                display: flex;
                align-items: center;
                justify-content: center;

                & .el-form-item {
                    padding-top: 20px;
                }
            }
        }
    }

    .el-input-number {
        width: 220px;
    }



</style>
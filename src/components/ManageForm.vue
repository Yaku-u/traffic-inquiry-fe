<template>
    <div class="main">
        <el-tabs class="tabs" tab-position="left">

            <el-tab-pane label="添加城市">
                <el-form label-width="auto" style="max-width: 500px">
                    <el-form-item label="城市名称">
                        <el-input v-model="addCityForm.name" />
                    </el-form-item>
                    <el-form-item label="城市简称">
                        <el-input v-model="addCityForm.code" />
                    </el-form-item>
                    <el-form-item>
                        <el-button type="primary" @click="emit('add-city', addCityForm)"> Add </el-button>
                        <el-button>Cancel</el-button>
                    </el-form-item>
                </el-form>
            </el-tab-pane>

            <el-tab-pane label="更改城市">
                <el-form label-width="auto" style="max-width: 500px">
                    <el-form-item label="原名称">
                        <el-input v-model="updateCityForm.name" />
                    </el-form-item>
                    <el-form-item label="新名称">
                        <el-input v-model="updateCityForm.newname" />
                    </el-form-item>
                    <el-form-item label="新简称">
                        <el-input />
                    </el-form-item>
                    <el-form-item>
                        <el-button type="primary"> Update </el-button>
                        <el-button>Cancel</el-button>
                    </el-form-item>
                </el-form>
            </el-tab-pane>

            <el-tab-pane label="添加路线">
                <el-form label-width="auto" style="max-width: 500px">
                    <el-form-item label="起始城市">
                        <el-input v-model="addRouteForm.from"/>
                    </el-form-item>
                    <el-form-item label="目的城市">
                        <el-input v-model="addRouteForm.to"/>
                    </el-form-item>
                    <el-form-item label="出发时间">
                        <el-input v-model="addRouteForm.startTime"/>
                    </el-form-item>
                    <el-form-item label="到达时间">
                        <el-input v-model="addRouteForm.endTime"/>
                    </el-form-item>
                    <el-form-item label="班次">
                        <el-input v-model="addRouteForm.num"/>
                    </el-form-item>
                    <el-form-item label="费用">
                        <el-input v-model="addRouteForm.price"/>
                    </el-form-item>
                    <el-form-item>
                        <el-button type="primary" class="create-button">Add</el-button>
                        <el-button>Cancel</el-button>
                    </el-form-item>
                </el-form>
            </el-tab-pane>

            <el-tab-pane label="更改路线">
                <el-form label-width="auto" style="max-width: 500px">
                    <el-form-item label="路线编码">
                        <el-input />
                    </el-form-item>
                    <el-form-item label="起始城市">
                        <el-input />
                    </el-form-item>
                    <el-form-item label="目的城市">
                        <el-input />
                    </el-form-item>
                    <el-form-item label="出发时间">
                        <el-input />
                    </el-form-item>
                    <el-form-item label="到达时间">
                        <el-input />
                    </el-form-item>
                    <el-form-item label="班次">
                        <el-input />
                    </el-form-item>
                    <el-form-item label="费用">
                        <el-input />
                    </el-form-item>
                    <el-form-item>
                        <el-button type="primary" class="create-button">Add</el-button>
                        <el-button>Cancel</el-button>
                    </el-form-item>
                </el-form>
            </el-tab-pane>

        </el-tabs>

    </div>
</template>

<script setup lang="ts">
    import { ref } from 'vue'

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

    const addCityForm = ref({
        name: '',
        code: ''
    })

    const updateCityForm = ref({
        name: '',
        newname: '',
        code: ''
    })

    const addRouteForm = ref({
        from: '',
        to: '',
        startTime: '',
        endTime: '',
        num: '',
        price: '',
        type: 1
    })


</script>

<style scoped lang="less">
    .main {
        border-radius: 5px;
        background-color: #fff;
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
            // margin: 10px;
            width: 600px;
            // border: 1px solid #d5d5d5;


            & .el-tab-pane {
                height: 100%;
                display: flex;
                align-items: center;
                justify-content: center;
                // border: 1px solid #d5d5d5;




                & .el-form-item {
                    padding: 10px;


                    :last-child {
                        justify-content: center;
                    }
                }
            }

        }




    }

</style>
import { defineStore } from 'pinia'
import { queryTraffic } from '../api/traffic'

export const useTrafficStore = defineStore('traffic', {
    state: () => ({
        loading: false,
        queryParams: null as any,
        tableData: [] as any[],
        chartData: [] as any[],
    }),

    actions: {
        async submitQuery(params: any) {
            this.loading = true
            this.queryParams = params

            const res = await queryTraffic(params)

            // 假设后端返回结构
            // { tableData: [...], chartData: [...] }
            this.tableData = res.tableData
            this.chartData = res.chartData

            this.loading = false
        }
    }
})

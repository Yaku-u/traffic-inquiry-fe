<template>
    <div ref="chartRef" class="chart"></div>
</template>

<script setup lang="ts">
    import { ref, onMounted, onBeforeUnmount } from 'vue'
    import type { ECharts, EChartsOption } from 'echarts'
    import * as echarts from 'echarts'

    const chartRef = ref<HTMLDivElement | null>(null)

    let chart: ECharts | null = null

    interface TrafficNode {
        id: string
        name: string
        symbolSize: number
    }


    interface TrafficLink {
        source: string
        target: string
        value: number 
        transport: string 
        label?: {
            show: boolean
            formatter?: string
        }
        lineStyle?: {
            color?: string
            type?: 'solid' | 'dashed'
        }
    }



    const nodes: TrafficNode[] = [
        { id: 'beijing', name: '北京', symbolSize: 60 },
        { id: 'shanghai', name: '上海', symbolSize: 60 },
        { id: 'guangdong', name: '广东', symbolSize: 60 },
        { id: 'qingdao', name: '青岛', symbolSize: 40 }
    ]

    const links: TrafficLink[] = [
        {
            source: 'beijing',
            target: 'jinan',
            value: 90, 
            transport: '高铁',
            label: {
                show: true,
                formatter: '高铁 1.5h'
            },
            lineStyle: { color: '#5470C6' }
        },
        {
            source: 'beijing',
            target: 'shanghai',
            value: 120,
            transport: '飞机',
            label: {
                show: true,
                formatter: '飞机 2h'
            },
            lineStyle: { color: '#EE6666', type: 'dashed' }
        }
    ]


    const option: EChartsOption = {
    
        tooltip: {
            formatter: (params: any) => {
                if (params.dataType === 'edge') {
                    return `路线信息：${params.value}`
                }
                return params.name
            }
        },
        series: [
            {
                type: 'graph',
                layout: 'force',
                roam: true,
                label: {
                    show: true
                },
                force: {
                    repulsion: 300,
                    edgeLength: 150
                },
                data: nodes,
                links: links
            }
        ]
    }


    onMounted(() => {
        if (!chartRef.value) return

        chart = echarts.init(chartRef.value)
        chart.setOption(option)

        window.addEventListener('resize', resizeChart)
    })

    onBeforeUnmount(() => {
        window.removeEventListener('resize', resizeChart)
        chart?.dispose()
    })

    function resizeChart() {
        chart?.resize()
    }
</script>

<style scoped lang="less">
    .chart {
        width: 800px;
        height: 800px;
        border: 1px solid #d5d5d5;
        border-radius: 5px;
        // background-color: #f4f4f4;
        background-color: #fff;
    }
</style>

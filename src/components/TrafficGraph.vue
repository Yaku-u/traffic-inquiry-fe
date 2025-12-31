<template>
    <div ref="chartRef" class="chart"></div>
</template>

<script setup lang="ts">
    import { ref, onMounted, onBeforeUnmount, watch } from 'vue'
    import * as echarts from 'echarts'
    import type { ECharts, EChartsOption } from 'echarts'
    import { useTrafficStore } from '../stores/TrafficStore'
    import { storeToRefs } from 'pinia'

    const trafficStore = useTrafficStore()
    const { tableData } = storeToRefs(trafficStore)

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
        label: {
            show: boolean
            formatter: string
        }
        lineStyle?: {
            color?: string
            type?: 'solid' | 'dashed'
        }
    }

    function generateGraphData(tableData: any[]) {
        const nodeMap = new Map<string, TrafficNode>()
        const links: TrafficLink[] = []

        tableData.forEach((route: any) => {
            // 添加起点和终点节点
            if (!nodeMap.has(route.from)) nodeMap.set(route.from, { id: route.from, name: route.from, symbolSize: 60 })
            if (!nodeMap.has(route.to)) nodeMap.set(route.to, { id: route.to, name: route.to, symbolSize: 60 })

            // 计算行程时间（小时数）
            const start = route.startTime.split(':').map(Number)
            const end = route.endTime.split(':').map(Number)
            let duration = (end[0] + end[1] / 60) - (start[0] + start[1] / 60)
            if (duration < 0) duration += 24 // 跨天处理
            duration = Math.round(duration * 10) / 10

            links.push({
                source: route.from,
                target: route.to,
                value: route.price,
                transport: route.type, 
                label: {
                    show: true,
                    formatter: `${route.type} ${duration}h`
                },
                lineStyle: {
                    color: route.type === 'Fastest' ? '#5470C6' : '#EE6666',
                    type: route.type === 'LessTransfer' ? 'dashed' : 'solid'
                }
            })
        })

        return {
            nodes: Array.from(nodeMap.values()),
            links
        }
    }

    function renderChart() {
        if (!chartRef.value) return
        if (!chart) chart = echarts.init(chartRef.value)

        const { nodes, links } = generateGraphData(tableData.value)

        const option: EChartsOption = {
            tooltip: {
                formatter: (params: any) => {
                    if (params.dataType === 'edge') {
                        return `路线：${params.source} → ${params.target}，费用：${params.value}`
                    }
                    return params.name
                }
            },
            series: [
                {
                    type: 'graph',
                    layout: 'force',
                    roam: true,
                    label: { show: true },
                    force: {
                        repulsion: 300,
                        edgeLength: 150
                    },
                    data: nodes,
                    links
                }
            ]
        }

        chart.setOption(option)
    }

    onMounted(() => {
        renderChart()
        window.addEventListener('resize', resizeChart)
    })

    // 数据变化时自动更新图表
    watch(tableData, () => {
        renderChart()
    }, { deep: true })

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
        background-color: #fff;
    }
</style>

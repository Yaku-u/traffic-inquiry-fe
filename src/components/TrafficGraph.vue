<template>
    <div ref="chartRef" class="chart"></div>
</template>

<script setup lang="ts">
    import { ref, onMounted, watch } from "vue"
    import * as echarts from "echarts"

    const props = defineProps<{
        cities: any[]
        routes: any[]
        highlightRoutes: any[]
    }>()

    const chartRef = ref<HTMLDivElement | null>(null)
    let chart: echarts.ECharts | null = null

    onMounted(() => {
        chart = echarts.init(chartRef.value!)
        render()
    })

    watch(
        () => [props.routes, props.highlightRoutes],
        () => {
            render()
        },
        { deep: true }
    )

    const render = () => {
        if (!chart) return


        const nodes = props.cities.map(c => ({
            id: String(c.id),
            name: c.name,

            symbolSize: 60,
            itemStyle: {
                color: "#409EFF"
            },
            label: {
                show: true
            }
        }))
        
        const isDark = () => {
            return document.documentElement.classList.contains('dark')
        }

        const normalLinks = props.routes.map(r => ({
            source: String(r.from),
            target: String(r.to),
            // label: {
            //     show: true
            // },
            lineStyle: {
                color: isDark()? '#777': '#ccc',
                width: 2,
                opacity: 0.7,
                curveness: 0.2
            }
        }))



        const highlightLinks = props.highlightRoutes.map(r => ({
            source: String(r.from),
            target: String(r.to),
            lineStyle: {
                color: isDark()? '#ddd': '#777',
                width: 2.5,
                opacity: 1,
                curveness: 0.2
            }
        }))

        chart.setOption({
            tooltip: {},
            series: [
                {
                    type: "graph",
                    layout: "force",
                    roam: true,
                    edgeSymbol: ['circle', 'arrow'],
                    edgeSymbolSize: [4, 8],

                    data: nodes,
                    links: [...normalLinks, ...highlightLinks],

                    force: {
                        repulsion: 1000,
                        edgeLength: [120, 230],
                        friction: 0.6
                    },

                    emphasis: {
                        focus: "adjacency"
                    }
                }
            ]
        })
    }
</script>

<style scoped lang="less">
    .chart {
        width: 800px;
        height: 800px;
        border: var(--border);
        border-radius: 5px;
        // background-color: #f4f4f4;
        background-color: var(--bg-color);
    }
</style>

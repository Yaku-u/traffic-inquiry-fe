import type { RouteRecordRaw } from 'vue-router'

const homeRoutes: RouteRecordRaw[] = [
    {
        path: '/home',
        name: 'Home',
        component: () => import('@/views/Home.vue'),
        meta: {
            requiresAuth: true,
            role: 'user'
        }
    }
]

export default homeRoutes

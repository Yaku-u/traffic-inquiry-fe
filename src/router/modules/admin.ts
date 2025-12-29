import type { RouteRecordRaw } from 'vue-router'

const adminRoutes: RouteRecordRaw[] = [
    {
        path: '/admin',
        name: 'Admin',
        component: () => import('@/views/Admin.vue'),
        meta: {
            requiresAuth: true,
            role: 'admin'
        }
    }
]

export default adminRoutes

import type { RouteRecordRaw } from "vue-router"

const loginRoutes: RouteRecordRaw[] = [
    {
        path: '/login',
        name: 'Login',
        component: () => import('@/views/Login.vue'),
        
    }
]

export default loginRoutes
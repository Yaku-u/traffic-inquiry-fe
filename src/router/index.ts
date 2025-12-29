import { createRouter, createWebHistory } from 'vue-router'
import type { RouteRecordRaw } from 'vue-router'

import loginRoutes from './modules/login'
import homeRoutes from './modules/home'
import adminRoutes from './modules/admin'

const routes: RouteRecordRaw[] = [
    {
        path: '/',
        redirect: '/login'
    },
    ...loginRoutes,
    ...homeRoutes,
    ...adminRoutes
]

const router = createRouter({
    history: createWebHistory(),
    routes
})

export default router
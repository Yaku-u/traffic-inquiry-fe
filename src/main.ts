import { createApp } from 'vue'
import './style.less'
import App from './App.vue'
import router from './router'
import { createPinia } from 'pinia'
import 'element-plus/theme-chalk/el-message.css'


createApp(App)
    .use(router)
    .use(createPinia())
    .mount('#app')

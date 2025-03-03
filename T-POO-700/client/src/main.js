import { createApp } from 'vue'
import Toast from "vue-toastification";
import "vue-toastification/dist/index.css";
import './styles/style.scss'
import './styles/input.scss'
import './styles/container.scss'
import App from './App.vue'
import router from "./router/index.js";
import 'vuetify/styles'
import { createVuetify } from 'vuetify'
import * as components from 'vuetify/components'
import * as directives from 'vuetify/directives'

const vuetify = createVuetify({
    components,
    directives,
})

const app = createApp(App)
app.use(router) // Utilise le routeur
app.use(vuetify) // Utilise le routeur
app.use(Toast, {
    transition: "Vue-Toastification__bounce",
    maxToasts: 20,
    newestOnTop: true
});

app.mount('#app')

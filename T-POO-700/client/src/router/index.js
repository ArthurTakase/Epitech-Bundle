import { createRouter, createWebHistory } from 'vue-router'
import ChartManager from "../components/ChartManager.vue";
import ClockManager from "../components/ClockManager.vue";
import User from "../components/User.vue";
import WorkingTime from "../components/WorkingTime.vue";
import WorkingTimes from "../components/WorkingTimes.vue";
import HomePage from "../components/HomePage.vue";
import ManagerPage from "../components/ManagerPage.vue";
import TeamsPage from "../components/TeamsPage.vue";
import axios from "axios";

const router = createRouter({
  history: createWebHistory(),
  routes: [
    {path: "/", component: HomePage, meta: { isAuth: false, isManager: false }},
    {path: "/index.html", component: HomePage, meta: { isAuth: false, isManager: false }},
    {path: "/account", component: User, meta : { isAuth: true, isManager: false }},
    {path: "/manager", component: ManagerPage, meta : { isAuth: true, isManager: true }},
    {path: "/user/:userid", component: User, meta : { isAuth: true, isManager: true }},
    {path: "/chartManager", component: ChartManager, meta : { isAuth: true, isManager: true }},
    {path: "/chartManager/:userid", component: ChartManager, meta : { isAuth: true, isManager: true }},
    {path: "/clock/:username", component: ClockManager, meta : { isAuth: true, isManager: false }},
    {path: "/clock", component: ClockManager, meta : { isAuth: true, isManager: false }},
    {path: "/workingTimes", component: WorkingTimes, meta : { isAuth: true, isManager: true }},
    {path: "/workingTimes/:userid", component: WorkingTimes, meta : { isAuth: true, isManager: true }},
    {path: "/workingTime/:userid/:id", component: WorkingTime, meta : { isAuth: true, isManager: true }},
    {path: "/workingTime/:userid", component: WorkingTime, meta : { isAuth: true, isManager: true }},
    {path: "/teams", component: TeamsPage, meta : { isAuth: true, isManager: false }},
  ]
})

router.beforeEach(async (to, from, next) => {
  const isAuth = to.meta.isAuth;
  const isManager = to.meta.isManager;

  if (isAuth && !localStorage.getItem("token")) return next('/');

  if (isManager) {
    const headers = { 'Authorization': `Bearer ${localStorage.getItem("token")}` }
    try {
      const url = import.meta.env.DEV ? "http://localhost:4000" : "http://time-manager.labbtech.fr:4000"
      const response = await axios.get(url + "/api/user/", { headers });
      localStorage.setItem('user_role', response.data.data.user_role)
      localStorage.setItem('user_id', response.data.data.id ?? response.data.data.user_id)
      localStorage.setItem('username', response.data.data.username)
      if (response.data.role < 2) return next(-1);
      return next();
    } catch (error) {
      return next('/');
    }
  }


  next();
})

export default router;

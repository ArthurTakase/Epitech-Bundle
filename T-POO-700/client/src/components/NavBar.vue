<script>
import SvgIcon from '@jamescoyle/vue-icon';
import { mdiTimerPlusOutline } from '@mdi/js';
import Login from './Login.vue'

export default {
  name: "NavBar",
  components: {
    SvgIcon,
    Login
  },
  data() {
    return {
      path: mdiTimerPlusOutline,
      token: localStorage.getItem('token'),
      isManager: parseInt(localStorage.getItem('user_role')) > 1,
      username: localStorage.getItem('username')
    }
  }
}

console.log(window.location)

if (window.location.pathname === "/index.html")
  window.location.href = "/"

</script>

<template>
  <div class="nav-main">
    <div class="nav-logo" :status="token ? 'true' : 'false'">
      <div class="nav-button-container relative">
        <button @click="() => { this.$router.push('/') }" class="btn-no-style">
          <svg-icon class="nav-icon" type="mdi" :path="path"></svg-icon>
        </button>
        <Login style="height: 100%;" />
      </div>
    </div>
    <div v-if="token" class="nav-container">
      <div class="nav-button-container overflow">
        <button v-if="token" @click="() => { this.$router.go(-1) }"><i class='bx bx-left-arrow-alt'></i></button>
        <button v-if="token" @click="() => { this.$router.push(`/clock`) }">Clock</button>
        <button v-if="token" @click="() => { this.$router.push('/workingTimes') }">Working Times</button>
        <button v-if="token" @click="() => { this.$router.push('/chartManager') }">DashBoard</button>
        <button v-if="token" @click="() => { this.$router.push('/teams') }">Teams</button>
        <button v-if="isManager" @click="() => { this.$router.push('/manager') }">Manage Teams</button>
        <button v-if="token" @click="() => { this.$router.push('/account') }">Account</button>
      </div>
    </div>
  </div>
</template>

<style scoped>
.nav-logo {
  height: 50px;
  background-color: #ffffff;
  color: black;
  padding-left: 15px;
  &[status="false"] {
    background-color: #2b7bd7;
    color: white;
    .btn-no-style {
      color: white !important;
    }
  }
  &[status="true"] .btn-no-style {
    background: none !important;
    border: none !important;
    margin-left: -10px;
  }
  .nav-button-container {
    justify-content: space-between;
  }
}

.nav-container {
  height: 50px;
  background-color: #2b7bd7;
  color: white;
}

.nav-button-container {
  height: 100%;
  display: flex;
  justify-content: flex-start;
  align-items: center;
  a, button {
    display: flex;
    justify-content: center;
    align-items: center;
    height: 100%;
    color: white;
    padding: 0 10px;
    border-radius: 0;
    border-right: solid 1px rgba(0, 0, 0, 0.05);
    &:first-child {
      background-color: #2167b8;
    }
    &:hover {
      background: rgba(0, 0, 0, 0.078);
    }
  }
  &.overflow {
    overflow-y: scroll;
    /* hide navbar */
    scrollbar-width: none;
    -ms-overflow-style: none;
    &::-webkit-scrollbar {
      display: none;
    }

    a, button {
      white-space: nowrap;
      text-overflow: ellipsis;
      padding-left: 10px;
      padding-right: 10px;
    }
  }
}

.nav-button-container svg {
  font-weight: bold;
  margin: auto 0 auto 0;
}

.btn-no-style {
  background: none !important;
  color: black !important;
  border: none !important;
  margin-left: -10px;
}
</style>

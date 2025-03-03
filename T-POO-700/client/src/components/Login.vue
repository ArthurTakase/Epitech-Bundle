<script>
import axios from 'axios'
import User from './User.vue'
import { useToast } from 'vue-toastification'

export default {
  name: "Login",
  components: {},
  computed: {},
  methods: {
    async login(email, password) {
      const body = { email: email, password: password }
        let response;
        try {
        response = await axios.post(`${import.meta.env.DEV ? "http://localhost:4000" : "http://time-manager.labbtech.fr:4000"}/auth/login`, body)
      } catch (error) {
        useToast().error(`Can't login to your account. ${error.message}`, { timeout: 4000 });
        return
      }
      localStorage.setItem('token', response.data.data.token)
      localStorage.setItem('user_role', response.data.data.user_role)
      localStorage.setItem('user_id', response.data.data.id ?? response.data.data.user_id)
      localStorage.setItem('username', response.data.data.username)
      localStorage.setItem('user', JSON.stringify(response.data.data))
      window.location.reload()
    },
    async register(username, email, password) {
      const isGood = await User.methods.createUser(username, email, password)
      if (isGood) await this.login(email, password)
    },
    disconnect() {
      localStorage.removeItem('token')
      localStorage.removeItem('user_role')
      localStorage.removeItem('user_id')
      localStorage.removeItem('username')
      window.location.href = '/'
    },
    open(id) {
      const container = document.querySelector('.login-panel')
      const div = document.querySelector(`#${id}`)
      container.style.display = "flex"
      div.style.display = "flex"
    },
    close(id) {
      const container = document.querySelector('.login-panel')
      const div = document.querySelector(`#${id}`)
      container.style.display = "none"
      div.style.display = "none"
    }
  },
  data() {
    return {
      token: localStorage.getItem('token'),
      url: window.location.href,
      email: '',
      password: '',
      email_r: '',
      password_r: '',
      username_r: ''
    }
  }
}
</script>

<template>
  <div v-if="token">
    <div class="btn-panel">
      <button @click="disconnect">Disconnect </button>
    </div>
  </div>
  <div v-else>

    <div class="btn-panel">
      <button @click="() => {
        close('register-container')
        open('login-container')
      }">Login</button>
      <button @click="() => {
        close('login-container')
        open('register-container')
      }">Register</button>
    </div>

    <div class="login-panel" style="display: none;">

      <div id="login-container" class="container w-300 unset-h">
        <p class="title">Connect to your account</p>
        <button class="close" @click="() => { close('login-container') }">✖</button>
        <input label="email" placeholder="Email" v-model="email" />
        <input label="password" placeholder="Password" type="password" v-model="password" />
        <div class="btn-container">
          <button class="big-btn" @click="() => { login(email, password) }">Login</button>
        </div>
      </div>

      <div id="register-container" class="container w-300 unset-h">
        <p class="title">Create an account</p>
        <button class="close" @click="() => { close('register-container') }">✖</button>
        <input label="username" placeholder="Username" v-model="username_r" />
        <input label="email" placeholder="Email" v-model="email_r" />
        <input label="password" placeholder="Password" type="password" v-model="password_r" />
        <div class="btn-container">
          <button class="big-btn" @click="() => { register(username_r, email_r, password_r ) }">Register</button>
        </div>
      </div>

    </div>
  </div>
</template>

<style scoped>

@keyframes from_top {
  from {
    opacity: 0;
    transform: translateY(-20px);
  }
  to {
    opacity: 1;
    transform: translateY(0);
  }
}

.btn-panel {
  display: flex;
  justify-content: flex-end;
  height: 100%;
  button {
    border-radius: 0;
    height: 100%;
    &:hover {
      background: rgba(0, 0, 0, 0.078);
    }
  }
}

.login-panel {
  position: absolute;
  top: 0;
  right: 0;
  width: 100%;
  height: 100%;
  background: rgba(0, 0, 0, 0.5);
  backdrop-filter: blur(10px);
  display: flex;
  justify-content: center;
  align-items: center;
  z-index: 2;
  .container {
    padding-top: 1.5rem;
    background: white;
    display: flex;
    flex-direction: column;
    position: relative;
    animation: from_top 0.5s ease-in-out;
    border-radius: 10px;
    box-shadow: 0 0 10px 0 rgba(0,0,0,0.2);
    width: 300px;
  }
}

.title {
  font-weight: bold;
  margin: 0 10px 0 10px;
  padding-bottom: 1rem;
  color: #2b7bd7;
}

.btn-container {
  padding: 10px;
  padding-top: 20px;
}

.big-btn {
  background: #2b7bd7;
  color: white;
  border-radius: 10px;
  padding: 5px 10px;
  max-width: fit-content;
  box-shadow: 0 0 10px 0 rgba(0,0,0,0.2);
  transition: scale 0.2s ease-in-out;
  &:hover {
    scale: 1.1;
  }
}

.login-panel {
  .container .close {
    position: absolute;
    top: -.5rem;
    right: -.5rem;
    opacity: 0.2;
    color: #2b7bd7;
  }
  input {
    margin: 0 10px 0 10px;
    color: black;
    border: none;
    border-bottom: 1px solid rgb(212, 212, 212);
    padding: .5rem;
    &::placeholder {
      color: black;
    }
  }
}
</style>

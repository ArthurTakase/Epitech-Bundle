<!--
– used to identify the current user ;
– must be present on all pages of your web application ;
– must implement the following methods (with self-explanatory names):
  - createUser() ;
  - updateUser() ;
  - getUser() ;
  - deleteUser().
-->

<script>
import axios from 'axios'
import { useToast } from 'vue-toastification'

export default {
  name: "User",
  methods: {
    async createUser(username, email, password) {
      const body = { user: { email: email, password: password, username: username } }
      try {
        await axios.post(`${import.meta.env.DEV ? "http://localhost:4000" : "http://time-manager.labbtech.fr:4000"}/api/users`, body)
        useToast().success(`User ${username} created`, { timeout: 4000 });
        return true
      } catch (error) {
        useToast().error(`Can't create user. ${error.message}`, { timeout: 4000 });
        return false
      }
    },
    async updateUser(id, data) {
      const token = localStorage.getItem('token')
      if (!token) {
        this.$router.push('/')
        return
      }

      const header = { headers: { 'Authorization': 'Bearer ' + token } }
      const body = { user: data }
      try {
        await axios.put(`${import.meta.env.DEV ? "http://localhost:4000" : "http://time-manager.labbtech.fr:4000"}/api/users/${id}`, body, header)
      } catch (error) {
        useToast().error(`Can't update user ${id}. ${error.message}`, { timeout: 4000 });
        return false
      }
      useToast().success(`User ${id} updated`, { timeout: 4000 });

      if (id == localStorage.getItem('user_id')) {
        data.username ? localStorage.setItem('username', data.username) : null
        data.email ? localStorage.setItem('email', data.email) : null
        data.user_role ? localStorage.setItem('user_role', data.user_role) : null
        window.location.reload()
      }

      return true
    },
    async getUser(id) {
      const token = localStorage.getItem('token')
      if (!token) {
        window.location.href = '/'
        return
      }

      const header = { headers: { Authorization: `Bearer ${token}` } }
      try {
        const response = await axios.get(`${import.meta.env.DEV ? "http://localhost:4000" : "http://time-manager.labbtech.fr:4000"}/api/users/${id}`, header)
        return response.data.data
      } catch (error) {
        useToast().error(`Can't get user ${id}. ${error.message}`, { timeout: 4000 });
        return false
      }
    },
    async getAllUsers() {
      const token = localStorage.getItem('token')
      if (!token) {
        window.location.href = '/'
        return
      }

      const header = { headers: { Authorization: `Bearer ${token}` } }
      try {
        const response = await axios.get(`${import.meta.env.DEV ? "http://localhost:4000" : "http://time-manager.labbtech.fr:4000"}/api/all_users`, header)
        return response.data.data
      } catch (error) {
        useToast().error(`Can't get users. ${error.message}`, { timeout: 4000 });
        return false
      }
    },
    async getAllUsersFromTeams(userID) {
      const token = localStorage.getItem('token')
      if (!token) {
        window.location.href = '/'
        return
      }

      const header = { headers: { Authorization: `Bearer ${token}` } }
      try {
        const response = await axios.get(`${import.meta.env.DEV ? "http://localhost:4000" : "http://time-manager.labbtech.fr:4000"}/api/teams/${userID}`, header)
        return response.data.data
      } catch (error) {
        useToast().error(`Can't get users. ${error.message}`, { timeout: 4000 });
        return false
      }
    },
    async deleteUser(id) {
      const token = localStorage.getItem('token')
      if (!token) {
        this.$router.push('/')
        return
      }

      const header = { headers: { 'Authorization': 'Bearer ' + token } }
      try {
        await axios.delete(`${import.meta.env.DEV ? "http://localhost:4000" : "http://time-manager.labbtech.fr:4000"}/api/users/${id}`, header)
        useToast().success(`User ${id} removed`, { timeout: 4000 });
        return true
      } catch (error) {
        useToast().error(`Can't remove user ${id}. ${error.message}`, { timeout: 4000 });
        return false
      }
    },
    toggleEditMode() {
      const inputs = document.querySelectorAll('#userInfos input[canEdit="true"]')
      inputs.forEach(input => input.disabled = !input.disabled)
      const saveUser = document.querySelector('#saveUser')
      saveUser.style.display = saveUser.style.display === 'none' ? 'block' : 'none'
    },
    async saveEdit(event) {
      event.target.disabled = true
      var teams = Array.isArray(this.user.teams)
            ? this.user.teams
            : this.user.teams.split(',').map(team => parseInt(team))
      teams = teams.filter(team => !isNaN(team))
      const isGood = await this.updateUser(
        this.user.id,
        {
          username: this.user.username,
          email: this.user.email,
          user_role: this.user.user_role,
          teams: teams
        }
      )

      if (!isGood) {
        event.target.disabled = false
        return
      }

      const inputs = document.querySelectorAll('#userInfos input[canEdit="true"]')
      const saveUser = document.querySelector('#saveUser')
      inputs.forEach(input => input.disabled = !input.disabled)
      saveUser.style.display = 'none'
      event.target.disabled = false
    },
    async deleteUserBtn(event) {
      event.target.disabled = true
      const isGood = await this.deleteUser(this.user.id)
      
      if (!isGood) {
        event.target.disabled = false
        return
      }

      if (this.user.id == localStorage.getItem('user_id')) {
        localStorage.removeItem("token")
        localStorage.removeItem("user_role")
        localStorage.removeItem("user_id")
        window.location.href = '/'
        return
      }

      this.$router.go(-1)
    }
  },
  data() {
    return {
      token: localStorage.getItem('token'),
      url: window.location.href,
      user: {},
      user_id: this.$route.params.userid,
      can_remove: false,
      isManager: false,
      isSuperManager: false,
      canEditName: false
    }
  },
  async mounted() {
    if (this.user_id && this.user_id != localStorage.getItem('user_id')) {
      if (localStorage.getItem('user_role') === '1') {
        this.$router.go(-1)
        useToast().error(`You can't view this page`, { timeout: 4000 });
        return
      }
    }

    const id = this.user_id ? this.user_id : localStorage.getItem('user_id')
    this.user = await this.getUser(id);

    this.isManager = parseInt(localStorage.getItem('user_role')) > 1
    this.isSuperManager = parseInt(localStorage.getItem('user_role')) == 3
    this.can_remove = parseInt(localStorage.getItem('user_role')) == 3
      || id == localStorage.getItem('user_id')
    this.canEditName = !this.isManager || id == localStorage.getItem('user_id')
  }
}
</script>

<template>
  <div v-if="user" class="container little-container">
    <h1>Informations</h1>
    <div id="userInfos" class="container-body">
      <div class="inputField">
        <label for="username">Username</label>
        <input :canEdit="canEditName" type="text" v-model="user.username" placeholder="Username" disabled />
      </div>
      <div class="inputField">
        <label for="email">Email</label>
        <input :canEdit="canEditName" type="text" v-model="user.email" placeholder="Email" disabled />
      </div>
      <div class="inputField">
        <label for="user_role">Role</label>
        <input :canEdit="isSuperManager" type="text" v-model="user.user_role" placeholder="Role" disabled />
      </div>
      <div class="inputField">
        <label for="teams">Teams</label>
        <input :canEdit="isManager" type="text" v-model="user.teams" placeholder="Teams (int, int...)" disabled />
      </div>
      <div class="btn-zone">
        <button @click="saveEdit" id="saveUser" class="big-btn green" style="display: none;">Save <i class='bx bx-save'></i></button>
        <button  @click="toggleEditMode" class="big-btn">Edit <i class='bx bx-edit' ></i></button>
      </div>
    </div>
  </div>
  <div v-if="user" style="position: absolute; bottom: 10px; right: 10px;">
    <button @click="deleteUserBtn" v-if="can_remove" class="big-btn red">Delete account <i class='bx bxs-trash'></i></button>
  </div>
</template>

<style scoped>

#userInfos {
  flex-direction: column;
}


</style>

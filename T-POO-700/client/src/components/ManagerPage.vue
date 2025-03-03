<script>
import { useToast } from 'vue-toastification'
import axios from 'axios'

export default {
  name: "ManagerPage",
  components: {},
  computed: {},
  methods: {
    async updateTeams() {
      const token = localStorage.getItem('token')
      if (!token) return false

      const header = { headers: { Authorization: `Bearer ${token}` } }
      try {
        const url = '/api/teams'
        const response = await axios.get(`${import.meta.env.DEV ? "http://localhost:4000" : "http://time-manager.labbtech.fr:4000"}${url}`, header)
        this.teams = response.data.data
        return true
      } catch (error) {
        useToast().error(`Can't get teams. ${error.message}`, { timeout: 4000 });
        return false
      }
    },
    async createTeam(event) {
      if (!this.teamName || !this.managerMail) return false

      if (event) event.target.disabled = false

      const body = { team: { name: this.teamName, manager_email: this.managerMail } }
      const token = localStorage.getItem('token')
      if (!token) return false
      const header = { headers: { Authorization: `Bearer ${token}` } }
      try {
        await axios.post(`${import.meta.env.DEV ? "http://localhost:4000" : "http://time-manager.labbtech.fr:4000"}/api/teams`, body, header)
        useToast().success(`Team '${this.teamName}' created'`, { timeout: 4000 });
        await this.updateTeams()
        this.managerMail = ""
        this.teamName = ""
        if (event) event.target.disabled = false
        return true
      } catch (error) {
        useToast().error(`Can't create team. ${error.message}`, { timeout: 4000 });
        if (event) event.target.disabled = false
        return false
      }
    },
    async removeTeam(teamToRemove, event) {
      if (!teamToRemove) return false

      if (event) event.target.disabled = true

      const token = localStorage.getItem('token')
      if (!token) {
        if (event) event.target.disabled = false
        return false
      }

      const header = { headers: { Authorization: `Bearer ${token}` } }
      try {
        await axios.delete(`${import.meta.env.DEV ? "http://localhost:4000" : "http://time-manager.labbtech.fr:4000"}/api/teams/${teamToRemove.id}`, header)
        useToast().success(`Team '${teamToRemove.name}' removed'`, { timeout: 4000 });
        await this.updateTeams()
        if (event) event.target.disabled = false
        return true
      } catch (error) {
        useToast().error(`Can't remove team. ${error.message}`, { timeout: 4000 });
        if (event) event.target.disabled = false
        return false
      }
    },
    async addUserToTeam(event) {
      if (!this.userEmail || !this.teamToAddUser) return false
      
      const body = { email: this.userEmail }
      const token = localStorage.getItem('token')
      if (!token) return false      
      if (event) event.target.disabled = true
      
      try {
        const header = { headers: { Authorization: `Bearer ${token}` } }
        await axios.put(`${import.meta.env.DEV ? "http://localhost:4000" : "http://time-manager.labbtech.fr:4000"}/api//user_teams/${this.teamToAddUser}`, body, header)
        useToast().success(`User '${this.userEmail}' added to team '${this.teamToAddUser}'`, { timeout: 4000 });
        if (event) event.target.disabled = false
        this.userEmail = ""
        this.teamToAddUser = ""
        return true
      } catch (error) {
        useToast().error(`Can't add user to team. ${error.message}`, { timeout: 4000 });
        if (event) event.target.disabled = false
        return false
      }
    }
  },
  data() {
    return {
      token: localStorage.getItem('token'),
      url: window.location.href,
      teams: [],
      teamName: "",
      managerMail: "",
      userEmail: "",
      teamToAddUser: "",
      isManager: false,
      isSuperManager: false,
      userRole : parseInt(localStorage.getItem('user_role')),
      userId: localStorage.getItem('user_id'),
    }
  },
  async mounted() {
    this.isManager = this.userRole > 1
    this.isSuperManager = this.userRole > 2
  if (!this.updateTeams()) this.$router.go(-1)
  }
}
</script>

<template>

<div v-if="isSuperManager" class="container mid-container">
  <h1>Create a new team</h1>
  <div class="container-body row">
    <div class="inputField">
      <label for="email">Name</label>
      <input type="text" v-model="teamName" placeholder="Team name" />
    </div>
    <div class="inputField">
      <label for="email">Manager's email</label>
      <input type="text" v-model="managerMail" placeholder="Email" />
    </div>
  </div>
  <div class="btn-zone top-1rem">
    <button @click="createTeam" class="big-btn"><i class='bx bx-plus' ></i></button>
  </div>
</div>

<div class="container mid-container">
  <h1>Add user to teams</h1>
  <div class="container-body row">
    <div class="inputField">
      <label for="email">Email</label>
      <input type="text" v-model="userEmail" placeholder="User mail" />
    </div>
    <div class="inputField">
      <label for="email">Team</label>
      <select v-model="teamToAddUser">
        <option v-for="team in teams" :value="team.id">{{ team.name }}</option>
      </select>
    </div>
  </div>
  <div class="btn-zone top-1rem">
    <button @click="addUserToTeam" class="big-btn"><i class='bx bx-plus' ></i></button>
  </div>
</div>

<!-- /user_teams/:id -->

<div v-if="teams.length" class="container">
  <h1>Teams</h1>
  <div v-for="team in teams" class="box relative team">
    <div class="inputField">
      <label for="email">Name</label>
      <input type="text" v-model="team.name" placeholder="Team name" disabled />
    </div>
    <br>
    <div class="inputField">
      <label for="email">ID</label>
      <input type="text" v-model="team.id" placeholder="Team ID" disabled />
    </div>
    <div class="btn-zone" v-if="isSuperManager">
      <button @click="() => { removeTeam(team) }" class="big-btn red"><i class='bx bxs-trash'></i></button>
    </div>
      
  </div>
</div>

</template>

<style scoped>

.team {
  display: flex;
  justify-content: center;
  position: relative;
  @media screen and (max-width: 768px) {
    flex-direction: column;
    .btn-zone {
    position: absolute;
    bottom: 5px;
    right: 5px;
  }
  }
}

</style>

<script>
import { useToast } from 'vue-toastification'
import axios from 'axios'

export default {
  name: "TeamsPage",
  components: {},
  computed: {},
  methods: {
    sortByTeam(users) {
      const teams = {}
      users.forEach(user => {
        user.teams.forEach(team => {
          if (!teams[team]) teams[team] = []
          teams[team].push(user)
        })
      })

      Object.keys(this.teamsInfos).forEach(team => {
        if (!teams[team]) teams[team] = []
        const manager = users.find(user => user.id === this.teamsInfos[team]?.manager_id)
        if (!teams[team]?.find(user => user.id === manager.id)) teams[team]?.push(manager)
      })

      if (!this.isSuperManager)
        Object.keys(teams).forEach(team => {
          if (!teams[team].some(user => user.id === parseInt(this.userId))) {
            delete teams[team];
          }
        });

      return teams
    },
    teamsToDict(teams) {
      const dict = {}
      teams.forEach(team => {
        dict[team.id] = {
          name: team.name,
          manager: team.manager,
          manager_id: team.manager_id
        }
      })
      return dict
    },
    async getTeams() {
      const token = localStorage.getItem('token')
      if (!token) return false

      const header = { headers: { Authorization: `Bearer ${token}` } }
      try {
        const response = await axios.get(`${import.meta.env.DEV ? "http://localhost:4000" : "http://time-manager.labbtech.fr:4000"}/api/teams`, header)
        this.teamsInfos = this.teamsToDict(response.data.data)
        return true
      } catch (error) {
        useToast().error(`Can't get teams infos. ${error.message}`, { timeout: 4000 });
        return false
      }
    },
    async updateTeams() {
      const token = localStorage.getItem('token')
      if (!token) return false

      const header = { headers: { Authorization: `Bearer ${token}` } }
      try {
        const response = await axios.get(`${import.meta.env.DEV ? "http://localhost:4000" : "http://time-manager.labbtech.fr:4000"}/api/all_users`, header)
        return this.sortByTeam(response.data.data)
      } catch (error) {
        useToast().error(`Can't get teams. ${error.message}`, { timeout: 4000 });
        return false
      }
    }
  },
  data() {
    return {
      teams: {},
      teamsInfos: [],
      userId: this?.$route?.params?.userid,
      userRole: localStorage.getItem('user_role'),
      isManager: false,
      isSuperManager: false,
    }
  },
  async mounted() {
    this.userId = this.userId ? this.userId : localStorage.getItem('user_id')
    this.userRole = this.userRole ? this.userRole : localStorage.getItem('user_role')
    this.isManager = this.userRole > 1
    this.isSuperManager = this.userRole > 2
    await this.getTeams()
    const temp = await this.updateTeams()

    // remove all teams that no longer exist
    Object.keys(temp).forEach(team => {
      if (!this.teamsInfos[team]) delete temp[team]
    })

    this.teams = temp
  }
}
</script>

<template>

<div v-if="Object.keys(this.teams).length" v-for="team in Object.keys(this.teams)" class="container">
  <h1 v-if="teamsInfos[team]" class="pad-bot">{{ teamsInfos[team].name }} ({{ teamsInfos[team].manager }})</h1>
  <h1 v-else class="pad-bot red-txt">This team no longer exists</h1>
  <div :id="team" class="container-body">
    <div v-for="user in teams[team]" class="box">
      <div class="inputField">
        <label for="username">Username</label>
        <input type="text" v-model="user.username" placeholder="Username" disabled />
      </div>
      <div class="inputField">
        <label for="email">Email</label>
        <input type="text" v-model="user.email" placeholder="Email" disabled />
      </div>
      <div class="btn-zone">
        <div class="status-zone" :title="user.clock ? 'Working' : 'Not Working'" >
          <div :status="user.clock" class="info-status"></div>
        </div>
        <button v-if="isManager" @click="() => this.$router.push(`/chartManager/${user.id}`)" class="big-btn green" title="Dashboard"><i class='bx bxs-data'></i></button>
        <button v-if="isManager" @click="() => this.$router.push(`/workingtimes/${user.id}`)" class="big-btn green" title="WorkingTimes"><i class='bx bxs-time' ></i></button>
        <button v-if="isManager" @click="() => this.$router.push(`/user/${user.id}`)" class="big-btn" title="Infos"><i class='bx bxs-user' ></i></button>
      </div>
    </div>
  </div>
</div>

<div class="container" v-if="!Object.keys(this.teams).length">
  <h1 class="pad-bot pointer arrow-down">Teams</h1>
  <div class="container-body reverse">
    <p>You don't belong to any team</p>
  </div>
</div>

</template>

<style scoped>
.status-zone {
  padding-right: 5px;
  display: flex;
  align-items: center;
  /* border: solid red; */
}
</style>

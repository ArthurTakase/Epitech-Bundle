<!--
- used to display the working times recorded by the API ;
– connected to the /workingTimes/:userI route ;
– should also have at least:
    - the userId and workingTimes data (the table summarizing the offset times) ;
    - the getWorkingTimes() method.
-->

<script>
import axios from 'axios'
import { useToast } from 'vue-toastification'

export default {
  name: "WorkingTimes",
  components: {},
  computed: {},
  methods: {
    formatDate(date) {
      const formattedDate = new Date(date).toISOString().slice(0, 19).replace('T', ' ');
      return formattedDate
    },
    async createWorkingTime(userId = this.userId) {
      const token = localStorage.getItem('token')
      if (!token) {
        this.$router.push('/')
        return false
      }

      const start = this.formatDate(new Date())
      const body = { workingtime: { start: start, end: start } }
      const header = { headers: { 'Authorization': 'Bearer ' + token } }
      try {
        const response = await axios.post(`${import.meta.env.DEV ? "http://localhost:4000" : "http://time-manager.labbtech.fr:4000"}/api/workingtimes/${userId}`, body, header)
        useToast().success(`Working time created`, { timeout: 4000 });
        return response.data.data.id
      } catch (error) {
        useToast().error(`Can't create working time. ${error.message}`, { timeout: 4000 });
        return false
      }
    },
    async updateWorkingTime(id, data) {
      if (!this.isManager) return
      const token = localStorage.getItem('token')
      if (!token) {
        this.$router.push('/')
        return
      }

      const header = { headers: { 'Authorization': 'Bearer ' + token } }
      const body = { workingtime: data }
      try {
        const response = await axios.put(`${import.meta.env.DEV ? "http://localhost:4000" : "http://time-manager.labbtech.fr:4000"}/api/workingtimes/${id}`, body, header)
        this.workingTime = response.data.data
      } catch (error) {
        useToast().error(`Can't update workingtime ${id}. ${error.message}`, { timeout: 4000 });
        return false
      }
      useToast().success(`Workingtime ${id} updated`, { timeout: 4000 });
      return true
    },
    async deleteWorkingTime(id) {
      if (!this.isManager) return
      const token = localStorage.getItem('token')
      if (!token) {
        this.$router.push('/')
        return
      }

      const header = { headers: { 'Authorization': 'Bearer ' + token } }
      try {
        await axios.delete(`${import.meta.env.DEV ? "http://localhost:4000" : "http://time-manager.labbtech.fr:4000"}/api/workingtimes/${id}`, header)
        useToast().success(`Workingtime ${id} removed`, { timeout: 4000 });
        return true
      } catch (error) {
        useToast().error(`Can't remove workingtime ${id}. ${error.message}`, { timeout: 4000 });
        return false
      }
    },
    async getWorkingTime(userId, id) {
      const token = localStorage.getItem('token')
      if (!token) {
        window.location.href = '/'
        return
      }

      const header = { headers: { Authorization: `Bearer ${token}` } }
      try {
        const response = await axios.get(`${import.meta.env.DEV ? "http://localhost:4000" : "http://time-manager.labbtech.fr:4000"}/api/workingtimes/${userId}/${id}`, header)
        return response.data.data
      } catch (error) {
        useToast().error(`Can't get WorkingTime ${id}. ${error.message}`, { timeout: 4000 });
        return false
      }
    },
    async deleteWorkingTimeBtn(event) {
      if (!this.isManager) return
      event.target.disabled = true
      const isGood = await this.deleteWorkingTime(this.workingTime.id)
      if (!isGood) {
        if (event) event.target.disabled = false
        return
      }
      if (event) event.target.disabled = false
      this.$router.go(-1)
    },
    toggleEditMode() {
      if (!this.isManager) return
      const inputs = document.querySelectorAll('#userInfos input[canEdit="true"]')
      inputs.forEach(input => input.disabled = !input.disabled)
      const saveUser = document.querySelector('#saveUser')
      saveUser.style.display = saveUser.style.display === 'none' ? 'block' : 'none'
    },
    async saveEdit(event) {
      if (!this.isManager) return
      event.target.disabled = true
      
      this.workingTime.start = new Date(this.workingTime.start).toISOString()
      this.workingTime.end = new Date(this.workingTime.end).toISOString()

      const isGood = await this.updateWorkingTime(
        this.workingTime.id,
        {
          start: this.workingTime.start,
          end: this.workingTime.end,
          isFinished: this.workingTime.isFinished,
        }
      )

      if (!isGood) {
        if (event) event.target.disabled = false
        return
      }

      this.workingTime.start = this.toLocalDate(this.workingTime.start)
      this.workingTime.end = this.toLocalDate(this.workingTime.end)

      const inputs = document.querySelectorAll('#userInfos input[canEdit="true"]')
      const saveUser = document.querySelector('#saveUser')
      inputs.forEach(input => input.disabled = !input.disabled)
      saveUser.style.display = 'none'
      if (event) event.target.disabled = false
    },
    toLocalDate(dateString) {
      const dateUTC = new Date(dateString);
      const timeZoneOffset = new Date().getTimezoneOffset();
      const dateLocale = new Date(dateUTC.getTime() - timeZoneOffset * 60 * 1000);
      const isoDate = dateLocale.toISOString()
      return isoDate.slice(0, -5)
    }
  },
  data() {
    return {
        userId: this.$route.params.userid,
        workingTimeId: this.$route.params.id,
        workingTime: null,
        isManager: false
    }
  },
  async mounted() {
    if (this.userId && this.userId != localStorage.getItem('user_id')) {
      if (localStorage.getItem('user_role') === '1') {
        this.$router.go(-1)
        useToast().error(`You can't view this page`, { timeout: 4000 });
        return
      }
    }

    this.userId = this.userId ? this.userId : localStorage.getItem('user_id')
    if (!this.workingTimeId)
      this.workingTimeId = await this.createWorkingTime(this.userId)
    this.workingTime = await this.getWorkingTime(this.userId, this.workingTimeId)
    this.workingTime.start = this.toLocalDate(this.workingTime.start)
    this.workingTime.end = this.toLocalDate(this.workingTime.end)
    this.isManager = parseInt(localStorage.getItem('user_role')) > 1
  }
}
</script>

<template>

<div v-if="workingTime" class="container little-container">
  <h1>WorkingTime</h1>
  <div id="userInfos" class="container-body">
    <div class="inputField">
      <label for="id">ID</label>
      <input :canEdit="false" type="text" v-model="workingTime.id" placeholder="id" disabled />
    </div>
    <div class="inputField">
      <label for="start">Start</label>
      <input :canEdit="isManager" type="datetime-local" v-model="workingTime.start" placeholder="Start date" disabled />
    </div>
    <div v-if="workingTime.isFinished || isManager" class="inputField">
      <label for="end">End</label>
      <input :canEdit="isManager" type="datetime-local" v-model="workingTime.end" placeholder="End date" disabled />
    </div>
    <div class="inputField">
      <label for="isFinished" class="isFinished">
        isFinished
        <div :status="workingTime.isFinished" class="info-status"></div>
      </label>
      <input :canEdit="false" type="text" v-model="workingTime.isFinished" placeholder="true/false" disabled />
    </div>
    <div class="btn-zone" v-if="isManager">
      <button @click="saveEdit" id="saveUser" class="big-btn green" style="display: none;">Save <i class='bx bx-save'></i></button>
      <button  @click="toggleEditMode" class="big-btn">Edit <i class='bx bx-edit' ></i></button>
    </div>
  </div>
</div>
<div v-if="workingTime" style="position: absolute; bottom: 10px; right: 10px;">
  <button @click="deleteWorkingTimeBtn" v-if="isManager" class="big-btn red">Delete WorkingTime <i class='bx bxs-trash'></i></button>
</div>

</template>

<style scoped>
.isFinished {
  display: flex;
  align-items: center;
  gap: 10px;

}
.info-status {
  width: 10px;
  height: 10px;
  border-radius: 50%;
  background-color: green;
  &[status="false"] {
    background-color: red;
    animation: blinker 2s ease-in-out infinite;
  }
}

@keyframes blinker {
  50% {
    opacity: 20%;
  }
}
</style>

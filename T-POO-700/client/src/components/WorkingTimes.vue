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
import WorkingTime from "../components/WorkingTime.vue";

export default {
  name: "WorkingTimes",
  components: {},
  computed: {},
  methods: {
    async getWorkingTimes(id) {
      const token = localStorage.getItem('token')
      if (!token) return []
      try {
        this.startTime = this.startTime ? this.startTime : '2000-01-01'
        this.endTime = this.endTime ? this.endTime : '2100-01-01'

        const header = { headers: { 'Authorization': 'Bearer ' + token } }
        const response = await axios.get(`${import.meta.env.DEV ? "http://localhost:4000" : "http://time-manager.labbtech.fr:4000"}/api/workingtimes/${id}?start=${this.startTime} 00:00:00&end=${this.endTime} 00:00:00`, header)
        return response.data.data
      } catch (error) {
        useToast().error(`Can't get working times. ${error.message}`, { timeout: 4000 });
        return []
      }
    },
    toDate(date) {
      return new Date(date).toLocaleString(
        'en-EN',
        {
          year: 'numeric',
          month: 'long',
          day: 'numeric',
          hour: 'numeric',
          minute: 'numeric'
        }
      )
    },
    expand(divName) {
      const div = document.getElementById(divName)
      if (div.style.display === 'none') {
        div.style.display = 'block'
      } else {
        div.style.display = 'none'
      }
    },
    async createWorkingTime(event)
    {
      if (event) event.target.disabled = true
      const workingTimeId = await WorkingTime.methods.createWorkingTime(this.userId)
      if (workingTimeId)
        this.$router.push(`/workingTime/${this.userId}/${workingTimeId}`)
      if (event) event.target.disabled = false
    }
  },
  data() {
    return {
        userId: this?.$route?.params?.userid,
        workingTimes: [],
        startTime: null,
        endTime: null,
        isManager: parseInt(localStorage.getItem('user_role')) > 1
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
    this.workingTimes = await this.getWorkingTimes(this.userId)
  }
}
</script>

<template>
  <div class="container">
  <h1 class="pad-bot pointer arrow-down" @click="() => { expand('time') }">WorkingTimes</h1>
  <div id="time" class="pad-bot" style="display: none;">
    <b>From</b> <input type="date" name="" id="" v-model="startTime">
    <br>
    <b>To</b> <input type="date" name="" id="" v-model="endTime">
    <br>
    <button class="big-btn marg-top" @click="() => { getWorkingTimes(userId) }">Search</button>
  </div>
  <div class="container-body reverse">

    <div v-if="!workingTimes.length">
      <p>No working times</p>
    </div>

    <button v-for="workingTime in workingTimes" @click="() => {
      this.$router.push(`/workingTime/${userId}/${workingTime.id}`)
    }" class="box relative">
      <div class="btn-zone">
        <div :status="workingTime.isFinished" class="info-status"></div>
      </div>
      <div class="infos">
        <span class="bold">Start</span>
        <span>{{ toDate(workingTime.start) }}</span>
      </div>
      <div v-if="workingTime.isFinished" class="infos">
        <span class="bold">End</span>
        <span>{{ toDate(workingTime.end) }}</span>
      </div>

    </button>

  </div>
</div>

<div v-if="isManager" style="position: fixed; bottom: 10px; right: 10px;">
  <button @click="createWorkingTime" v-if="isManager" class="big-btn">New WorkingTime <i class='bx bx-plus' ></i></button>
</div>
</template>

<style scoped>
.container-body.reverse {
  flex-direction: column-reverse;
}

.pad-bot {
  padding-bottom: 20px;
}

.marg-top {
  margin-top: 10px;
}

.infos {
  display: flex;
  flex-direction: column;
  align-items: center;
}

.relative {
  position: relative;
}

.bold {
  font-weight: bold;
}

.btn-zone {
  display: flex;
  flex-direction: row;
  align-items: center;
  position: absolute;
  top: 10px;
  right: 10px;
}
</style>

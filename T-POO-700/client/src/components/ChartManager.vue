<script>
import axios from "axios";
import { useToast } from "vue-toastification";
import {
  Chart as ChartJS,
  Title,
  Tooltip,
  Legend,
  BarElement,
  CategoryScale,
  LinearScale,
  PointElement,
  LineElement,
  Filler,
  ArcElement,
} from 'chart.js'
import {Bar, Doughnut, Line} from "vue-chartjs";

ChartJS.register(
  ArcElement,
  CategoryScale,
  LinearScale,
  PointElement,
  BarElement,
  LineElement,
  Title,
  Filler,
  Tooltip,
  Legend
)


export default {
  name: "ChartManager",
  components: { Bar, Doughnut, Line },
  computed: {},
  methods: {
    getRandomInt() {
      return Math.floor(Math.random() * 256)
    },
    fillData(data, labels, label = 'WIP') {
      const backgroundColor = []
      for (var i = 0; i < labels.length; i++) {
        const r = this.getRandomInt()
        const g = this.getRandomInt()
        const b = this.getRandomInt()
        backgroundColor.push(`rgba(${r},${g},${b},0.5)`)
      }
      return {
        labels: labels,
        datasets: [
          {
            label: label,
            fill: true,
            backgroundColor: backgroundColor,
            pointBorderColor: '#bd8795',
            pointColor: 'rgba(16,99,253,1)',
            pointBorderWidth: 5,
            borderWidth: 3,
            data: data,
          }
        ]
      }
    },
    donutData() {
      const data = this.line
      const temp = []
      for (var i = 0; i < data.labels.length; i++)
        temp.push({
          time: data.datasets[0].data[i],
          date: data.labels[i]
        })

      const dataToReturn = {}
      temp.forEach(element => {
        const start = new Date(element.date)
        const day = start.toLocaleDateString('en-EN', { weekday: 'long' })
        if (dataToReturn[day]) {
          dataToReturn[day].count += 1
          dataToReturn[day].time += element.time
        } else {
          dataToReturn[day] = {
            count: 1,
            time: element.time
          }
        }
      })

      Object.keys(dataToReturn).forEach(key => {
        dataToReturn[key] = dataToReturn[key].time / dataToReturn[key].count
        dataToReturn[key] = Math.round(dataToReturn[key] * 100) / 100
      })

      return this.fillData(Object.values(dataToReturn),  Object.keys(dataToReturn), 'Working time')
    },
    barData() {
      const data = this.line
      const temp = []
      for (var i = 0; i < data.labels.length; i++)
        temp.push({
          time: data.datasets[0].data[i],
          date: data.labels[i]
        })

      const dataToReturn = {
        "January": 0,
        "February": 0,
        "March": 0,
        "April": 0,
        "May": 0,
        "June": 0,
        "July": 0,
        "August": 0,
        "September": 0,
        "October": 0,
        "November": 0,
        "December": 0,
      }
      temp.forEach(element => {
        const start = new Date(element.date)
        const month = start.toLocaleDateString('en-EN', { month: 'long' })
        dataToReturn[month] += element.time
      })

      return this.fillData(Object.values(dataToReturn),  Object.keys(dataToReturn), 'Working time')
    },
    lineData() {
      const temp = {}
      this.workingtimes.forEach(workingtime => {
        const start = new Date(workingtime.start)
        const end = new Date(workingtime.end)
        const date = start.toLocaleDateString('en-EN', { year: 'numeric', month: 'long', day: 'numeric' })

        if (temp[date]) temp[date] += (end - start) / 1000
        else temp[date] = (end - start) / 1000
      })

      // convert all seconds to hours
      Object.keys(temp).forEach(key => {
        temp[key] = temp[key] / 3600
      })

      return this.fillData(Object.values(temp),  Object.keys(temp), 'Working time')
    },
    async search(event) {
      if (event) event.target.disabled = true
      this.workingtimes = await this.getWorkingTimes(this.userId)
      this.line = this.lineData()
      this.donut = this.donutData()
      this.bar = this.barData()
      this.forceReRender++
      if (event) event.target.disabled = false
    },
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
  },
  data() {
    return {
      token: localStorage.getItem('token'),
      url: window.location.href,
      chartOption: {
        responsive: true,
        maintainAspectRatio: false,
      },
      chartLineOption: {
        scales: {
          y: {
            min: 0,
            max: 24,
          }
        },
        responsive: true,
        maintainAspectRatio: false,
      },
      donut: this.fillData([], []),
      line: this.fillData([], []),
      bar: this.fillData([], []),
      startTime: '2000-01-01',
      endTime: '2100-01-01',
      workingtimes: [],
      userId: this.$route.params.userid,
      forceReRender: 0
    }
  },
  async mounted() {
    this.userId = this.userId ? this.userId : localStorage.getItem('user_id')
    await this.search()
  },
  async unmounted() {},
}
</script>

<template>
  <div class="container chart fit unset-h">
    <b>From</b> <input type="date" name="" id="" v-model="startTime">
    <b>To</b> <input type="date" name="" id="" v-model="endTime">
    <button class="big-btn marg-top" @click="search"><i class='bx bx-search-alt-2'></i></button>
  </div>
  <div class="container chart unset-h" :key="forceReRender">
    <h1>Total hour per month</h1>
    <div class="chart-card">
      <Bar :data="bar" :options="chartOption" />
    </div>
  </div>
  <div class="container chart unset-h" :key="forceReRender">
    <h1>Average hour per week day</h1>
    <div class="chart-card">
      <Doughnut :data="donut" :options="chartOption" />
    </div>
  </div>
  <div class="container chart unset-h" :key="forceReRender">
    <h1>Time hour per days</h1>
    <div class="chart-card more-height">
      <Line :data="line" :options="chartLineOption" />
    </div>
  </div>
  <div class="bottom"></div>
</template>

<style scoped>

.chart {
  min-width: 40vw;
  display: flex;
  flex: 1;
  width: 100%;
}

.fit {
  min-width: unset;
  position: fixed;
  background: rgba(255, 255, 255, 0.494);
  backdrop-filter: blur(4px);
  left: 50%;
  transform: translateX(-50%);
  display: flex;
  flex-direction: row;
  gap: 10px;
  transition: left 0.5s ease-in-out;
  width: 450px;
  bottom: -15px;
  border-bottom-left-radius: 0;
  border-bottom-right-radius: 0;
}

@media screen and (max-width: 768px) {
  .chart {
    min-width: 80vw;
  }
  .fit {
    left: -15px;
    transform: unset;
    min-width: 100vw;
  }
  .bottom {
    height: 80px;
    min-width: 100vw;
    flex: 1;
  }
}

.chart-card {
  background-color: white;
  border-radius: 20px;
  padding: 20px;
  height: 100%;
  width: 100%;
  &.more-height {
    min-height: 250px;
  }
}
</style>

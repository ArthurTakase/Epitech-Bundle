<script>
import TimeImg from '../assets/time.png'

export default {
  name: "HomePage",
  components: {},
  computed: {},
  methods: {},
  data() {
    return {
        timeImg: TimeImg
    }
  },
  mounted() {
    const token = localStorage.getItem('token')
    if (token) this.$router.push('/clock')
  }
}
</script>

<template>
  <div id="time-container">
    <img :src="timeImg" alt="logo" id="time" />
  </div>
  <div id="time-infos">
    <h1>Manage your time like a champion!</h1>
    <p>Welcome to Gotham City</p>
  </div>
</template>

<style scoped>
#time-infos {
  position: absolute;
  top: 100px;
  background: rgba(255, 255, 255, 0.454);
  backdrop-filter: blur(10px);
  width: 100%;
  padding-left: 200px;
  padding-right: 200px;
  h1 {
    transition: color 0.2s ease-in-out;
    &:hover {
      color: #2b7bd7;
    }
  }
}

@keyframes float {
  0% {
    transform: translateY(0px);
  }
  50% {
    transform: translateY(20px);
  }
  100% {
    transform: translateY(0px);
  }
}

#time-container {
  width: 100vw;
  height: calc(100vh - 50px);
  display: flex;
  justify-content: center;
  align-items: center;
  overflow: hidden;
  padding-top: 300px;
  z-index: -1;
}
#time {
  overflow: visible;
  width: 100%;
  object-fit: cover;
  filter: drop-shadow(0px 0px 5px rgba(0, 0, 0, 0.5));
  animation: float 3s ease-in-out infinite;
}

@media screen and (max-width: 600px) {
  #time {
    width: 150%;
    height: 150%;
  }
  #time-infos {
    padding: 0 20px;
  }
}

</style>

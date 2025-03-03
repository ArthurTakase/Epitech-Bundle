<script>
import axios from "axios";
import { useToast } from "vue-toastification";

export default {
    name: "ClockManager",
    components: {},
    computed: {},
    methods: {
        async clock(event) {
            if (event) event.target.disabled = true
            const token = localStorage.getItem('token')
            if (!token) {
                if (event) event.target.disabled = false
                return
            }

            try {
                const headers = { headers: { 'Authorization': 'Bearer ' + token } }
                const response = await axios.post(`${import.meta.env.DEV ? "http://localhost:4000" : "http://time-manager.labbtech.fr:4000"}/api/clocks/${this.username}`, {}, headers)
                this.launch_timer(response.data.data)
            } catch (error) {
                useToast().error(`Can't update clock. ${error.message}`, { timeout: 4000 });
            }
            if (event) event.target.disabled = false
        },
        async refresh(event) {
            this.isOnline = await this.ping()
            if (!this.isOnline) return
            
            this.postQueue()
    
            if (event) event.target.disabled = true
            const token = localStorage.getItem('token')
            if (!token) {
                if (event) event.target.disabled = false
                return
            }

            try {
                const headers = { headers: { 'Authorization': 'Bearer ' + token } }
                const response = await axios.get(`${import.meta.env.DEV ? "http://localhost:4000" : "http://time-manager.labbtech.fr:4000"}/api/clocks/${this.username}`, headers)
                this.launch_timer(response.data.data)
            } catch (error) {
                useToast().error(`Can't get clock. ${error.message}`, { timeout: 4000 });
            }
            if (event) event.target.disabled = false
        },
        launch_timer(data) {
            this.myClock = data
            this.startDateTime = data.time
            this.clockIn = data.status

            if (!this.clockIn) {
                clearInterval(this.interval)
                this.elapsedTime = 'Loading...'
            }
            else this.timer()
        },
        timer() {
            let time = new Date(new Date() - new Date(this.startDateTime))

            this.interval = setInterval(() => {
                time.setSeconds(time.getSeconds() + 1)
                const hours = time.getUTCHours()
                let minutes = time.getUTCMinutes()
                let seconds = time.getUTCSeconds()

                // add 0 if minutes or seconds < 10
                minutes = minutes < 10 ? '0' + minutes : minutes
                seconds = seconds < 10 ? '0' + seconds : seconds

                this.elapsedTime = `${hours}:${minutes}:${seconds}`
            }, 1000)
        },
        newOfflineSession() {
            const queue = localStorage.getItem('queue') ? JSON.parse(localStorage.getItem('queue')) : []
            queue.push({ start: new Date(), end: null, id: queue.length + 1 })
            this.queue = queue
            localStorage.setItem('queue', JSON.stringify(queue))
        },
        endOfflineSession(sessionId) {
            const queue = localStorage.getItem('queue') ? JSON.parse(localStorage.getItem('queue')) : []
            const session = queue.find(item => item.id == sessionId)
            session.end = new Date()
            queue[queue.findIndex(item => item.id == sessionId)] = session
            localStorage.setItem('queue', JSON.stringify(queue))
            this.queue = queue
        },
        async ping() {
            const url = `${import.meta.env.DEV ? "http://localhost:4000" : "http://time-manager.labbtech.fr:4000"}/api/ping`
            try {
                await axios.get(url)
                return true
            } catch (error) {
                return false
            }
        },
        formatDate(date) {
            if (!date) return null
            const formattedDate = new Date(date).toISOString().slice(0, 19).replace('T', ' ');
            return formattedDate
        },
        async postQueue() {
            const token = localStorage.getItem('token')
            const username = localStorage.getItem('username')
            if  (username != this.username) return false
            if (!token) return false
            const header = { headers: { Authorization: `Bearer ${token}` } }

            const queue = localStorage.getItem('queue') ? JSON.parse(localStorage.getItem('queue')) : []
            if (queue.length == 0) return false

            const id = localStorage.getItem('user_id')

            queue.forEach(async item => {
                try {
                    if (!item.end) return false
                    const body = {
                        "workingtime": {
                            "start": item.start,
                            "end": item.end
                        }
                    }
                    const url = `${import.meta.env.DEV ? "http://localhost:4000" : "http://time-manager.labbtech.fr:4000"}/api/workingtimes/${id}`
                    await axios.post(url, body, header)
                } catch (error) {
                    useToast().error(`Can't post queue. ${error.message}`, { timeout: 4000 });
                    return false
                }
            })
        
            queue.forEach(item => { if (item.end) queue.splice(queue.findIndex(item => item.end), 1) })
            localStorage.setItem('queue', JSON.stringify(queue))
            this.queue = queue
            useToast().success(`Queue posted`, { timeout: 4000 });
        }
    },
    data() {
        return {
            token: localStorage.getItem('token'),
            url: window.location.href,
            myClock: {},
            username: this.$route.params.username,
            startDateTime: null,
            clockIn: false,
            elapsedTime: 'Loading...',
            interval: null,
            isOnline: true,
            queue: localStorage.getItem('queue') ? JSON.parse(localStorage.getItem('queue')) : []
        }
    },
    async mounted() {
        this.username = this.username ? this.username : localStorage.getItem('username')
        this.refresh()
    },
    async unmounted() {
        clearInterval(this.interval)
    },
}
</script>

<template>
    <div class="container relative pad-bot full-container">
        <h1>{{ username }}'s Clock</h1>
        <button class="refresh blue" @click="refresh" title="refresh">
            <i class='bx bx-refresh'></i>
        </button>
        <button v-if="isOnline" :clockIn="clockIn" @click="clock" class="myClock">
            <i class="bx bxs-right-arrow" v-if="!clockIn" ></i>
            <div v-else class="since">
                Your are working since :
                <br>
                <span class="bold">{{ elapsedTime }}</span>
            </div>
        </button>
        <button v-else class="offline-box">
            <div class="flex">Your are offline<i class='bx bx-no-signal'></i></div>
            <button @click="newOfflineSession" class="big-btn">Start an offline session</button>
            <div class="min">Offline sessions will be synchronized once the connection is re-established.
                You can attempt to reconnect at any time by clicking on <i class='bx bx-refresh'></i>.
                Without connection, the application is unable to determine whether a session was in progress.
                If an error occurs in the data, please contact your manager.    
            </div>
        </button>
    </div>

    <div v-if="queue.length != 0" class="container relative">
        <h1>Offline queue</h1>
        <div class="container-body invert">
            <div v-if="queue.length == 0">No offline session</div>
            <div v-for="item in queue" class="box queue-box">
                <b>From</b>
                <p>{{ formatDate(item.start) }}</p>
                <b v-if="item.end">To</b>
                <p v-if="item.end">{{ formatDate(item.end) }}</p>
                <button v-if="!item.end" @click="() => endOfflineSession(item.id)" title="End this session" class="stop-btn red-txt"><i class='bx bx-stop-circle'></i></button>
            </div>
        </div>
    </div>

</template>

<style scoped>

.offline-box {
    width: 100%;
    border: solid rgb(249, 217, 111);
    background: rgb(255, 255, 170);
    .flex {
        display: flex;
        justify-content: center;
        align-items: center;
        gap: 5px;
        font-weight: bold;
    }
    div {
        color: rgb(255, 115, 0);
        padding-bottom: .5rem;
    }
    button {
        background: rgb(255, 115, 0);
        margin-bottom: .5rem;
    }
    .min {
        font-size: .8rem;
        font-style: italic;
    }
}

.queue-box {
    display: flex;
    justify-content: center;
    align-items: center;
    gap: 10px;
    .stop-btn {
        /* border: solid blue; */
        position: absolute;
        right: 10px;
        font-size: 1.8rem;
        padding: 0;
        margin: 0;
        display: flex;
        transition: scale .2s ease-in-out;
        &:hover {
            scale: 1.1;
        }
    }
}

.pad-bot {
    padding-bottom: 35px;
}

.since {
    font-size: 1.2rem;
}

.bold {
    font-weight: bold;
}

.myClock {
    margin-top: 1rem;
    background: #ff4d4d;
    border: solid rgb(200, 200, 200);
    width: 100px;
    height: 100px;
    max-width: 100px;
    max-height: 100px;
    overflow: hidden;
    border-radius: 50%;
    box-shadow: 0px 10px 1px 0px rgb(155, 155, 155);
    transition: all 0.2s ease-in-out;
    color: white;
    font-size: 2rem;
    display: flex;
    justify-content: center;
    align-items: center;
    &:hover {
        box-shadow: none;
        translate: 0 5px;
        box-shadow: 0px 7px 1px 0px rgb(155, 155, 155);
    }
    &[clockIn="true"] {
        background: #42b883;
        font-size: 3rem;
        border-radius: 10px;
        width: fit-content;
        max-width: unset;
    }
}

.relative {
    position: relative;
}

.refresh {
    position: absolute;
    top: 5px;
    right: 10px;
    width: fit-content;
    height: fit-content;
    padding: 0;
    transition: rotate 0.2s ease-in-out;
    &:hover {
        rotate: 180deg;
    }
}

</style>

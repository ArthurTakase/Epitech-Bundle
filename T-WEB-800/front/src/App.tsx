import './scss/App.scss'
import MyMap from './components/Map'
import Navbar from './components/Navbar'
import { ToastContainer } from 'react-toastify'
import 'react-toastify/dist/ReactToastify.css'
import LeftPanel from './components/LeftPanel'
import Modal from './components/Modal'
import './scss/print.scss'

function App() {
  return (
    <>
      <Navbar />
      <MyMap />
      <LeftPanel />
      <Modal />
      <ToastContainer
        autoClose={3000}
        />
    </>
  )
}

export default App

import { wrapper } from 'axios-cookiejar-support';
import { CookieJar } from 'tough-cookie';
import axios from "axios";

const jar = new CookieJar();
const AXIOS = wrapper(axios.create({ jar }));

export default AXIOS;
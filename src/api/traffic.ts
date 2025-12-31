import axios from 'axios'

const request = axios.create({
    baseURL: 'http://192.168.11.88:8080',
    timeout: 5000
})

export function queryTraffic(params: any) {
    return request.post('/traffic/query', params)
        .then(res => res.data)
}

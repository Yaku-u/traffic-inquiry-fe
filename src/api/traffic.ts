import request from '../utils/request'

// 获取所有城市
export function getAllCities() {
    return request.get('/getAllCities').then(res => res.data)
}

// 添加城市
export function addCity(data: {
    name: string
    code: string
}) {
    return request.post('/addCity', data)
}

// 删除城市
export function deleteCity(name: string) {
    return request.post('/deleteCity', { name })
}

// 修改城市
export function updateCity(data: {
    name: string
    newname: string
    newcode: string
}) {
    return request.post('/updateCity', data)
}

// 获取所有路线
export function getAllRoutes() {
    return request.get('/getAllRoutes').then(res => res.data)
}

// 添加路线
export function addRoute(data: {
    from: string
    to: string
    startTime: number
    endTime: number
    num: number
    price: number
    type: number
}) {
    return request.post('/addRoute', data)
}

// 删除路线
export function deleteRoute(id: number) {
    return request.post('/deleteRoute', { id })
}

// 修改路线
export function updateRoute(data: {
    id: number
    from: string
    to: string
    startTime: number
    endTime: number
    num: number
    price: number
    type: number
}) {
    return request.post('/updateRoute', data)
}


// 最便宜路径
export function getCheapestPath(from: string, to: string) {
    return request.post('/getCheapestPath', { from, to })
        .then(res => res.data)
}

// 最快路径
export function getFastestPath(from: string, to: string) {
    return request.post('/getFastestPath', { from, to })
        .then(res => res.data)
}

// 最少中转路径
export function getLessTransferPath(from: string, to: string) {
    return request.post('/getLessTransferPath', { from, to })
        .then(res => res.data)
}
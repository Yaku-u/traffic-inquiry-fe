#include <iostream>
#include <string>

// 引入必要的库
#include "include/httplib/httplib.h" 
#include "include/nlohmann/json.hpp"
#include "ChinaMap.h"

using namespace httplib;
using namespace std;
using json = nlohmann::json;

int main() {
    Server svr;
    ChinaMap china_map;
    china_map.load_from_file("city.json", "route.json");
    cout << "Data loaded. Current city: " << china_map.getAllCities().size() << endl;

    // 挂载静态资源（前端页面）
    auto ret = svr.set_mount_point("/", "./index.html");

    // 设置 CORS 跨域头
    svr.set_default_headers({
        { "Access-Control-Allow-Origin" , "*" },
        { "Access-Control-Allow-Methods", "POST, GET, PUT, OPTIONS, DELETE"},
        { "Access-Control-Max-Age", "3600"},
        { "Access-Control-Allow-Headers", "*"},
        { "Content-Type", "application/json;charset=utf-8"}
        });

    // 处理 OPTIONS 请求（预检请求）
    svr.Options(R"(.*)", [&](const Request& req, Response& res) {
        res.status = 200;
        });

    // ==========================================
    // 1. 城市管理接口
    // ==========================================

    // 获取所有城市
    svr.Get("/getAllCities", [&](const Request& req, Response& res) {
        json j = china_map.getAllCities();
        res.set_content(j.dump(), "application/json");
        });

    // 添加城市
    svr.Post("/addCity", [&](const Request& req, Response& res) {
        json j = json::parse(req.body);
        auto name = j.at("name").get<string>();
        auto code = j.at("code").get<string>();
        cout << name << ' ' << code << endl;
        china_map.addCity(name, code);
        });

    // 删除城市
    svr.Post("/deleteCity", [&](const Request& req, Response& res) {
        json j = json::parse(req.body);
        string name = j.at("name").get<string>();
        cout << name << endl;
		int id = china_map.city_name_to_id[name];
        china_map.deleteCity(id);

        });

    //修改城市
    svr.Post("/updateCity", [&](const Request& req, Response& res) {
        json j = json::parse(req.body);
        string name = j.at("name").get<string>();
		int id = china_map.city_name_to_id[name];
		name = j.at("newname").get<string>();
        string code = j.at("newcode").get<string>();
        china_map.updateCity(id, name, code);
        });

    // ==========================================
    // 2. 路线管理接口
    // ==========================================

    //获取所有路线
    svr.Get("/getAllRoutes", [&](const Request& req, Response& res) {
        json j = china_map.getAllRoutes();
        res.set_content(j.dump(), "application/json");
        });

    //添加路线
    svr.Post("/addRoute", [&](const Request& req, Response& res) {
        json j = json::parse(req.body);
        int from = china_map.city_name_to_id[j.at("from").get<string>()];
        int to = china_map.city_name_to_id[j.at("to").get<string>()];
        int startTime = j.at("startTime").get<int>();
        int endTime = j.at("endTime").get<int>();
        int num = j.at("num").get<int>();
        int price = j.at("price").get<int>();
        int type = j.at("type").get<int>();
        china_map.addRoute(from, to, startTime, endTime, num, price,type);
        });

    //删除路线
    svr.Post("/deleteRoute", [&](const Request& req, Response& res) {
        json j = json::parse(req.body);
        int id = j.at("id").get<int>();
        china_map.deleteRoute(id);
        });

    //修改路线
    svr.Post("/updateRoute", [&](const Request& req, Response& res) {
        json j = json::parse(req.body);
        int id = j.at("id").get<int>();
        int from = china_map.city_name_to_id[j.at("from").get<string>()];
        int to = china_map.city_name_to_id[j.at("to").get<string>()];
        int startTime = j.at("startTime").get<int>();
        int endTime = j.at("endTime").get<int>();
        int num = j.at("num").get<int>();
        int price = j.at("price").get<int>();
        int type = j.at("type").get<int>();
        china_map.updateRoute(id,from,to,startTime,endTime,num, price, type);
        });

    // ==========================================
    // 3. 算法查询接口
    // ==========================================

    //最便宜路径
    svr.Post("/getCheapestPath", [&](const Request& req, Response& res) {
        json j = json::parse(req.body);
        int from = china_map.city_name_to_id[j.at("from").get<string>()];
        int to = china_map.city_name_to_id[j.at("to").get<string>()];

        json result = china_map.getCheapestPath(from, to);
        res.set_content(result.dump(), "application/json");
        });

    //最快路径
    svr.Post("/getFastestPath", [&](const Request& req, Response& res) {
        json j = json::parse(req.body);
        int from = china_map.city_name_to_id[j.at("from").get<string>()];
        int to = china_map.city_name_to_id[j.at("to").get<string>()];

        json result = china_map.getFastestPath(from, to);
        res.set_content(result.dump(), "application/json");
        });

    //最少中转路径
    svr.Post("/getLessTransferPath", [&](const Request& req, Response& res) {
        json j = json::parse(req.body);
        int from = china_map.city_name_to_id[j.at("from").get<string>()];
        int to = china_map.city_name_to_id[j.at("to").get<string>()];

        json result = china_map.getLessTransferPath(from, to);
        res.set_content(result.dump(), "application/json");
        });

    // 启动服务器
    cout << "Server is running at http://localhost:8080" << endl;
    if (!svr.listen("0.0.0.0", 8080)) {
        cerr << "Error: Failed to start server!" << endl;
        return -1;
    }

    return 0;
}
#include <iostream>
#include <sstream>
#include <exception>
#include <string>
#include <vector>
#include "httplib.h"
#include "nlohmann/json.hpp"
#include "quandl.h"

using namespace httplib;
using json = nlohmann::json;

//#define SERVICE 

void post(const Request& req, Response& res) {

    std::string body = req.body;

    try {
        json j;
        j = j.parse(body);

        auto valuesIter = j.find("values");

        if(valuesIter == j.end()) {
            throw std::invalid_argument("json was invalid");
        }

        j["return"] = "hello";
        res.set_content(j.dump(), "application/json");
    }
    catch(nlohmann::detail::exception e) {
        std::cout << e.what() << std::endl;
        res.status = 400;
    }
    catch(std::exception e) {
        std::cout << e.what() << std::endl;
        res.status = 400;
    }
}

#ifdef SERVICE

int main(void) {

    std::cout << "Starting server..." << std::endl;

    Server svr(httplib::HttpVersion::v1_1);

    svr.post("/", post);

    svr.listen("0.0.0.0",80);

    return 0;
}

#else

int main(void) {

    std::cout << "Hello!" << std::endl;

    Quandl qaundl;
    //quandl.QueryCommodityPriceData();
    qaundl.QueryCommodityPriceData();

    return 0;
}

#endif



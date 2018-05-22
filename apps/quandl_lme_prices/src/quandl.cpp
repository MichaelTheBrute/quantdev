#define CPPHTTPLIB_OPENSSL_SUPPORT


#include "quandl.h"
#include "nlohmann/json.hpp"
#include <iostream>
#include "quandlapi.h"
#include "httplib.h"


using namespace httplib;

/*
"https://www.quandl.com/api/v3/datasets"
"LME/PR_CU.json?api_key=2gki9M8eR7H1p28dypxi"
*/

void Quandl::QueryCommodityPriceData()
{
/*     httplib::SSLClient cli("httpbin.org",443);


    // 'Range: bytes=1-10'
    httplib::Headers headers = { httplib::make_range_header(1, 10) };

    auto res = cli.Get("/range/32", headers);

    std::cout << res << std::endl;

*/
    /*
      SSLClient google("www.google.com", 443);

    auto gr = google.Get("/");

    std::cout << gr->body << std::endl;
  */
    SSLClient client("www.quandle.com",443);

    auto response = client.Get("/");

    if(response == nullptr) {
        std::cout << "Response was null!" << std::endl;
        return;
    }

    if(response && response->status == 200) {
        std::cout << "response was OK!" << std::endl;
//        std::cout << response->body << std::endl;
    }
    else {
        std::cout << "Response status: " << response->status << std::endl;

        std::cout << response->get_header_value("Location") << std::endl;

        std::cout << response->body << std::endl;
    }

    quandl ql;
    ql.auth("2gki9M8eR7H1p28dypxi");
    ql.get("LME/PR_CU");
}

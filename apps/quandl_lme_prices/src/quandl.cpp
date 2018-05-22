#define CPPHTTPLIB_OPENSSL_SUPPORT


#include "quandl.h"
#include "nlohmann/json.hpp"
#include <iostream>
#include "quandlapi.h"


//using namespace httplib;

/*
"https://www.quandl.com/api/v3/datasets"
"LME/PR_CU.json?api_key=2gki9M8eR7H1p28dypxi"
*/

void Quandl::QueryCommodityPriceData()
{
    quandl ql;
    ql.auth("2gki9M8eR7H1p28dypxi");
    ql.get("LME/PR_CU");
}

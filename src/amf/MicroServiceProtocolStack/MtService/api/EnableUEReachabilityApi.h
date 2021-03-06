/**
* AMF MT Service
* AMF Mobile Termination Service
*
* OpenAPI spec version: 1.R15.0.0
* 
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/
/*
 * EnableUEReachabilityApi.h
 *
 * 
 */

#ifndef EnableUEReachabilityApi_H_
#define EnableUEReachabilityApi_H_


#include <pistache/http.h>
#include <pistache/router.h>
#include <pistache/http_headers.h>
#include <pistache/optional.h>


#include "EnableUeReachabilityReqData.h"
#include "EnableUeReachabilityRspData.h"
#include "ProblemDetails.h"
#include <string>

namespace org {
namespace openapitools {
namespace server {
namespace api {

using namespace org::openapitools::server::model;

class  EnableUEReachabilityApi {
public:
    EnableUEReachabilityApi(std::shared_ptr<Pistache::Rest::Router>);
    virtual ~EnableUEReachabilityApi() {}
    void init();

    const std::string base = "/namf-mt/v1";

private:
    void setupRoutes();

    void enable_ue_reachability_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);
    void enable_ue_reachability_api_default_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);

    std::shared_ptr<Pistache::Rest::Router> router;

    /// <summary>
    /// Namf_MT EnableUEReachability service Operation
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="ueContextId">UE Context Identifier</param>
    /// <param name="enableUeReachabilityReqData"></param>
    virtual void enable_ue_reachability(const std::string &ueContextId, const EnableUeReachabilityReqData &enableUeReachabilityReqData, Pistache::Http::ResponseWriter &response) = 0;

};

}
}
}
}

#endif /* EnableUEReachabilityApi_H_ */


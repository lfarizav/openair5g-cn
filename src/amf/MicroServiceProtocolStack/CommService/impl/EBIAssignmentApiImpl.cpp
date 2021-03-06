/**
* AMF Communicaiton Service
* AMF Communication Service
*
* OpenAPI spec version: 1.R15.0.0
*
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/

#include "EBIAssignmentApiImpl.h"

namespace org {
namespace openapitools {
namespace server {
namespace api {

using namespace org::openapitools::server::model;

EBIAssignmentApiImpl::EBIAssignmentApiImpl(std::shared_ptr<Pistache::Rest::Router> rtr)
    : EBIAssignmentApi(rtr)
    { }

void EBIAssignmentApiImpl::e_bi_assignment(const std::string &ueContextId, const AssignEbi &assignEbi, Pistache::Http::ResponseWriter &response) {
    std::cout<<"ueContextId:"<<ueContextId<<"\nAssignEbi:"<<assignEbi.toJson()<<std::endl;
    response.send(Pistache::Http::Code::Ok, "EBIAssignment\n");
}

}
}
}
}


/**
* Nsmf_PDUSession
* SMF PDU Session Service. © 2019, 3GPP Organizational Partners (ARIB, ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved. 
*
* The version of the OpenAPI document: 1.1.0.alpha-1
* 
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/

/*
* IndividualPDUSessionHSMFApiImpl.h
*
* 
*/

#ifndef INDIVIDUAL_PDU_SESSION_HSMF_API_IMPL_H_
#define INDIVIDUAL_PDU_SESSION_HSMF_API_IMPL_H_


#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>
#include <memory>

#include <IndividualPDUSessionHSMFApi.h>

#include <pistache/optional.h>

#include "HsmfUpdateData.h"
#include "HsmfUpdateError.h"
#include "HsmfUpdatedData.h"
#include "ProblemDetails.h"
#include "ReleaseData.h"
#include <string>

namespace oai {
namespace smf {
namespace api {

using namespace oai::smf::model;

class IndividualPDUSessionHSMFApiImpl : public oai::smf::api::IndividualPDUSessionHSMFApi {
public:
    IndividualPDUSessionHSMFApiImpl(std::shared_ptr<Pistache::Rest::Router>);
    ~IndividualPDUSessionHSMFApiImpl() {}

    void release_pdu_session(const std::string &pduSessionRef, const ReleaseData &releaseData, Pistache::Http::ResponseWriter &response);
    void update_pdu_session(const std::string &pduSessionRef, const HsmfUpdateData &hsmfUpdateData, Pistache::Http::ResponseWriter &response);

};

}
}
}



#endif
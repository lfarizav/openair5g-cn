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
/*
 * UeContextTransferReqData.h
 *
 * 
 */

#ifndef UeContextTransferReqData_H_
#define UeContextTransferReqData_H_


#include "ModelBase.h"

#include "TransferReason.h"
#include "N1MessageContainer.h"
#include <string>

namespace org {
namespace openapitools {
namespace server {
namespace model {

/// <summary>
/// 
/// </summary>
class  UeContextTransferReqData
    : public ModelBase
{
public:
    UeContextTransferReqData();
    virtual ~UeContextTransferReqData();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(const nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// UeContextTransferReqData members

    /// <summary>
    /// 
    /// </summary>
    TransferReason getReason() const;
    void setReason(TransferReason const& value);
        /// <summary>
    /// 
    /// </summary>
    N1MessageContainer getRegRequest() const;
    void setRegRequest(N1MessageContainer const& value);
    bool regRequestIsSet() const;
    void unsetRegRequest();
    /// <summary>
    /// 
    /// </summary>
    std::string getSupportedFeatures() const;
    void setSupportedFeatures(std::string const& value);
    bool supportedFeaturesIsSet() const;
    void unsetSupportedFeatures();

protected:
    TransferReason m_Reason;

    N1MessageContainer m_RegRequest;
    bool m_RegRequestIsSet;
    std::string m_SupportedFeatures;
    bool m_SupportedFeaturesIsSet;
};

}
}
}
}

#endif /* UeContextTransferReqData_H_ */
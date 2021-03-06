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


#include "NasSecurityMode.h"

namespace org {
namespace openapitools {
namespace server {
namespace model {

NasSecurityMode::NasSecurityMode()
{
    
}

NasSecurityMode::~NasSecurityMode()
{
}

void NasSecurityMode::validate()
{
    // TODO: implement validation
}

nlohmann::json NasSecurityMode::toJson() const
{
    nlohmann::json val = nlohmann::json::object();

    val["integrityAlgorithm"] = ModelBase::toJson(m_IntegrityAlgorithm);
    val["cipheringAlgorithm"] = ModelBase::toJson(m_CipheringAlgorithm);
    

    return val;
}

void NasSecurityMode::fromJson(const nlohmann::json& val)
{
    
}


IntegrityAlgorithm NasSecurityMode::getIntegrityAlgorithm() const
{
    return m_IntegrityAlgorithm;
}
void NasSecurityMode::setIntegrityAlgorithm(IntegrityAlgorithm const& value)
{
    m_IntegrityAlgorithm = value;
    
}
CipheringAlgorithm NasSecurityMode::getCipheringAlgorithm() const
{
    return m_CipheringAlgorithm;
}
void NasSecurityMode::setCipheringAlgorithm(CipheringAlgorithm const& value)
{
    m_CipheringAlgorithm = value;
    
}

}
}
}
}


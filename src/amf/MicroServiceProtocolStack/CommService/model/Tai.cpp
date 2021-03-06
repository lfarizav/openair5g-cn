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


#include "Tai.h"

namespace org {
namespace openapitools {
namespace server {
namespace model {

Tai::Tai()
{
    m_Tac = "";
    
}

Tai::~Tai()
{
}

void Tai::validate()
{
    // TODO: implement validation
}

nlohmann::json Tai::toJson() const
{
    nlohmann::json val = nlohmann::json::object();

    val["plmnId"] = ModelBase::toJson(m_PlmnId);
    val["tac"] = ModelBase::toJson(m_Tac);
    

    return val;
}

void Tai::fromJson(const nlohmann::json& val)
{
    setTac(val.at("tac"));
    
}


PlmnId Tai::getPlmnId() const
{
    return m_PlmnId;
}
void Tai::setPlmnId(PlmnId const& value)
{
    m_PlmnId = value;
    
}
std::string Tai::getTac() const
{
    return m_Tac;
}
void Tai::setTac(std::string const& value)
{
    m_Tac = value;
    
}

}
}
}
}


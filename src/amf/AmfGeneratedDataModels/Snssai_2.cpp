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


#include "Snssai_2.h"

namespace org {
namespace openapitools {
namespace server {
namespace model {

Snssai_2::Snssai_2()
{
    m_Sst = 0;
    m_Sd = "";
    m_SdIsSet = false;
    
}

Snssai_2::~Snssai_2()
{
}

void Snssai_2::validate()
{
    // TODO: implement validation
}

nlohmann::json Snssai_2::toJson() const
{
    nlohmann::json val = nlohmann::json::object();

    val["sst"] = m_Sst;
    if(m_SdIsSet)
    {
        val["sd"] = ModelBase::toJson(m_Sd);
    }
    

    return val;
}

void Snssai_2::fromJson(const nlohmann::json& val)
{
    setSst(val.at("sst"));
    if(val.find("sd") != val.end())
    {
        setSd(val.at("sd"));
    }
    
}


int32_t Snssai_2::getSst() const
{
    return m_Sst;
}
void Snssai_2::setSst(int32_t const value)
{
    m_Sst = value;
    
}
std::string Snssai_2::getSd() const
{
    return m_Sd;
}
void Snssai_2::setSd(std::string const& value)
{
    m_Sd = value;
    m_SdIsSet = true;
}
bool Snssai_2::sdIsSet() const
{
    return m_SdIsSet;
}
void Snssai_2::unsetSd()
{
    m_SdIsSet = false;
}

}
}
}
}


#include <stdint.h>

#define SECURITY_HEADER_TYPE_MINIMUM_LENGTH 1
#define SECURITY_HEADER_TYPE_MAXIMUM_LENGTH 1 
  
typedef uint8_t SecurityHeaderType;
  
int encode_security_header_type(SecurityHeaderType *securityheadertype, uint8_t iei, uint8_t *buffer, uint32_t len);
  
//void dump_security_header_type_xml(SecurityHeaderType *securityheadertype, uint8_t iei);
  
int decode_security_header_type(SecurityHeaderType *securityheadertype, uint8_t iei, uint8_t *buffer, uint32_t len);

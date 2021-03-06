#include <stdint.h>
#include "bstrlib.h"

#define EAP_MESSAGE_MINIMUM_LENGTH 10
#define EAP_MESSAGE_MAXIMUM_LENGTH 1506

typedef bstring EAPMessage;

int encode_eap_message ( EAPMessage eapmessage, uint8_t iei, uint8_t * buffer, uint32_t len  ) ;
int decode_eap_message ( EAPMessage * eapmessage, uint8_t iei, uint8_t * buffer, uint32_t len  ) ;


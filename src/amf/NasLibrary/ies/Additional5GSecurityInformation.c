#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#include "TLVEncoder.h"
#include "TLVDecoder.h"
#include "Additional5GSecurityInformation.h"

int encode_additional_5g_security_information ( Additional5GSecurityInformation additional5gsecurityinformation, uint8_t iei, uint8_t * buffer, uint32_t len  ) 
{
    uint8_t *lenPtr;
    uint32_t encoded = 0;
    int encode_result;
    CHECK_PDU_POINTER_AND_LENGTH_ENCODER (buffer,ADDITIONAL_5G_SECURITY_INFORMATION_MINIMUM_LENGTH , len);
    

       if( iei >0  )
       {
           *buffer=iei;
               encoded++;
       }



    lenPtr = (buffer + encoded);
    encoded++;



    if ((encode_result = encode_bstring (additional5gsecurityinformation, buffer + encoded, len - encoded)) < 0)//加密,实体,首地址,长度
        return encode_result;
    else
        encoded += encode_result;

    *lenPtr = encoded - 1 - ((iei > 0) ? 1 : 0);    
    return encoded;
}

int decode_additional_5g_security_information ( Additional5GSecurityInformation * additional5gsecurityinformation, uint8_t iei, uint8_t * buffer, uint32_t len  ) 
{
	int decoded=0;
	uint8_t ielen=0;
	int decode_result;

    if (iei > 0)
    {
        CHECK_IEI_DECODER (iei, *buffer);
        decoded++;
    }


    ielen = *(buffer + decoded);
    decoded++;
    CHECK_LENGTH_DECODER (len - decoded, ielen);


    if((decode_result = decode_bstring (additional5gsecurityinformation, ielen, buffer + decoded, len - decoded)) < 0)
        return decode_result;
    else
        decoded += decode_result;
            return decoded;
}


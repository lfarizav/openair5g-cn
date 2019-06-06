#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "ngap_amf_setup_response.h"

#include "Ngap_ProtocolIE-Field.h"
#include "Ngap_BroadcastPLMNItem.h"
#include "Ngap_GNB-ID.h"
#include "Ngap_GlobalGNB-ID.h"
#include "Ngap_PagingDRX.h"
#include "Ngap_SliceSupportItem.h"
#include "Ngap_SupportedTAItem.h"
#include "Ngap_GlobalRANNodeID.h"
#include "Ngap_SuccessfulOutcome.h"

#include "sctp_gNB_defs.h"

#include  "bstrlib.h"
#include  "intertask_interface_types.h"

#include  "Ngap_CriticalityDiagnostics-IE-Item.h"
#include  "Ngap_PLMNSupportItem.h"


//AMFName
Ngap_NGSetupResponseIEs_t *make_AMFName_ie(const char *name)
{
	Ngap_NGSetupResponseIEs_t *ie;
	ie = calloc(1, sizeof(Ngap_NGSetupResponseIEs_t));

   	ie->id = Ngap_ProtocolIE_ID_id_AMFName;
	ie->criticality = Ngap_Criticality_reject;
	ie->value.present = Ngap_NGSetupResponseIEs__value_PR_AMFName;
	OCTET_STRING_fromBuf (&ie->value.choice.AMFName, name, strlen (name));
	
	printf("AMFName:%s\n", ie->value.choice.AMFName.buf);
	
    return ie;
}


//RelativeAMFCapacity
Ngap_NGSetupResponseIEs_t * make_RelativeAMFCapacity_ie(Ngap_RelativeAMFCapacity_t RelativeAMFCapacity)
{
	Ngap_NGSetupResponseIEs_t *ie = NULL;
	ie = calloc(1, sizeof(Ngap_NGSetupResponseIEs_t));
	
	ie->id = Ngap_ProtocolIE_ID_id_RelativeAMFCapacity;
	ie->criticality = Ngap_Criticality_reject;
	ie->value.present = Ngap_NGSetupResponseIEs__value_PR_RelativeAMFCapacity;
    ie->value.choice.RelativeAMFCapacity  =   RelativeAMFCapacity;
	
	printf("RelativeAMFCapacity:%d\n", ie->value.choice.RelativeAMFCapacity);
	
	return ie;
}

//PLMNSupportList
//Ngap_PLMNSupportItem_t

//pLMNIdentity
void fill_PLMNSupportItem_with_pLMNIdentity(Ngap_PLMNIdentity_t	 *pLMNIdentity)
{
    uint8_t plmn[3] = { 0x02, 0xF8, 0x29 };
	OCTET_STRING_fromBuf(pLMNIdentity, (const char*)plmn, 3);

	printf("pLMNIdentity: 0x%x,0x%x,0x%x\n", pLMNIdentity->buf[0],pLMNIdentity->buf[1],pLMNIdentity->buf[2]);
}

void fill_s_NSSAI_sST(Ngap_SST_t *sST)
{
    uint8_t plmn[3] = { 0x02};
	OCTET_STRING_fromBuf(sST, (const char*)plmn, 1);
	printf("NSSAI_sST:0x%x\n",sST->buf[0]);
}
#if 0
void fill_s_NSSAI_sD(Ngap_SD_t	*sD)
{
   
}
#endif
void fill_sliceSupportItem_with_s_NSSAI(Ngap_S_NSSAI_t	 *s_NSSAI)
{
    fill_s_NSSAI_sST(&s_NSSAI->sST);
}
void fill_PLMNSupportItem_with_sliceSupportList(Ngap_SliceSupportList_t	 *sliceSupportList)
{
    Ngap_SliceSupportItem_t *ss = NULL;
	ss = calloc(1, sizeof(Ngap_SliceSupportItem_t));
    fill_sliceSupportItem_with_s_NSSAI(&ss->s_NSSAI);
	ASN_SEQUENCE_ADD(&sliceSupportList->list, ss);
}

Ngap_PLMNSupportItem_t  *make_PLMNSupportItem()
{
    Ngap_PLMNSupportItem_t  *plmn = NULL;
    plmn = calloc(1, sizeof(Ngap_PLMNSupportItem_t));

	fill_PLMNSupportItem_with_pLMNIdentity(&plmn->pLMNIdentity);
	fill_PLMNSupportItem_with_sliceSupportList(&plmn->sliceSupportList);
	return plmn;
}

Ngap_NGSetupResponseIEs_t * make_PLMNSupportList()
{
    Ngap_NGSetupResponseIEs_t *ie = NULL;
	ie = calloc(1, sizeof(Ngap_NGSetupResponseIEs_t));
	
	ie->id = Ngap_ProtocolIE_ID_id_PLMNSupportList;
	ie->criticality = Ngap_Criticality_reject;
	ie->value.present = Ngap_NGSetupResponseIEs__value_PR_PLMNSupportList;

    Ngap_PLMNSupportItem_t  *plmn = NULL;
    plmn= make_PLMNSupportItem();

	ASN_SEQUENCE_ADD(&ie->value.choice.PLMNSupportList.list, plmn);
    return ie;
}
void add_NGSetupResponse_ie(Ngap_NGSetupResponse_t *ngapSetupResponse, Ngap_NGSetupResponseIEs_t *ie)
	{
    int ret;
	ret = ASN_SEQUENCE_ADD(&ngapSetupResponse->protocolIEs.list, ie);
    if ( ret != 0 ) {
        fprintf(stderr, "Failed to add ie\n");
    }
}

Ngap_NGAP_PDU_t *make_NGAP_SetupResponse()
{
	Ngap_NGAP_PDU_t *pdu;
	pdu = calloc(1, sizeof(Ngap_NGAP_PDU_t));
	
	pdu->present = Ngap_NGAP_PDU_PR_successfulOutcome;
	pdu->choice.successfulOutcome = calloc(1, sizeof(Ngap_SuccessfulOutcome_t));
	pdu->choice.successfulOutcome->procedureCode = Ngap_ProcedureCode_id_NGSetup;
	pdu->choice.successfulOutcome->criticality = Ngap_Criticality_reject;
	pdu->choice.successfulOutcome->value.present = Ngap_SuccessfulOutcome__value_PR_NGSetupResponse;
	
	Ngap_NGSetupResponse_t *ngapSetupResponse;
	ngapSetupResponse = &pdu->choice.successfulOutcome->value.choice.NGSetupResponse;

	//Make NGSetupResponse IEs and add it to message
   
	#if 0
	Ngap_AMFName_t	 AMFName;  
	Ngap_RelativeAMFCapacity_t	 RelativeAMFCapacity;
	Ngap_PLMNSupportList_t	 PLMNSupportList;
    #endif

    
    Ngap_NGSetupResponseIEs_t *ie = NULL;

	//AMFName
	ie  = make_AMFName_ie("test gNB");
	add_NGSetupResponse_ie(ngapSetupResponse, ie);


	//RelativeAMFCapacity
	ie  = make_RelativeAMFCapacity_ie(0x80);
	add_NGSetupResponse_ie(ngapSetupResponse, ie);
	
    //PLMNSupportList
	//Ngap_PLMNSupportList_t	 PLMNSupportList;
	ie  = make_PLMNSupportList();
	add_NGSetupResponse_ie(ngapSetupResponse, ie);
	
	#if 0
	ie = make_GlobalRANNodeID_ie();
	add_NGSetupRequest_ie(ngapSetupRequest, ie);
	
	ie = make_RANNodeName_ie("test gNB");
	add_NGSetupRequest_ie(ngapSetupRequest, ie);
	
	ie = make_DefaultPagingDRX_ie(Ngap_PagingDRX_v128);
	add_NGSetupRequest_ie(ngapSetupRequest, ie);
	
	ie = make_supportedTAList();
	add_NGSetupRequest_ie(ngapSetupRequest, ie);
	#endif

	return pdu;
}


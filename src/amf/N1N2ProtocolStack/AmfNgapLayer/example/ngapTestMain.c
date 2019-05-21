#include <stdio.h>
#include <stdlib.h>

#include "ngap_ies_defs.h"
#include "Cause.h"
#include "CauseProtocol.h"
#include "TimeToWait.h"
#include "bstrlib.h"
#include "intertask_interface_types.h"
/*
int
ngap_amf_set_cause (
  Cause_t * cause_p,
  const Cause_PR cause_type,
  const long cause_value)
{           
  //DevAssert (cause_p != NULL);
  cause_p->present = cause_type;
            
  switch (cause_type) {
  case Cause_PR_radioNetwork:
    cause_p->choice.radioNetwork = cause_value;
    break;

  case Cause_PR_transport:
    cause_p->choice.transport = cause_value;
    break;
    
  case Cause_PR_nas:
    cause_p->choice.nas = cause_value;
    break;

  case Cause_PR_protocol:
    cause_p->choice.protocol = cause_value;
    break;

  case Cause_PR_misc:
    cause_p->choice.misc = cause_value;
    break;

  default:
    return -1;
  }

  return 0;
}
*/
int main()
{
  ngap_message message = {0};
  NGSetupFailureIEs_t * ng_setup_failure_p = NULL;
  const Cause_PR cause_type = Cause_PR_transport;
  const long cause_value = CauseProtocol_unspecified;
  const long time_to_wait = TimeToWait_v20s;

  uint8_t * buffer_p = NULL;
  uint32_t length = 0;

  ng_setup_failure_p = &message.msg.ngSetupFailureIEs;
  message.procedureCode = Ngap_ProcedureCode_id_NGSetup;
  message.direction = NGAP_PDU_PR_unsuccessfulOutcome;
  ngap_amf_set_cause (&ng_setup_failure_p->cause, cause_type, cause_value);
  ng_setup_failure_p->presenceMask |= NGSETUPFAILUREIES_TIMETOWAIT_PRESENT;
  ng_setup_failure_p->timeToWait = time_to_wait;

  if (ngap_amf_encode_pdu (&message, &buffer_p, &length) < 0) {
    printf("encode ngap pdu error\n");
  }
  bstring b = blk2bstr(buffer_p, length);
  
  MessagesIds message_id = MESSAGES_ID_MAX;
  ngap_message decoded_message = {0};
  printf("1\n");
  ngap_amf_decode_pdu(&decoded_message,b,&message_id);
  printf("2\n");
  printf("cause_type:%d\n",decoded_message.msg.ngSetupFailureIEs.cause.present);
  printf("timeToWait:%d\n",decoded_message.msg.ngSetupFailureIEs.timeToWait);
  printf("procedureCode:%d\n",decoded_message.procedureCode);
  printf("direction:%d\n",decoded_message.direction);

}
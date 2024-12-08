#ifndef __FW_LIB_L2_ARP_H__
#define __FW_LIB_L2_ARP_H__

#include <packet.h>
#include <protocol_common.h>
#include <logging.h>

namespace fw {

struct arp_hdr {
    uint16_t hdr_type;
    uint16_t protocol_type;
    uint8_t hdr_len;
    uint8_t protocol_len;
    uint16_t op;
    uint8_t sender_hw_addr[FW_LIB_ETH_MACADDR_LEN];
    uint32_t sender_protocol_addr;
    uint8_t target_hw_addr[FW_LIB_ETH_MACADDR_LEN];
    uint32_t target_protocol_addr;

    int serialize(packet &p, logging *log);
    int deserialize(packet &p, logging *log);
    void print(logging *log);
};

}

#endif


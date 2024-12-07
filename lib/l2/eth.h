#ifndef __FW_LIB_L2_ETH_H__
#define __FW_LIB_L2_ETH_H__

#include "protocol_common.h"
#include "packet.h"
#include "logging.h"

namespace fw {

struct eth_hdr {
    uint8_t dst[FW_LIB_ETH_MACADDR_LEN];
    uint8_t src[FW_LIB_ETH_MACADDR_LEN];
    uint16_t ethertype;

    explicit eth_hdr();
    ~eth_hdr();

    int serialize(packet *pkt, logging *log);
    int deserialize(packet *pkt, logging *log);
    void print(logging *log);

    private:
        size_t len_ = 14u;
};

}

#endif


#pragma once

#define FAQ_PROTOS __declspec(dllimport)
#include "faq_client.grpc.pb.h"

class ClientRpc final : public faq_client::Client::Service
{
public:
};

#pragma once

#include "rpc/sample.pb.h"
#include "rpc/sample.grpc.pb.h"

class SampleServiceImpl final : public sample::Sample::Service {
    
public:
    ::grpc::Status Ask(::grpc::ServerContext *contenxt, const sample::AskRequest *req, sample::AskResponse *res) override;
    
};

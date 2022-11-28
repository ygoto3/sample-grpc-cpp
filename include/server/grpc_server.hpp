#pragma once

#include <string.h>
#include <memory.h>
#include <grpcpp/grpcpp.h>

#include "server/services/sample_service.hpp"

class GrpcServer {

public:
    GrpcServer();
    void run();

private:
    std::unique_ptr<grpc::Server> _server;
    std::string _server_address;
    std::unique_ptr<SampleServiceImpl> _sample_service;

};

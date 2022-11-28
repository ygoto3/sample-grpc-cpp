#include "server/grpc_server.hpp"

#include <iostream>
#include <memory.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>

GrpcServer::GrpcServer() {
    _server_address = "localhost:50051";
    _sample_service = std::unique_ptr<SampleServiceImpl>(new SampleServiceImpl);
    
    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();
    grpc::ServerBuilder builder;
    builder.AddListeningPort(_server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(_sample_service.release());
    
    _server = builder.BuildAndStart();
}

void GrpcServer::run() {
    std::cout << "gRPC server is listening on " << _server_address << std::endl;
    _server->Wait();
}

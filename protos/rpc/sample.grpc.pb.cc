// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: rpc/sample.proto

#include "rpc/sample.pb.h"
#include "rpc/sample.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace sample {

static const char* Sample_method_names[] = {
  "/sample.Sample/Ask",
};

std::unique_ptr< Sample::Stub> Sample::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< Sample::Stub> stub(new Sample::Stub(channel, options));
  return stub;
}

Sample::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_Ask_(Sample_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status Sample::Stub::Ask(::grpc::ClientContext* context, const ::sample::AskRequest& request, ::sample::AskResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::sample::AskRequest, ::sample::AskResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Ask_, context, request, response);
}

void Sample::Stub::async::Ask(::grpc::ClientContext* context, const ::sample::AskRequest* request, ::sample::AskResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::sample::AskRequest, ::sample::AskResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Ask_, context, request, response, std::move(f));
}

void Sample::Stub::async::Ask(::grpc::ClientContext* context, const ::sample::AskRequest* request, ::sample::AskResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Ask_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::sample::AskResponse>* Sample::Stub::PrepareAsyncAskRaw(::grpc::ClientContext* context, const ::sample::AskRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::sample::AskResponse, ::sample::AskRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Ask_, context, request);
}

::grpc::ClientAsyncResponseReader< ::sample::AskResponse>* Sample::Stub::AsyncAskRaw(::grpc::ClientContext* context, const ::sample::AskRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncAskRaw(context, request, cq);
  result->StartCall();
  return result;
}

Sample::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Sample_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Sample::Service, ::sample::AskRequest, ::sample::AskResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Sample::Service* service,
             ::grpc::ServerContext* ctx,
             const ::sample::AskRequest* req,
             ::sample::AskResponse* resp) {
               return service->Ask(ctx, req, resp);
             }, this)));
}

Sample::Service::~Service() {
}

::grpc::Status Sample::Service::Ask(::grpc::ServerContext* context, const ::sample::AskRequest* request, ::sample::AskResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace sample


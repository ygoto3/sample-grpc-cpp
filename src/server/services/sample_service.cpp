#include "server/services/sample_service.hpp"

::grpc::Status SampleServiceImpl::Ask(::grpc::ServerContext *contenxt, const sample::AskRequest *req, sample::AskResponse *res) {
    std::cout << "Question received: " << req->question() << std::endl;
    res->set_answer("Your question: " + req->question() + " My answer is: yes.");
    return ::grpc::Status::OK;
}

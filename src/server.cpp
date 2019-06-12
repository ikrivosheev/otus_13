#include "server.h"

Server::Server(boost::asio::io_service& ios, short port):
    _ios(ios), _acceptor(_ios, tcp::endpoint(tcp::v4(), port)) {

    handle_accept();
}


void Server::handle_accept() {
    _acceptor.async_accept([this](const boost::system::error_code& error, tcp::socket socket) {
        if (!error) {        
            std::shared_ptr<Session> session = std::make_shared<Session>(std::move(socket));
            session->start_read();
        }
        else {
            std::cerr << "Error on accept" << error.message() << std::endl;
        }
        handle_accept();
    });
}


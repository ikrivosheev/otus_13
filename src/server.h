#ifndef SERVER_H
#define SERVER_H

#include <memory>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

#include "session.h"

using boost::asio::ip::tcp;


class Server {
    public:
        Server(boost::asio::io_service&, short); 
        ~Server() = default;
    private:
        void handle_accept();

        Server& operator=(const Server&) = delete;
        Server(const Server&) = delete;

        boost::asio::io_service& _ios;
        tcp::acceptor _acceptor;
};

#endif // SERVER_H

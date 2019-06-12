#ifndef SESSION_H
#define SESSION_H

#include <iostream>
#include <memory>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;


class Session: public std::enable_shared_from_this<Session> {
    public:
        Session(tcp::socket socket);
       
        tcp::socket& socket();
        void start_read();
    private:
        Session(const Session&) = delete;
        Session& operator=(const Session&) = delete;

        tcp::socket _socket;
        boost::asio::streambuf _buffer;
};

#endif // SESSION_H

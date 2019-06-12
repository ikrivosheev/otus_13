#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

#include "server.h"


int main(int argc, char* argv[]) {
    if (argc != 2) {
      std::cerr << "Usage: join_server <port>\n";
      return 1;
    }

    try {
        boost::asio::io_service ios;
        Server s(ios, std::atoi(argv[1]));
        ios.run();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

  return 0;
}

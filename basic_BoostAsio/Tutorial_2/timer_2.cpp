#include <iostream>
#include <boost/asio.hpp>

void print(const boost::system::error_code& /*e*/) {
    std::cout << "Print Completed!" << std::endl;
}

int main() {
    // all programs that use asio need to have one of these objects
    // such as io_context or thread_pool object
    // these objects are known as "executors"
    boost::asio::io_context io;
    // Creates a timer object
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5)); 
    // Uses the timer to call the print after the timer has completed
    t.async_wait(&print);
    io.run();
    return 0;
}
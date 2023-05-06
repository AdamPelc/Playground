#include <iostream>
#include <thread>
#include <chrono>

auto main() -> int {
    using namespace std::chrono_literals;
    using namespace std::chrono;

    std::cout << "[Consumer]\t\tStarted\n";
    std::this_thread::sleep_for(500ms);
    std::cout << "[Consumer]\t\tReceiving data\n";

    std::string receivedData;
    std::getline(std::cin, receivedData);
    std::cout << "[Consumer]\t\tReceived data: \"" << receivedData << "\"\n";

    std::this_thread::sleep_for(1s);
    std::cout << "[Consumer]\t\tFinished\n";
    return 0;
}

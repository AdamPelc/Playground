#include <iostream>
#include <thread>
#include <chrono>

auto main() -> int {
    using namespace std::chrono_literals;
    using namespace std::chrono;

    std::cerr << "[Producer(stderr)]\tStarted\n";
    std::this_thread::sleep_for(1s);
    std::cerr << "[Producer(stderr)]\tSending data\n";

    std::cout << "[Producer(stdout)]: Some data from producer\n";

    std::this_thread::sleep_for(1s);
    std::cerr << "[Producer(stderr)]\tFinished\n";
    return 0;
}

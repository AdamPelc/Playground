#include <iostream>
#include <unistd.h>
#include <ranges>
#include <thread>
#include <sstream>

std::string Prefix() {
    std::stringstream buffer;
    buffer << "[Pipe(proc_id:";
    buffer << std::this_thread::get_id();
    buffer << ")]\t";
    return buffer.str();
}

using FileDescriptor = int;

class Pipe {
public:
    Pipe() {
        std::ignore = pipe(&mRead);
    }

    auto Write(const std::ranges::input_range auto& buffer) const {
        std::ignore = write(mWrite, std::ranges::cbegin(buffer), std::ranges::size(buffer));
    }

    [[nodiscard]] auto Read(std::unsigned_integral auto length) const -> std::string {
        std::string buffer(length, 0);
        std::ignore = read(mRead, buffer.data(), buffer.size());
        return buffer;
    }
private:
    FileDescriptor mRead{};
    FileDescriptor mWrite{};
};

using namespace std::chrono_literals;

auto Producer(const Pipe& pipe, std::string_view writeBuffer) {
    std::cout << Prefix() << "Producer thread started\n";
    std::this_thread::sleep_for(1s);
    std::cout << Prefix() << "Producer thread writing: \"" << writeBuffer << "\" to pipe\n";
    pipe.Write(writeBuffer);
    std::this_thread::sleep_for(1s);
    std::cout << Prefix() << "Producer thread finished\n";
}

auto Consumer(const Pipe& pipe, const std::unsigned_integral auto length) {
    std::cout << Prefix() << "Consumer thread started\n";
    std::this_thread::sleep_for(500ms);
    std::cout << Prefix() << "Consumer thread starts reading\n";
    const auto readBuffer = pipe.Read(length);
    std::cout << Prefix() << "Consumer thread read: \"" << readBuffer << "\"\n";
    std::this_thread::sleep_for(1s);
    std::cout << Prefix() << "Consumer thread finished\n";
}

auto main() -> int {
    std::cout << Prefix() << "Main thread started\n";
    Pipe pipeHandle{};
    std::string_view writeBuffer{"How it's flowing?"};
    std::jthread producer(Producer, std::cref(pipeHandle), writeBuffer);
    std::jthread consumer(Consumer<decltype(writeBuffer.size())>, std::cref(pipeHandle), writeBuffer.size());
    std::cout << Prefix() << "Main thread finished\n";
    return 0;
}

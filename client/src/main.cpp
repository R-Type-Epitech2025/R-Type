#include "Core.hpp"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: ./client [ip] [port]" << std::endl;
        return 84;
    }
    rtype::Core core;
    core.run(argc, argv);
    return 0;
}
#include "StationeryStore.hpp"

int main() {
    try {
        UserInterface ui;
        ui.run();
    } catch (const std::exception &e) {
        std::cerr << "程序发生严重错误: " << e.what() << std::endl;
        return 1;
    }
    return 0;
} 
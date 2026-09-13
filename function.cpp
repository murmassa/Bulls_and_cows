#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

#include "game.h"




void print_slow(std::string text, int enter, int delay) { // функция для медленного вывода текста
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
    for (int i = 0; i < enter; ++i) {
        std::cout << std::endl;
    }
}


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <tuple>

#include "game.h"



std::string generate_number() { // функция для генерации случайного числа
    std::string number;
    while (number.length() < 4){
        char digit = rand() % 10;

        if (number.empty() && digit == 0){
            continue; // пропускаем ведущий ноль
        }
        if (number.find('0' +digit) == std::string::npos){
            number += '0' + digit;
        }
    }
    return number;
}


bool check_number(std::string number) {// функция для проверки числа удовлетворяет ли оно условию игры
    if (number.length() != 4) {
        return false;
    }

    if (number[0] == '0'){
        return false;
    }

    for (char c : number){
        if (!isdigit(c)){
            return false;
        }

    }
    if (number[0] == number[1] || number[0] == number[2] || number[0] == number[3] ||
        number[1] == number[2] || number[1] == number[3] ||
        number[2] == number[3]) {
        return false;
    }
    return true;
}

std::tuple<int,int> check_bulls_and_cows(std::string secret_number, std::string player_number){
    int bulls {0};
    int cows {0};
    
    // Проверка быков
    for (int i {0}; i<4; ++i){
        if(secret_number[i] == player_number[i]){
            ++bulls;
            player_number[i] ='B';
        }
    }

    // Проверяем коров
    for(int i {0}; i<4; ++i){
        if (player_number[i] == 'B'){
            continue;
        }
        if (secret_number.find(player_number[i]) != std::string::npos){
            ++cows;
        }
    }
    return {bulls, cows};


}



void start_game_1() {
    // Здесь логика игры_1
    std::string computer_output_number {generate_number()};
    std::string user_input_number;

    while (computer_output_number != user_input_number) {
        print_slow("Введите число:", 2, 3);
        std::cin >> user_input_number;

        while (check_number(user_input_number) == false){
            print_slow("Неверный ввод. Пожалуйста, введите 4-значное число с уникальными цифрами:", 2, 3);
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin >> user_input_number;
        }

        int bulls;
        int cows;
        std::tie(bulls, cows) = check_bulls_and_cows(computer_output_number, user_input_number);

        std::cout << std::endl;
        print_slow("Быков: ", 0, 10);
        std::cout << bulls << std::endl;;
        print_slow("Коров: ", 0, 10);
        std::cout << cows << std::endl;
        
        if (bulls == 4){
            print_slow("Поздравляю!", 1, 5);
            print_slow("Ты победил!", 1, 5);
            print_slow("Отличная работа! Ты угадал загаданное число!", 3, 5);
        }


    }

}


void start_game_2(){
    // Здесь логика игры_2
    
}
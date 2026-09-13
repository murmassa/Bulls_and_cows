#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <tuple>

void print_slow(std::string text, int enter, int delay) { // функция для медленного вывода текста
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
    for (int i = 0; i < enter; ++i) {
        std::cout << std::endl;
    }
}

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

// классы для читаемости вывода из функции menu()
enum class MenuResult {
    Exit  = 0,
    Again = 1,
    Play  = 2
};



// функция main меню игры 
MenuResult menu() { 


    // начальное меню 
    std::string choice;
    std::cout << "1. Начать игру" << std::endl 
        << "2. Инструкция" << std::endl 
        << "3. Выход" << std::endl 
        << std::endl; 
 
    std::cout << "Выберите действие: "; 
    std::cin >> choice;
 

    // действия которые возможны 
    if (choice == "1") { 
        std::cout << std::endl; 
        print_slow("Начинаем игру...", 2, 30);

        return MenuResult::Play; // начинаем игру 
    } 
    else if (choice == "2") { 
        std::cout << std::endl; 
        print_slow("ИНСТРУКЦИЯ:", 1, 5);
        print_slow("В этой игре вам нужно угадать загаданное число.", 1, 5); 
        print_slow("Вы должны вводить 4-значные числа с уникальными цифрами.", 1, 5); 
        print_slow("После каждой попытки вы получите подсказку в виде количества быков и коров.", 1, 5); 
        print_slow("Бык — правильная цифра стоит на правильном месте.", 1, 5); 
        print_slow("Корова — правильная цифра есть, но стоит не на своём месте.", 1, 5); 
        print_slow("Но также компьютер будет угадывать ваше число, и вы должны будете давать ему подсказки.", 1, 5); 
        print_slow("Удачи!", 2, 30); 

        return MenuResult::Again; // возвращаемся в меню
    } 
    else if (choice == "3") {
        std::cout << std::endl ;
            print_slow("Выход из игры...", 2, 30);
            print_slow("До свидания!", 2, 30);

        return MenuResult::Exit; // конец игры, завершение 

    } 

    // если в cin пошло не то 
    else { 
        std::cout << std::endl;
        print_slow("Неверный выбор.", 1, 30);
        print_slow("Пожалуйста, выберите 1, 2 или 3.", 2, 30);
        std::cin.clear();
        std::cin.ignore(1000, '\n');

        return MenuResult::Again; // возвращаемся в меню
    } 
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



int main() {
    srand(time(0));
    print_slow("Загрузка игры...", 2, 30);

    std::cout << "========================================" << std::endl;
    print_slow("          Игра 'Быки и Коровы'          ", 1, 30);
    std::cout << "========================================" << std::endl
        << std::endl;

    print_slow("Добро пожаловать в игру!", 2, 30);

    // вызов функции меню и вызов самой игры 
    
    while (true) {
        switch(menu()) {

            case MenuResult::Play:
                start_game_1();
                continue; // после игры отправляет в меню снова чтобы начать новую или выйти из игры
            
            case MenuResult::Exit:
                return 0; // завершение программы полностью 
            
            case MenuResult::Again:
                continue; // повторение при вызове меню снова, например при ошибке 
            
            default:
                return 0; 
        }
    }
}
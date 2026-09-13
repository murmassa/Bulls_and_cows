#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <thread>
#include <chrono>


void printSlow(std::string text, int enter, int delay) { // функция для медленного вывода текста
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
    for (int i = 0; i < enter; ++i) {
        std::cout << std::endl;
    }
}
/*
std::vector generateAllCombinations() {  
    std::vector combinations;

    for (int i = 1023; i <= 9876; ++i) {
        std::string s = std::to_string(i);

        // Проверка уникальности всех 4 цифр
        if (s[0] != s[1] && s[0] != s[2] && s[0] != s[3] &&
            s[1] != s[2] && s[1] != s[3] && s[2] != s[3]) {
            combinations.push_back(s);
        }
    }
    return combinations;
}
int random4() //генератор случайных 4 значных чисел
{
    std::random_device rd;
    std::mt19937 gen(rd());//это алгоритм «Вихрь Мерсенна»
    std::uniform_int_distribution<int> dist(1000, 9999);
    int random_num = dist(gen);
    return random_num;
}
*/

// классы для читаемости вывода из функции menu()
enum class MenuResult {
    Exit  = 0,
    Again = 1,
    Play  = 2
};



// функция мейн меню игры 
MenuResult menu() { 


    // начанльное меню 
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
        printSlow("Начинаем игру...", 2, 30);

        return MenuResult::Play; // начнинаем игру 
    } 
    else if (choice == "2") { 
        std::cout << std::endl; 
        printSlow("ИНСТРУКЦИЯ:", 1, 5);
        printSlow("В этой игре вам нужно угадать загаданное число.", 1, 5); 
        printSlow("Вы должны вводить 4-значные числа с уникальными цифрами.", 1, 5); 
        printSlow("После каждой попытки вы получите подсказку в виде количества быков и коров.", 1, 5); 
        printSlow("Бык — правильная цифра стоит на правильном месте.", 1, 5); 
        printSlow("Корова — правильная цифра есть, но стоит не на своём месте.", 1, 5); 
        printSlow("Но также компьютер будет угадывать ваше число, и вы должны будете давать ему подсказки.", 1, 5); 
        printSlow("Удачи!", 2, 30); 

        return MenuResult::Again; // возвращаемся в меню
    } 
    else if (choice == "3") {
        std::cout << std::endl ;
            printSlow("Выход из игры...", 2, 30);
            printSlow("До свидания!", 2, 30);

        return MenuResult::Exit; // конец игры, завершение 

    } 

    // если в cin пошло не то 
    else { 
        std::cout << std::endl;
        printSlow("Неверный выбор.", 1, 30);
        printSlow("Пожалуйста, выберите 1, 2 или 3.", 2, 30);
        std::cin.clear();
        std::cin.ignore(1000, '\n');

        return MenuResult::Again; // возвращаемся в меню
    } 
}



int main() {
    printSlow("Загрузка игры...", 2, 30);

    std::cout << "========================================" << std::endl;
    printSlow("          Игра 'Быки и Коровы'          ", 1, 30);
    std::cout << "========================================" << std::endl
        << std::endl;

    printSlow("Добро пожаловать в игру!", 2, 30);

    // вызов функции меню и вызов самой игры 
    
    while (true) {
        switch(menu()) {

            case MenuResult::Play:
                //PlayGame
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
#include <iostream>
#include <random>
#include <vector>
#include <string>

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


int 
int main() {
    int random_number = random4();
    std::cout << random_number << std::endl;
    return 0;
}
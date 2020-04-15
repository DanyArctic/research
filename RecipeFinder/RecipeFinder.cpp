#include <algorithm>
#include <iostream>
#include <vector>

int main ()
{
    std::vector <std::string> ingredients_recipe_1 {"Йогурт", "Кокосовое молоко", "Сахарная пудра",
    "Кокосовая стружка", "Семена чиа", "Манго консервированное"};
    std::string user_input;
    //std::cin >> user_input;
    std::getline(std::cin, user_input); //read until end of line
    /*
        cin reads a word
        getline calls cin untill the end of the line 

        http://www.cplusplus.com/reference/string/string/getline/
    */

    std::vector<std::string> user_ingr;
    std::string current_ingr;

    for (char c : user_input)
    {
        if (c == ',')
        {
            user_ingr.push_back(current_ingr);
            current_ingr.clear();
        }
        else
        {
            current_ingr += c;
        }
    }
    user_ingr.push_back(current_ingr); 

    bool doesUserHaveAllIngr = true;
    // проверить, что есть все продукты

    for (std::string ingr : ingredients_recipe_1)
    {
                //std::cout << ingr << std::endl; 1) "Йогурт", 2) Кокосовое молоко
        std::vector<std::string>::iterator iter = std::find(user_ingr.begin(), user_ingr.end(), ingr);
        if (iter == user_ingr.end()) // если не нашли продукт из рецепта у пользователя
        {
            doesUserHaveAllIngr = false;
            break; // выходит из for преждевременно
        }
    }
    if (doesUserHaveAllIngr) // операция true == true -> вернёт true, поэтому не обязательно писать полностью
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }

    return 0;
}    
//
// Created by thxxe on 10.10.2023.
//

#ifndef CONSOLE_APP_AWARIA_H
#define CONSOLE_APP_AWARIA_H
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <vector>
#include <string>


class Awaria {
public:
    Awaria() = default;

    Awaria(std::string nazwa_param, std::string opis_param, std::vector<int> data_vector_param);

    std::string nazwa;
    std::string opis;
    std::vector<int> data_vector;
    ~Awaria();

    bool is_file_readable();
    void uzupelnij_dane();
    unsigned long long int czas_utworzenia();
    unsigned long long int licz_czas_trwania(unsigned long long int czas_utworzenia);

};

#endif //CONSOLE_APP_AWARIA_H

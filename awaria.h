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
    std::string data_utworzenia_string;
    ~Awaria();

    bool is_file_readable();
    void uzupelnij_dane();
    std::string zwroc_date();
    std::string roznica_czasu(const std::string& data_poczatkowa, const std::string& data_koncowa);
};

#endif //CONSOLE_APP_AWARIA_H

#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include <fstream>
#include "awaria.h"


void wyswietl_menu_glowne(std::vector<int> data, std::vector<int> godzina);
std::vector<int> zwroc_date();
std::vector<int> zwroc_godzine();
void wyswietl_godzine(std::vector<int> godzina);
void wyswietl_date(std::vector<int> data);
std::string zwroc_date_string(std::vector<int> data);




int main() {
    //    Awaria(std::string nazwa_param, std::string opis_param, std::vector<int> data_vector_param);
    std::string nazwa_awarii = "awaria1";
    std::string nazwa_awarii2 = "awaria2";
    std::string opis_awarii = "maszyna zepsuta";
    std::string opis_awarii2 = "maszyna zepsuta2";
    std::vector<int> tablica = zwroc_date();
    std::vector<int> tablica2 = zwroc_godzine();
    Awaria awaria1(nazwa_awarii, opis_awarii, tablica);
    Awaria awaria2(nazwa_awarii2, opis_awarii2, tablica);

    std::fstream plik;
    plik.open("awaria_dane.txt", std::ios::out);
    if (plik.good() == true) {
        std::cout << "Uzyskano dostep do pliku!" << std::endl;
        //tu operacje na pliku
    } else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;

    std::cout << "czy klasa ma dostep do pliku:" << awaria1.is_file_readable() << std::endl;


    awaria1.uzupelnij_dane();
    awaria2.uzupelnij_dane();


    while (true) {
        std::thread menu_display(wyswietl_menu_glowne, zwroc_date(), zwroc_godzine());
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        menu_display.join();
        std::vector<int> tablica = zwroc_date();
        std::vector<int> tablica2 = zwroc_godzine();
        wyswietl_godzine(zwroc_godzine());
        wyswietl_date(zwroc_date());


    }
    return 0;
}


    std::vector<int> zwroc_date() {
        // Pobieranie aktualnego czasu
        std::time_t currentTime = std::time(nullptr);

        // Konwersja czasu na czytelną dla ludzi formę
        std::tm *localTime = std::localtime(&currentTime);

        auto rok = (localTime->tm_year + 1900);
        auto miesiac = (localTime->tm_mon + 1);
        auto dzien = (localTime->tm_mday);
        std::vector<int> data;
        data.push_back(rok);
        data.push_back(miesiac);
        data.push_back(dzien);

        return data;
    }

    std::vector<int> zwroc_godzine() {
        // Pobieranie aktualnego czasu
        std::time_t currentTime = std::time(nullptr);
        // Konwersja czasu na czytelną dla ludzi formę
        std::tm *localTime = std::localtime(&currentTime);

        auto godzina = (localTime->tm_hour);
        auto minuta = (localTime->tm_min);
        auto sekunda = (localTime->tm_sec);

        std::vector<int> zwrot_godzina;
        zwrot_godzina.push_back(godzina);
        zwrot_godzina.push_back(minuta);
        zwrot_godzina.push_back(sekunda);

        return zwrot_godzina;
    };

    void wyswietl_godzine(std::vector<int> godzina) {
        int k = 0;
        for (auto i: godzina) {
            if (k < godzina.size()) {
                std::cout << i << ":";
                k++;
            } else
                std::cout << i;
            k++;
        }
    }

    void wyswietl_date(std::vector<int> data) {
        int k = 0;
        for (auto i: data) {
            if (k < data.size()) {
                std::cout << i << ".";
                k++;
            } else
                std::cout << i;
            k++;
        }
    }

    std::string zwroc_date_string(std::vector<int> data) {
        int k = 0;
        std::string concat;
        for (auto i: data) {
            if (k < data.size()) {
                concat += std::to_string(i);
                concat += ".";
                k++;
            } else
                concat += std::to_string(i);
            k++;
        }
        return concat;
    }

    void wyswietl_menu_glowne(std::vector<int> data, std::vector<int> godzina) {
        std::string wewn_data = [](auto data) {
            int k = 0;
            std::string concat;
            for (auto i: data) {
                if (k < data.size()) {
                    concat += std::to_string(i);
                    concat += ".";
                    k++;
                } else
                    concat += std::to_string(i);
                k++;
            }
            return concat;
        }(data);
        std::string wewn_godzina = [](auto data) {
            int k = 0;
            std::string concat;
            for (auto i: data) {
                if (k < data.size()) {
                    concat += std::to_string(i);
                    concat += ":";
                    k++;
                } else
                    concat += std::to_string(i);
                k++;
            }
            return concat;
        }(godzina);
        std::cout << "dzis jest: " << wewn_data << " godzina: " << wewn_godzina << std::endl;
        std::cout << "*********************************************************************************" << std::endl;
        std::cout << "***  1. Zgloszenie awarii                                                     ***" << std::endl;
        std::cout << "***  2. Aktualne awarie                                                       ***" << std::endl;
        std::cout << "***  3. Usuwanie awarii                                                       ***" << std::endl;
        std::cout << "***                                                                           ***" << std::endl;
        std::cout << "*********************************************************************************" << std::endl;
        //uśpienie wątku na 2s
        //std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }



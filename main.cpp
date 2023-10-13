#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include "awaria.h"


void wyswietl_menu_glowne(std::vector<int> data, std::vector<int> godzina);
std::vector<int> zwroc_date();
std::vector<int> zwroc_godzine();
void wyswietl_godzine(std::vector<int> godzina);
void wyswietl_date(std::vector<int> data);
std::string zwroc_date_string(std::vector<int> data);
void zgloszenie_awarii(std::string nazwa_awarii, std::string opis_awarii, std::vector<int> data_vector);
void uzupelnij_mape(std::map<int, std::string>& mapa_awarii, std::string& nazwa_awarii);
void wyswietlanie_aktualnych_awarii(std::map<int, std::string>& mapa_awarii);
void kasowanie_podanej_awarii(std::map<int, std::string>& mapa_awarii, int wybor);




int main() {
    std::fstream plik;
    plik.open("awaria_dane.txt", std::ios::out);
    if (plik.good() == true) {
        std::cout << "Uzyskano dostep do pliku!" << std::endl;
    } else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;

    std::vector data = zwroc_date();
    std::vector godzina = zwroc_godzine();
    std::string nazwa_awarii;
    std::string opis_awarii;

    std::map<int, std::string> mapa_awarii;
    mapa_awarii.insert(std::pair<int, std::string>(1, "awaria1"));
    mapa_awarii.insert(std::pair<int, std::string>(2, "awaria2"));
    mapa_awarii.insert(std::pair<int, std::string>(3, "awaria3"));



    std::cout << mapa_awarii.size();


    while(1){
        wyswietl_menu_glowne(data, godzina);
        int wybor = 0;
        std::cin >> wybor;
        switch(wybor){
            case 1:
                std::cout << "podaj nazwe awarii" << std::endl;
                std::cin >> nazwa_awarii;
                std::cout << "podaj opis awarii" << std::endl;
                std::cin >> opis_awarii;
                zgloszenie_awarii(nazwa_awarii, opis_awarii, zwroc_date());
                std::cout << "pomyslnie utworzono record o nazwie: " << nazwa_awarii << "z opisem: " << opis_awarii << " z data: " << zwroc_date_string << std::endl;
                uzupelnij_mape(mapa_awarii, nazwa_awarii);
                break;
            case 2:
                //wyswietlanie aktualnych awarii
                wyswietlanie_aktualnych_awarii(mapa_awarii);
                break;
            case 3:
                //kasowanie awarii
                std::cout << "czy chcesz wyswietlic awarie? y/n" << std::endl;
                char wybor;
                std::cin >> wybor;
                if (wybor == 'y') {
                    wyswietlanie_aktualnych_awarii(mapa_awarii);
                }
                else if(wybor == 'n'){
                    std::cout << "podaj numer awarii ktora chcesz usunac:";
                    int wybor2 = 0;
                    std::cin >> wybor2;
                    kasowanie_podanej_awarii(mapa_awarii, wybor2);
                    break;
                }
                else{
                    std::cout << "podales zly znak" << std::endl;
                    break;
                }
            case 9:
                std::cout << "koncze dzialanie programu" << std::endl;
                return 0;
        }
    }

    return 0;
}

void kasowanie_podanej_awarii(std::map<int, std::string>& mapa_awarii, int wybor) {
    if (mapa_awarii.erase(wybor) == true) {
        std::cout << "usunieto";
    } else {
        std::cout << "cos poszlo nie tak przy usuwaniu" << std::endl;
    }
}


void uzupelnij_mape(std::map<int, std::string>& mapa_awarii, std::string& nazwa_awarii){
    int temp = mapa_awarii.size();
    std::cout << "testowy numer mapy: " << temp << std::endl;
    mapa_awarii.insert(std::pair<int, std::string>(temp, nazwa_awarii));
}

void wyswietlanie_aktualnych_awarii(std::map<int, std::string>& mapa_awarii){
    for(auto& i : mapa_awarii){
        int klucz = i.first;
        std::string nazwa_awarii = i.second;
        std::cout << "Numer: " << klucz << " Nazwa: " << nazwa_awarii << std::endl;
    }
}


    std::vector<int> zwroc_date() {
        std::time_t currentTime = std::time(nullptr);
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
        std::time_t currentTime = std::time(nullptr);
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

    void zgloszenie_awarii(std::string nazwa_awarii, std::string opis_awarii, std::vector<int> data_vector){
        Awaria awaria(nazwa_awarii, opis_awarii, data_vector);
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
    }



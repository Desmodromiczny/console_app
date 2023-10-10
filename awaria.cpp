//
// Created by thxxe on 10.10.2023.
//

#include <fstream>
#include "awaria.h"

    Awaria::Awaria(std::string nazwa_param, std::string opis_param, std::vector<int> data_vector_param){
        nazwa = nazwa_param;
        opis = opis_param;
        data_vector = data_vector_param;
    }
    Awaria::~Awaria(){

}

    std::string nazwa;
    std::string opis;
    std::vector<int> data_vector;


    bool Awaria::is_file_readable(){
        std::fstream plik("awaria_dane.txt");
        if (plik.is_open() == true)
        {
            plik.close();
            return true;
        }
        else {return false;}

    }

    void Awaria::uzupelnij_dane(){
        std::ofstream plik("awaria_dane.txt", std::ios::app);
        if(plik.is_open() == false)
        {
            std::cout << "nie udalo sie zapisac do pliku" << std::endl;
        }
        plik << "==========" << std::endl;
        plik << "Nazwa: " << nazwa << std::endl;
        plik << "Opis: " << opis << std::endl;
        plik << "Data Vector: ";
        int k = 0;
        for(int i : data_vector){
            if(k < (data_vector.size() -1)){
                    plik << i << " ";
                    k++;
                    std::cout << k << std::endl;
                }
            else {
                plik << i << std::endl;
            }
        }
        plik << "==========" <<std::endl;


    }

    unsigned long long int Awaria::czas_utworzenia(){
            auto start = std::chrono::steady_clock::now();
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            auto end = std::chrono::steady_clock::now();
            auto end2 = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
            unsigned long long int miliseconds = static_cast<long long int>(end2.count());
            auto end3 = std::chrono::duration_cast<std::chrono::seconds>(end-start);
            auto end4 = std::chrono::duration_cast<std::chrono::hours>(end-start);
            auto end5 = std::chrono::duration_cast<std::chrono::hours>(end-start) /24;

//            std::cout << end2.count() << "milisekund" << std::endl;
//            std::cout << end3.count() << "sekund" << std::endl;
//            std::cout << end4.count() << "godzin" << std::endl;
//            std::cout << end5.count() << "dni" << std::endl;

            return miliseconds;
    };
//TODO - nie działa, poprawić

    unsigned long long int licz_czas_trwania(unsigned long long int czas_utworzenia){

        auto zakonczenie = std::chrono::steady_clock::now();
        unsigned long long int end_miliseconds = static_cast<unsigned long long int>(zakonczenie.count());
        unsigned long long int wynik = (end_miliseconds - zakonczenie);
        //unsigned long long int miliseconds = static_cast<long long int>(end2.count());
        return wynik;

    };





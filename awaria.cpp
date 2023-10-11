//
// Created by thxxe on 10.10.2023.
//

#include <fstream>
#include "awaria.h"

    Awaria::Awaria(std::string nazwa_param, std::string opis_param, std::vector<int> data_vector_param){
        nazwa = nazwa_param;
        opis = opis_param;
        data_vector = data_vector_param;
        data_utworzenia_string = zwroc_date();

    }
    Awaria::~Awaria(){
}

    std::string nazwa;
    std::string opis;
    std::vector<int> data_vector;
    std::string data_utworzenia_string;


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
        plik << "Data utworzenia string: " << data_utworzenia_string << std::endl;
        plik << "==========" <<std::endl;


    }


     std::string Awaria::zwroc_date() {
         time_t now = time(0);
         tm *lokalny_czas = localtime(&now);
         char czas[100];
         strftime(czas, 100, "%Y-%m-%d %H:%M:%S", lokalny_czas);
         return czas;
     }

std::string Awaria::roznica_czasu(const std::string& data_poczatkowa, const std::string& data_koncowa) {
    std::tm czas_tm_pocz = {};
    std::istringstream ss_pocz(data_poczatkowa);
    ss_pocz >> std::get_time(&czas_tm_pocz, "%Y-%m-%d %H:%M:%S");
    std::time_t data_unix_pocz = std::mktime(&czas_tm_pocz);

    std::tm czas_tm_kon = {};
    std::istringstream ss_kon(data_koncowa);
    ss_kon >> std::get_time(&czas_tm_kon, "%Y-%m-%d %H:%M:%S");
    std::time_t data_unix_kon = std::mktime(&czas_tm_kon);

    std::time_t roznica = data_unix_kon - data_unix_pocz;

    int dni = roznica / (60 * 60 * 24);
    int godziny = (roznica % (60 * 60 * 24)) / (60 * 60);
    int minuty = (roznica % (60 * 60)) / 60;
    int sekundy = roznica % 60;

    std::ostringstream wynik;
    wynik << dni << " dni, " << godziny << " godzin, " << minuty << " minut, " << sekundy << " sekund";
    return wynik.str();
}






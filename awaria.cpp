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







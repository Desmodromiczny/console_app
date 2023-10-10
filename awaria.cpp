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





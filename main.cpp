#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <vector>

void wyswietl_menu_glowne();

std::vector<int> zwroc_date();
std::vector<int> zwroc_godzine();
void wyswietl_godzine(std::vector<int> godzina);
void wyswietl_date(std::vector<int> data);


int main() {

    //std::thread menu_display(wyswietl_menu_glowne);
    //menu_display.join();



    std::vector<int> tablica = zwroc_date();
    std::vector<int> tablica2 = zwroc_godzine();
    wyswietl_godzine(zwroc_godzine());
    wyswietl_date(zwroc_date());

    return 0;
}

std::vector<int> zwroc_date(){
    // Pobieranie aktualnego czasu
    std::time_t currentTime = std::time(nullptr);

    // Konwersja czasu na czytelną dla ludzi formę
    std::tm* localTime = std::localtime(&currentTime);

    auto rok = (localTime->tm_year + 1900);
    auto miesiac = (localTime->tm_mon + 1);
    auto dzien = (localTime->tm_mday);
    std::vector<int> data;
    data.push_back(rok);
    data.push_back(miesiac);
    data.push_back(dzien);

    return data;
}

std::vector<int> zwroc_godzine(){
        // Pobieranie aktualnego czasu
        std::time_t currentTime = std::time(nullptr);
        // Konwersja czasu na czytelną dla ludzi formę
        std::tm* localTime = std::localtime(&currentTime);

    auto godzina = (localTime->tm_hour);
    auto minuta = (localTime->tm_min);
    auto sekunda = (localTime->tm_sec);

    std::vector<int> zwrot_godzina;
    zwrot_godzina.push_back(godzina);
    zwrot_godzina.push_back(minuta);
    zwrot_godzina.push_back(sekunda);

    return zwrot_godzina;
};

void wyswietl_godzine(std::vector<int> godzina){
    int k = 0;
    for(auto i : godzina){
        if (k < godzina.size()) {
            std::cout << i << ":";
            k++;
        }
        else
            std::cout << i;
            k++;
    }
}

void wyswietl_date(std::vector<int> data){
    int k = 0;
    for(auto i : data){
        if (k < data.size()) {
            std::cout << i << ".";
            k++;
        }
        else
            std::cout << i;
        k++;
    }
}



void wyswietl_menu_glowne(std::vector<int> data, std::vector<int> godzina ){
    while(true) {
        std::cout << "*********************************************************************************" << std::endl;
        std::cout << "***                                                                           ***" << std::endl;
        std::cout << "***                                                                           ***" << std::endl;
        std::cout << "***                                                                           ***" << std::endl;
        std::cout << "***                                                                           ***" << std::endl;
        std::cout << "*********************************************************************************" << std::endl;
        //uśpienie wątku na 2s
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }

}

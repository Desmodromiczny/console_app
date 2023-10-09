#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <vector>

void wyswietl_menu_glowne();

std::vector<int> wyswietl_czas;

int main() {
    int i = 0;
    int time = 2000;
    /*
    std::thread menu_display(wyswietl_menu_glowne);
    menu_display.join();

*/
    return 0;
}


void wyswietl_menu_glowne(){
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

std::vector<int> wyswietl_czas(){
    // Pobieranie aktualnego czasu
    std::time_t currentTime = std::time(nullptr);

    // Konwersja czasu na czytelną dla ludzi formę
    std::tm* localTime = std::localtime(&currentTime);

    // Wyświetlanie aktualnej daty i godziny
    std::cout << "Aktualna data i godzina: ";
    std::cout << (localTime->tm_year + 1900) << "-" << (localTime->tm_mon + 1) << "-" << localTime->tm_mday;
    std::cout << " " << localTime->tm_hour << ":" << localTime->tm_min << ":" << localTime->tm_sec << std::endl;

    auto rok = (localTime->tm_year + 1900),
    auto miesiac = (localTime->tm_mon + 1); ;
    auto dzien = (localTime->tm_mday);
    std::vector<int> data;
    data.push_back(rok);
    data.push_back(miesiac);
    data.push_back(dzien);

    return data;

}
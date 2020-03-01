#include <iostream>

#include "proces.h"





int load_process() {
	std::string name;
	std::cout << std::endl << "Wpisz nazwe pliku" << std::endl;
	std::cin >> name;
	std::cout << name;
	process process_1(name);
	std::cout << "DLugosc procesu: " << process_1.calculate_length_of_process() << std::endl;
	process_1.print_order();
	process_1.sort_process_first();
	std::cout << "DLugosc procesu: " << process_1.calculate_length_of_process() << std::endl;
	process_1.print_order();
	
	return 0;
}

int menu() {
    std::cout << std::endl << "n - nowy proces," << std::endl << "k - koniec programu" << std::endl;
    char wybor;
    std::cin >> wybor;
    switch (wybor) {
    case'n':
		load_process();
		break;
	case 'k':
		exit(0);
    }
	return 0;
}

int main() {
	while(1)
	{
		menu();
	}
    return 0;
}
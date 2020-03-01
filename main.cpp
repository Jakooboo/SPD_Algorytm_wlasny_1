#include <iostream>
#include <algorithm>
#include <vector>


class process {
private:
    const unsigned int size_of_process;
    const std::vector<int>* front_time;
    const std::vector<int>* middle_time;
    const std::vector<int>* end_time;
    int* order;
public:
    process(std::vector<int>*, std::vector<int>*, std::vector<int>*, int);
    int calculate_length_of_process();
    int* sort_process();
};

process::process(std::vector<int>* a, std::vector<int>* b, std::vector<int>* c, int n) : front_time(a), middle_time(b), end_time(c), size_of_process(n) {}

int process::calculate_length_of_process() {
    int
}

int* process::sort_process() {
    int order_table[size_of_process];

    return nullptr;
}

int load_file() {
    FILE
}

int menu() {
    std::cout << std::endl << "n - nowy proces," << std::endl << "k - koniec programu" << std::endl;
    char wybor;
    std::cin >> wybor;
    switch (wybor) {
    case'n':

    }
}

int main() {

    return 0;
}
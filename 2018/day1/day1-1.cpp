#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    std::ifstream input(argv[1]);
    std::string line;
    int frequency = 0;
    std::string::size_type sz;

    if (input.is_open()) {
        while (std::getline(input, line)) {
            if (line[0] == '-') {
                frequency -= std::stoi(line.substr(1,line.size()), &sz);
            } else {
                frequency += std::stoi(line.substr(1, line.size()), &sz);
            }
        }

        input.close();
    }

    std::cout << "Remaining Frequency: " << frequency << '\n';

    return 0;
}

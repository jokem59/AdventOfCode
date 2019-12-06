#include <iostream>
#include <fstream>
#include <string>
#include <map>

bool LoopThroughInput(int& frequency, char* filename, std::map<int,int>& m) {
    std::ifstream input(filename);
    std::string line;
    std::string::size_type sz;
    std::map<int, int>::iterator it;
    bool found = false;


    if (input.is_open()) {
        while (std::getline(input, line)) {
            if (line[0] == '-') {
                frequency -= std::stoi(line.substr(1,line.size()), &sz);
            } else {
                frequency += std::stoi(line.substr(1, line.size()), &sz);
            }

            it = m.find(frequency);
            if (it != m.end()) {
                std::cout << "Duplicate found\n";
                found = true;
                break;
            }
            else {
                m[frequency] = 1;
            }
        }

        input.close();
    }

    return found;
}

int main(int argc, char* argv[]) {
    int frequency = 0;
    std::map<int, int> m;
    bool isFound = false;

    while (!isFound) {
        isFound = LoopThroughInput(frequency, argv[1], m);
    }


    std::cout << "First Duplicate Frequency: " << frequency << '\n';

    return 0;
}

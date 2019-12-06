#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>

std::pair<int, int> ReturnHits(const std::map<char, int>& m) {
    auto p = std::make_pair(0, 0);
    bool countedTwo = false;
    bool countedThree = false;

    for (const std::pair<char, int>& x : m) {
        if (countedTwo == false && x.second == 2) {
            countedTwo = true;
            p.first = 1;
        }

        if (countedThree == false && x.second == 3) {
            countedThree = true;
            p.second = 1;
        }
    }

    return p;
}

std::map<char, int> MapChars(const std::string& line) {
    std::map<char, int> m;

    for (const char c : line) {
        if (m.find(c) == m.end())
            m[c] = 1;
        else
            m[c] += 1;
    }

    return m;
}

int CheckSum(char* filename) {
    std::ifstream input(filename);
    std::string line;
    std::string::size_type sz;
    std::map<char, int> m;
    auto result = std::make_pair(0, 0);
    int checkSum = 0;

    if (input.is_open()) {
        while (std::getline(input, line)) {
            auto p = std::make_pair(0, 0);
            m = MapChars(line);
            p = ReturnHits(m);
            result.first += p.first;
            result.second += p.second;
        }
    }

    checkSum = result.first * result.second;

    return checkSum;
}

int main(int argc, char* argv[]) {
    int checkSum = 0;

    checkSum = CheckSum(argv[1]);

    std::cout << "Checksum: " << checkSum << '\n';

    return 0;
}

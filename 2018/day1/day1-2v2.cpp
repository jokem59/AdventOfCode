#include <iostream>
#include <fstream>
#include <string>
#include <vector>

typedef struct Props_t {
    int shift = 0;
    std::vector<int> inputs;
    std::vector<std::vector<int>> modGroup;
} Props;

Props GetInput(char* filename) {
    std::ifstream input(filename);
    std::string line;
    std::string::size_type sz;
    Props p;

    if (input.is_open()) {
        while (std::getline(input, line)) {
            int temp = 0;
            if (line[0] == '-') {
                temp = std::stoi(line.substr(1, line.size()), &sz);
                p.shift -= temp;
                p.inputs.push_back(temp * -1);
            } else {
                temp = std::stoi(line.substr(1, line.size()), &sz);
                p.shift += temp;
                p.inputs.push_back(temp);
            }
        }
    }
    return p;

}

// TODO: Run with windbg to find out why it's only looping over
Props PopulateModGroups(Props& properties) {
    int modResult;
    std::vector<std::vector<int>> mods(properties.shift);

    std::cout << "Number of inputs: " << properties.inputs.size() << '\n';

    for (auto num : properties.inputs) {
        std::cout << num << " \n";
        modResult = num % properties.shift;
        mods[modResult].push_back(num);
    }

    properties.modGroup = mods;

    return properties;
}

int main(int argc, char* argv[]) {
    Props properties;

    properties = GetInput(argv[1]);
    std::cout << "Shift: " << properties.shift << '\n';

    properties = PopulateModGroups(properties);
    std::cout << "First replication: " << properties.modGroup[0][0] << '\n';


    return 0;
}

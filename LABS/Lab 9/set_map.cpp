#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <map>

// Function to check if a value exists in a set
bool set(const std::string &value, const std::set<std::string> &countries) {
    return countries.find(value) != countries.end();
}

// Function to look up a value in a map and return its corresponding integer
int map(const std::string &value, const std::map<std::string, int> &stateCases) {
   std::map<std::string, int>::const_iterator it = stateCases.find(value);
    if(it != stateCases.end()){
        return it->second;
    }
    return 0;
}

// Function to process data and commands files
void processFiles(const std::string& dataFileName, const std::string& commandsFileName){
    std::set<std::string> countries;
    std::map<std::string, int> stateCases;
    int cases = 0;

    int i = 0;
    
    std::string country;
    std::string state;
    std::string line;
    std::ifstream dataFile(dataFileName);

   

    // Skip the first line
    std::getline(dataFile, line);

    while(std::getline(dataFile, line)){
        std::stringstream streamline(line);
        std::string entry;

        while (std::getline(streamline, entry, ',')){
            if(i == 3){
                country = entry;
            }
            if(i == 2){
                state = entry;
            }
            if(i == 7){
                cases = std::stoi(entry);
            }
            i++;
        }

        if(!state.empty()){
            stateCases[state] = cases;
        } 
        else{
            stateCases[country] = cases;
        }
        countries.insert(country);
        i = 0;
    }

    dataFile.close();

    std::ifstream commandsFile(commandsFileName);

    

    while(std::getline(commandsFile, line)){
        std::stringstream ss(line);
        std::string value;

        while (std::getline(ss, value, ' ')) {
            if (std::getline(ss, value, '\n')) {
                if (line[0] == 's') {
                    std::cout << set(value, countries) << std::endl;
                } else {
                    std::cout << map(value, stateCases) << std::endl;
                }
            }
        }
    }

    commandsFile.close();
}

int main(int argc, char *argv[]) {
   
    processFiles(argv[1], argv[2]);

    return 0;
}

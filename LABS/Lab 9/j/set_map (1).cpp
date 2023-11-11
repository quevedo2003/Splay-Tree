#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <vector>

std::string most_cases(std::map<std::string, int> mymap) {
    std::string highest_value;
    for( auto i : mymap) {
        if(i.second > mymap[highest_value]) {
            highest_value = i.first;
        }
    }
    return highest_value;
}



int main(int argc, char *argv[]) {

        //input Data into set and map

        std::string line;
        std::string entry;
        std::ifstream table;// 1. Create instance

        const char* case_file = argv[1];
        const char* command_file = argv[2];

        table.open(case_file);                    // 2. Open the file

        if(table.fail()){                           //    Check open
            std::cerr << "Can't open data file\n";
            return 1;
        }

        //Define Set and Map
        std::vector<std::string> input_vec;
        std::set<std::string> unique_countries;
        std::map<std::string, int> cases_map;

            //Skip the first line.
            std::getline(table, line);
        while(std::getline(table, line)){// 3. get a line of data from table, store in 'line'
            std::stringstream streamline(line);
            input_vec.clear();
            while(std::getline(streamline, entry, ',')){  // 4. loop each "column" in 'line'. It will be stored into 'entry'
                //This is here for debugging
                //std::cout << entry << std::endl;
                input_vec.push_back(entry);
            }
            unique_countries.insert(input_vec.at(3));
            if(input_vec.at(2).empty()) {                         //Check if there is a Associated State or Province if there isn't use the country as the key instead.
                cases_map.insert({{input_vec[3],stoi(input_vec[7])}});

            }
            else {
                cases_map.insert({{input_vec[2],stoi(input_vec[7])}}); //Insert the # of cases into the map, with Province as the key.
//                std::cout << input_vec[7] << "\n";
            }
        }

        table.close();                                  // 5. Close the file
        // ...


        //Execute Command File

        std::ifstream commands;

        commands.open(command_file);

        std::vector<std::string> command_vec;

        if(commands.fail()) {
            std::cerr << "Can't open command file \n";
            return 1;
        }

        while(std::getline(commands, line)) {
            std::stringstream ss(line);
            command_vec.clear();
            while(std::getline(ss, entry, ' ')) {
                command_vec.push_back(entry);
            }
            std::string search_string = line.substr(4, line.npos);
            if(command_vec[0] == "set") {
                if(unique_countries.find(search_string) != unique_countries.end()) {
                    std::cout << "1\n";
                }
                else {
                    std::cout <<"0\n";
                }
            }
            else if(command_vec[0] == "map") {
                if(cases_map.find(command_vec[1]) != cases_map.end()) {
//                    std::cout << cases_map.at(command_vec[1]);
                    std::cout << cases_map[command_vec[1]] << "\n";
                }
                else {
                    std::cout << "0\n";
                }
            }
        }
//        std::cout << most_cases(cases_map) << "\n";
        commands.close();
    return 0;
    }

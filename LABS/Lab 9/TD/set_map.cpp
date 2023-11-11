#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <map>

bool set(std::string &value,std::set<std::string> &countries){
if(countries.find(value)!= countries.end()){
return true;
}
else{

    return false;
}
}

int map(std::string &value, std::map<std::string, int> &state_cases){
//should return the # of confirmed cases (0 if the state/province/country is not in the map!)
if(state_cases.find(value)!= state_cases.end()){
 return state_cases.find(value)->second;
}
else{
    int i = 0;
    return i;
}
}

void record_data(std::string file_name,std::set<std::string> &countries, std::map<std::string, int> &state_cases){
    int counter=0;
    int cases;
    std::string country;
    std::string state;
    std::string line;
    std::string entry;
    std::ifstream table;                // 1. Create instance
    
    table.open(file_name);                    // 2. Open the file
    
    if(table.fail()){                           //    Check open
        std::cerr << "Can't open file\n";
    }
    std::getline(table, line);   // used to skip first line
    while(std::getline(table, line)){           // 3. get a line of data from table, store in 'line'
        std::stringstream streamline(line);
        while(std::getline(streamline, entry, ',')){  // 4. loop each "column" in 'line'. It will be stored into 'entry'
            if(counter==3){
               country = entry;
            }
            if (counter ==2)
            {
                state = entry;
            }
            if(counter == 7){
                cases = stoi(entry);
            }
            counter++;
        }

        
        if(state.size() != 0){
            state_cases.emplace(state, cases);
        }
        else{
            state_cases.emplace(country, cases);
        }
        countries.insert(country);
        counter = 0;
    }    
    table.close();                                  // 5. Close the file

}

void run_cmds(std::string file_name,std::set<std::string> &countries, std::map<std::string, int> &state_cases){
    std::string line;
    std::ifstream table;                // 1. Create instance
    
    table.open(file_name);                    // 2. Open the file
    
    if(table.fail()){                           //    Check open
        std::cerr << "Can't open file\n";
    }
    
    while(std::getline(table, line)){           // 3. get a line of data from table, store in 'line'
    std::stringstream ss(line);
    std::string value;

    while (std::getline(ss, value, ' ')) {
                 

        if (std::getline(ss, value, '\n')) {
        if(line[0]== 's'){
             std::cout<< int(set(value,countries)) << std::endl;
        }
        else{
            std::cout<< map(value,state_cases) << std::endl;
            
        }

        }
    }
    
    } 
    
    table.close(); 
}

int main(int argc, char*argv[]){

std::set<std::string> countries;
std::map<std::string, int> state_cases;
record_data(argv[1], countries, state_cases);
run_cmds(argv[2], countries, state_cases);

return 0;
}

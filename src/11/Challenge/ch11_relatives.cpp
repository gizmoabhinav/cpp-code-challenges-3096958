// C++ Code Challenges, LinkedIn Learning

// Challenge #11: Finding Relatives
// Write an application that reads a list of people's names in a CSV file and outputs the first pair of people it finds to be possibly related based on their family names.
// Assume that all entries have one name and one family name.
// Entries are separated by commas.
// Names and family names are separated by spaces.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

// Finding Relatives, main()
// Summary: This application displays the first pair of possible relatives from a list of names in a CSV file.
int main(){
    std::vector<std::vector<std::string>> people;
    std::vector<std::string> person;
    std::string entry, name;
    std::unordered_map<std::string, std::vector<std::string>> family;
    std::fstream file ("names.csv", std::ios::in);
    // Read the CSV file.
    if(file.is_open()){
        while (std::getline(file,entry,',')) {
            std::stringstream str(entry);
            person.clear();
            while (std::getline(str,name,' ')) {
                if (person.size() != 0) {
                    if (family.find(name) == family.end()) {
                        person.push_back(name);
                        family[name] = person;
                    } else {
                        std::cout << family[name][0] << " " << family[name][1] << " is related to " << person[0] << " " << person[1] << std::endl;
                        file.close();
                        return 0;
                    }
                } else {
                    person.push_back(name);
                }
            }
            people.push_back(person);
        }
    
        file.close();
    }
    else{
        std::cout << "Something went wrong\n" << std::flush;
        return 1;
    }

    // Write your code here

    std::cout << "No relatives found.\n\n" << std::flush;    
    return 0;
}
 
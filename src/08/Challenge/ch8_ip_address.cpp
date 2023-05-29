// C++ Code Challenges, LinkedIn Learning

// Challenge #8: IP Address Validation
// Write an application that reads a string from the terminal and responds with a message indicating whether the string is a valid IP address or not.
// Assume decimal IP addresses.
// 158.25.0.33
// All numbers between 0 and 255.

#include <iostream>
#include <vector>
#include <string>

bool is_number(std::string& str) {
    if (str.empty()) {
        return false;
    } else if (str.find_first_not_of("[0123456789]") == std::string::npos) {
        return true;
    }
    return false;
}

// is_valid_ip()
// Summary: This function validates an IP address.
// Arguments:
//           ip: The string to analyze with a potential ip address.
// Returns: A boolean value. True for valid ip addresses, false otherwise.
bool is_valid_ip(std::string ip){
    std::vector<std::string> parts;
    int last = 0;
    for (int i=0;i<ip.size();i++) {
        if (ip[i] == '.') {
            parts.push_back(ip.substr(last,i));
            last = i+1;
        } else if (i==ip.size()-1) {
            parts.push_back(ip.substr(last,i+1));
        }
    }
    if (parts.size()>4) {
        return false;
    }
    for (std::string& value: parts) {
        if (!is_number(value)) {
            return false;
        }
        int number = stoi(value);
        if (number > 255) {
            return false;
        }
    }
    return true;;
}

// Main function
int main(){
    std::string s;
    
    std::cout << std::endl << "Enter an IP address in decimal: " << std::flush;
    std::getline(std::cin,s);
    std::cout << " \n" << s << (is_valid_ip(s) ? " is" : " is not" ) << " a valid IP address.\n\n";
    return 0;
}

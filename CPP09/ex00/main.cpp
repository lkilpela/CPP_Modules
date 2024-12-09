/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:32:55 by lkilpela          #+#    #+#             */
/*   Updated: 2024/12/11 18:11:19 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <regex>    // regex_match, regex
#include <iostream> // cerr, endl
#include <fstream>  // ifstream
#include <sstream>  // istringstream

// Check if the date has valid format YYYY-MM-DD
// Regex is used to check the format of the date string
// How to read regex: \d{4}-\d{2}-\d{2} means 
//     \d is a digit, {4} means 4 digits, - is a dash, \d{2} means 2 digits, and so on
// regrex_match means that the whole string must match the pattern
// It has two arguments: the string to match and the pattern
bool isValidDate(const std::string& date) {
    std::regex datePattern(R"((\d{4})-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01]))");
    return std::regex_match(date, datePattern);
}

bool isValidValue(const std::string& valueStr, double& value) {
    try {
        value = std::stod(valueStr);
        return value >= 0 && value <= 1000;
    } catch (...) {
        return false;
    }
}

void validateDate(const std::string& line) {
    // Extract the date from line
    std::istringstream iss(line);
    std::string date;
    iss >> date;
    if (!isValidDate(date)) {
        throw std::runtime_error("Error: bad input => " + date);
    }
}

int main(int argc, char* argv[]) {
    try {
        if (argc != 2) {
            throw std::runtime_error("Usage: ./btc <input file>");                                                                                                                                              
        }   
        BitcoinExchange btc("data.csv");

        std::ifstream inputFile(argv[1]);
        if (!inputFile.is_open()) {
            throw std::runtime_error("Could not open file");
        }

        std::string line;
        // Skip the header line swe
        std::getline(inputFile, line);
        std::cout << line << std::endl;
        std::string date, separator, valueStr;
        double value;
        std::smatch match;
        // linePattern means that the line must have a date in the format YYYY-MM-DD, a pipe, and a value
        std::regex linePattern(R"((\d{4})-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01]) \| (-?\d+(\.\d+)?))"); 
        //td::cout << "date | value" << std::endl;
        
        while (std::getline(inputFile, line)) {
            try {
                validateDate(line);
                if (std::regex_match(line, match, linePattern)) {
                    date = match[1].str() + "-" + match[2].str() + "-" + match[3].str();
                    valueStr = match[4];
                    if (!isValidValue(valueStr, value)) {
                        if (value < 0) {
                            throw std::runtime_error("Error: not a positive number");
                        } else {
                            throw std::runtime_error("Error: value too large");
                        }
                    }
                } else {
                    std::cerr << "Error: could not parse line " << line << std::endl;
                }
                double rate = btc.getExchangeRate(date);
                std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
            } catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
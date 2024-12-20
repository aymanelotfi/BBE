#include "Parser.h"
#include <fstream>
#include <iostream>

Parser::Parser(const Path& filename, SharedQueue<Trade>& queue): inFile(filename), queue(queue) {
    if(!inFile.is_open()) {
        std::cerr << "Error opening file ! " << std::endl;
    }
}

void Parser::load() {
    std::string line;
    while(std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string token;
        std::vector<int> values;

        while (std::getline(ss, token, ',')) {
            values.push_back(std::stoi(token)); // Convert token to int
        }

        if (values.size() == 5) {
            Trade trade(values[0], values[1], values[2], values[3], values[4]);
            queue.push(trade);
        } else {
            std::cerr << "Error: Invalid CSV format." << std::endl;
        }
    }
    queue.finish();
}


Parser::~Parser() {
    inFile.close();
}




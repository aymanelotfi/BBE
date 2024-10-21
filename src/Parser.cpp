

#include "Parser.h"
#include "TraderQueue.h"
#include <fstream>
#include <iostream>

Parser::Parser(const std::string& filename): inFile(filename) {
    if(!inFile.is_open()) {
        std::cerr << "Error opening file ! " <<std::endl;
    }
}

void Parser::load(TraderQueue& queue) {
    std::string line;
    while(std::getline(inFile, line)) {
            queue.addTrade(Trade(line));
    }
    queue.finish();
}


Parser::~Parser() {
    inFile.close();
}




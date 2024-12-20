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
            queue.push(Trade(line));
    }
    queue.finish();
}


Parser::~Parser() {
    inFile.close();
}




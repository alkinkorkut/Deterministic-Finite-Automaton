#include <bits/stdc++.h>
#include <iostream>
#include <string>

int main()
{
    std::ifstream inputStream;
    inputStream.open("input.txt");
    std::string str;
    inputStream >> str;
    std::stringstream numOfStates(str);  //Total number of stateNames
    int numberOfStates = 0;
    numOfStates >> numberOfStates;
    inputStream >> str;
    std::stringstream numOfVariables(str); //Total number of variables
    int numberOfVariables = 0;
    numOfVariables >> numberOfVariables;
    inputStream >> str;
    std::stringstream numOfFinalStates(str); //Total number of final stateNames
    int numberOfFinalStates = 0;
    numOfFinalStates >> numberOfFinalStates;

    std::ofstream outputStream;
    outputStream.open("output.txt");

    std::vector<std::string> stateNames;
    for(int i = 0; i < numberOfStates; i++){
        inputStream >> str;
        std::stringstream singleState(str);
        std::string state;
        singleState >> state;
        stateNames.push_back(state);
    }

    std::vector<std::string> finalStateNames;
    for(int i = 0; i < numberOfFinalStates; i++){
        inputStream >> str;
        std::stringstream singleFinalState(str);
        std::string state;
        singleFinalState >> state;
        finalStateNames.push_back(state);
    }

    std::vector<char> variableNames;
    for(int i = 0; i < numberOfVariables; i++){
        inputStream >> str;
        std::stringstream singleVariable(str);
        char variable;
        singleVariable >> variable;
        variableNames.push_back(variable);
    }

    std::map<std::string,std::map<char, std::string>> transitionTable;
    for(int i = 0; i < numberOfStates * numberOfVariables; i++){
        inputStream >> str;
        std::stringstream stream0(str);
        std::string state;
        stream0 >> state;

        inputStream >> str;
        std::stringstream stream1(str);
        char variable;
        stream1 >> variable;

        inputStream >> str;
        std::stringstream stream2(str);
        std::string nextState;
        stream2 >> nextState;

        transitionTable[state][variable] = nextState;
    }

    try {
        while(!inputStream.eof()){
            inputStream >> str;
            std::stringstream stringStream(str);
            std::string entryData="";
            stringStream >> entryData;
            if(entryData == ""){
                throw std::runtime_error("Empty data encountered.");
            }
            std::string presentState;
            presentState= "q1";
            for(char & i : entryData){
                presentState = transitionTable[presentState][i];
                outputStream << presentState << " ";
                std::cout << presentState << " ";
            }
            bool accepted = false;
            for(int i = 0; i < numberOfFinalStates; i++){
                if (finalStateNames[i] == presentState)
                    accepted = true;
            }
            if(accepted) outputStream << std::endl << "Accepted" << std::endl;
            else outputStream << std::endl << "Rejected" << std::endl;
            if(accepted) std::cout << std::endl << "Accepted" << std::endl;
            else std::cout << std::endl << "Rejected" << std::endl;
        }
    } catch(const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        outputStream << "Exception: " << e.what() << std::endl;
    }

    outputStream.close();
    return 0;
}
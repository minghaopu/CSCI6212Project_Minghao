//
//  AdjMatrix.cpp
//  CSCI6212Project_Minghao
//
//  Created by Minghao PU on 15/11/25.
//  Copyright © 2015年 Geroge Washington University. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "AdjMatrix.h"




GraphMatrix::GraphMatrix(string path) {
    
    ifstream inputData(path);
    string inputString;
    int tempWeight;
    
    numVertexes = 0;
    
    if (inputData.good()) {
        while (getline(inputData, inputString)) {
            std::size_t found = inputString.find_last_not_of("\n");
            if (found!=std::string::npos) {
                stringstream ss(inputString);
                vexs.push_back(numVertexes);
                vector<int> row;
                while (ss >> tempWeight) {
                    if (tempWeight!=0) {
                        row.push_back(tempWeight);
                    }else {
                        row.push_back(INFINITYWEIGHT);
                    }
                }
                adjMatrix.push_back(row);
                numVertexes++;
            }
        }
        
        source = adjMatrix.back()[0]-1;
        adjMatrix.pop_back();
        numVertexes--;
        
        inputData.close();
        
    } else {
        
        cout<< "\nError:\n"
            <<"The input file can not open!\n"
            <<"Please check the input.txt file and start the program again.\n"
            <<"Program End.\n" <<endl;
        exit(0);
        
    }
    
}
//
//  main.cpp
//  CSCI6212Project_Minghao
//
//  Created by Roneil on 15/11/24.
//  Copyright © 2015年 Geroge Washington University. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;



int main(int argc, const char * argv[]) {
    
    std::string str;
    std::cout<<"please enter the path"<<endl;
    
    std::cin>>str;
    
    
    
    std::ifstream ifs (str);
    
    if (ifs.is_open()) {
        // print file:
        char c = ifs.get();
        while (ifs.good()) {
            std::cout << c;
            c = ifs.get();
        }
    }
    else {
        // show message:
        std::cout << "Error opening file" <<endl;
    }
    return 0;
    
}

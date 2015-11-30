//
//  AdjMatrix.h
//  CSCI6212Project_Minghao
//
//  Created by Minghao PU on 15/11/25.
//  Copyright © 2015年 Geroge Washington University. All rights reserved.
//

#ifndef AdjMatrix_h
#define AdjMatrix_h
#define INFINITYWEIGHT 99999

#include <vector>
#include <string>
using namespace std;

typedef vector<int> VertexType;
typedef vector<VertexType> AdjacentMatrix;


class GraphMatrix {
    
public:

    GraphMatrix();
    GraphMatrix(string path);

    ~GraphMatrix();
    
    AdjacentMatrix adjMatrix;
    VertexType vexs;
    int numVertexes;
    int source;
};


#endif /* AdjMatrix_h */

//
//  main.cpp
//  CSCI6212Project_Minghao
//
//  Created by Minghao PU on 15/11/24.
//  Copyright © 2015年 Geroge Washington University. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>
#include "AdjMatrix.h"
using namespace std;

struct Node{
    int distance;
    int parentIndex;
    int nodeName;
    int index;
};
typedef vector<Node> Queue;



Node FindMin(Queue array, int start, int end) {
    int length = end-start+1;
    Node minNode;
    if (length == 1) {
        minNode = array.at(start);
        return minNode;
    }else if(length == 2) {
        minNode = (array.at(start).distance < array.at(end).distance?array.at(start):array.at(end));
        return minNode;
    }else {
        int end1 = start+length/2-1;
        int start2 = end1+1;
        Node min1 = FindMin(array, start, end1);
        Node min2 = FindMin(array, start2, end);
        minNode = (min1.distance < min2.distance?min1:min2);
        return minNode;
    }
}

//Node ExtractMin(Queue queue) {
//    Node minNode;
//    int length = sizeof(queue)/sizeof(queue[0]);
//    minNode = FindMin(queue, 0, length-1);
//    queue.erase(queue.begin() + minNode.nodeName);
//    return minNode;
//}


//void Relax(Queue queue, AdjacentMatrix weight, int index, Node parent) {
//
//    if (queue.at(index).distance > parent.distance + weight[parent.nodeName][queue.at(index).nodeName]) {
//        queue.at(index).distance = parent.distance + weight[parent.nodeName][queue.at(index).nodeName];
//        queue.at(index).parentIndex = parent.nodeName;
//    }
//    
//}

void ShortestPath_DIJ(GraphMatrix* pGraph) {
    

    Queue waitingQueue;
    Queue finalArray(pGraph->numVertexes);

    
    int row;
    int col;
    Node vertexNode;
    int length;

    for (row = 0; row<pGraph->numVertexes; row++) {

        Node temp;
        temp.distance = INFINITYWEIGHT;
        temp.nodeName = row;
        temp.index = row;
        temp.parentIndex = -1;
        
        waitingQueue.push_back(temp);
    }
    
    waitingQueue.at(pGraph->source).distance = 0;
    waitingQueue.at(pGraph->source).parentIndex = -1;
    
    for (row = 0; row < pGraph->numVertexes; row++) {

        
        length = (int)waitingQueue.size();
        vertexNode = FindMin(waitingQueue, 0, length-1);
        waitingQueue.erase(waitingQueue.begin() + vertexNode.index);

        
        finalArray[vertexNode.nodeName]=vertexNode;
        
        for (col = 0; col < length-1; col++) {

            if (pGraph->adjMatrix[vertexNode.nodeName][waitingQueue[col].nodeName] < INFINITYWEIGHT) {
                if (waitingQueue[col].distance > vertexNode.distance + pGraph->adjMatrix[vertexNode.nodeName][waitingQueue[col].nodeName]) {
                    waitingQueue[col].distance = vertexNode.distance + pGraph->adjMatrix[vertexNode.nodeName][waitingQueue[col].nodeName];
                    waitingQueue[col].parentIndex = vertexNode.nodeName;
                }
            }
            waitingQueue[col].index = col;
        }

    }
    for (row = 0; row < pGraph->numVertexes; row++) {
//        cout<<finalArray[row].parentIndex<<"->"<<finalArray[row].nodeName<<endl;
        cout<<finalArray[row].distance<<endl;
    }

}





int main(int argc, const char * argv[]) {
    
//    string path = "/Users/roneil/Project/CSCI6212Project_Minghao/CSCI6212Project_Minghao/test2.txt";
    

    GraphMatrix* pGraph;
//    pGraph = new GraphMatrix(path);
    pGraph = new GraphMatrix(argv[1]);
    
    if (pGraph->source+1>pGraph->numVertexes) {
        cout<<"The source vertex is larger than the total number of vertexes"<<endl;
        return 0;
    } else if (pGraph->source<0) {
        cout<<"The source vertex is smaller than 1"<<endl;
        return 0;
    }
    
    ShortestPath_DIJ(pGraph);
    
    
    return 0;
    
}

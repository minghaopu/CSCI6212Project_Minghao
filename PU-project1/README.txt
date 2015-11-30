//
//  README.txt
//  CSCI6212Project_Minghao
//
//  Created by Minghao PU on 15/11/25.
//  Copyright © 2015年 Geroge Washington University. All rights reserved.
//


/*
* How to Compile
*/

1.cd /Users/roneil/Project/CSCI6212Project_Minghao/PU-project1  // Please change the path

2.$ g++ -Wall main.cpp AdjMatrix.cpp -o dijkstra //for Mac

/*
* How to Run
*/

1.Put the input.txt in the same folder with main.cpp

2.$ ./dijkstra input.txt // for Mac

/*
* Specification
*/

1. Vertex Index:
	The vetex index start from 1.

2. Unreachable Vertex:
	If there is no path from source the ith vertex, the ith line output "99999" which means infinity length.

3. Error message:
	If the input.txt is not find or can not open, there will be an error message as following:

	Error:
		The input file can not open!
		Please check the input.txt file and start the program again.
		Program End.
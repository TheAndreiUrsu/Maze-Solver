/*
    Maze Escape

    Sometimes when dealing with graphs, it is easiest to leave it in its input format 
    rather than creating another structure like an adjacency list/matrix. You are given 
    a graph represented as a vector of strings. Write a function 
    `traverse(vector<string>& graph)` that takes as input a graph and returns the length 
    of the shortest path between vertices `s` and `t`. If no path exists between `s` and 
    `t`, then return `-1`. The details of the graph as a vector of strings are as follows:

    1. The start position is represented by a 's' and will always be the first character of 
       the first string (`graph[0][0]`). 
    2. The end position is represented by a 't' and will always be the last character of the 
       final string (`graph[graph.size()-1][graph[0].length()-1]`).
    3. A '.' character represents a normal vertex in the graph.
    4. A '#' character represents that you cannot visit this vertex in the graph (or there 
       is no vertex at this position).
    5. Adjacent vertices are those immediately horizontal or vertical from the current vertex 
       (diagonal moves are not allowed).
    6. The cost of moving along one edge (from one vertex to an adjacent vertex) is always 1 
       (i.e. this is an unweighted graph).

    Sample Input
        s#.#.   
        .#...  
        ...#t    

    Sample Output: 8
*/

#include <iostream>
#include <vector>
#include <queue>

#define NOENTRY '#'
#define ENTRY '.'

int traverse(std::vector<std::string> &graph) 
{
	std::queue<char> q;
	std::vector<std::vector<bool>> visited(graph.size(), std::vector<bool>(graph[0].size(), false));
	visited[0][0] = true;
	q.push(graph[0][0]);

	// down, up, right, left
	std::vector<int> dx = {1,-1,0,0};
	std::vector<int> dy = {0,0,1,-1};

	int x = 0, y = 0;

	while(!q.empty()){

		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			//check bounds
			if(nx < 0 || ny < 0 || nx >= graph.size() || ny >= graph[0].size())
				continue;
			char current = graph[nx][ny];
            if(current == NOENTRY)
                continue;
			if(current == ENTRY && !visited[nx][ny]){
                x = nx;
                y = ny;
				visited[nx][ny] = true;
				q.push(graph[nx][ny]);
				q.pop();
				i = 4;
			}
		}
	}
	
	for(int i = 0; i < visited.size(); ++i){
		for(int j = 0; j < visited[0].size(); ++j){
			std::cout << visited[i][j];
		}
		std::cout << std::endl;
	}


	return -1;
}

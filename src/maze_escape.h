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
#include <map>

int traverse(std::vector<std::string> &graph) 
{
    char ENTRY = '.', TARGET = 't';

    std::map<std::pair<int,int>, bool> V;
    std::map<std::pair<int,int>, int> dist;
	std::queue<std::pair<int,int>> q;

    int x = 0, y = 0;

    V[std::make_pair(x,y)] = true;
    dist[std::make_pair(x,y)] = 0;

	q.push(std::make_pair(x,y));

	// down, up, right, left
	int dx[] = {1,-1,0,0};
	int dy[] = {0,0,1,-1};

    do{
        auto U = q.front();
        x = U.first, y = U.second;

        if(graph[x][y] == TARGET)
            return dist[U];

        q.pop();

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i], ny = y + dy[i];
            // hit a wall
            if(nx < 0 || ny < 0 || nx >= graph.size() || ny >= graph[0].size())
                continue;
            if(graph[nx][ny] == ENTRY && V.find(std::make_pair(nx,ny)) == V.end()){
                q.push(std::make_pair(nx,ny));
                V[std::make_pair(nx,ny)] = true;
                dist[std::make_pair(nx,ny)] = dist[std::make_pair(x,y)]+1;
            }

            if(graph[nx][ny] == TARGET)
                return dist[std::make_pair(nx,ny)];

        }
    }
    while(!q.empty());

    std::vector<std::vector<int>> dist_g;
    dist_g.reserve(graph.size());
    for(int i = 0; i < graph.size(); ++i){
        dist_g.emplace_back('#');
        dist_g[i].reserve(graph[0].size());
    }
    for(auto& vertex : dist){
        dist_g[vertex.first.first][vertex.first.second] = vertex.second;
    }

    for(int i = 0; i < dist_g.size(); ++i){
        for(int j = 0; j < dist_g[0].size(); ++j){
            std::cout << dist_g[i][j];
        }
        std::cout << std::endl;
    }

	return -1;
}

// Written by Andrei Ursu

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

int traverse(std::vector<std::string> &graph) 
{
    char ENTRY = '.', TARGET = 't';

    std::set<std::pair<int,int>> V;
    std::map<std::pair<int,int>, int> dist;
	std::queue<std::pair<int,int>> q;

    int x = 0, y = 0;

    V.insert(std::make_pair(x,y));
    dist[std::make_pair(x,y)] = 0;

	q.push(std::make_pair(x,y));

	// down, up, right, left; taken from lecture Graphs Part 1, slides 79-86
	int dx[] = {1,-1,0,0};
	int dy[] = {0,0,1,-1};

    while(!q.empty()){
        auto U = q.front();
        x = U.first, y = U.second;

        q.pop();

        if(graph[x][y] == TARGET)
            return dist[U];

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i], ny = y + dy[i];

            // hit a wall
            if(nx < 0 || ny < 0 || nx >= graph.size() || ny >= graph[0].size())
                continue;

            // valid vertices have a '.' or 't'.
            if((graph[nx][ny] == ENTRY || graph[nx][ny] == TARGET) && V.find(std::make_pair(nx,ny)) == V.end()){
                q.push(std::make_pair(nx,ny));
                V.insert(std::make_pair(nx,ny));
                dist[std::make_pair(nx,ny)] = dist[std::make_pair(x,y)]+1;
            }

        }

    }


	return -1;
}

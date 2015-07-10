#include "stdafx.h"
#include "Graph.h"
#include <fstream>
#include <vector>
using std::vector;
using std::string;

Graph::Graph()
{

}


Graph::~Graph()
{
}
void Graph::Floyd()
{
	for (int k = 0; k < NUM_OF_VERTICES; k++) {
		for (int i = 0; i < NUM_OF_VERTICES; i++) {
			for (int j = 0; j < NUM_OF_VERTICES; j++) {
				if (sRouteLength[i][k] + sRouteLength[k][j] < sRouteLength[i][j]) {
					sRouteLength[i][j] = sRouteLength[i][k] + sRouteLength[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}
}
vector<int> Graph::printShortestPath(int startPoint, int endPoint)
{
	vector<int> tmp;
	tmp.push_back(endPoint);
	while (startPoint != path[startPoint][endPoint]) {
		endPoint = path[startPoint][endPoint];
		tmp.push_back(endPoint);		
	}
	tmp.push_back(startPoint);
	return tmp;
}
void Graph::init()
{

}
int Graph::getShortestRoadLength(int startPoint, int endPoint)
{
	return sRouteLength[startPoint][endPoint];
}
int Graph::getLocNumber(string locName)
{
	return locations[locName];
}
string Graph::getLocName(int locNumber)
{
	string ans;
		MyMap::iterator it = locations.begin();
		while (it != locations.end()) {
			if (it->second == locNumber) {
				ans = it->first;
				return ans;
			}
			it++;
		}
		return "";

}
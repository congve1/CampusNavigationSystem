#include "stdafx.h"
#include "Graph.h"
#include <fstream>
#include <vector>
using std::vector;
using std::string;
using std::fstream;
using std::ios;
Graph::Graph()
{
	init();
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
vector<int> Graph::printShortestPath(int startPoint, int endPoint, string & ansPath)
{
	vector<int> tmp;
	tmp.push_back(endPoint);
	while (startPoint != path[startPoint][endPoint]) {
		endPoint = path[startPoint][endPoint];
		tmp.push_back(endPoint);		
	}
	tmp.push_back(startPoint);
	
	for (int i = tmp.size() - 1, j = 0; i >=0 ; i--) {
		if (tmp[i] < 19) {
			ansPath += getLocName(tmp[i]);
			j++;
			if (i != 0 && tmp[i] < 19) {
				ansPath += " -> ";
			}
			//if (j % 2 == 0) {
			//	ansPath += "\r\n";
			//}
		}		
		
	}
	return tmp;
}
void Graph::init()
{
	fstream file;
	file.open("LocationsName.txt", ios::in);
	if (!file.is_open()) {
		
	} else {
		int i = 0;
		while (!file.eof()) {
			char tmp[200];
			file.getline(tmp,200);
			string strTmp(tmp);
			locations[strTmp] = i++;
		}
	}
	file.close();
	file.open("length.txt", ios::in);
	char tmp[200];
	for (int i = 0; i < NUM_OF_VERTICES; i++) {
		for (int j = 0; j < NUM_OF_VERTICES; j++) {
			file.getline(tmp, 200);
			int num = atoi(tmp);
			sRouteLength[i][j] = num;
			if (i != j && sRouteLength[i][j] < MAX_VALUE) {
				path[i][j] = i;
			} else {
				path[i][j] = 0;
			}
		}
	}
	file.close();
}
int Graph::getShortestRoadLength(int startPoint, int endPoint)
{
	return sRouteLength[startPoint][endPoint];
}
int Graph::getLocNumber(string locName)
{
	int tmp = locations[locName];
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
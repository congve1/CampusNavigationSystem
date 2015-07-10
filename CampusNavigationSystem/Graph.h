#pragma once
#include <vector>
#include <map>
#include <string>
using std::vector;
using std::map;
using std::string;
typedef map<string, int> MyMap;
const int NUM_OF_VERTICES = 19;
class Graph {
public:
	Graph();
	~Graph();
	void Floyd();
	vector<int>  printShortestPath(int startPoint, int endPoint);
	int getShortestRoadLength(int startPoint, int endPoint);
	int getLocNumber(string locName);
	string getLocName(int locNumber);
private:
	void init();
	int sRouteLength[NUM_OF_VERTICES][NUM_OF_VERTICES];
	int path[NUM_OF_VERTICES][NUM_OF_VERTICES];
	MyMap locations;
};


#pragma once
#include <vector>
#include <map>
#include <string>
using std::vector;
using std::map;
using std::string;
typedef map<string, int> MyMap;
const int NUM_OF_VERTICES = 77;
const int MAX_VALUE = 1000;
class Graph {
public:
	Graph();
	~Graph();
	void Floyd();
	vector<int>  printShortestPath(int startPoint, int endPoint, string & ansPath);
	int getShortestRoadLength(int startPoint, int endPoint);
	int getLocNumber(string locName);
	string getLocName(int locNumber);
private:
	void init();
	int sRouteLength[NUM_OF_VERTICES][NUM_OF_VERTICES];
	int path[NUM_OF_VERTICES][NUM_OF_VERTICES];
	MyMap locations;
};


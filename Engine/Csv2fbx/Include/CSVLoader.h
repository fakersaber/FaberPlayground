#pragma once

#include <vector>
#include "fbxsdk.h"
//#include<iostream>
using namespace std;

//定义保存读取到的csv数据的结构体，目前只包含vertices、texCoords、normals、tangents
struct CSVGeometry
{
	vector<FbxVector4> vertices;
	vector<FbxVector4> texCoords;
	vector<FbxVector4> texCoords1;
	vector<FbxVector4> texCoords2;
	vector<FbxVector4> normals;
	vector<FbxVector4> tangents;
	// TODO 顶点色

};

class CSVLoader
{
public:
	CSVLoader();

	CSVGeometry& Load(const std::vector<std::string>& inputArgv, const char* strCSVPath);
	
private:
	//包含加载解析csv文件的方法
	void AssignedOutputObj(const vector<vector<double> >& outputDataObj, CSVGeometry& objFile, vector<string>& inputPrefix);
	void MatchSemanticsPrefix(vector<string>& input, vector<string>& prefix, vector<int>& tag, vector<vector<double> >& output);
	void const GetSemanticName(const std::vector<std::string>& inputArgv, vector<string> &sem, vector<string> &var);
	void CleanAndSplit(char buffer[], std::vector<std::string>& values);
	
	CSVGeometry _cOutput;
};



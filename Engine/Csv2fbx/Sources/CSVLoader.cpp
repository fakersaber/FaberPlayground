#include <istream>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cassert>
//#include<string>
//#include <cstdlib>
#include<iterator>
#include "CSVLoader.h"
using namespace std;

extern int inputArgc;

static const inline double UnrealConvert(double type) {
	return -type;
}

static const inline double UnrealConvertUV(double UV_y) {
	return /*1.0 - */UV_y;
}

void CSVLoader::AssignedOutputObj(const vector<vector<double> >& outputDataObj, CSVGeometry& objFile, vector<string>& inputPrefix)
{
	for (int j = 0; j < outputDataObj.at(0).size(); ++j)
	{
		objFile.vertices.emplace_back();
		objFile.texCoords.emplace_back();
		objFile.texCoords1.emplace_back();
		objFile.texCoords2.emplace_back();
		objFile.normals.emplace_back();
		objFile.tangents.emplace_back();

		FbxVector4& vertex = objFile.vertices.back();
		FbxVector4& texCoord = objFile.texCoords.back();
		FbxVector4& texCoord1 = objFile.texCoords1.back();
		FbxVector4& texCoord2 = objFile.texCoords2.back();
		FbxVector4& normal = objFile.normals.back();
		FbxVector4& tangent = objFile.tangents.back();

		for (int i = 0; i < inputPrefix.size(); ++i)
		{ 
			if (inputPrefix.at(i) == "Pos.x")
				vertex[0] = outputDataObj.at(i).at(j);
			else if (inputPrefix.at(i) == "Pos.y")
				vertex[1] = UnrealConvert(outputDataObj.at(i).at(j));
			else if (inputPrefix.at(i) == "Pos.z")
				vertex[2] = outputDataObj.at(i).at(j);
			else if (inputPrefix.at(i) == "Pos.w")
				vertex[3] = outputDataObj.at(i).at(j);


			else if (inputPrefix.at(i) == "Tex.x")
				texCoord[0] = outputDataObj.at(i).at(j);
			else if (inputPrefix.at(i) == "Tex.y")
				texCoord[1] = UnrealConvertUV(outputDataObj.at(i).at(j));

			//UV2 No ClipY
			else if (inputPrefix.at(i) == "Te1.x")
				texCoord1[0] = outputDataObj.at(i).at(j);
			else if (inputPrefix.at(i) == "Te1.y")
				texCoord1[1] = outputDataObj.at(i).at(j);


			else if (inputPrefix.at(i) == "Nor.x")
				normal[0] = outputDataObj.at(i).at(j);
			else if (inputPrefix.at(i) == "Nor.y")
				normal[1] = UnrealConvert(outputDataObj.at(i).at(j));
			else if (inputPrefix.at(i) == "Nor.z")
				normal[2] = outputDataObj.at(i).at(j);
			else if (inputPrefix.at(i) == "Nor.w")
				normal[3] = outputDataObj.at(i).at(j);

			else if (inputPrefix.at(i) == "Tan.x")
				tangent[0] = outputDataObj.at(i).at(j);
			else if (inputPrefix.at(i) == "Tan.y")
				tangent[1] = UnrealConvert(outputDataObj.at(i).at(j));
			else if (inputPrefix.at(i) == "Tan.z")
				tangent[2] = outputDataObj.at(i).at(j);

		}
	}
}

//��prefix���ҵ�inputƥ����ַ������ҵ��˾ͼ�¼��prefix�г��ֵ�λ�ã�����tagΪ1
void CSVLoader::MatchSemanticsPrefix(vector<string>& input, vector<string>& prefix, vector<int>& tag,vector<vector<double> >& output)
{
	assert(!input.empty());
	assert(!prefix.empty());
	for (int i = 0; i < input.size(); ++i)
	{
		 vector<string>::iterator it = find(prefix.begin(), prefix.end(), input.at(i));
		 int pos = distance(begin(prefix), it);
		 tag.at(pos) = 1;
		 vector<double> tmp;
		 output.push_back(tmp);
	}
}

//��һ����buffer�ַ����ָ�����ֵ�values��
void CSVLoader::CleanAndSplit(char buffer[], std::vector<std::string>& values)
{
	char* end = std::remove(buffer, buffer + strlen(buffer), ',');
	*end = 0;
	std::istringstream iss(buffer);
	values = std::vector<std::string>(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());
}

//���û����룬���Ϊ���岿��sem�Ͷ�Ӧֵ���֣��ֱ𱣴��������У�����pos.x(ֵ)��POSITION.x(����)
void const CSVLoader::GetSemanticName(const std::vector<std::string>& inputArgv, vector<string> &sem, vector<string> &var)
{
	assert(inputArgv.empty() != true);
	for (int i = 0; i < inputArgv.size(); ++i)
	{
		const string& str1 = inputArgv[i];
		//zmk
		sem.emplace_back(str1.substr(6, strlen(str1.c_str()) - 6));
		var.emplace_back(str1.substr(0, 5));
	}
	//str1.substr(6, strlen(str1.c_str()) - 6)
}

CSVLoader::CSVLoader()
{
}

CSVGeometry& CSVLoader::Load(const std::vector<std::string>& inputArgv, const char* strCSVPath)
{
	vector<int> semanticsTag;									//glsl�ж��������������ά�ģ���������������ı��λ��4*4*4*4
	// TODO ���ﲻ�ã���֮
	semanticsTag.assign(24, -1);									//��Ҫ�����������������ı�ǩ��ȫ����ʼ��Ϊ-1����Ҫ�������Ϊ1,���3*pos��3*normal��4*tangent��2*uv
	vector<string> semanticsPrefix = {							//����ַ�����ǰ׺
									   "Pos.x","Pos.y","Pos.z","Pos.w",
									   "Tex.x","Tex.y","Tex.z","Tex.w",
									   "Te1.x","Te1.y","Te1.z","Te1.w",
									   "Te2.x","Te2.y","Te2.z","Te2.w",
									   "Nor.x","Nor.y","Nor.z","Nor.w",
									   "Tan.x","Tan.y","Tan.z","Tan.w"

	};

	vector<string> inputSemantics;								//�û���������� ��:POSITION.x
	vector<string> inputPrefix;									//�û������ǰ׺���� ��:Pos.x
	GetSemanticName(inputArgv, inputSemantics, inputPrefix);    //���û�������������inputSemantics��,ǰ׺����inputPrefix��
	//��semanticsPrefix���ҵ�prefixƥ����ַ������ҵ��˾ͼ�¼��semantics�г��ֵ�λ�ã�����semanticsTagΪ1
	vector<vector<double> > outputData;							//��outputData������������ֵ����
	MatchSemanticsPrefix(inputPrefix, semanticsPrefix, semanticsTag, outputData);

	//��ȡcsv�ļ���һ�У�����������
	char buffer[2048] = {};
	ifstream fIn(strCSVPath);
	fIn.getline(buffer, sizeof(buffer));
	vector<string> CsvTittleName;
	CleanAndSplit(buffer, CsvTittleName);//����buffer�е����ݣ����������ƶ�Ӧ��CsvTittleName��

	//дһ��ѭ������semanticsTag��ֵΪ1�ľ�����Ҫ��ȡ���������ڵ��е�ֵ��
	//��Ҫ���弸��vector?����Ҫ��csv�����������
	while (!fIn.eof())
	{
		fIn.getline(buffer, sizeof(buffer));
		if (strlen(buffer) == 0)
			break;
		std::vector<std::string> values;
		CleanAndSplit(buffer, values);      //����buffer

		//ʹ������ѭ����֤�û����������˳���������
		for (int i = 0; i < semanticsTag.size(); ++i)
		{
			vector<vector<string> > semLists;
			if (semanticsTag.at(i) == 1)
			{
				string currentPrefix = semanticsPrefix.at(i);
				for (int j = 0; j < inputPrefix.size(); ++j)
				{
					if (currentPrefix == inputPrefix.at(j))
					{
						string currentSemantic = inputSemantics.at(j);
						for (int k = 0; k < CsvTittleName.size(); ++k)
						{
							if (CsvTittleName.at(k) == currentSemantic)
							{
								outputData.at(j).push_back(stod(values.at(k)));
							}
						}
					}
				}
			}
		}
	}
	fIn.close();

	//��������ֵ���Ѷ�ȡ������ֵoutputData��ֵ��output,����semanticsTag��ֵΪ1���ֵ
	AssignedOutputObj(outputData, _cOutput, inputPrefix);

	return _cOutput;
}
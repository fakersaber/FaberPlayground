#include "CSVLoader.h"
#include "FBXCommon.h"
#include<iostream>
#include<string>
#include<assert.h>
#include<vector>
//#include"fbxsdk.h"
using namespace std;

//�ж�����Ĳ��������Ƿ�Ϸ�
bool ArgcNumIsLegal(int arg)
{
	bool tag = true;
	//Ŀǰ�汾���֧��15������������4������
	//exe��input��output��3*pos��3*normal��4*tangent��2*uv
	if (arg < 4 || arg >17)
		tag = false;
	return tag;
}

//�ж����������Ĳ����Ƿ�Ϸ�
bool InputAndOutputNameIsLegal(char* inputName, char* outputName)
{
	int tag = true;
	string str1 = inputName;
	string str2 = outputName;
	string str3 = str1.substr(6, strlen(str1.c_str()) - 6); //�����û�������ַ����õ�csv�ļ���
	string str4 = str2.substr(7, strlen(str2.c_str()) - 7); //�����û�������ַ����õ�fbx�ļ���
	if (str1.substr(0, 5) != "Input" || str1.substr(5, 1) != "=")
	{
		cout << "����ǰ׺����Ϊ��Input='" << endl;
		tag = false;
		return tag;
	}
	else if (strcmp(str3.c_str() + strlen(str3.c_str()) - 4, ".csv"))
	{
		cout << "��ʹ��csv�ļ���Ϊ����" << endl;
		tag = false;
		return tag;
	}
	if (str2.substr(0, 6) != "Output" || str2.substr(6, 1) != "=")
	{
		cout << "����ǰ׺����Ϊ��Output='" << endl;
		tag = false;
		return tag;
	}
	else if (strcmp(str4.c_str() + strlen(str4.c_str()) - 4, ".fbx"))
	{
		cout << "��ʹ��fbx�ļ���Ϊ���" << endl;
		tag = false;
		return tag;
	}
	return tag;
}

const string GetCsvFileName(char* &src)
{
	string csvName;
	string str1 = src;
	csvName = str1.substr(6, strlen(str1.c_str()) - 6);
	return csvName;
}
const string GetFbxFileName(char* &dest)
{
	string fbxName;
	string str2 = dest;
	fbxName = str2.substr(7, strlen(str2.c_str()) - 7);
	return fbxName;
}

int intputArgc;
extern int OutputFBX(const char* myOutPut, const CSVGeometry& objFile);
int main(int argc, char* argv[])
{
	//if (!ArgcNumIsLegal(argc))
	//{
	//	cout << "����Ĳ����������Ϸ�:��exe��������4�������17��" << endl;
	//	exit(1);
	//}
	//if (!InputAndOutputNameIsLegal(argv[1], argv[2]))
	//{
	//	cout << "���������Ĳ��������Ϸ�" << endl;
	//	exit(1);
	//}
	//for (int i = 3; i < argc; ++i)
	//{
	//	inputArgv.push_back(argv[i]);
	//}
	intputArgc = argc - 3;

	std::vector<std::string> inputArgv = {
		"Pos.x=in_ATTRIBUTE0.x","Pos.y=in_ATTRIBUTE0.y","Pos.z=in_ATTRIBUTE0.z",
		"Tex.x=in_ATTRIBUTE4.x","Tex.y=in_ATTRIBUTE4.y",
		"Te1.x=in_ATTRIBUTE4.z","Te1.y=in_ATTRIBUTE4.w",
		/*"Te2.x=in_ATTRIBUTE4.z","Te2.y=in_ATTRIBUTE4.w",*/
		"Nor.x=in_ATTRIBUTE2.x","Nor.y=in_ATTRIBUTE2.y","Nor.z=in_ATTRIBUTE2.z", "Nor.w=in_ATTRIBUTE2.w",
		"Tan.x=in_ATTRIBUTE1.x","Tan.y=in_ATTRIBUTE1.y","Tan.z=in_ATTRIBUTE1.z"
	};

	//���������������󣬽��������Ƕ�ȡcsv�ļ���
	string csvFileName = /*GetCsvFileName(argv[1])*/"Tree.csv";
	//�����û��������ȡcsv�ļ�
	CSVLoader cCSVLoader;
	//һ��Ҫʹ�ø÷�����csv�����ݻ�ȡ��������fbx��Զ���ǿյ�
	CSVGeometry& cSVGeometry = cCSVLoader.Load(inputArgv, csvFileName.c_str());

	string fbxFileName = "Tree.fbx";
	OutputFBX(fbxFileName.c_str(), cSVGeometry);

	return 0;
}
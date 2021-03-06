#include <istream>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cassert>
#include <array>
#include <unordered_map>

struct VertDataAttribute{
	using FPosition = std::array<float, 3>;
	using FNormal = std::array<float, 3>;
	using FTexcoord_Tow = std::array<float, 2>;
	using FTexcoord_Three = std::array<float, 3>;
	using FTexcoord_Four = std::array<float, 4>;

	FPosition PositionData;
	FNormal NormalData;
	FTexcoord_Tow Texcoord;

	static std::unordered_map<uint64_t, float*> VertexAttribute2Value;
};

struct ObjFile
{
	std::vector<VertDataAttribute::FPosition> Vertices;
	std::vector<VertDataAttribute::FNormal> Normal;
	std::vector<VertDataAttribute::FTexcoord_Tow> Texcoords;
};

const static uint64_t HashPositionX = std::hash<std::string>().operator()("POSITION.x");
const static uint64_t HashPositionY = std::hash<std::string>().operator()("POSITION.y");
const static uint64_t HashPositionZ = std::hash<std::string>().operator()("POSITION.z");
const static uint64_t HashNormalX = std::hash<std::string>().operator()("NORMAL.x");
const static uint64_t HashNormalY = std::hash<std::string>().operator()("NORMAL.y");
const static uint64_t HashNormalZ = std::hash<std::string>().operator()("NORMAL.z");
const static uint64_t HashTexcoord0X = std::hash<std::string>().operator()("TEXCOORD0.x");
const static uint64_t HashTexcoord0Y = std::hash<std::string>().operator()("TEXCOORD0.z");

void cleanAndSplit(char buffer[], std::vector<std::string>& values)
{
	char* end = std::remove(buffer, buffer + strlen(buffer), ',');
	*end = 0;

	std::istringstream iss(buffer);
	values = std::vector<std::string>(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());
}

void distributeValues(const std::vector<uint64_t>& header, const std::vector<std::string>& values, ObjFile& objFile)
{
	objFile.Vertices.emplace_back();
	objFile.Normal.emplace_back();
	objFile.Texcoords.emplace_back();

	VertDataAttribute::FPosition& Vertex = objFile.Vertices.back();
	VertDataAttribute::FNormal& Normal = objFile.Normal.back();
	VertDataAttribute::FTexcoord_Tow& Texcoord = objFile.Texcoords.back();

	size_t i = 0;
	assert(header.size() == values.size());
	for (const uint64_t& h : header)
	{
		if (h == HashPositionX){
			Vertex[0] = std::stof(values[i]);
		}
		else if (h == HashPositionY){
			Vertex[1] = std::stof(values[i]);
		}
		else if (h == HashPositionZ){
			Vertex[2] = std::stof(values[i]);
		}
		else if (h == HashNormalX){
			Normal[0] = std::stof(values[i]);
		}
		else if (h == HashNormalY){
			Normal[1] = std::stof(values[i]);
		}
		else if (h == HashNormalZ){
			Normal[2] = std::stof(values[i]);
		}
		else if (h == HashTexcoord0X) {
			Texcoord[0] = std::stof(values[i]);
		}
		else if (h == HashTexcoord0Y) {
			Texcoord[1] = std::stof(values[i]);
		}
		++i;
	}
}

void printHelp()
{
	std::cout << "Using: csv2obj input.csv" << std::endl;
}

void writeObj(const ObjFile& obj, const char* outFileName)
{
	std::ofstream fOut(outFileName);
	for (const auto& v : obj.Vertices)
		fOut << "v " << v[0] << " " << v[1] << " " << v[2] << std::endl;

	for (const auto& v : obj.Normal)
		fOut << "vn " << v[0] << " " << v[1] << " " << v[2] << std::endl;

	for (const auto& v : obj.Normal)
		fOut << "vt " << v[0] << " " << v[1] << std::endl;

	fOut << "g default" << std::endl;
	
	size_t trianglesCount = obj.Vertices.size() / 3;

	for (size_t i = 0; i < trianglesCount; ++i)
	{
		fOut << "f " << 3 * i + 1 << "/" << 3 * i + 1 << "/" << 3 * i + 1 << " ";
		fOut << 3 * i + 2 << "/" << 3 * i + 2 << "/" << 3 * i + 2 << " ";
		fOut << 3 * i + 3 << "/" << 3 * i + 3 << "/" << 3 * i + 3 << std::endl;
	}

	fOut.close();
}

int main(int argc, const char* argv[])
{
	//if (argc != 2)
	//{
	//	printHelp();
	//	return 1;
	//}
	const char* test = "grass.csv";

	size_t fileNameSize = strlen(test);
	if (strcmp(test + fileNameSize - 4, ".csv"))
	{
		printHelp();
		return 2;
	}

	ObjFile output;

	char outputFileName[2048] = {};
	snprintf(outputFileName, sizeof(outputFileName), "%s", test);
	snprintf(outputFileName + fileNameSize - 4, 5, ".obj");

	char buffer[2048] = {};
	const char* inputFileName = test;
	std::ifstream fIn(inputFileName);
	fIn.getline(buffer, sizeof(buffer));

	std::vector<std::string> headerValues;
	cleanAndSplit(buffer, headerValues);
	std::vector<uint64_t> hashes;
	for (const std::string& h : headerValues) {
		uint64_t VerteAttributeHash = std::hash<std::string>().operator()(h);
		hashes.emplace_back(VerteAttributeHash);
		//VertDataAttribute::VertexAttribute2Value.emplace(VerteAttributeHash, )
	}
		
	
	while (!fIn.eof())
	{
		fIn.getline(buffer, sizeof(buffer));
		if (strlen(buffer) == 0)
			break;

		std::vector<std::string> values;
		cleanAndSplit(buffer, values);
		distributeValues(hashes, values, output);
	}

	fIn.close();

	writeObj(output, outputFileName);

    return 0;
}

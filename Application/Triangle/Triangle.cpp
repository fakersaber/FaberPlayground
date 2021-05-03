#include "Triangle.h"

std::unique_ptr<IApplicationBase> IApplicationBase::CreateApplicationInstance() {
	return std::make_unique<TriangleApp>();
}

std::string IApplicationBase::MakeAppName(const std::string& EngineName){
	return EngineName + std::string("_Triangle");
}

TriangleApp::TriangleApp()
	: IApplicationBase()
{
	
}

TriangleApp::~TriangleApp(){

}

void TriangleApp::Init(/*int32 width, int32 height, const char* title*/){

}

void TriangleApp::Tick(const float DeltaTime){

}

void TriangleApp::Release(){

}

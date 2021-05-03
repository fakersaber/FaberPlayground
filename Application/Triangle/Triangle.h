#include "Application/IApplicationBase.h"
#include <string>


class TriangleApp : public IApplicationBase{
public:
    TriangleApp();
    virtual ~TriangleApp();
	virtual void Init(/*int32 width, int32 height,const char* title*/);
	virtual void Tick(const float DeltaTime);
	virtual void Release();

	//inline int32 GetWidth() { return Width; }
	//inline int32 GetHeight() { return Height; }
	/*inline const std::string& GetAppName() { return ApplicationName; }*/
private:
    //int32 Width;
    //int32 Height;
    /*std::string ApplicationName;*/
};
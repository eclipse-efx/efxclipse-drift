#include <DriftGL.h>
#include <DriftGL_wgl.h>
#include <iostream>
#include "Test.h"

#include <cstdlib>
#include <cstring>


//Returns the last Win32 error, in string format. Returns an empty string if there is no error.
std::string GetLastErrorAsString()
{
    //Get the error message, if any.
    DWORD errorMessageID = ::GetLastError();
    if(errorMessageID == 0)
        return std::string(); //No error message has been recorded

    LPSTR messageBuffer = nullptr;
    size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                 NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

    std::string message(messageBuffer, size);

    //Free the buffer.
    LocalFree(messageBuffer);

    return message;
}

std::string ToErrorString(DWORD errorMessageID)
{
    //Get the error message, if any.
    if(errorMessageID == 0)
        return std::string(); //No error message has been recorded

    LPSTR messageBuffer = nullptr;
    size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                 NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

    std::string message(messageBuffer, size);

    //Free the buffer.
    LocalFree(messageBuffer);

    return message;
}

void testInitialize() {
	TEST_BEGIN("DriftGL initialize");

	ASSERT_TRUE(driftgl::Initialize());

	ASSERT_TRUE(driftgl::Destroy());

	HANDLE result = driftgl::wglDXOpenDeviceNV((void*)1337);
	std::cout << "result = " << result << std::endl;
	DWORD err = GetLastError();
	std::string errStr = ToErrorString(err);
	std::cout << "0x" << std::hex << err << ": '" << errStr << "'" << std::endl;

	TEST_END();
}


int main(int count, char** arg) {
	testInitialize();
}

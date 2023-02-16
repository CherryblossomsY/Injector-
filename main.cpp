#include "injector.h"
#include <iostream>
bool InitMap(const char* MapName)
{
	SECURITY_ATTRIBUTES sa;
	SECURITY_DESCRIPTOR sd;
	InitializeSecurityDescriptor(&sd, SECURITY_DESCRIPTOR_REVISION);
	SetSecurityDescriptorDacl(&sd, TRUE, NULL, FALSE);
	sa.bInheritHandle = FALSE;
	sa.lpSecurityDescriptor = &sd;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	if (CreateFileMappingA(INVALID_HANDLE_VALUE, &sa, PAGE_READWRITE, 0, 144008, MapName) == NULL)
		return false;
	return true;
}

int main()
{
	if (!InitMap("livdwmdraw2021"))
		std::cout << "map failed." << std::endl;
	ManualMapDll("dwm.exe", "dwmoverlay.dll");
	Sleep(1000);
	return 0;
}
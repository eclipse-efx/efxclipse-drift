
#include <DriftGL.h>
#include <iostream>

int main(int count, char** arg) {
	std::cout << "Test" << std::endl;

	driftgl::Initialize();

	driftgl::Context *ctx = driftgl::CreateContext(nullptr, 3, 0);

	std::cout << "Context: " << ctx << std::endl;

	bool success = driftgl::MakeContextCurrent(ctx);
	std::cout << "MakeCurrent: " << success << std::endl;

	std::cout << "GL_VERSION: " << driftgl::glGetString(driftgl::GL_VERSION) << std::endl;
	std::cout << "GL_VENDOR: " << driftgl::glGetString(driftgl::GL_VENDOR) << std::endl;

	int major, minor;
	driftgl::glGetIntegerv(driftgl::GL_MAJOR_VERSION, &major);
	driftgl::glGetIntegerv(driftgl::GL_MINOR_VERSION, &minor);
	std::cout << major << "." << minor << std::endl;

	driftgl::DestroyContext(ctx);


	driftgl::Destroy();

}

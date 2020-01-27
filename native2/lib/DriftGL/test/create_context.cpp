
#include <DriftGL.h>
#include <DriftGL_wgl.h>
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

	driftgl::DestroyContext(ctx);


	driftgl::Destroy();

}

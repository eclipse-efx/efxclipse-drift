#include <DriftGL.h>
#include <DriftGL_wgl.h>
#include <iostream>
#include "Test.h"

#include <cstdlib>
#include <cstring>

void testInitialize() {
	TEST_BEGIN("DriftGL initialize");

	ASSERT_TRUE(driftgl::Initialize());

	ASSERT_TRUE(driftgl::Destroy());

	TEST_END();
}

void fuck() {
	TEST_BEGIN("fuck");

	void* pPixels = malloc(4 * 4 * 4 * sizeof(driftgl::GLubyte));

	driftgl::Initialize();
	driftgl::Context* ctx = driftgl::CreateContext(0, 3, 2);
	driftgl::MakeContextCurrent(ctx);

	for (int i = 0; i < 100000; i++) {
		driftgl::GLuint tex;
		driftgl::glGenTextures(1, &tex);

		driftgl::glBindTexture(driftgl::GL_TEXTURE_2D, tex);

		driftgl::glTexImage2D(driftgl::GL_TEXTURE_2D, 0, driftgl::GL_RGBA8, 4, 4, 0, driftgl::GL_RGBA, driftgl::GL_UNSIGNED_INT_8_8_8_8_REV, pPixels);

		driftgl::glDeleteTextures(1, &tex);
	}

	driftgl::DestroyContext(ctx);

	driftgl::Destroy();


	free(pPixels);

	TEST_END();
}

int main(int count, char** arg) {
	fuck();
}

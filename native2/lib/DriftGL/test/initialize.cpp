#include <DriftGL.h>
#include <DriftGL_wgl.h>
#include <iostream>
#include "Test.h"


void testInitialize() {
	TEST_BEGIN("DriftGL initialize");

	ASSERT_TRUE(driftgl::Initialize());

	ASSERT_TRUE(driftgl::Destroy());

	TEST_END();
}



int main(int count, char** arg) {
	testInitialize();
}

#include <DriftGL.h>
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


int main(int count, char** arg) {
	testInitialize();
}

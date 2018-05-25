#include "TestsPerformer.h"

#include <memory>

using namespace FlameSteelEngine::GameToolkit::Tests;
using namespace std;

int main() {

	auto testsPerformer = make_shared<TestsPerformer>();
	testsPerformer->perform();

	return 0;

}
#include "TestsPerformer.h"

#include <iostream>
#include <memory>

#include "ObjectsMapTest.h"

using namespace std;
using namespace FlameSteelEngine::GameToolkit::Tests;

void TestsPerformer::perform() {

	cout << "Tests started" << endl;

	auto objectsMapTests = make_shared<ObjectsMapTest>();
	auto result = objectsMapTests->perform();

	if (!result)
	{
		cout << "Objects Map Test failed" << endl;
	}

	cout << "Tests ended" << endl;

};
#include <iostream>
#include "ObjectsMapTest.h"
#include <FlameSteelEngineGameToolkit/Data/ObjectsMap/ObjectsMap.h>
#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>

using namespace std;
using namespace FlameSteelEngine::GameToolkit;
using namespace FlameSteelEngine::GameToolkit::Tests;

bool ObjectsMapTest::perform() {

	auto object = FSEGTFactory::makeOnSceneObject(
                                        make_shared<string>("test object class"),
                                        make_shared<string>("test object identifier"),
                                        shared_ptr<string>(),
                                        shared_ptr<string>(),
						  shared_ptr<string>(),
                                        1, 0, 1,
                                        64, 64,64,
                                        0, 0, 0,
                                        0                 
                                      );

	auto objectsMap = make_shared<ObjectsMap>();
	objectsMap->handleObject(object);
	auto sameObject = objectsMap->objectAtXY(1, 1);

	if (object.get() != sameObject.get()) {

		cout << "Test 1 - basic scene object handling: Failed" << endl;

		return false;
	}

	cout << "Test 1: Success" << endl;

	auto position = FSEGTUtils::getObjectPosition(object);
	position->x = 2;
	position->z = 2;

	objectsMap->handleObject(object);

	auto objectAtOldPosition = objectsMap->objectAtXY(1, 1);
	sameObject = objectsMap->objectAtXY(2, 2);

	if (objectAtOldPosition.get() != nullptr) {

		cout << "Test 2 - object moving handling: case 1 failed" << endl;

		return false;
	}

	if (object.get() != sameObject.get()) {

		cout << "Test 2 - object moving handling: case 2 failed" << endl;

		return false;
	}

	cout << "Test 2: Success" << endl;

	objectsMap->removeObject(object);
	sameObject = objectsMap->objectAtXY(2, 2);

	if (sameObject.get() != nullptr) {

		cout << "Test 3 - object deleting: Failed" << endl;

		return false;
	}

	cout << "Test 3: Success" << endl;

	objectsMap->handleObject(object);
	objectsMap->removeAllObjects();

	sameObject = objectsMap->objectAtXY(2, 2);

	if (sameObject.get() != nullptr) {

		cout << "Test 4 - remove all: Failed" << endl;

		return false;
	}

	cout << "Test 4: Success" << endl;

	return true;
}
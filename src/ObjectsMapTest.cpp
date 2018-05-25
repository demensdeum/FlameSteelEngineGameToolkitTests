#include "ObjectsMapTest.h"
#include <FlameSteelEngineGameToolkit/Data/ObjectsMap/ObjectsMap.h>
#include <FlameSteelEngineGameToolkit/Data/Components/FSEGTFactory.h>

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
                                        0, 0, 0,
                                        64, 64,64,
                                        0, 0, 0,
                                        0                 
                                      );

	auto objectsMap = make_shared<ObjectsMap>(64, 64);
	objectsMap->addOrUpdateObject(object);
	auto sameObject = objectsMap->objectAtXY(0, 0);


	return object.get() == sameObject.get();

}
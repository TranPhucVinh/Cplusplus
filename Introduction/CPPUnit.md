# Fundamental concept 

CPPUnit is a test framework used for CPP unit testing.

## Install and setup

Check [libcppunit installation document in Linux Shell](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Bash%20script/Install%20package.md#download-debian-package-from-link-for-used-as-system-library-in-usrlibx86_64-linux-gnu)

After successfully install ``libcppunit`` package, CPPUnit now is available as an external library.

## Implementation

A fixture, from ``TestFixture``, is a known set of objects that serves as a base for a set of test cases.

**Example**

```cpp
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>

class TestClass : public CppUnit::TestFixture
{
	void equal_check()
	{
		CPPUNIT_ASSERT_EQUAL(1 + 1, 2);
	}

	CPPUNIT_TEST_SUITE(TestClass);
	CPPUNIT_TEST(equal_check);
	CPPUNIT_TEST_SUITE_END();
};

CPPUNIT_TEST_SUITE_REGISTRATION(TestClass);

int main()
{
	CPPUNIT_NS::Test *suite = CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest();//Get the top level suite from the registry
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(suite);//Add test suite
	runner.run();//Run test suite
	return 0;
}
```

Compile: ``g++ test.cpp -lcppunit``

Result

```
OK (1 tests)
```

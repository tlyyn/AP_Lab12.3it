#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_Lab12.3it/Source.cpp" // include the header file for your code

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourTestProject
{
    TEST_CLASS(YourTestProject)
    {
    public:

        TEST_METHOD(TestEnqueue)
        {
            Elem* first = NULL, * last = NULL;
            enqueue(first, last, 1);
            Assert::IsNotNull(first);
            Assert::IsNotNull(last);
            Assert::AreEqual(first->info, 1);
            Assert::AreEqual(last->info, 1);
        }

        TEST_METHOD(TestSwapList)
        {
            Elem* first = NULL, * last = NULL;
            enqueue(first, last, 1);
            enqueue(first, last, 2);
            enqueue(first, last, 3);
            swapList(first, last);
            Assert::AreEqual(first->info, 3);
            Assert::AreEqual(last->info, 1);
        }
    };
}
#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HivemindLibraryTest
{
	TEST_CLASS(HiveTest)
	{
	public:

		static void InitializeLeakDetection()
		{
			_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF);
			_CrtMemCheckpoint(&sStartMemState);
		}

		/// Detects if memory state has been corrupted
		static void FinalizeLeakDetection()
		{
			_CrtMemState endMemState, diffMemState;
			_CrtMemCheckpoint(&endMemState);
			if (_CrtMemDifference(&diffMemState, &sStartMemState, &endMemState))
			{
				_CrtMemDumpStatistics(&diffMemState);
				Assert::Fail(L"Memory Leaks!");
			}

			// ReSharper disable CppSomeObjectMembersMightNotBeInitialized
			UNREFERENCED_PARAMETER(endMemState);
			UNREFERENCED_PARAMETER(diffMemState);
			// ReSharper restore CppSomeObjectMembersMightNotBeInitialized
		}

		TEST_METHOD_INITIALIZE(MethodInitialize)
		{
			InitializeLeakDetection();
		}

		TEST_METHOD_CLEANUP(MethodCleanup)
		{
			FinalizeLeakDetection();
		}

		TEST_METHOD(Hive_Stub)
		{
			Assert::Fail(L"Test not implemented");
		}

		static _CrtMemState sStartMemState;
	};

	_CrtMemState HiveTest::sStartMemState;
}
#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\maxor\Desktop\project 1\project 1\project 1.cpp" //������� ���� �� ����� ���������.

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(calculate_Test1) //���������� ��������� � ������� ����������.
	{
	public:

		TEST_METHOD(calculate_get3and10_15returned) //������ ����� ���������� ��������� � ��� ��������� �������.
		{
			int n = 3; //���� ��� ����������.
			int x = 10; //���� ��� ����������.
			int expected = 15; //³������ ������� �� ����'���� � �������, �� ������ ����������.
			int actual = calculate(n, x); //���������� �� ��������� ��������� ������ � ������ �������.
			Assert::AreEqual(expected, actual); //��������� ������� ������ �� ����������� ���������� ������.
		}
	};
	TEST_CLASS(calculate_Test2) //���������� ��������� � ������ ���������� ��� 100% �������� ����������� ���������.
	{
	public:

		TEST_METHOD(calculate_get3and10_15returned) //������ ����� ���������� ��������� � ��� ��������� �������.
		{
			int n = 5; //���� ��� ����������.
			int x = -10; //���� ��� ����������.
			int expected = -34; //³������ ������� �� ����'���� � �������, �� ������ ����������.
			int actual = calculate(n, x); //���������� �� ��������� ��������� ������ � ������ �������.
			Assert::AreEqual(expected, actual); //��������� ������� ������ �� ����������� ���������� ������.
		}
	};
	TEST_CLASS(checkVaildParams_Tests) //���������� ��������� �� ��������� ����.
	{
	public:
		TEST_METHOD(checkValiddParams_get18_exceptionNotThrown) //������ ����� ����������.
		{
			int n = 18; //���� ��� ����������(²�Ͳ).
			try
			{
				checkValidParams(n); //��������� �� ������� checkValidParams ��� ��������� ������.
				Assert::IsTrue(true); //���� ����� ��������, ������ ���� ��� - Assert �s True.
			}
			catch (...)
			{
				Assert::Fail(); //���� ����� �� ��������, ������ ���� �� ��� - Assert �s Fail (�������).
			}
		}
	public:
		TEST_METHOD(checkValiddParams_get0_exceptionThrown) //������ (����������) ����� ����������.
		{
			{
				int n = 0; //���� ��� ����������(����� ²�Ͳ �������� ���� ��� ֲ�� �����).
				//���, n = 0 < 2, ��� � ����� ����� try catch n = 0 ���� ���� ��������� �������� Fail � ����� try.
				//����� ���� ��� ���� try catch �����, �� n = 0 �� ����, ���� �� ��������� ���� 
				//� ���� � ��������� catch, � ������ �� ��������� �������� ������� �� ������ Assert::Fail().
				try
				{
					checkValidParams(n); //��������� �� ������� checkValidParams ��� ��������� ������.
					Assert::Fail(); //���� ����� �� ��������, ������ ���� �� ��� - Assert �s Fail.
				}
				catch (...)
				{
					Assert::IsTrue(true); //���� ����� ��������, ������ ���� ��� - Assert �s True (�������).
				}
			}
		};
	};
}

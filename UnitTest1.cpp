#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\maxor\Desktop\project 1\project 1\project 1.cpp" //Вказуємо шлях до файла программи.

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(calculate_Test1) //Тестування программи з першими значеннями.
	{
	public:

		TEST_METHOD(calculate_get3and10_15returned) //Перший метод тестування программи з вже вписаними данними.
		{
			int n = 3; //Данні для розрахунку.
			int x = 10; //Данні для розрахунку.
			int expected = 15; //Вірогідна відповідь на розв'язок з данними, які вписав користувач.
			int actual = calculate(n, x); //Розрахунок та отримання правильної відповіді з даними числами.
			Assert::AreEqual(expected, actual); //Порівняння вірогідної відповіді та розрахованої прогрмамою відповіді.
		}
	};
	TEST_CLASS(calculate_Test2) //Тестування программи з іншими значеннями для 100% перевірки правильності программи.
	{
	public:

		TEST_METHOD(calculate_get3and10_15returned) //Другий метод тестування программи з вже вписаними данними.
		{
			int n = 5; //Данні для розрахунку.
			int x = -10; //Данні для розрахунку.
			int expected = -34; //Вірогідна відповідь на розв'язок з данними, які вписав користувач.
			int actual = calculate(n, x); //Розрахунок та отримання правильної відповіді з даними числами.
			Assert::AreEqual(expected, actual); //Порівняння вірогідної відповіді та розрахованої прогрмамою відповіді.
		}
	};
	TEST_CLASS(checkVaildParams_Tests) //Тестування программи на виконання умов.
	{
	public:
		TEST_METHOD(checkValiddParams_get18_exceptionNotThrown) //Перший метод тестування.
		{
			int n = 18; //Данні для розрахунку(ВІРНІ).
			try
			{
				checkValidParams(n); //Посилання на функцію checkValidParams для отримання данних.
				Assert::IsTrue(true); //Якщо умова виконана, введені данні вірні - Assert іs True.
			}
			catch (...)
			{
				Assert::Fail(); //Якщо умова не виконана, введені данні не вірні - Assert іs Fail (ПОМИЛКА).
			}
		}
	public:
		TEST_METHOD(checkValiddParams_get0_exceptionThrown) //Другий (остаточний) метод тестування.
		{
			{
				int n = 0; //Данні для розрахунку(ТАКОЖ ВІРНІ ЗНАЧЕННЯ САМЕ ДЛЯ ЦІЄЇ УМОВИ).
				//Так, n = 0 < 2, але у цьому блоці try catch n = 0 буде мати правильне значення Fail в блоці try.
				//Тобто саме цей блок try catch вважає, що n = 0 це вірно, тому не відправляє його 
				//в блок з помилками catch, а записує як правильно виконану функцію та виписує Assert::Fail().
				try
				{
					checkValidParams(n); //Посилання на функцію checkValidParams для отримання данних.
					Assert::Fail(); //Якщо умова не виконана, введені данні не вірні - Assert іs Fail.
				}
				catch (...)
				{
					Assert::IsTrue(true); //Якщо умова виконана, введені данні вірні - Assert іs True (ПОМИЛКА).
				}
			}
		};
	};
}

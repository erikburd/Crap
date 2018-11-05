// CPPTest1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <iostream>

int main()
{
	LARGE_INTEGER m_frequency;
	LARGE_INTEGER m_starttime;
	LARGE_INTEGER m_endtime;

	::QueryPerformanceFrequency(&m_frequency);
	m_starttime.QuadPart = 0;
	m_endtime.QuadPart = 0;

	for (int i = 0; i < 10; i++)
	{
		::QueryPerformanceCounter(&m_starttime);
		::Sleep(750);
		::QueryPerformanceCounter(&m_endtime);

		std::cout << "Time: " << ((m_endtime.QuadPart - m_starttime.QuadPart) * 1000 / m_frequency.QuadPart) << "\n";
	}


	std::cout << "Hello World!\n"; 
}

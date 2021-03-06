// CPPTest1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <iostream>

int main()
{
	const int NUM_ITERATIONS = 10;

	LARGE_INTEGER m_frequency;
	LARGE_INTEGER m_starttime;
	LARGE_INTEGER m_endtime;

	::QueryPerformanceFrequency(&m_frequency);
	m_starttime.QuadPart = 0;
	m_endtime.QuadPart = 0;

	double dTotalTime = 0.0;

	for (int i = 0; i < NUM_ITERATIONS; i++)
	{
		::QueryPerformanceCounter(&m_starttime);
		::Sleep(750);
		::QueryPerformanceCounter(&m_endtime);
		double dTime = ((m_endtime.QuadPart - m_starttime.QuadPart) * 1000 / m_frequency.QuadPart);
		dTotalTime += dTime;
		std::cout << "Iteration " << i << " Time: " << dTime << "\n";
	}

	std::cout << "Average Time: " << dTotalTime / NUM_ITERATIONS << "\n";
}

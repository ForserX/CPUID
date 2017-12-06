#include "../include/cpuid.hpp"
#include <Windows.h>
#include <iostream>

void main()
{
	processor_info CPU;

	std::cout << CPU.hasFeature(CPUFeature::MMXExt);
	std::cout << CPU.hasFeature(CPUFeature::AVX512F);
	std::cout << CPU.hasFeature(CPUFeature::AVX);
}
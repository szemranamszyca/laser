#include <iostream>
#include <string>

#include "../include/HMI.hpp"

namespace emulator
{
namespace HMI
{

HMI::HMI()
{
	std::cout << "HMI created!\n";
}

HMI::~HMI()
{}

void HMI::interact() const
{
	std::string input;
	if (cmd_ == nullptr)
	{
		return;
	}
	
	while(1)
	{
		std::cin >> input;
		auto output = cmd_(input);
		std::cout << output << '\n'; 
	}
}

void HMI::plugProcessor(const processorFunction& procToBePlugged)
{
	std::cout << "Plugging command processor\n";
	cmd_= [=](std::string cmd) -> std::string
	{
		return procToBePlugged(cmd);
	};

}

} // namespace HMI
} // namespace emulator

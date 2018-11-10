#include <iostream>
#include <string>

#include "../include/HMI.hpp"

namespace laser
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
	// add check if proc is plugged!
	while(1)
	{
		std::cin >> input;
		auto output = cmd_(input);
		std::cout << "OUTPUT: " << output << '\n'; 
	}
}

void HMI::plugProcessor(processorFunction procToBePlugged)
{
	std::cout << "Pluggin cmd processor\n";
	cmd_= [=](std::string cmd) -> std::string
	{
		return procToBePlugged(cmd);
	};

}

} // namespace HMI
} // namespace laser


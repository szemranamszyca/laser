#include <iostream>

#include "../include/CmdProcessor.hpp"

namespace laser
{
namespace cmdProcessor
{

CmdProcessor::CmdProcessor()
{
	std::cout << "CmdProcessor created!\n";
}

CmdProcessor::~CmdProcessor()
{}

std::string CmdProcessor::process(const std::string& input) const
{
	std::cout << "INPUT: " << input << '\n';
	std::string output = input + "#";
	return output;
}

} // namespace CmdProcessor
} // namespace laser


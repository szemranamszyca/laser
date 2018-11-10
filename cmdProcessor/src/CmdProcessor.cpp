#include <iostream>
#include <algorithm>

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


void CmdProcessor::configure(
	std::shared_ptr<std::map<std::string, std::function<bool()>>> actionFuncMap)
{
	actionFunctionMap_ = actionFuncMap;
}

std::string CmdProcessor::process(const std::string& input) const
{
	std::cout << "INPUT: " << input << '\n';
	std::string commandToProcess = input;
	if (sillyMode_)
		std::reverse(commandToProcess.begin(), commandToProcess.end());

    std::string extractedCommand = extractCmd(input);

    auto actionIt = commandActionMap_.find(extractedCommand);

    std::string output;
    if (actionIt == commandActionMap_.end())
    	output = "UK!";
    else
    {
    	auto functionIt = actionFunctionMap_->find(actionIt->second);
    	if (functionIt == actionFunctionMap_->end())
    	{
  			output = "no function!";
    	}
    	else
    	{    	
    		output += (functionIt->second() ? "1" : "0");
    	}
    }


	output += "#";
	return output;
}

std::string CmdProcessor::extractCmd(const std::string& inputCmd) const
{
	return inputCmd.substr(0, 3);
}

} // namespace cmdProcessor
} // namespace laser


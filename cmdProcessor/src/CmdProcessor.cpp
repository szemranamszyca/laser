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
	std::shared_ptr<std::map<std::string, std::function<bool(Params&)>>> actionFuncMap)
{
	actionFunctionMap_ = actionFuncMap;
}

std::string CmdProcessor::process(const std::string& input)
{
	std::cout << "INPUT: " << input << '\n';
	std::string commandToProcess = input;
	if (sillyMode_)
		std::reverse(commandToProcess.begin(), commandToProcess.end());

	//i'm aware that this might be considered as hack 
	//due to there's no spec that cmd always has 3 letters
    std::string extractedCommand = extractCmd(commandToProcess);

    if (extractedCommand == "ESM")
    {
        sillyMode_ = true;
        return "ESM#";
    }
    if (extractedCommand == "DSM")
    {
        sillyMode_ = false;
        return "DSM#";
    }

    auto actionIt = commandActionMap_.find(extractedCommand);
    if (actionIt == commandActionMap_.end())
    	return "UK!";

	auto functionIt = actionFunctionMap_->find(actionIt->second);
	if (functionIt == actionFunctionMap_->end())
	{
			return "No defined action for command " + extractedCommand +
            " shouldn't happend!";
	}
 	
    Params params;
    if (extractedCommand == "PW=")
    {
        auto extractedParam = extractParameter(commandToProcess);
        params.inParam = extractedParam;
    }

    bool success = functionIt->second(params);
    
    if (params.outParam)
    {
        extractedCommand += "|" + std::to_string(*params.outParam);
    }

	extractedCommand += (success ? '#' : '!');

	return extractedCommand;
}

std::string CmdProcessor::extractCmd(const std::string& inputCmd) const
{
	return inputCmd.substr(0, 3);
}

int CmdProcessor::extractParameter(const std::string& inputCmd) const
{
    // check if inputCmd is in correct syntax should be added
    return std::stoi(inputCmd.substr(4, inputCmd.size()-1));
}

} // namespace cmdProcessor
} // namespace laser


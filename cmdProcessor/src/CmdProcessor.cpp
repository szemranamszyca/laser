#include <iostream>
#include <algorithm>
#include <sstream>

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
	std::shared_ptr<ActionFunctionMap_t> actionFuncMap)
{
	actionFunctionMap_ = actionFuncMap;
}

std::string CmdProcessor::process(const std::string& input)
{
	std::cout << "INPUT: " << input << '\n';
	std::string commandToProcess = input;
	if (sillyMode_)
		std::reverse(commandToProcess.begin(), commandToProcess.end());

    auto cmdTokens = splitCmd(commandToProcess);
    auto extractedCommand = cmdTokens[0];

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
    {
    	return "UK!";
    }

	auto functionIt = actionFunctionMap_->find(actionIt->second);
	if (functionIt == actionFunctionMap_->end())
	{
			return "No defined action for command " + extractedCommand +
            " shouldn't happend!";
	}
 	
    Params params;
    if (extractedCommand == "PW=")
    {
        params.inParam = std::stoi(cmdTokens[1]);
    }

    bool success = functionIt->second(params);
    
    if (params.outParam)
    {
        extractedCommand += "|" + std::to_string(*params.outParam);
    }

	extractedCommand += (success ? '#' : '!');

	return extractedCommand;
}

std::vector<std::string> CmdProcessor::splitCmd(const std::string& inputCmd) const
{
    std::stringstream command(inputCmd);
    std::vector<std::string> tokens;
    std::string tmpToken;

    while(getline(command, tmpToken, '|')) 
    { 
        tokens.push_back(tmpToken); 
    }
    return tokens;
}

} // namespace cmdProcessor
} // namespace laser

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
	std::shared_ptr<ActionReactionMap_t> actionReactionMap)
{
	actionReactionMap_ = actionReactionMap;
}

std::string CmdProcessor::process(const std::string& input)
{
	std::string commandToProcess = input;
	if (sillyMode_)
		std::reverse(commandToProcess.begin(), commandToProcess.end());

    auto cmdTokens = tokenizeCmd(commandToProcess);
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

	auto reactionIt = actionReactionMap_->find(actionIt->second);
	if (reactionIt == actionReactionMap_->end())
	{
			return "No defined reaction for command " + extractedCommand +
            " shouldn't happend!";
	}
 	
    Params params;
    if (extractedCommand == "PW=")
    {
        params.inParam = std::stoi(cmdTokens[1]);
    }

    bool success = reactionIt->second(params);
    
    if (params.outParam)
    {
        extractedCommand += "|" + std::to_string(*params.outParam);
    }

	extractedCommand += (success ? '#' : '!');

	return extractedCommand;
}

std::vector<std::string> CmdProcessor::tokenizeCmd(const std::string& inputCmd) const
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

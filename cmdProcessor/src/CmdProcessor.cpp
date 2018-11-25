#include <iostream>
#include <algorithm>
#include <sstream>

#include "../include/CmdProcessor.hpp"

namespace emulator
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
    if (actionReactionMap_ == nullptr)
    {
        std::cout << "CmdProcessor not configured!\n";
        return "UK!";
    }

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

    std::cout << "EX cmd " << extractedCommand << '\n';
    
    auto cmdActionIt = commandActionMap_.find(extractedCommand);
    if (cmdActionIt == commandActionMap_.end())
    {
    	return "UK!";
    }

    auto validator = cmdActionIt->second.first;
    if (!validator(cmdTokens.size()-1))
    {
        std::cout << "[Validation not passed!]\n";
        return "UK!";
    }

	auto reactionIt = actionReactionMap_->find(cmdActionIt->second.second);
	if (reactionIt == actionReactionMap_->end())
	{
			return "No defined reaction for command " + extractedCommand +
            " shouldn't NEVER happend!";
	}
 	
    /*INPUT PHASE*/
    Params params;
    if (extractedCommand == "PW=" && cmdTokens.size() == 2)
    {
        params.push_back(std::stoi(cmdTokens[1]));
    }

    bool success = reactionIt->second(params);
    
    /*OUTPUT PHASE*/
    if (params.size() > 0)
    {
        for (const auto& param : params)
        {
            extractedCommand += "|" + std::to_string(param);
        }
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
} // namespace emulator

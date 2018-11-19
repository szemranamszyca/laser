#ifndef CMDPROCESSOR_H
#define CMDPROCESSOR_H

#include <string>
#include <memory>
#include <optional>

#include "ICmdProcessor.hpp"

namespace laser
{
namespace cmdProcessor
{

class CmdProcessor : public ICmdProcessor
{
public:
	CmdProcessor();
	virtual ~CmdProcessor();
	std::string process(const std::string&) override;
	void configure(std::shared_ptr<ActionReactionMap_t>) override;


private:
	const std::map<std::string, std::string> commandActionMap_ = 
	{
		{"STR", "StartEmission"},
		{"STP", "StopEmission"},
		{"ST?", "GetStatus"},
		{"KAL", "KeepAlive"},
		{"PW?", "GetPower"},
		{"PW=", "SetPower"}
	};

	std::shared_ptr<const ActionReactionMap_t> actionReactionMap_;
	bool sillyMode_;
	std::vector<std::string> tokenizeCmd(const std::string&) const;
};

} // namespace laser
} // namespace cmdProcessor

#endif /* CMDPROCESSOR_H */


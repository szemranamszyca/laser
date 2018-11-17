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
	std::string process(const std::string&);
	void configure(std::shared_ptr<ActionFunctionMap_t>) override;


private:
	std::map<std::string, std::string> commandActionMap_ = 
	{
		{"STR", "StartEmission"},
		{"STP", "StopEmission"},
		{"ST?", "GetStatus"},
		{"KAL", "KeepAlive"},
		{"PW?", "GetPower"},
		{"PW=", "SetPower"},
		{"ESM", "SillyModeOn"},
		{"DSM", "SillyModeOff"}
	};

	std::shared_ptr<const std::map<std::string, std::function<bool(Params&)>>> actionFunctionMap_;
	bool sillyMode_;
	std::string extractCmd(const std::string&) const;
	int extractParameter(const std::string&) const;
};

} // namespace laser
} // namespace cmdProcessor

#endif /* CMDPROCESSOR_H */


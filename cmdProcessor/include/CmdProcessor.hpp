#ifndef CMDPROCESSOR_H
#define CMDPROCESSOR_H

#include <string>
#include <memory>
#include "ICmdProcessor.hpp"

// not pretty include
#include "../../controlPanel/include/ControlPanel.hpp"

namespace laser
{
namespace cmdProcessor
{

class CmdProcessor : public ICmdProcessor
{
public:
	CmdProcessor();
	virtual ~CmdProcessor();
	std::string process(const std::string&) const override;
	void configure(std::shared_ptr<std::map<std::string, std::function<bool()>>>) override;


private:
	std::map<std::string, std::string> commandActionMap_ = {{"ST?", "GetStatus"}};
	std::shared_ptr<const std::map<std::string, std::function<bool()>>> actionFunctionMap_;
	bool sillyMode_;
	std::string extractCmd(const std::string&) const;
};

} // namespace laser
} // namespace cmdProcessor


#endif /* CMDPROCESSOR_H */
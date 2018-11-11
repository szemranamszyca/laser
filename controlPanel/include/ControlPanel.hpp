#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <memory>
#include <map>
#include "IControlPanel.hpp"
#include "../../HMI/include/HMI.hpp"
#include "../../cmdProcessor/include/CmdProcessor.hpp"

namespace laser
{
namespace controlPanel
{


// enum class Action
// {
// 	StartEmission, 
// 	StopEmission, 
// 	GetStatus, 
// 	SetPower, 
// 	GetPower, 
// 	SillyModeON, 
// 	SillyModeOFF 
// };

using Func_t = std::function<bool(laser::cmdProcessor::Params&)>;
using ActionFunctionMap_t = std::map<std::string, Func_t>;

class ControlPanel : public IControlPanel
{
public:
	ControlPanel(
		std::unique_ptr<laser::HMI::IHMI>,
		std::unique_ptr<laser::cmdProcessor::ICmdProcessor>);
	virtual ~ControlPanel();

	void configure() const override;
	void start() const override;

private:
	void addActionFunc(const std::string&, const Func_t& func);
	uint8_t laserPower_;
	bool emissionStatus_ = true;

	std::unique_ptr<laser::HMI::IHMI> hmi_;
	std::unique_ptr<laser::cmdProcessor::ICmdProcessor> cmdProcessor_;
	std::shared_ptr<ActionFunctionMap_t> actionFuncMap_;

};

} // namespace laser
} // namespace controlPanel


#endif /* CONTROLPANEL_H */
#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <memory>
#include <map>
#include "IControlPanel.hpp"
#include "../../HMI/include/IHMI.hpp"
#include "../../cmdProcessor/include/ICmdProcessor.hpp"

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
	void addActionFunc(const std::string&, const laser::cmdProcessor::Func_t& func);
	uint8_t laserPower_;
	bool emissionStatus_;

	std::unique_ptr<laser::HMI::IHMI> hmi_;
	std::unique_ptr<laser::cmdProcessor::ICmdProcessor> cmdProcessor_;
	std::shared_ptr<laser::cmdProcessor::ActionFunctionMap_t> actionFuncMap_;

};

} // namespace laser
} // namespace controlPanel


#endif /* CONTROLPANEL_H */


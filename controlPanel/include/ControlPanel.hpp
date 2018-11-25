#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <memory>
#include <map>
#include <chrono>
#include <future>
#include "IControlPanel.hpp"
#include "../../HMI/include/IHMI.hpp"
#include "../../cmdProcessor/include/ICmdProcessor.hpp"


namespace emulator
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
		std::unique_ptr<emulator::HMI::IHMI>,
		std::unique_ptr<emulator::cmdProcessor::ICmdProcessor>);
	virtual ~ControlPanel();

	void configure() const override;
	void start() const override;

private:
	void addActionReaction(const std::string&, const emulator::cmdProcessor::Reaction_t&);
	uint8_t laserPower_;
	bool emissionStatus_;

	size_t deathMenSwitch;
	std::chrono::system_clock::time_point lastKalSignal_;
	std::future<void> timer_;

	std::unique_ptr<emulator::HMI::IHMI> hmi_;
	std::unique_ptr<emulator::cmdProcessor::ICmdProcessor> cmdProcessor_;
	std::shared_ptr<emulator::cmdProcessor::ActionReactionMap_t> actionReactionMap_;

};

} // namespace emulator
} // namespace controlPanel


#endif /* CONTROLPANEL_H */


#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <memory>
#include "IControlPanel.hpp"
#include "../../HMI/include/HMI.hpp"
#include "../../cmdProcessor/include/CmdProcessor.hpp"

namespace laser
{
namespace controlPanel
{


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
	std::unique_ptr<laser::HMI::IHMI> hmi_;
	std::unique_ptr<laser::cmdProcessor::ICmdProcessor> cmdProcessor_;
};

} // namespace laser
} // namespace controlPanel


#endif /* CONTROLPANEL_H */
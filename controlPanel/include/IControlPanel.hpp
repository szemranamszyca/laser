#ifndef ICONTROLPANEL_H
#define ICONTROLPANEL_H

namespace emulator
{
namespace controlPanel
{


class IControlPanel
{
public:
	virtual void configure() const = 0;
	virtual void start() const = 0;
	virtual ~IControlPanel(){};
};

} // namespace emulator
} // namespace controlPanel

#endif /* ICONTROLPANEL_H */


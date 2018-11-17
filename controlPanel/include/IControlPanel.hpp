#ifndef ICONTROLPANEL_H
#define ICONTROLPANEL_H

namespace laser
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

} // namespace laser
} // namespace controlPanel

#endif /* ICONTROLPANEL_H */


#ifndef IHMI_H
#define IHMI_H

#include <functional>

namespace laser
{
namespace HMI
{

using processorFunction = std::function<std::string(std::string)>;

class IHMI
{
public:
	virtual void interact() const = 0;
	virtual void plugProcessor(processorFunction) = 0;
	virtual ~IHMI(){};
};

} // namespace laser
} // namespace cmdProcessor

#endif /* IHMI_H */
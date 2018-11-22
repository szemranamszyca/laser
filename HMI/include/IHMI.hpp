#ifndef IHMI_HPP
#define IHMI_HPP

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
	virtual void plugProcessor(const processorFunction&) = 0;
	virtual ~IHMI(){};
};

} // namespace laser
} // namespace cmdProcessor

#endif /* IHMI_HPP */

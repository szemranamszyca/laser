#ifndef ICMDPROCESSOR_H
#define ICMDPROCESSOR_H

#include <memory>
#include <functional>
#include <map>

namespace laser
{
namespace cmdProcessor
{

class ICmdProcessor
{
public:
	virtual std::string process(const std::string&) const = 0;
	virtual void configure(
		std::shared_ptr<std::map<std::string, std::function<bool()>>>) = 0;
	virtual ~ICmdProcessor(){};
};

} // namespace laser
} // namespace cmdProcessor

#endif /* ICMDPROCESSOR_H */
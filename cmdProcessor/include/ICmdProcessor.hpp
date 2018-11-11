#ifndef ICMDPROCESSOR_H
#define ICMDPROCESSOR_H

#include <memory>
#include <functional>
#include <map>

namespace laser
{
namespace cmdProcessor
{

struct Params
{
	std::optional<int> inParam;
	std::optional<int> outParam;
};

class ICmdProcessor
{
public:
	virtual std::string process(const std::string&) = 0;
	virtual void configure(
		std::shared_ptr<std::map<std::string, std::function<bool(Params&)>>>) = 0;
	virtual ~ICmdProcessor(){};
};

} // namespace laser
} // namespace cmdProcessor

#endif /* ICMDPROCESSOR_H */
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


using Func_t = std::function<bool(Params&)>;
using ActionFunctionMap_t = std::map<std::string, Func_t>;


class ICmdProcessor
{
public:
	virtual std::string process(const std::string&) = 0;
	virtual void configure(
		std::shared_ptr<ActionFunctionMap_t>) = 0;
	virtual ~ICmdProcessor(){};
};

} // namespace laser
} // namespace cmdProcessor

#endif /* ICMDPROCESSOR_H */


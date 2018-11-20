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

using Validator_t = std::function<bool(size_t)>;
using Reaction_t = std::function<bool(Params&)>;
using ActionReactionMap_t = std::map<std::string, Reaction_t>;


class ICmdProcessor
{
public:
	virtual std::string process(const std::string&) = 0;
	virtual void configure(
		std::shared_ptr<ActionReactionMap_t>) = 0;
	virtual ~ICmdProcessor(){};
};

} // namespace laser
} // namespace cmdProcessor

#endif /* ICMDPROCESSOR_H */


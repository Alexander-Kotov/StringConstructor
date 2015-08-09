#include "StringConstructor.h"
#include <regex>
#include "TextGenerator.h"

StringConstructor::StringConstructor(const StringView &template_,
                                     IGeneratorRegistry &registry)
{
    std::regex re("\\$\\{([^}]*)\\}");
    std::cregex_iterator begin(template_.begin(), template_.end(), re);
    std::cregex_iterator end;

    if (begin != end) {
        size_t index = 0;
        while(index < template_.size()) {
            const std::cmatch &match = *begin;

            if (index == match.position()) {
                auto generator = registry.getGenerator(match[1].str());
                if (generator) {
                    program.emplace_back(std::move(generator));
                }

                index += match.length();
                ++begin;

                if (begin == end) {
                    auto generator = std::make_shared<TextGenerator>(template_.substr(index, template_.size() - index));
                    program.emplace_back(std::move(generator));
                    index = template_.size();
                }
            } else if (index < match.position()) {
                auto generator = std::make_shared<TextGenerator>(template_.substr(index, match.position() - index));
                program.emplace_back(std::move(generator));
                index = match.position();
            }
        }
    } else {
        auto generator = std::make_shared<TextGenerator>(template_);
        program.emplace_back(std::move(generator));
    }
}

void StringConstructor::constructTo(std::ostream &s)
{
    for(auto &g : program) {
        g->generateTo(s);
    }
}

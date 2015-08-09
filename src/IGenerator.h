#ifndef IGENERATOR_H
#define IGENERATOR_H

class IGenerator {
public:
    virtual ~IGenerator() {}

    virtual void generateTo(std::ostream &) = 0;
};

#endif

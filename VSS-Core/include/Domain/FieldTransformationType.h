#ifndef FIELD_TRANSFORMATION_H_
#define FIELD_TRANSFORMATION_H_

#include <string>

namespace vss {

    enum FieldTransformationType{
        None = 0,
        Flip180Degrees = 1
    };

    std::string toDescription(FieldTransformationType);
    FieldTransformationType toFieldTransformationType(std::string);

}

#endif
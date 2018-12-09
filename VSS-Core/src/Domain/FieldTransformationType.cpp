//
// Created by johnathan on 01/07/18.
//

#include <Domain/FieldTransformationType.h>

namespace vss {

    std::string toDescription(FieldTransformationType fieldTransformationType) {
        switch (fieldTransformationType){
            case FieldTransformationType::None:
                return "None";
            case FieldTransformationType::Flip180Degrees:
                return "Flip180Degrees";
            default:
                return "None";
        }
    }

    FieldTransformationType toFieldTransformationType(std::string fieldTransformationType) {
        if(fieldTransformationType == "None")
            return FieldTransformationType::None;

        if(fieldTransformationType == "Flip180Degrees")
            return FieldTransformationType::Flip180Degrees;

        return FieldTransformationType::None;
    }

};
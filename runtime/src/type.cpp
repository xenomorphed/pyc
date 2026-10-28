#include <type.hpp>

namespace pyc {
    Type::Type(long double digital, string type_name, map<string, Type> fields) {
        this->digital = digital;
        this->type_name = type_name;
        this->fields = fields;
    }
}
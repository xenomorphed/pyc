#pragma once

#include <string>
#include <map>
#include <optional>

using namespace std;

namespace pyc {
    class Type {
        private:
            long double digital;
            string type_name;
            optional<map<string, Type>> fields;
        
        public:
            explicit Type(long double digital, string type_name, optional<map<string, Type>> fields);
            explicit Type(long double digital, string type_name);
            virtual ~Type() = default;

            string __str__() {
                return to_string(this->digital);
            }
    };
}
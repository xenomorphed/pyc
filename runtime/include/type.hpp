#pragma once

#include <string>
#include <map>

using namespace std;

namespace pyc {
    class Type {
        private:
            long double digital;
            string type_name;
            map<string, Type> fields;
        
        public:
            explicit Type(long double digital, string type_name, map<string, Type> fields);
            virtual ~Type() = default;
    };
}
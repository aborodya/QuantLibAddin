
#include <qlo/obj_date.hpp>

bool QuantLibAddin::dateIsEndOfMonth(const QuantLib::Date& d) {
    return QuantLib::Date::isEndOfMonth(d);
}


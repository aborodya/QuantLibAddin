
%feature("rp:group", "calendars");
%feature("rp:obj_include") %{
#include <ql/time/calendar.hpp>
%}

%feature("rp:loopParameter", "date") QuantLib::Calendar::isEndOfMonth;
%feature("rp:loopParameter", "date") QuantLib::Calendar::endOfMonth;
%feature("rp:loopParameter", "period") QuantLib::Calendar::advance;

namespace QuantLib {

    class Calendar {
    
    public:
    
        bool isEndOfMonth(const QuantLib::Date& date) const;
        QuantLib::Date endOfMonth(const QuantLib::Date& date) const;
        
        QuantLib::Date advance(
            const QuantLib::Date& date,
            const QuantLib::Period& period,
            QuantLib::BusinessDayConvention convention,
            bool endOfMonth) const;        
    };
}

%feature("rp:group", "");

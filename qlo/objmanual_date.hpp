
#ifndef obj_date_hpp
#define obj_date_hpp

#include <string>
#include <oh/libraryobject.hpp>
#include <oh/valueobject.hpp>
#include <boost/shared_ptr.hpp>
#include <ql/time/date.hpp>

namespace QuantLibAddin {

    // BEGIN typemap rp_tm_obj_ret bool
    bool
    // END   typemap rp_tm_obj_ret
    dateIsEndOfMonth(
        // BEGIN typemap rp_tm_default
        QuantLib::Date const &d
        // END   typemap rp_tm_default
    );
} // namespace QuantLibAddin

#endif


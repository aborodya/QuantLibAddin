
#ifndef obj_ratehelpers_hpp
#define obj_ratehelpers_hpp

#include <string>
#include <oh/libraryobject.hpp>
#include <oh/valueobject.hpp>
//#include <boost/shared_ptr.hpp>
//#include <ql/quotes/simplequote.hpp>
//#include <ql/quotes/lastfixingquote.hpp>
//#include <ql/quotes/futuresconvadjustmentquote.hpp>
//#include <ql/math/comparison.hpp>
#include <ql/termstructures/yield/oisratehelper.hpp>

namespace QuantLibAddin {

    class RateHelper : public ObjectHandler::LibraryObject<QuantLib::RateHelper> {
      public:
        //enum DepoInclusionCriteria {AllDepos,
        //                            DeposBeforeFirstFuturesStartDate,
        //                            DeposBeforeFirstFuturesStartDatePlusOne,
        //                            DeposBeforeFirstFuturesExpiryDate
        //};
        std::string quoteName() { return quoteName_; }
      protected:
        OH_LIB_CTOR(RateHelper, QuantLib::RateHelper);
        std::string quoteName_;
    };

    class FuturesRateHelper : 
        public RateHelper {
    public:
        FuturesRateHelper(
            const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
            // BEGIN typemap rp_tm_default
            QuantLib::Handle< QuantLib::Quote > const &price,
            QuantLib::Futures::Type type,
            QuantLib::Date const &immDate,
            boost::shared_ptr< QuantLib::IborIndex > const &iborIndex,
            QuantLib::Handle< QuantLib::Quote > const &convAdj,
            // END   typemap rp_tm_default
            bool permanent);
    };

    class FraRateHelper : 
        public RateHelper {
    public:
        FraRateHelper(
            const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
            // BEGIN typemap rp_tm_default
            QuantLib::Handle< QuantLib::Quote > const &rate,
            QuantLib::Period periodToStart,
            boost::shared_ptr< QuantLib::IborIndex > const &iborIndex,
            // END   typemap rp_tm_default
            bool permanent);
    };

    class OISRateHelper : 
        public RateHelper {
    public:
        OISRateHelper(
            const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
            // BEGIN typemap rp_tm_default
            QuantLib::Natural settlementDays,
            QuantLib::Period const &tenor,
            QuantLib::Handle< QuantLib::Quote > const &fixedRate,
            boost::shared_ptr< QuantLib::OvernightIndex > const &overnightIndex,
            QuantLib::Handle< QuantLib::YieldTermStructure > const &discount,
            // END   typemap rp_tm_default
            bool permanent);
    };

    class DatedOISRateHelper : 
        public RateHelper {
    public:
        DatedOISRateHelper(
            const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
            // BEGIN typemap rp_tm_default
            QuantLib::Date const &startDate,
            QuantLib::Date const &endDate,
            QuantLib::Handle< QuantLib::Quote > const &fixedRate,
            boost::shared_ptr< QuantLib::OvernightIndex > const &overnightIndex,
            QuantLib::Handle< QuantLib::YieldTermStructure > const &discount,
            // END   typemap rp_tm_default
            bool permanent);
    };

} // namespace QuantLibAddin

#endif


%feature("rp:group", "instruments");
%feature("rp:obj_include") %{
#include <ql/instruments/vanillaoption.hpp>
%}
%feature("rp:add_include") "#include \"qlo/obj_pricingengines.hpp\"
#include \"qlo/obj_payoffs.hpp\"
#include \"qlo/obj_exercise.hpp\""

namespace QuantLib {
    class Instrument {
      public:
        //Instrument();
        void setPricingEngine(const boost::shared_ptr<QuantLib::PricingEngine>& engine);
        QuantLib::Real NPV();
    };
    class VanillaOption : public Instrument {
      public:
        VanillaOption(const boost::shared_ptr<QuantLib::StrikedTypePayoff>& payoff,
                      const boost::shared_ptr<QuantLib::Exercise>& exercise);
    };
}

%feature("rp:group", "");


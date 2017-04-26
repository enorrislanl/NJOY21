class Card8a {
public:
  #include "njoy21/input/GROUPR/Card8a/Fehi.hpp"
  #include "njoy21/input/GROUPR/Card8a/Sigpot.hpp"
  #include "njoy21/input/GROUPR/Card8a/Nflmax.hpp"
  #include "njoy21/input/GROUPR/Card8a/Ninwt.hpp"
  #include "njoy21/input/GROUPR/Card8a/Jsigz.hpp"
  #include "njoy21/input/GROUPR/Card8a/Alpha2.hpp"

  Argument< Fehi > fehi;
  Argument< Sigpot > sigpot;
  Argument< Nflmax > nflmax;
  Argument< Ninwt > ninwt;
  Argument< Jsigz > jsigz;
  Argument< Alpha2 > alpha2;

  template< typename Char >
  Card8a( iRecordStream< Char >& is )
    try:
      fehi( argument::extract< Fehi >( is ) ),
      sigpot( argument::extract< Sigpot >( is ) ),
      nflmax( argument::extract< Nflmax >( is ) ),
      ninwt( argument::extract< Ninwt >( is ) ),
      jsigz( argument::extract< Jsigz >( is ) ),
      alpha2( argument::extract< Alpha2 >( is ) )
    {   
      Card::clear( is );
    }
    catch( std::exception& e ){
      Log::info( "Trouble validating Card8a");
      throw e;
    }
};

#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Rtop output values", "[PLOTR],[Card7], [Rtop]"){

  double rbot = -2.0;

  GIVEN( "valid Rtop parameters" ){
    std::vector<double> validValues{-2.0,-1.0,0.01,0.1,0.5,0.8,1.0,2.0,80.0};

    THEN( "the returned class has the correct value" ){
      for( auto rtop : validValues ){
        iRecordStream<char> issRtop( 
            std::istringstream( std::to_string( rtop ) ) );

        REQUIRE( rtop == argument::extract< PLOTR::Card7::Rtop >( 
                          issRtop, rbot ).value );
      }
    }
  } // GIVEN

  GIVEN( "default value" ){
    iRecordStream<char> issRtop( std::istringstream( " /" ) );
    
    THEN( "default value is returned" ){
      REQUIRE( Approx( rbot ) == argument::extract< PLOTR::Card7::Rtop >(
                          issRtop, rbot ).value );
    }
  }//GIVEN


  GIVEN( "Rtop is less than Rbot" ){
    iRecordStream<char> issRtop( std::istringstream( " 10.0 / " ) );
    rbot = 20.0;

    REQUIRE_THROWS( argument::extract< PLOTR::Card7::Rtop >( issRtop, rbot ) );
  }//GIVEN
} // SCENARIO

#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
IntegerVector whichValueGreaterEqualC(IntegerVector x, IntegerVector threshold, IntegerVector iStart) {
	int _threshold  = as<int>(threshold);
	int i = as<int>(iStart)-1L;		// note indexing in C starts from 0
	while( (i < x.size()) & (x[i] < _threshold) ) i++;
	if( i == x.size() )  return( IntegerVector::create(NA_INTEGER) ); // no break found
	return( IntegerVector::create(i+1L) );
}

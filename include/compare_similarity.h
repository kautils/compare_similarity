#ifndef KAUTIL_ALGORITHM_COMPAIR_SIMILARITY_H
#define KAUTIL_ALGORITHM_COMPAIR_SIMILARITY_H


#include <stdint.h>

namespace kautil{
namespace algorithm{

typedef uint64_t (*randf_t)() ;
struct compare_similarity;
compare_similarity * compare_similarity_initialize();
void compare_similarity_finalize(compare_similarity * m );
void compare_similarity_configure_str_len(compare_similarity * m ,int32_t const& len);
void compare_similarity_configure_abs_range(compare_similarity * m ,int32_t const& range);
void compare_similarity_configure_trial(compare_similarity * m ,uint64_t const& trial);
void compare_similarity_configure_random_function(compare_similarity * m ,uint64_t(*rand)());
int32_t const& compare_similarity_str_len(compare_similarity * m);
uint64_t const& compare_similarity_abs_range(compare_similarity * m);
uint64_t const& compare_similarity_trial(compare_similarity * m);
randf_t compare_similarity_random_function(compare_similarity * m );
uint64_t compare_similarity_calc(compare_similarity * m,const char * data,uint64_t const& data_bytes,const char * cmp,uint64_t const& cmp_bytes);

} //namespace algorithm{
} //namespace kautil{


#endif
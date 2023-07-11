
#include "../include/compare_similarity.h"
#include <cstdlib>
#include <cstring>

namespace kautil{
namespace algorithm{

typedef uint64_t (*randf_t)() ;
struct compare_similarity{
    int32_t len = 0;
    uint64_t range=0;
    uint64_t trial = 0;
    randf_t w_rand =0/*[](){ return static_cast<uint64_t>(rand()); }*/;
};

compare_similarity * compare_similarity_initialize(){
    auto m= new compare_similarity;
    return m;
}
void compare_similarity_finalize(compare_similarity * m ){ delete m; }
void compare_similarity_configure_str_len(compare_similarity * m ,int32_t const& len){ m->len = len; }
void compare_similarity_configure_abs_range(compare_similarity * m ,int32_t const& range){ m->range = range; }
void compare_similarity_configure_trial(compare_similarity * m ,uint64_t const& trial){ m->trial = trial; }
void compare_similarity_configure_random_function(compare_similarity * m ,uint64_t(*rand)()){ m->w_rand = rand; }

int32_t const& compare_similarity_str_len(compare_similarity * m){ return m->len; }
uint64_t const& compare_similarity_abs_range(compare_similarity * m){ return m->range; }
uint64_t const& compare_similarity_trial(compare_similarity * m){ return m->trial; }
randf_t compare_similarity_random_function(compare_similarity * m ){ return m->w_rand; }


uint64_t compare_similarity_calc(compare_similarity * m,const char * data,uint64_t const& data_bytes,const char * cmp,uint64_t const& cmp_bytes){
    auto count=uint64_t(0);
    auto at = int64_t(0);
    for(auto i = 0; i < m->trial;++i){
        do{
            at = m->w_rand() % data_bytes; 
        }while((at+m->len >= data_bytes) || (at >=cmp_bytes));
        auto beg = at-m->range; 
        if(beg >=cmp_bytes)beg = cmp_bytes-m->range;
        if(beg<0) beg=0;
        
        auto end = beg+(m->range*2); 
        if(end >= cmp_bytes) end=cmp_bytes;
        for(auto j = beg; j < end;++j){
            if(0==memcmp(&data[at],&cmp[j],m->len)){
                ++count;
                break;
            }
        }
    }
    return count;
}


} //namespace algorithm{
} //namespace kautil{



int tmain_compare_similarity(
        int(*__printf)(const char *,...)
        ,const char * src,uint64_t src_bytes
        ,const char * dst,uint64_t dst_bytes
        ,uint64_t trial,int32_t strlen,int32_t abs_range){
    using namespace kautil::algorithm;
    auto m = compare_similarity_initialize();
    srand(*reinterpret_cast<uint64_t*>(&m));
    {
        compare_similarity_configure_abs_range(m,abs_range);
        compare_similarity_configure_trial(m,trial);
        compare_similarity_configure_str_len(m,strlen);
        compare_similarity_configure_random_function(m,[](){return static_cast<uint64_t>(rand());});
    }
    __printf("rate : %lf\n",((double)compare_similarity_calc(m,src,src_bytes,dst,dst_bytes) / (double)trial));
    kautil::algorithm::compare_similarity_finalize(m);
    return 0;
}

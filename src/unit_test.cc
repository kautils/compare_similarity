
#ifdef TMAIN_COMPAIR_SIMILARITY
#include <string>

int tmain_compare_similarity(
        int(*__printf)(const char *,...)
        ,const char * src,uint64_t src_bytes
        ,const char * dst,uint64_t dst_bytes
        ,uint64_t trial,int32_t strlen,int32_t abs_range);
int main(){
    
    auto trial=uint64_t(100);
    auto strlen=int32_t(15);
    auto abs_range=int32_t(50); 
    auto src = std::string("from : https://en.wikipedia.org/wiki/Turtle"
                  "Turtles are an order of reptiles known as Testudines, "
                  "characterized by a special shell developed mainly from their ribs. Modern turtles are divided into two major groups, "
                  "the Pleurodira (side necked turtles) and Cryptodira (hidden necked turtles), which differ in the way the head retracts. "
                  "There are 360 living and...");
    auto dst = std::string("from : https://en.wikipedia.org/wiki/Turtle"
              "Turtles are an order of reptiles known as Testudines, "
              "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA mainly from their ribs. Modern turtles are divided into two major groups, "
              "the Pleurodira (side necked turtles) BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB, which differ in the way the head retracts. "
              "There are 360 living and...CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC");
    tmain_compare_similarity(printf,src.data(),src.size(),dst.data(),dst.size(),trial,strlen,abs_range);
    return 0;
}
#endif
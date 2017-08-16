#include <msa.h>
#include <iostream>
#include <iomanip>

#define DUMP_VECTOR(vec0,vec1,type,suffix) \
void dumpVector(vec0 a)                    \
{                                          \
	unsigned char stub[16];                \
	__msa_st_##suffix((vec1)a, (void*)stub, 0);\
	type* dump = (type*)stub;              \
	const int cLength = 16 / sizeof(type); \
	std::cout << "========================================" << std::endl; \
	for(auto i = 0;i < cLength;i++)        \
	{                                      \
		std::cout << i << ": " << dump[i] << std::endl; \
	}                                      \
}

DUMP_VECTOR(v16i8,v16i8,char,b);
DUMP_VECTOR(v16u8,v16i8,unsigned char,b);
DUMP_VECTOR(v8i16,v8i16,short,h);
DUMP_VECTOR(v8u16,v8i16,unsigned short,h);
DUMP_VECTOR(v4i32,v4i32,int,w);
DUMP_VECTOR(v4u32,v4i32,unsigned,w);
DUMP_VECTOR(v4f32,v4i32,float,w);
DUMP_VECTOR(v2i64,v2i64,long long,d);
DUMP_VECTOR(v2u64,v2i64,unsigned long long,d);
DUMP_VECTOR(v2f64,v2i64,double,d);


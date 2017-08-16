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

#define DUMP_VECTOR_CHAR(vec,type)         \
void dumpVector(vec a)                     \
{                                          \
	unsigned char stub[16];                \
	__msa_st_b((v16i8)a, (void*)stub, 0);  \
	type* dump = (type*)stub;              \
	const int cLength = 16 / sizeof(type); \
	std::cout << "========================================" << std::endl; \
	for(auto i = 0;i < cLength;i++)        \
	{                                      \
		std::cout << i << ": 0x" << std::hex << (((int)dump[i]) & 0xff) << std::endl; \
	}                                      \
}

#define DUMP_VECTOR_FLOATING(vec0,vec1,type,suffix)\
void dumpVector(vec0 a)                    \
{                                          \
	unsigned char stub[16];                \
	__msa_st_##suffix((vec1)a, (void*)stub, 0); \
	type* dump = (type*)stub;              \
	const int cLength = 16 / sizeof(type); \
	std::cout << "========================================" << std::endl; \
	for(auto i = 0;i < cLength;i++)        \
	{                                      \
		std::cout << i << ": 0x" << std::hex << dump[i] << std::endl; \
	}                                      \
}

DUMP_VECTOR(v8i16,v8i16,short,h);
DUMP_VECTOR(v8u16,v8i16,unsigned short,h);
DUMP_VECTOR(v4i32,v4i32,int,w);
DUMP_VECTOR(v4u32,v4i32,unsigned,w);
DUMP_VECTOR(v2i64,v2i64,long long,d);
DUMP_VECTOR(v2u64,v2i64,unsigned long long,d);

DUMP_VECTOR_CHAR(v16i8,char);
DUMP_VECTOR_CHAR(v16u8,unsigned char);

DUMP_VECTOR_FLOATING(v4f32,v4i32,int,w);
DUMP_VECTOR_FLOATING(v2f64,v2i64,long long,d);

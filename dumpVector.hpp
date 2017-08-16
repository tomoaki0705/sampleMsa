#include <msa.h>
#include <iostream>
#include <iomanip>

#define DEFAULT_DUMP_16(suffix,vec) \
	std::cout << "0: 0x" << std::hex << __msa_copy_u_b(vec,0) << std::endl; \
	std::cout << "1: 0x" << std::hex << __msa_copy_u_b(vec,1) << std::endl; \
	std::cout << "2: 0x" << std::hex << __msa_copy_u_b(vec,2) << std::endl; \
	std::cout << "3: 0x" << std::hex << __msa_copy_u_b(vec,3) << std::endl; \
	std::cout << "4: 0x" << std::hex << __msa_copy_u_b(vec,4) << std::endl; \
	std::cout << "5: 0x" << std::hex << __msa_copy_u_b(vec,5) << std::endl; \
	std::cout << "6: 0x" << std::hex << __msa_copy_u_b(vec,6) << std::endl; \
	std::cout << "7: 0x" << std::hex << __msa_copy_u_b(vec,7) << std::endl; \
	std::cout << "8: 0x" << std::hex << __msa_copy_u_b(vec,8) << std::endl; \
	std::cout << "9: 0x" << std::hex << __msa_copy_u_b(vec,9) << std::endl; \
	std::cout << "10: 0x" << std::hex << __msa_copy_u_b(vec,10) << std::endl; \
	std::cout << "11: 0x" << std::hex << __msa_copy_u_b(vec,11) << std::endl; \
	std::cout << "12: 0x" << std::hex << __msa_copy_u_b(vec,12) << std::endl; \
	std::cout << "13: 0x" << std::hex << __msa_copy_u_b(vec,13) << std::endl; \
	std::cout << "14: 0x" << std::hex << __msa_copy_u_b(vec,14) << std::endl; \
	std::cout << "15: 0x" << std::hex << __msa_copy_u_b(vec,15) << std::endl;

#define DEFAULT_DUMP_8(suffix,vec) \
	std::cout << "0: 0x" << std::hex << __msa_copy_u_h(vec,0) << std::endl; \
	std::cout << "1: 0x" << std::hex << __msa_copy_u_h(vec,1) << std::endl; \
	std::cout << "2: 0x" << std::hex << __msa_copy_u_h(vec,2) << std::endl; \
	std::cout << "3: 0x" << std::hex << __msa_copy_u_h(vec,3) << std::endl; \
	std::cout << "4: 0x" << std::hex << __msa_copy_u_h(vec,4) << std::endl; \
	std::cout << "5: 0x" << std::hex << __msa_copy_u_h(vec,5) << std::endl; \
	std::cout << "6: 0x" << std::hex << __msa_copy_u_h(vec,6) << std::endl; \
	std::cout << "7: 0x" << std::hex << __msa_copy_u_h(vec,7) << std::endl;

#define DEFAULT_DUMP_4(suffix,vec) \
	std::cout << "0: 0x" << std::hex << __msa_copy_u_w(vec,0) << std::endl; \
	std::cout << "1: 0x" << std::hex << __msa_copy_u_w(vec,1) << std::endl; \
	std::cout << "2: 0x" << std::hex << __msa_copy_u_w(vec,2) << std::endl; \
	std::cout << "3: 0x" << std::hex << __msa_copy_u_w(vec,3) << std::endl;

#define DEFAULT_DUMP_4(suffix,vec) \
	std::cout << "0: 0x" << std::hex << __msa_copy_u_d(vec,0) << std::endl; \
	std::cout << "1: 0x" << std::hex << __msa_copy_u_d(vec,1) << std::endl;

template<typename T>
void dumpVector(T a);

template <>
void dumpVector<v16i8>(v16i8 a)
{
	DEFAULT_DUMP_16(a);
}

template <>
void dumpVector<v16u8>(v16u8 a)
{
	DEFAULT_DUMP_16(a);
}

template <>
void dumpVector<v8i16>(v8i16 a)
{
	DEFAULT_DUMP_8(a);
}

template <>
void dumpVector<v8u16>(v8u16 a)
{
	DEFAULT_DUMP_8(a);
}

template <>
void dumpVector<v4i32>(v4i32 a)
{
	DEFAULT_DUMP_4(a);
}

template <>
void dumpVector<v4u32>(v4u32 a)
{
	DEFAULT_DUMP_4(a);
}

template <>
void dumpVector<v4f32>(v4f32 a)
{
	DEFAULT_DUMP_4(a);
}

template <>
void dumpVector<v2i64>(v2i64 a)
{
	DEFAULT_DUMP_2(a);
}

template <>
void dumpVector<v2u64>(v2u64 a)
{
	DEFAULT_DUMP_2(a);
}

template<>
void dumpVector<v2f64>(v2f64 a)
{
	DEFAULT_DUMP_2(a);
}


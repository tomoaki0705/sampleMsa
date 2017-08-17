#include <msa.h>
#include <iostream>
#include <iomanip>

#define DEFAULT_DUMP_16(vec) \
	std::cout << "15: 0x" << std::hex << std::setw(2) << std::setfill('0') << __msa_copy_u_b((v16i8)vec,15) << ' '; \
	std::cout << "14: 0x" << std::hex << std::setw(2) << std::setfill('0') << __msa_copy_u_b((v16i8)vec,14) << ' '; \
	std::cout << "13: 0x" << std::hex << std::setw(2) << std::setfill('0') << __msa_copy_u_b((v16i8)vec,13) << ' '; \
	std::cout << "12: 0x" << std::hex << std::setw(2) << std::setfill('0') << __msa_copy_u_b((v16i8)vec,12) << ' '; \
	std::cout << "11: 0x" << std::hex << std::setw(2) << std::setfill('0') << __msa_copy_u_b((v16i8)vec,11) << ' '; \
	std::cout << "10: 0x" << std::hex << std::setw(2) << std::setfill('0') << __msa_copy_u_b((v16i8)vec,10) << ' '; \
	std::cout << " 9: 0x" << std::hex << std::setw(2) << std::setfill('0') << __msa_copy_u_b((v16i8)vec,9) << ' '; \
	std::cout << " 8: 0x" << std::hex << std::setw(2) << std::setfill('0') << __msa_copy_u_b((v16i8)vec,8) << ' '; \
	std::cout << " 7: 0x" << std::hex << std::setw(2) << std::setfill('0') << __msa_copy_u_b((v16i8)vec,7) << ' '; \
	std::cout << " 6: 0x" << std::hex << std::setw(2) << std::setfill('0') << __msa_copy_u_b((v16i8)vec,6) << ' '; \
	std::cout << " 5: 0x" << std::hex << std::setw(2) << std::setfill('0') << __msa_copy_u_b((v16i8)vec,5) << ' '; \
	std::cout << " 4: 0x" << std::hex << std::setw(2) << std::setfill('0') << __msa_copy_u_b((v16i8)vec,4) << ' '; \
	std::cout << " 3: 0x" << std::hex << std::setw(2) << std::setfill('0') << __msa_copy_u_b((v16i8)vec,3) << ' '; \
	std::cout << " 2: 0x" << std::hex << std::setw(2) << std::setfill('0') << __msa_copy_u_b((v16i8)vec,2) << ' '; \
	std::cout << " 1: 0x" << std::hex << std::setw(2) << std::setfill('0') << __msa_copy_u_b((v16i8)vec,1) << ' '; \
	std::cout << " 0: 0x" << std::hex << std::setw(2) << std::setfill('0') << __msa_copy_u_b((v16i8)vec,0) << std::endl;

#define DEFAULT_DUMP_8(vec) \
	std::cout << "7: 0x" << std::hex << std::setw(4) << std::setfill('0') << __msa_copy_u_h((v8i16)vec,7) << ' '; \
	std::cout << "6: 0x" << std::hex << std::setw(4) << std::setfill('0') << __msa_copy_u_h((v8i16)vec,6) << ' '; \
	std::cout << "5: 0x" << std::hex << std::setw(4) << std::setfill('0') << __msa_copy_u_h((v8i16)vec,5) << ' '; \
	std::cout << "4: 0x" << std::hex << std::setw(4) << std::setfill('0') << __msa_copy_u_h((v8i16)vec,4) << ' '; \
	std::cout << "3: 0x" << std::hex << std::setw(4) << std::setfill('0') << __msa_copy_u_h((v8i16)vec,3) << ' '; \
	std::cout << "2: 0x" << std::hex << std::setw(4) << std::setfill('0') << __msa_copy_u_h((v8i16)vec,2) << ' '; \
	std::cout << "1: 0x" << std::hex << std::setw(4) << std::setfill('0') << __msa_copy_u_h((v8i16)vec,1) << ' '; \
	std::cout << "0: 0x" << std::hex << std::setw(4) << std::setfill('0') << __msa_copy_u_h((v8i16)vec,0) << std::endl;

#define DEFAULT_DUMP_4(vec) \
	std::cout << "3: 0x" << std::hex << std::setw(8) << std::setfill('0') << __msa_copy_u_w((v4i32)vec,3) << ' '; \
	std::cout << "2: 0x" << std::hex << std::setw(8) << std::setfill('0') << __msa_copy_u_w((v4i32)vec,2) << ' '; \
	std::cout << "1: 0x" << std::hex << std::setw(8) << std::setfill('0') << __msa_copy_u_w((v4i32)vec,1) << ' '; \
	std::cout << "0: 0x" << std::hex << std::setw(8) << std::setfill('0') << __msa_copy_u_w((v4i32)vec,0) << std::endl;

#define DEFAULT_DUMP_2(vec) \
	std::cout << "1: 0x" << std::hex << std::setw(16) << std::setfill('0') << __msa_copy_u_d((v2i64)vec,1) << ' '; \
	std::cout << "0: 0x" << std::hex << std::setw(16) << std::setfill('0') << __msa_copy_u_d((v2i64)vec,0) << std::endl;

template<typename T>
void dumpVector(T a);

template <>
void dumpVector<v16i8>(v16i8 a)
{
	std::cout << "====================" << std::endl;
	DEFAULT_DUMP_16(a);
}

template <>
void dumpVector<v16u8>(v16u8 a)
{
	std::cout << "====================" << std::endl;
	DEFAULT_DUMP_16(a);
}

template <>
void dumpVector<v8i16>(v8i16 a)
{
	std::cout << "====================" << std::endl;
	DEFAULT_DUMP_8(a);
}

template <>
void dumpVector<v8u16>(v8u16 a)
{
	std::cout << "====================" << std::endl;
	DEFAULT_DUMP_8(a);
}

template <>
void dumpVector<v4i32>(v4i32 a)
{
	std::cout << "====================" << std::endl;
	DEFAULT_DUMP_4(a);
}

template <>
void dumpVector<v4u32>(v4u32 a)
{
	std::cout << "====================" << std::endl;
	DEFAULT_DUMP_4(a);
}

template <>
void dumpVector<v4f32>(v4f32 a)
{
	std::cout << "====================" << std::endl;
	DEFAULT_DUMP_4(a);
}

template <>
void dumpVector<v2i64>(v2i64 a)
{
	std::cout << "====================" << std::endl;
	DEFAULT_DUMP_2(a);
}

template <>
void dumpVector<v2u64>(v2u64 a)
{
	std::cout << "====================" << std::endl;
	DEFAULT_DUMP_2(a);
}

template<>
void dumpVector<v2f64>(v2f64 a)
{
	std::cout << "====================" << std::endl;
	DEFAULT_DUMP_2(a);
}


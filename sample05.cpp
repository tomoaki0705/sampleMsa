#include <msa.h>
#include <iostream>
#include <iomanip>

template <typename T, typename Tp>
void dumpVector(T a)
{
	unsigned char stub[16];
	__msa_st_b((v16i8)a, (void*)stub, 0);

	Tp* dump = (Tp*)stub;
	const int cLength = 16 / sizeof(Tp);
	std::cout << "========================================" << std::endl;
	for(auto i = 0;i < cLength;i++)
	{
		std::cout << i << ": " << dump[i] << std::endl;
	}
}

struct _f64u64
{
	union
	{
		double d;
		unsigned long long u;
	};
};
typedef struct _f64u64 f64u64;

struct _f32u32
{
	union
	{
		float f;
		unsigned u;
	};
};
typedef struct _f32u32 f32u32;

template <>
void dumpVector<v2f64, double>(v2f64 a)
{
	unsigned char stub[16];
	__msa_st_b((v16i8)a, (void*)stub, 0);

	double* dump = (double*)stub;
	const int cLength = 16 / sizeof(double);
	std::cout << "****************************************" << std::endl;
	for(auto i = 0;i < cLength;i++)
	{
		f64u64 x;
		x.d = dump[i];
		std::cout << i << ": 0x" << std::hex << x.u << std::endl;
	}
}

template <>
void dumpVector<v4f32, float>(v4f32 a)
{
	unsigned char stub[16];
	__msa_st_b((v16i8)a, (void*)stub, 0);

	float* dump = (float*)stub;
	const int cLength = 16 / sizeof(float);
	std::cout << "****************************************" << std::endl;
	for(auto i = 0;i < cLength;i++)
	{
		f32u32 x;
		x.f = dump[i];
		std::cout << i << ": 0x" << std::hex << x.u << std::endl;
	}
}

template <>
void dumpVector<v16u8, unsigned char>(v16u8 a)
{
	unsigned char stub[16];
	__msa_st_b((v16i8)a, (void*)stub, 0);

	char* dump = (char*)stub;
	const int cLength = 16 / sizeof(char);
	std::cout << "****************************************" << std::endl;
	for(auto i = 0;i < cLength;i++)
	{
		std::cout << i << ": 0x" << std::hex << (int)dump[i] << std::endl;
	}
}

template <>
void dumpVector<v16i8, char>(v16i8 a)
{
	unsigned char stub[16];
	__msa_st_b(a, (void*)stub, 0);

	char* dump = (char*)stub;
	const int cLength = 16 / sizeof(char);
	std::cout << "****************************************" << std::endl;
	for(auto i = 0;i < cLength;i++)
	{
		std::cout << i << ": 0x" << std::hex << (int)dump[i] << std::endl;
	}
}

int main(int argc, char**argv)
{
	std::cout << "example of filling 0" << std::endl;
	volatile v16i8 v_src0 = (v16i8)__msa_fill_b(0);
	volatile v16u8 v_src1 = (v16u8)__msa_fill_b(0);
	volatile v8i16 v_src2 = (v8i16)__msa_fill_h(0);
	volatile v8u16 v_src3 = (v8u16)__msa_fill_h(0);
	volatile v4i32 v_src4 = (v4i32)__msa_fill_w(0);
	volatile v4u32 v_src5 = (v4u32)__msa_fill_w(0);
	volatile v4f32 v_src6 = (v4f32)__msa_fill_w(0);
	volatile v2i64 v_src7 = (v2i64)__msa_fill_d(0);
	volatile v2u64 v_src8 = (v2u64)__msa_fill_d(0);
	volatile v2f64 v_src9 = (v2f64)__msa_fill_d(0);
	dumpVector<v16i8, char>(v_src0);
	dumpVector<v16u8, unsigned char>(v_src1);
	dumpVector<v8i16, short>(v_src2);
	dumpVector<v8u16, unsigned short>(v_src3);
	dumpVector<v4i32, int>(v_src4);
	dumpVector<v4u32, unsigned>(v_src5);
	dumpVector<v4f32, float>(v_src6);
	dumpVector<v2i64, long long int>(v_src7);
	dumpVector<v2u64, unsigned long long>(v_src8);
	dumpVector<v2f64, double>(v_src9);

	std::cout << "example of filling value" << std::endl;
	volatile v16i8 v_src00 = (v16i8)__msa_fill_b(-1);
	volatile v16u8 v_src01 = (v16u8)__msa_fill_b(128);
	volatile v8i16 v_src02 = (v8i16)__msa_fill_h(-1);
	volatile v8u16 v_src03 = (v8u16)__msa_fill_h(32768);
	volatile v4i32 v_src04 = (v4i32)__msa_fill_w(-1);
	volatile v4u32 v_src05 = (v4u32)__msa_fill_w(0x80000000);
	volatile v4f32 v_src06 = (v4f32)__msa_fill_w(0x3f800000);
	volatile v2i64 v_src07 = (v2i64)__msa_fill_d(-1);
	volatile v2u64 v_src08 = (v2u64)__msa_fill_d(0x8000000000000000);
	volatile v2f64 v_src09 = (v2f64)__msa_fill_d(0x3ff0000000000000);
	dumpVector<v16i8, char>(v_src00);
	dumpVector<v16u8, unsigned char>(v_src01);
	dumpVector<v8i16, short>(v_src02);
	dumpVector<v8u16, unsigned short>(v_src03);
	dumpVector<v4i32, int>(v_src04);
	dumpVector<v4u32, unsigned>(v_src05);
	dumpVector<v4f32, float>(v_src06);
	dumpVector<v2i64, long long int>(v_src07);
	dumpVector<v2u64, unsigned long long>(v_src08);
	dumpVector<v2f64, double>(v_src09);

	return 0;
}

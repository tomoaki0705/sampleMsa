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


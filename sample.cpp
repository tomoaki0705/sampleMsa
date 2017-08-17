#include <msa.h>
#include "dumpVector.hpp"

const unsigned long long pack01[] = {0x11111111, 0x22222222, };
const unsigned long long pack02[] = {0x33333333, 0x44444444, };
const unsigned int pack11[] = {0x1111, 0x2222, 0x3333, 0x4444};
const unsigned int pack12[] = {0x5555, 0x6666, 0x7777, 0x8888};
const unsigned short pack21[] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, };
const unsigned short pack22[] = {0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00, };

const unsigned int endianCheck[] = {0x1234567, 0x89abcdef, 0xacacacac, 0x559f559f};
const short src1[] = {1, 2, 3, 4, 5, 6, 7, 8, };
const short src2[] = {100, 100, 100, 100, 100, 100, 100, 100,};
short dst[] = {0, 0, 0, 0, 0, 0, 0, 0, };

// pack
// extract lower half of each element from two vectors
// and concatenate as one vector
void v_pack()
{
	v2i64 v_pack01 = __msa_ld_d((void*)pack01, 0);
	v2i64 v_pack02 = __msa_ld_d((void*)pack02, 0);
	v4i32 v_pack03 = __msa_pckev_w((v4i32)v_pack02, (v4i32)v_pack01);
	dumpVector(v_pack01);
	dumpVector(v_pack02);
	dumpVector(v_pack03);

	std::cout << "================" << std::endl;
	v4i32 v_pack11 = __msa_ld_w((void*)pack11, 0);
	v4i32 v_pack12 = __msa_ld_w((void*)pack12, 0);
	v8i16 v_pack13 = __msa_pckev_h((v8i16)v_pack12, (v8i16)v_pack11);
	dumpVector(v_pack11);
	dumpVector(v_pack12);
	dumpVector(v_pack13);

	std::cout << "================" << std::endl;
	v8i16 v_pack21 = __msa_ld_h((void*)pack21, 0);
	v8i16 v_pack22 = __msa_ld_h((void*)pack22, 0);
	v16i8 v_pack23 = __msa_pckev_b((v16i8)v_pack22, (v16i8)v_pack21);
	dumpVector(v_pack21);
	dumpVector(v_pack22);
	dumpVector(v_pack23);
}

// pack two vectors and then store to memory
void v_pack_store()
{
	v2i64 v_pack01 = __msa_ld_d((void*)pack01, 0);
	v2i64 v_pack02 = __msa_ld_d((void*)pack02, 0);
	v4i32 v_pack03 = __msa_pckev_w((v4i32)v_pack02, (v4i32)v_pack01);
	unsigned int v_dst04[] = {0, 0, 0, 0, };
	__msa_st_w(v_pack03, (void*)v_dst04, 0);
	dumpArray(v_dst04);

	std::cout << "================" << std::endl;
	v4i32 v_pack11 = __msa_ld_w((void*)pack11, 0);
	v4i32 v_pack12 = __msa_ld_w((void*)pack12, 0);
	v8i16 v_pack13 = __msa_pckev_h((v8i16)v_pack12, (v8i16)v_pack11);
	unsigned short v_dst14[] = {0, 0, 0, 0, 0, 0, 0, 0, };
	__msa_st_h(v_pack13, (void*)v_dst14, 0);
	dumpArray(v_dst14);

	std::cout << "================" << std::endl;
	v8i16 v_pack21 = __msa_ld_h((void*)pack21, 0);
	v8i16 v_pack22 = __msa_ld_h((void*)pack22, 0);
	v16i8 v_pack23 = __msa_pckev_b((v16i8)v_pack22, (v16i8)v_pack21);
	unsigned char v_dst24[] = {0, 0, 0, 0, 0, 0, 0, 0, };
	__msa_st_b(v_pack23, (void*)v_dst24, 0);
	dumpArray(v_dst24);
}

// shift right and round and then pack
void v_rshr_pack()
{
	const long long pack01s[] = {-33, -34, };
	const long long pack02s[] = {-35, -36, };
	const int pack11s[] = {-1, -2, -3, -4};
	const int pack12s[] = {-37, -38, -39, -40};
	const short pack21s[] = {-1, -2, -3, -4, -5, -6, -7, -8};
	const short pack22s[] = {-41, -42, -43, -44, -45, -46, -47, -48};
	const int iShift = 4;

	v2i64 v_delta0 = __msa_fill_d(1);
	v2i64 v_pack01 = __msa_ld_d((void*)pack01s, 0);
	v2i64 v_pack02 = __msa_ld_d((void*)pack02s, 0);
	v4i32 v_pack03 = __msa_pckev_w((v4i32)((v_pack02 + (v_delta0 << (iShift - 1))) >> iShift), (v4i32)((v_pack01 + (v_delta0 << (iShift - 1))) >> iShift));
	dumpVector(v_pack01);
	dumpVector(v_pack02);
	dumpVector(v_pack03);

	std::cout << "================" << std::endl;
	v4i32 v_delta1 = __msa_fill_w(1);
	v4i32 v_pack11 = __msa_ld_w((void*)pack11s, 0);
	v4i32 v_pack12 = __msa_ld_w((void*)pack12s, 0);
	v8i16 v_pack13 = __msa_pckev_h((v8i16)((v_pack12 + (v_delta1 << (iShift - 1))) >> iShift), (v8i16)((v_pack11 + (v_delta1 << (iShift - 1))) >> iShift));
	dumpVector(v_pack11);
	dumpVector(v_pack12);
	dumpVector(v_pack13);

	std::cout << "================" << std::endl;
	v8i16 v_delta2 = __msa_fill_h(1);
	v8i16 v_pack21 = __msa_ld_h((void*)pack21s, 0);
	v8i16 v_pack22 = __msa_ld_h((void*)pack22s, 0);
	v16i8 v_pack23 = __msa_pckev_b((v16i8)((v_pack22 + (v_delta2 << (iShift - 1))) >> iShift), (v16i8)((v_pack21 + (v_delta2 << (iShift - 1))) >> iShift));
	dumpVector(v_pack11);
	dumpVector(v_pack12);
	dumpVector(v_pack13);
}

// shift right and round and then pack
void v_rshr_packu()
{
	const int iShift = 4;

	v2i64 v_delta0 = __msa_fill_d(1);
	v2i64 v_pack01 = __msa_ld_d((void*)pack01, 0);
	v2i64 v_pack02 = __msa_ld_d((void*)pack02, 0);
	v4i32 v_pack03 = __msa_pckev_w((v4i32)((v_pack02 + (v_delta0 << (iShift - 1))) >> iShift), (v4i32)((v_pack01 + (v_delta0 << (iShift - 1))) >> iShift));
	dumpVector(v_pack01);
	dumpVector(v_pack02);
	dumpVector(v_pack03);

	std::cout << "================" << std::endl;
	v4i32 v_delta1 = __msa_fill_w(1);
	v4i32 v_pack11 = __msa_ld_w((void*)pack11, 0);
	v4i32 v_pack12 = __msa_ld_w((void*)pack12, 0);
	v8i16 v_pack13 = __msa_pckev_h((v8i16)((v_pack12 + (v_delta1 << (iShift - 1))) >> iShift), (v8i16)((v_pack11 + (v_delta1 << (iShift - 1))) >> iShift));
	dumpVector(v_pack11);
	dumpVector(v_pack12);
	dumpVector(v_pack13);

	std::cout << "================" << std::endl;
	v8i16 v_delta2 = __msa_fill_h(1);
	v8i16 v_pack21 = __msa_ld_h((void*)pack21, 0);
	v8i16 v_pack22 = __msa_ld_h((void*)pack22, 0);
	v16i8 v_pack23 = __msa_pckev_b((v16i8)((v_pack22 + (v_delta2 << (iShift - 1))) >> iShift), (v16i8)((v_pack21 + (v_delta2 << (iShift - 1))) >> iShift));
	dumpVector(v_pack11);
	dumpVector(v_pack12);
	dumpVector(v_pack13);
}

void v_matmul()
{
	// only for v4f32
	const float m0[] = {1.f,  2.f,  3.f,  4.f, };
	const float m1[] = {5.f,  6.f,  7.f,  8.f, };
	const float m2[] = {11.f, 12.f, 13.f, 14.f, };
	const float m3[] = {10.f, 20.f, 30.f, 40.f, };
	const float v[]  = {1.f,  2.f,  3.f,  4.f, };

	v4f32 v_m0 = (v4f32)__msa_ld_w((void*)m0, 0);
	v4f32 v_m1 = (v4f32)__msa_ld_w((void*)m1, 0);
	v4f32 v_m2 = (v4f32)__msa_ld_w((void*)m2, 0);
	v4f32 v_m3 = (v4f32)__msa_ld_w((void*)m3, 0);
	v4f32 v_v  = (v4f32)__msa_ld_w((void*)v, 0);

	v_m0 = v_m0 * (v4f32)__msa_splati_w((v4i32)v_v, 0);
	v_m1 = v_m1 * (v4f32)__msa_splati_w((v4i32)v_v, 1);
	v_m2 = v_m2 * (v4f32)__msa_splati_w((v4i32)v_v, 2);
	v_m3 = v_m3 * (v4f32)__msa_splati_w((v4i32)v_v, 3);
	dumpVector(v_m0);
	dumpVector(v_m1);
	dumpVector(v_m2);
	dumpVector(v_m3);

	v4f32 result = v_m0 + v_m1 + v_m2 + v_m3;
	dumpVector(result);

	float dst[] = {0.f, 0.f, 0.f, 0.f, };
	dst[0] = m0[0] * v[0] + m1[0] * v[1] + m2[0] * v[2] + m3[0] * v[3];
	dst[1] = m0[1] * v[0] + m1[1] * v[1] + m2[1] * v[2] + m3[1] * v[3];
	dst[2] = m0[2] * v[0] + m1[2] * v[1] + m2[2] * v[2] + m3[2] * v[3];
	dst[3] = m0[3] * v[0] + m1[3] * v[1] + m2[3] * v[2] + m3[3] * v[3];
	dumpArray(dst);
	
}

void v_divide()
{
	const int div_src1[] = {1, 2, 3, 4, };
	const int div_src2[] = {2, 3, 4, 5, };

	v4i32 v_src1 = (v4i32)__msa_ld_w((void*)div_src1, 0);
	v4i32 v_src2 = (v4i32)__msa_ld_w((void*)div_src2, 0);
	v4i32 v_dst  = v_src2 / v_src1;
	dumpVector(v_dst);

	const float div_src11[] = {1.f, 2.f, 3.f, 4.f, };
	const float div_src12[] = {2.f, 3.f, 4.f, 5.f, };
	v4f32 v_src11 = (v4f32)__msa_ld_w((void*)div_src11, 0);
	v4f32 v_src12 = (v4f32)__msa_ld_w((void*)div_src12, 0);
	v4f32 v_dstf  = v_src12 / v_src11;
	dumpVector(v_dstf);
}

static inline void v_expand(const v16i8& a, v8i16 &b, v8i16 &c)
{
	b = ((v8i16)__msa_ilvr_b((v16i8)a, (v16i8)a)) >> 8;
	c = ((v8i16)__msa_ilvl_b((v16i8)a, (v16i8)a)) >> 8;
}

static inline void v_expand(const v16u8& a, v8u16 &b, v8u16 &c)
{
	v16u8 v_zero  = (v16u8)__msa_fill_b(0);
	b = (v8u16)__msa_ilvr_b((v16i8)v_zero, (v16i8)a);
	c = (v8u16)__msa_ilvl_b((v16i8)v_zero, (v16i8)a);
}

static inline void v_expand(const v8i16& a, v4i32 &b, v4i32 &c)
{
	b = ((v4i32)__msa_ilvr_h((v8i16)a, (v8i16)a)) >> 16;
	c = ((v4i32)__msa_ilvl_h((v8i16)a, (v8i16)a)) >> 16;
}

static inline void v_expand(const v8u16& a, v4u32 &b, v4u32 &c)
{
	v8u16 v_zero  = (v8u16)__msa_fill_h(0);
	b = (v4u32)__msa_ilvr_h((v8i16)v_zero, (v8i16)a);
	c = (v4u32)__msa_ilvl_h((v8i16)v_zero, (v8i16)a);
}

static inline void v_expand(const v4i32& a, v2i64 &b, v2i64 &c)
{
	b = ((v2i64)__msa_ilvr_w((v4i32)a, (v4i32)a)) >> 32;
	c = ((v2i64)__msa_ilvl_w((v4i32)a, (v4i32)a)) >> 32;
}

static inline void v_expand(const v4u32& a, v2u64 &b, v2u64 &c)
{
	v4u32 v_zero  = (v4u32)__msa_fill_w(0);
	b = (v2u64)__msa_ilvr_w((v4i32)v_zero, (v4i32)a);
	c = (v2u64)__msa_ilvl_w((v4i32)v_zero, (v4i32)a);
}

void v_mal_expand()
{
	const short mul01[] = {1000, 1001, 1002, 1003, 1004, 1005, 1006, 1007, };
	const short mul02[] = {100, 100, 100, 100, 100, 100, 100, 100, };
	v8i16 v_src01 = (v8i16)__msa_ld_h((void*)mul01, 0);
	v8i16 v_src02 = (v8i16)__msa_ld_h((void*)mul02, 0);
	v8i16 v_zero  = (v8i16)__msa_fill_h(0);
	v4i32 v_src03 = (v4i32)__msa_ilvr_h((v8i16)v_zero, (v8i16)v_src01);
	v4i32 v_src04 = (v4i32)__msa_ilvl_h((v8i16)v_zero, (v8i16)v_src01);
	v4i32 v_src05 = (v4i32)__msa_ilvr_h((v8i16)v_zero, (v8i16)v_src02);
	v4i32 v_src06 = (v4i32)__msa_ilvl_h((v8i16)v_zero, (v8i16)v_src02);

	v4i32 v_dst01 = v_src03 * v_src05;
	v4i32 v_dst02 = v_src04 * v_src06;
	dumpVector(v_dst01);
	dumpVector(v_dst02);
}

void v_expand()
{
	const unsigned char expand01[] = {255, 240, 224, 208, 192, 176, 160, 144, 128, 112, 96, 80, 64, 48, 32, 16, };
	v16u8 v_expand01 = (v16u8)__msa_ld_b((void*)expand01, 0);
	v8u16 v_dst01, v_dst02;
	v_expand(v_expand01, v_dst01, v_dst02);
	dumpVector(v_dst01);
	dumpVector(v_dst02);

	const char expand11[] = {-16, -32, -48, -64, -80, -96, -112, -128, -1, 1, -2, 2, -3, 3, -4, 4, };
	v16i8 v_expand11 = (v16i8)__msa_ld_b((void*)expand11, 0);
	v8i16 v_dst11, v_dst12;
	v_expand(v_expand11, v_dst11, v_dst12);
	dumpVector(v_dst11);
	dumpVector(v_dst12);

	const unsigned short expand21[] = {32768, 36864, 40960, 49554, 128, 256, 1, 16, };
	v8u16 v_expand21 = (v8u16)__msa_ld_h((void*)expand01, 0);
	v4u32 v_dst21, v_dst22;
	v_expand(v_expand21, v_dst21, v_dst22);
	dumpVector(v_dst21);
	dumpVector(v_dst22);

	const short expand31[] = {-32768, -28672, -24576, -15982, -1, 32767, 1, 16, };
	v8i16 v_expand31 = (v8i16)__msa_ld_h((void*)expand11, 0);
	v4i32 v_dst31, v_dst32;
	v_expand(v_expand31, v_dst31, v_dst32);
	dumpVector(v_dst31);
	dumpVector(v_dst32);

	const unsigned expand41[] = {2147483648, 3221225472, 3758096384, 4026531840};
	v4u32 v_expand41 = (v4u32)__msa_ld_w((void*)expand41, 0);
	v2u64 v_dst41, v_dst42;
	v_expand(v_expand41, v_dst41, v_dst42);
	dumpVector(v_dst41);
	dumpVector(v_dst42);
      
	const int expand51[] = {-4096, -256, -16, -1, };
	v4i32 v_expand51 = (v4i32)__msa_ld_w((void*)expand51, 0);
	v2i64 v_dst51, v_dst52;
	v_expand(v_expand51, v_dst51, v_dst52);
	dumpVector(v_dst51);
	dumpVector(v_dst52);
}

int main(int argc, char**argv)
{
	std::cout << "======== v_pack ========" << std::endl;
	v_pack();

	std::cout << "======== v_pack_store ========" << std::endl;
	v_pack_store();

	std::cout << "======== v_rshr_pack ========" << std::endl;
	v_rshr_pack();

	std::cout << "======== v_rshr_packu ========" << std::endl;
	v_rshr_packu();

	std::cout << "======== v_matmul ========" << std::endl;
	v_matmul();

	std::cout << "======== / ========" << std::endl;
	v_divide();

	std::cout << "======== v_mal_expand ========" << std::endl;
	v_mal_expand();

	std::cout << "======== v_expand ========" << std::endl;
	v_expand();

	return 0;
}


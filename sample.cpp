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

	v4i32 v_pack11 = __msa_ld_w((void*)pack11, 0);
	v4i32 v_pack12 = __msa_ld_w((void*)pack12, 0);
	v8i16 v_pack13 = __msa_pckev_h((v8i16)v_pack12, (v8i16)v_pack11);
	dumpVector(v_pack11);
	dumpVector(v_pack12);
	dumpVector(v_pack13);

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

	v4i32 v_pack11 = __msa_ld_w((void*)pack11, 0);
	v4i32 v_pack12 = __msa_ld_w((void*)pack12, 0);
	v8i16 v_pack13 = __msa_pckev_h((v8i16)v_pack12, (v8i16)v_pack11);
	unsigned short v_dst14[] = {0, 0, 0, 0, 0, 0, 0, 0, };
	__msa_st_h(v_pack13, (void*)v_dst14, 0);
	dumpArray(v_dst14);

	v8i16 v_pack21 = __msa_ld_h((void*)pack21, 0);
	v8i16 v_pack22 = __msa_ld_h((void*)pack22, 0);
	v16i8 v_pack23 = __msa_pckev_b((v16i8)v_pack22, (v16i8)v_pack21);
	unsigned char v_dst24[] = {0, 0, 0, 0, 0, 0, 0, 0, };
	__msa_st_b(v_pack23, (void*)v_dst24, 0);
	dumpArray(v_dst24);
}

int main(int argc, char**argv)
{
	v_pack();

	v_pack_store();

	v4u32 v_endian = (v4u32)__msa_ld_w((void*)endianCheck, 0);
	dumpVector(v_endian);
	v16u8 v_endianChar = (v16u8)v_endian;
	dumpVector(v_endianChar);

	//inline _Tpvec v_##pack(const _Tpwvec& a, const _Tpwvec& b) \
	//{ \
	//    hreg a1 = vqmov##op##_##wsuffix(a.val), b1 = vqmov##op##_##wsuffix(b.val); \
	//    return _Tpvec(vcombine_##suffix(a1, b1)); \
	//} \
	//inline void v_##pack##_store(_Tp* ptr, const _Tpwvec& a) \
	//{ \
	//    hreg a1 = vqmov##op##_##wsuffix(a.val); \
	//    vst1_##suffix(ptr, a1); \
	//} \
	//template<int n> inline \
	//_Tpvec v_rshr_##pack(const _Tpwvec& a, const _Tpwvec& b) \
	//{ \
	//    hreg a1 = vqrshr##op##_n_##wsuffix(a.val, n); \
	//    hreg b1 = vqrshr##op##_n_##wsuffix(b.val, n); \
	//    return _Tpvec(vcombine_##suffix(a1, b1)); \
	//} \
	//template<int n> inline \
	//void v_rshr_##pack##_store(_Tp* ptr, const _Tpwvec& a) \
	//{ \
	//    hreg a1 = vqrshr##op##_n_##wsuffix(a.val, n); \
	//    vst1_##suffix(ptr, a1); \
	//}


	v_endianChar = v_endianChar << 3;
	dumpVector(v_endianChar);

	unsigned char* foo = (unsigned char*)src1;
	for(auto i = 0;i < 16;i++)
	{
		std::cout << i << "\t: " << (int)foo[i] << std::endl;
	}
	v8i16 v_src1 = (v8i16)__msa_ld_h((void*)src1, 0);
	v8i16 v_src2 = (v8i16)__msa_ld_h((void*)src2, 0);

	dumpVector(v_src1);

	v8i16 v_dst = v_src1 + v_src2;

	dumpVector(v_dst);

	return 0;
}


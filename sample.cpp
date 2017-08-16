#include <msa.h>
#include "dumpVector.hpp"

const unsigned int endianCheck[] = {0x1234567, 0x89abcdef, 0xacacacac, 0x559f559f};
const unsigned int pack1[] = {0x1111, 0x3333, 0x5555, 0x7777};
const unsigned int pack2[] = {0x2222, 0x4444, 0x6666, 0x8888};
const short src1[] = {1, 2, 3, 4, 5, 6, 7, 8, };
const short src2[] = {100, 100, 100, 100, 100, 100, 100, 100,};
short dst[] = {0, 0, 0, 0, 0, 0, 0, 0, };

v8i16 v_pack(const v4i32& a, const v4i32& b)
{
	return __msa_pckev_h((v8i16)a. (v8i16)b);
}

int main(int argc, char**argv)
{
	v4i32 v_pack1 = __msa_ld_w((void*)pack1, 0);
	v4i32 v_pack2 = __msa_ld_w((void*)pack2, 0);
	v8i16 v_pack_dst = v_pack(v_pack1, v_pack2);
	dumpVector(v_pack_dst);

	std::cout << std::hex << "0x" << endianCheck[0] << std::endl;
	std::cout << std::hex << "0x" << endianCheck[1] << std::endl;
	std::cout << std::hex << "0x" << endianCheck[2] << std::endl;
	std::cout << std::hex << "0x" << endianCheck[3] << std::endl;
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


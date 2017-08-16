#include <msa.h>
#include <iostream>
#include <iomanip>

const float src1[] = {1.f, 2.f, 4.f, 8.f,};
const float src2[] = {4.f, 3.f, 2.f, 1.f,};
short dst[] = {0, 0, 0, 0, 0, 0, 0, 0,};
int main(int argc, char**argv)
{
	v4f32 v_src1, v_src2;
	v8i16 v_dst;
	v_src1 = (v4f32)__builtin_msa_ld_w((void*)src1, 0);
	v_src2 = (v4f32)__builtin_msa_ld_w((void*)src2, 0);

	v_dst = __builtin_msa_fexdo_h(v_src1, v_src2);

	__builtin_msa_st_h(v_dst, (void*)dst, 0);

	for( auto i = 0;i < 8;i++)
	{
		std::cout << i << ": 0x" << std::hex << std::setfill('0') << (int)dst[i] << std::endl;
	}

	return 0;
}

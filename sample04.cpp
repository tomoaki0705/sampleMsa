#include <msa.h>
#include <iostream>
#include <iomanip>

const float src[] = {1.f, 2.f, 4.f, 8.f,};
unsigned int dst[] = {0, 0, 0, 0, };
int main(int argc, char**argv)
{
	v4f32 v_src;
	v4i32 v_dst;
	v_src = (v4f32)(__builtin_msa_ld_w((void*)src, 0));

	//v_dst = (v4(v_src);

	__builtin_msa_st_w((v4i32)v_src, (void*)dst, 0);

	for( auto i = 0;i < 4;i++)
	{
		std::cout << i << ": 0x" << std::hex << std::setfill('0') << (int)dst[i] << std::endl;
	}

	return 0;
}

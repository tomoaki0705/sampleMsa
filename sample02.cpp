#include <msa.h>
#include <iostream>

const char src1[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
const char src2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, };
char dst[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
int main(int argc, char**argv)
{
	v16i8 v_src1, v_src2, v_dst;
	v_src1 = __builtin_msa_ld_b((void*)src1, 0);
	v_src2 = __builtin_msa_ld_b((void*)src2, 0);

	v_dst = __builtin_msa_addv_b(v_src1, v_src2);

	__builtin_msa_st_b(v_dst, (void*)dst, 0);

	for( auto i = 0;i < 16;i++)
	{
		std::cout << i << ": " << (int)dst[i] << std::endl;
	}

	return 0;
}

#include <msa.h>
#include "dumpVector.hpp"

const short src1[] = {1, 2, 3, 4, 5, 6, 7, 8, };
const short src2[] = {100, 100, 100, 100, 100, 100, 100, 100,};
short dst[] = {0, 0, 0, 0, 0, 0, 0, 0, };

int main(int argc, char**argv)
{
	unsigned char* foo = (unsigned char*)src1;
	for(auto i = 0;i < 16;i++)
	{
		std::cout << i << "\t: " << (int)foo[i] << std::endl;
	}
	v16i8 v_src1 = (v16i8)__msa_ld_h((void*)src1, 0);
	v16i8 v_src2 = (v16i8)__msa_ld_h((void*)src2, 0);

	dumpVector<v16i8, short>(v_src1);

	v16i8 v_dst = v_src1 + v_src2;

	dumpVector<v16i8, short>(v_dst);

	return 0;
}


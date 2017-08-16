#include <msa.h>
#include "dumpVector.hpp"

const unsigned int endianCheck[] = {0x1234567, 0x89abcdef, 0xacacacac, 0x559f559f};
const short src1[] = {1, 2, 3, 4, 5, 6, 7, 8, };
const short src2[] = {100, 100, 100, 100, 100, 100, 100, 100,};
short dst[] = {0, 0, 0, 0, 0, 0, 0, 0, };

int main(int argc, char**argv)
{
	std::cout << std::hex << "0x" << endianCheck[0] << std::endl;
	std::cout << std::hex << "0x" << endianCheck[1] << std::endl;
	std::cout << std::hex << "0x" << endianCheck[2] << std::endl;
	std::cout << std::hex << "0x" << endianCheck[3] << std::endl;
	v4u32 v_endian = (v4u32)__msa_ld_w((void*)endianCheck, 0);
	dumpVector(v_endian);
	v16u8 v_endianChar = (v16u8)v_endian;
	dumpVector(v_endianChar);

	//v_endianChar = __msa_slli_b(v_endianChar, 3);
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


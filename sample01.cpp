#include <msa.h>
#include <iostream>

int main(int argc, char**argv)
{
	std::cout << "hello world!" << std::endl;
#if defined(__mips_msa)
	std::cout << "MSA enabled via compiler!" << std::endl;
#endif
	return 0;
}

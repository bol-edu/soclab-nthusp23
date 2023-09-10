#include <iostream>
#include <bitset>

void integer_division_modulus(int a, int &r);

void integer_division_modulus_sw(int a, int &r)
{
    r = a % 100;
}

int main()
{
    int status = 0;

    int x;

    int mod_hw;
    int mod_sw;

    for (int i = 0; i < 65536; i++)
    {
        integer_division_modulus(i, mod_hw);
        integer_division_modulus_sw(i, mod_sw);
        if(mod_hw != mod_sw)
        {
            status = -1;
            std::cout << "i = " << std::bitset<5>(i) << "  mod_hw = " << mod_hw << "  mod_sw = " << mod_sw <<std::endl;
            break;
        }
    }

    if (status == 0)
    {
        std::cout << "Test Successful!" << std::endl;
    }
    else
    {
        std::cout << "Test Failed!" << std::endl;
    }

    return status;
}

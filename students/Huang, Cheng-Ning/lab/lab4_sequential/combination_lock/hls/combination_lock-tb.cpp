/************************************************
Copyright (c) 2021, Mohammad Hosseinabady
	mohammad@highlevel-synthesis.com.
	https://highlevel-synthesis.com/

All rights reserved.
Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software
without specific prior written permission.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. // Copyright (c) 2020, Mohammad Hosseinabady.
************************************************/
#include "combination_lock-tb.h"
#include <iostream>


int main() {

	int status = 0;



	bool door_open;
	ap_uint<4> x;
	bool enter = 1;
	bool lock = 0;
	ap_uint<8> seven_segment_data;
	ap_uint<4> seven_segment_enable;

	x=1; enter = 1;
	combination_lock(x, enter, door_open, lock, seven_segment_data,seven_segment_enable);
	std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << " seven_segment_data = " << seven_segment_data.to_string() << std::endl;
	//---------------------------------------------------
	x=2; enter = 1;
	combination_lock(x, enter, door_open, lock, seven_segment_data,seven_segment_enable);
	std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << " seven_segment_data = " << seven_segment_data.to_string() << std::endl;
	//---------------------------------------------------
	x=3; enter = 1;
	combination_lock(x, enter, door_open, lock, seven_segment_data,seven_segment_enable);
	std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << " seven_segment_data = " << seven_segment_data.to_string() << std::endl;
	//---------------------------------------------------
	x=1; enter = 1;
	combination_lock(x, enter, door_open, lock, seven_segment_data,seven_segment_enable);
	std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << " seven_segment_data = " << seven_segment_data.to_string() << std::endl;
	//---------------------------------------------------
	x=2; enter = 1;
	combination_lock(x, enter, door_open, lock, seven_segment_data,seven_segment_enable);
	std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << " seven_segment_data = " << seven_segment_data.to_string() << std::endl;
	//---------------------------------------------------
	x=3; enter = 1;
	combination_lock(x, enter, door_open, lock, seven_segment_data,seven_segment_enable);
	std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << " seven_segment_data = " << seven_segment_data.to_string() << std::endl;
	//---------------------------------------------------
	x=4; enter = 1;
	combination_lock(x, enter, door_open, lock, seven_segment_data,seven_segment_enable);
	std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << " seven_segment_data = " << seven_segment_data.to_string() << std::endl;
	//---------------------------------------------------
	x=6; enter = 0;
	combination_lock(x, enter, door_open, lock, seven_segment_data,seven_segment_enable);
	std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << " seven_segment_data = " << seven_segment_data.to_string() << std::endl;
	//---------------------------------------------------
	x=6; enter = 0;
	combination_lock(x, enter, door_open, lock, seven_segment_data,seven_segment_enable);
	std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << " seven_segment_data = " << seven_segment_data.to_string() << std::endl;
	//---------------------------------------------------
	x=6; enter = 0;
	combination_lock(x, enter, door_open, lock, seven_segment_data,seven_segment_enable);
	std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << " seven_segment_data = " << seven_segment_data.to_string() << std::endl;
	//---------------------------------------------------

	x=6; enter = 1;
	combination_lock(x, enter, door_open, lock, seven_segment_data,seven_segment_enable);
	std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << " seven_segment_data = " << seven_segment_data.to_string() << std::endl;
	//---------------------------------------------------
	x=1; enter = 1;
	combination_lock(x, enter, door_open, lock, seven_segment_data,seven_segment_enable);
	std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << " seven_segment_data = " << seven_segment_data.to_string() << std::endl;
	//---------------------------------------------------
	x=2; enter = 1;
	combination_lock(x, enter, door_open, lock, seven_segment_data,seven_segment_enable);
	std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << " seven_segment_data = " << seven_segment_data.to_string() << std::endl;
	//---------------------------------------------------

	x=2; enter = 1;
	combination_lock(x, enter, door_open, lock, seven_segment_data,seven_segment_enable);
	std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << " seven_segment_data = " << seven_segment_data.to_string() << std::endl;
	//---------------------------------------------------

	x=2; enter = 1;
	combination_lock(x, enter, door_open, lock, seven_segment_data,seven_segment_enable);
	std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << " seven_segment_data = " << seven_segment_data.to_string() << std::endl;
	//---------------------------------------------------
	x=2; enter = 1; lock = 1;
	combination_lock(x, enter, door_open, lock, seven_segment_data,seven_segment_enable);
	std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << " seven_segment_data = " << seven_segment_data.to_string() << std::endl;
	//---------------------------------------------------
	x=2; enter = 1; lock = 0;
	combination_lock(x, enter, door_open, lock, seven_segment_data,seven_segment_enable);
	std::cout << " x = " << x << " enter = " << enter << " lock = " << lock << " door_open = " << door_open << " seven_segment_data = " << seven_segment_data.to_string() << std::endl;
	//---------------------------------------------------





	return status;

}
